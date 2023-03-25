#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

// ��������� ��� ���������� ��������� ���������� ��� ��������
struct Book {
    string name;
    string author;
    string year;
    string language;
    string number;
};

// ��������� ���� ��� ��������
vector<Book> Create_Book_Base();

// ��������� �������� ����� �� ����� ����, ����������
void Write_File(const string& name_of_file, vector<Book> content);
void Read_File(const string& name_of_file);

// ���� ��������
/*vector<int> Birth_Transform(string date_of_birth);*/
vector<Book> Modify_Data(vector<Book>, string);
vector<Book> Swap(vector<Book>, int, int);
vector<Book> Sort_Data(vector<Book> content);