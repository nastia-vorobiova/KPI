#include "lib.h"

int main() {
    // ����� �����
    string input = "input.bin";
    string output = "output.bin";

    // ������������� ������
    vector<Book> book_base;
    vector<Book> modified_book_base;
    vector<Book> sorted_book_base;

    // ��������� ���������� ��� �����
    book_base = Create_Book_Base();

    // ����� �������� �� ���������� �������� �������� �����
    Write_File(input, book_base);
    cout << "\nFull list of books:\n";
    Read_File(input);

    // ������� ����������� ������
    string searched_author;
    cout << "\nSearched author: "; getline(cin, searched_author);

    // ����� ��� ���� ������
    modified_book_base = Modify_Data(book_base, searched_author);

    // ���������� ������ ��������� ����
    sorted_book_base = Sort_Data(modified_book_base);
    
    // ����� �������� �� ���������� ��������� �������� �����
    Write_File(output, sorted_book_base);
    cout << "\nSorted list of author's books:\n";
    Read_File(output);
}