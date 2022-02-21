import msvcrt

def linewithoutwords(lines):
    print("\nRemoved words: ", end="")
    num=0
    words = 0
    lineTemp = ""
    for i in range(len(lines)):
        editedline = ""
        for k in range(len(lines[i])):
            lines[i] = lines[i][:-1]
            lines[i] += " "
            if ((lines[i][k] != ' ') & (lines[i][k] != ',') & (lines[i][k] != '.')):
                num += 1
                lineTemp += lines[i][k]
            else:
                if num == 1:
                    words += 1
                    print(lineTemp, end=" ")
                    editedline = editedline[:-1]
                    editedline += lines[i][k]
                else:
                    editedline += lineTemp
                    editedline += lines[i][k]
                num = 0
                lineTemp = ""
        lines[i] = editedline + "\n"
    return lines, words

def linewithoutcommas(lines):
    commas = 0
    for i in range(len(lines)):
        editedline = ""
        k = 1
        while k < len(lines[i]):
            if lines[i][k] == ',' and lines[i][k] == lines[i][k-1]:
                lines[i] = lines[i][:k] + lines[i][k+1:]
                k -= 1
                commas += 1
            k += 1
    return lines, commas

def linewithoutdots(lines):
    dots = 0
    for i in range(len(lines)):
        editedline = ""
        k = 1
        while k < len(lines[i]):
            if lines[i][k] == '.' and lines[i][k] == lines[i][k-1]:
                lines[i] = lines[i][:k] + lines[i][k+1:]
                k -= 1
                dots += 1
            k += 1
    return lines, dots

def linewithoutspaces(lines):
    spaces = 0
    for i in range(len(lines)):
        editedline = ""
        k = 1
        while k < len(lines[i]):
            if lines[i][k] == ' ' and lines[i][k] == lines[i][k-1]:
                lines[i] = lines[i][:k] + lines[i][k+1:]
                k -= 1
                spaces += 1
            k += 1
    return lines, spaces

def output(name):
    with open(name) as file:
        for i in file.readlines():
            print(i, end="")

def enter(act):
    if act==0:                                  #Якщо задано очищення вхідного файлу
        with open("input.txt","w") as inFile:
            pass
    with open("input.txt","a") as inFile:
        print("Enter lines (`Shift+N` to finish entering).")
        m = msvcrt.getch().decode('ASCII')
        while m!='N':                           #Перевіряємо, чи введений Shift+N
            print(m,end="")
            inp=input()
            inFile.write(m+inp+"\n")
            m = msvcrt.getch().decode('ASCII')

def writing(inName,outName):
    with open(inName) as inFile:
        lines=inFile.readlines()
    with open(outName,"w") as outFile:
        outFile.write("")      
    lines, words = linewithoutwords(lines)     #Оброблюємо текст відповідно до умови
    lines, commas = linewithoutcommas(lines)
    lines, dots = linewithoutdots(lines)
    lines, spaces = linewithoutspaces(lines)
    print()
    with  open(outName,"a") as outFile:
        for i in range(len(lines)):
            outFile.write(lines[i])
        outFile.write("\nAmount of removed words = " + str(words))
        outFile.write("\nAmount of removed commas = " + str(commas))
        outFile.write("\nAmount of removed dots = " + str(dots))
        outFile.write("\nAmount of removed spaces = " + str(spaces))