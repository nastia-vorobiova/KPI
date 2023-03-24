#include "files.h"

string findingwords(string line, string pattern) {                                  //пошук слів, що відповідають масці
	line += " ";
	string lineOut = "",
		word = "";
	int i = 0, num = 0;
	while (i < line.length()) {
		if ((line[i] != ' ') & (line[i] != ',') & (line[i] != '.')) {					//формуємо слова
			num++;
			word += line[i];
		}
		else {
			if (num > 0)
				if (compare(word, pattern))
					lineOut += "(" + word + ")";
				else
					lineOut += word;
			lineOut += line[i];
			num = 0;
			word = "";
		}
		i++;
	}
	return lineOut;
}

bool compare(string word, string pattern) {                                //порівнюємо слово з маскою
	int w = 0, p = 0;
	while (pattern[p] != '*')
		if (word[w] == pattern[p]) {
			p++;
			w++;
		}
		else
			return false;
	w = word.length() - 1, p = pattern.length() - 1;
	while (pattern[p] != '*')
		if (word[w] == pattern[p]) {
			p--;
			w--;
		}
		else
			return false;
	return true;
}


void output(string name) {                                          //вивід вмісту файлу
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
	if (act == 0) {								                       //Якщо задано очищення вхідного файлу
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
	while (m != 'N') {						                                 //Перевіряємо, чи введено Shift+N для завершення вводу
		cout << m;
		ms = m;
		getline(cin, input);
		inFile << ms + input << endl;
		m = _getch();
	}
	inFile.close();
}

void editing(string inName, string outName, string pattern) {  //створення відредагованого файлу зі словами в дужках
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


	while (!inFile.eof()) {
		getline(inFile, line);
		lineOut = findingwords(line, pattern);	             	//порядково оброблюємо відповідно до умови
		outFile << lineOut << endl;
	}
	cout << endl;
	inFile.close();
	outFile.close();
	cout << "\n";
}

void renaming(const char* inName, const char* outName)           //перейменування файлу
{
	if (remove(outName) == 0)
		cout << "Deleted successfully\n";
	else
		cout << "Unable to delete the file\n";
	if (rename(inName, outName) != 0)
		cout << "There was an error renaming the file.\n" << endl;
	else
		cout << "File renamed successfully!\n" << endl;	
}

void writing(string inName, string outName)                           //запис  файл
{
	ifstream inFile;
	inFile.open(inName, ios::in);
	ofstream outFile(outName, ios::out);
	outFile.close();
	outFile.open(outName, ios::app);
	if (!inFile || !outFile) {
		cout << "Error to open file(s)";
		return;
	}

	string line;

	while (!inFile.eof()) {
		string word;
		getline(inFile, line);
		int count = 0;
		for (int i = 0; i < line.length(); i++)
			                                                // checking character in string
			if (line[i] == '(')
				count++;

		for (int i = 0; i < count; i++) {
			int open = line.find('(');
			int close = line.find(')');
			word = line.substr(open, close - open + 2);
			line.erase(open, close - open + 2);
			line +=  word;
		}

		outFile << line << endl;
	}
	inFile.close();
	outFile.close();
}