#include "header.h"

string getInput() {
    string text;
    string line;
    cout << "Enter lines to your text (or enter an empty line to stop): \n";
    getline(cin, line);
    while (line != "") {
        text += line + "\n";
        //cout << "Enter line (or enter an empty line to stop): ";
        getline(cin, line);
    }
    return text;
}

void findTextWithMostVowels(Text* texts, int num_texts) {
    int max_vowels = 0;
    int* max_indices = new int[num_texts];
    int num_max = 0;
    for (int i = 0; i < num_texts; i++) {
        int vowels = texts[i].countVowels();
        if (vowels > max_vowels) {
            max_vowels = vowels;
            max_indices[0] = i;
            num_max = 1;
        }
        else if (vowels == max_vowels) {
            max_indices[num_max] = i;
            num_max++;
        }
        cout << "\nText " << i + 1 << " has " << vowels << " vowels.";
    }
    if (num_max == 1) {
        cout << "\n\nThe text with the most vowels is text " << (max_indices[0] + 1) << "." << endl;
    }
    else {
        cout << "The texts with the most vowels are: ";
        for (int i = 0; i < num_max; i++) {
            cout << "text " << (max_indices[i] + 1);
            if (i < num_max - 1) {
                cout << ", ";
            }
        }
        cout << "." << endl;
    }
}
