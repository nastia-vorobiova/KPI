#include "files.h"

string linewithoutwords(string line, int& words) {
	line += " ";
	string lineOut = "",
		lineTemp = "";
	int i = 0, num = 0;
	while (i < line.length()) {
		if ((line[i] != ' ') & (line[i] != ',') & (line[i] != '.')) {			//ділимо текст на слова
			num++;
			lineTemp += line[i];
		}
		else {
			if (num == 1) {														//шукаємо односимвольні слова і видаляємо їх
				words++;
				cout << lineTemp << " ";
				lineOut[lineOut.length() - 1] = line[i];
			}
			else {
				lineOut += lineTemp;
				lineOut += line[i];
			}
			num = 0;
			lineTemp = "";
		}
		i++;
	}
	return lineOut;
}

string linewothoutcommas(string line, int& commas) {
	int i = 1;
	while (i < line.length()) {
		if ((line[i] == ',') && (line[i] == line[i-1])) {
			line.erase(i, 1);
			i--;
			commas++;
		}
		i++;
	}
	return line;
}

string linewothoutdots(string line, int& dots) {
	int i = 1;
	while (i < line.length()) {
		if ((line[i] == '.') && (line[i] == line[i - 1])) {
			line.erase(i, 1);
			i--;
			dots++;
		}
		i++;
	}
	return line;
}

string linewothoutspaces(string line, int& spaces) {
	int i = 1;
	while (i < line.length()) {
		if ((line[i] == ' ') && (line[i] == line[i - 1])) {
			line.erase(i, 1);
			i--;
			spaces++;
		}
		i++;
	}
	return line;
}

string newline(string line, int& words, int& commas, int& dots, int& spaces) {
	string newline = line;
	newline = linewithoutwords(newline, words);
	newline = linewothoutcommas(newline, commas);
	newline = linewothoutdots(newline, dots);
	newline = linewothoutspaces(newline, spaces);
	return newline;
}

void output(string name) {
	ifstream inFile(name);
	string line;
	while (!inFile.eof()) {
		getline(inFile, line);
		cout << line << endl;
	}
	inFile.close();
}

void input(int act) {
	fstream inFile;
	if (act == 0) {									//Якщо задано очищення вхідного файлу, відкриваємо у режимі з очищення
		inFile.open("input.txt", ios::out);
		inFile.close();
	}
	inFile.open("input.txt", ios::app);
	if (!inFile) {
		cout << "Can`t open input file.";
		return;
	}
	string input, ms;
	cout << "Enter lines (`Shift+N` to finish entering)." << endl;
	char m = _getch();
	cin.ignore();
	while (m != 'N') {										//Перевіряємо, чи введено Shift+N для завершення вводу
		cout << m;
		ms = m;
		getline(cin, input);
		inFile << ms + input << endl;
		m = _getch();
	}
	inFile.close();
}

void writing(string inName, string outName) {
	ifstream inFile;
	inFile.open(inName, ios::in);
	ofstream outFile(outName, ios::out);
	outFile.close();
	outFile.open(outName, ios::app);
	if (!inFile || !outFile) {
		cout << "Error to open file(s)";
		return;
	}
	string line, lineOut;
	int words = 0, commas = 0, dots = 0, spaces = 0;
	cout << "\nRemoved words: ";
	while (!inFile.eof()) {										//порядково оброблюємо текст і вносимо дані у вихідний файл
		getline(inFile, line);
		lineOut = newline(line, words, commas, dots, spaces);		
		outFile << lineOut << endl;
	}
	cout << endl;
	outFile << "Amount of removed words = " << words << "\n";
	outFile << "Amount of removed commas = " << commas << "\n";
	outFile << "Amount of removed dots = " << dots << "\n";
	outFile << "Amount of removed spaces = " << spaces << "\n";
	inFile.close();
	outFile.close();
	cout << "\n";
}