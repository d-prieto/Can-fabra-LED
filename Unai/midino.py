import mido

while True:
    try:
        track = mido.MidiFile(input("Enter MIDI file name: ") + ".mid")
        break
    except FileNotFoundError:
        print("FileNotFoundError: Please try again.")
text = ""
text += input("Enter song name: ") + "\n" + input("Enter song author: ") + "\n" + input("Comment: ") + "\n" + input("Enter song tempo: ") + "\n\n"
ltrack = []
for i in track:
    if i.type == 'note_on':
        ltrack.append([i.note, i.velocity, i.time])

song = {0:{}}
timestamp = 0
for i in range(len(ltrack)):
    lasttime = timestamp
    timestamp += ltrack[i][2]
    if timestamp not in song.keys():
        song[timestamp] = song[lasttime].copy()
    song[timestamp][["A","Bb","B","C","Db","D","Eb","E","F","Gb","G","Ab"][(ltrack[i][0]-21)%12] + str((ltrack[i][0]-24)//12+1)] = ltrack[i][1]

notesInOrder = []

for i in range(9):
    for j in range(12):
        notesInOrder.append(["C","Db","D","Eb","E","F","Gb","G","Ab","A","Bb","B"][j] + str(i))
lasttime = 0
for i in song.keys():
    done = False
    text += str(i - lasttime) + "\n"
    for j in notesInOrder[::-1]:
        if j in song[i]:
            if song[i][j] > 0:
                text += j[len(j)-1:] + "\n"
                text += j[:(len(j)-1)] + "\n"
                done = True
                break
    if not done:
        text += "0\nS\n"
    lasttime = i
    text += "\n"
text += "0"

# ------------
# -- Part 2 --
# ------------

score = text.splitlines()
name = score[0]
pin = input("Enter pin number: ")
output = open(input("Enter output file name: ") + ".ino", "w")
author = score[1]
comment = score[2]
tempo = score[3]
result = """

const int pin = """ + pin + """; // Change pin number if necessary

void setup() {
    Serial.begin(9600);
    pinMode(pin, OUTPUT);
    Serial.println(" -- """ + name + """ --\");
    Serial.println("By """ + author + """");
    Serial.println(\"""" + comment + """\");
}
void loop() {
"""

delay = 0

notes = {"C": 16.35, "Db": 17.32, "D": 18.35, "Eb": 19.45, "E": 20.60, "F": 21.83, "Gb": 23.12, "G": 24.50, "Ab": 25.96, "A": 27.50, "Bb": 29.14, "B": 30.87}
for i in range(5,len(score)-4,4):
    print(score[i-1])
    duration = float(score[i+4])*1000
    octave = int(score[i+1])
    note = score[i+2]
    if note != "S":
        freq = notes[note]*(2**octave)
        result += f"    delay({delay});\n"
        delay = 0
        result += f"    tone(pin, {freq}, {duration}); // {note}{octave}\n"
    delay += duration
result += """
    delay(1000); // Pause for 1 second
}"""
print(result)
output.write(result)
