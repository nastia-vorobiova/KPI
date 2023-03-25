#include "lib.h"

int main() {
    // Назва файлів
    string input = "input.bin";
    string output = "output.bin";

    // Ініціалізування змінних
    vector<Book> book_base;
    vector<Book> modified_book_base;
    vector<Book> sorted_book_base;

    // Створення інформації про книги
    book_base = Create_Book_Base();

    // Запис контенту та зчитування вхідного бінарного файлу
    Write_File(input, book_base);
    cout << "\nFull list of books:\n";
    Read_File(input);

    // Задання необхідного автора
    string searched_author;
    cout << "\nSearched author: "; getline(cin, searched_author);

    // Пошук усіх книг автора
    modified_book_base = Modify_Data(book_base, searched_author);

    // Сортування списку знайдених книг
    sorted_book_base = Sort_Data(modified_book_base);
    
    // Запис контенту та зчитування вихідного бінарного файлу
    Write_File(output, sorted_book_base);
    cout << "\nSorted list of author's books:\n";
    Read_File(output);
}