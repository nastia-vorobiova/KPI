#include "lib.h"

// Створення списку книг
vector<Book> Create_Book_Base() {
    int count;
    vector<Book> data;
    string name;

    cout << "Press Enter to add books to the list (to  STOP  press Enter instead of writing a name): "; //
    cin.ignore();

    do
    {
        struct Book info;

        cout << "\nEnter name of a book: "; getline(cin, info.name);
        if (info.name == "") break;
        cout << "Enter author of a book: "; getline(cin, info.author);
        cout << "Enter year of a book: "; getline(cin, info.year);
        cout << "Enter language of a book: "; getline(cin, info.language);
        cout << "Enter number of copies: "; getline(cin, info.number);

        data.push_back(info);
    } while (true);

    return data;
}

// Створення бінарного файлу та запис дати
void Write_File(const string& name_of_file, vector<Book> content) {
    string data_information;
    ofstream out(name_of_file, ios::binary);

    for (int i = 0; i < content.size(); ++i) {
        data_information = content[i].name + " - " + content[i].author + ", " + content[i].year + ", " + content[i].language + ", " + content[i].number + " copies";
        out << data_information;
        if (i != content.size() - 1)
            out << '\n';
    }

    out.close();
}

// Зчитування бінарного файлу
void Read_File(const string& name_of_file) {
    string line;
    cout << name_of_file << " file:" << endl;

    ifstream in(name_of_file, ios::binary);
    while (getline(in, line))
        cout << line << endl;
}

// Створення списку книг шуканого автора та підрахунок їх кількості
vector<Book> Modify_Data(vector<Book> content, string searched_author) {
    vector<Book> modify_content;
    bool find = true;
    int number = 0;

    cout << "\nAll books of a searched author:\n";

    for (int i = 0; i < content.size(); ++i) {

        for (int k = 0; k < searched_author.size(); k++)
        {
            if (searched_author[k] != content[i].author[k])
                find = false;
        }

        if (find) {
            cout << content[i].name << " - " << content[i].number << " copies\n";
            modify_content.push_back(content[i]);
            number += stoi(content[i].number);
        }
        else
            find = true;
    }
    cout << "\nTotal number of books: " << number << endl;

    return modify_content;
}

// 
vector<Book> Swap(vector<Book> content, int a, int b) {
    struct Book temp;
    temp = content[a];
    content[a] = content[b];
    content[b] = temp;
    return content;
}

// Сортування списку в алфавітному порядку
vector<Book> Sort_Data(vector<Book> content) {
    vector<Book> sorted_content = content;
    struct Book temp;

    for (int i = 0; i < sorted_content.size() - 1; i++)
        for (int k = i + 1; k < sorted_content.size(); k++) {
            if (sorted_content[i].name > sorted_content[k].name)
                sorted_content = Swap(sorted_content, i, k);
        }
    return sorted_content;
}
