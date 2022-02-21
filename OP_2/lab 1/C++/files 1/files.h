#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;

string linewithoutwords(string, int&);            //видалення односимвольних слів
string linewothoutcommas(string, int&);			  //видалення ком, що стоять підряд
string linewothoutdots(string, int&);			  //видалення крапок, що стоять підряд
string linewothoutspaces(string, int&);			  //видалення пробілів, що стоять підряд
string newline(string, int&, int&, int&, int&);	  //редагування тексту
void input(int);								  //створення вхідного файлу
void writing(string, string);					  //створення вихідного файлу
void output(string);						  	  //виведення вмісту файлів
