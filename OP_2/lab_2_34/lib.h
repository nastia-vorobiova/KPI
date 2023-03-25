#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

// Структура для збереження конкретної інформації про абітурієнтів
struct Book {
    string name;
    string author;
    string year;
    string language;
    string number;
};

// Створення дати про абітурієнтів
vector<Book> Create_Book_Base();

// Створення бінарного файлу та запис дати, зчитування
void Write_File(const string& name_of_file, vector<Book> content);
void Read_File(const string& name_of_file);

// Зміна контенту
/*vector<int> Birth_Transform(string date_of_birth);*/
vector<Book> Modify_Data(vector<Book>, string);
vector<Book> Swap(vector<Book>, int, int);
vector<Book> Sort_Data(vector<Book> content);