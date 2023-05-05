#include "header.h"

int main() {
    int num_texts;
    cout << "How many texts do you want to create? ";
    cin >> num_texts;
    cin.ignore(); // to consume the \n character left by cin

    Text* texts = new Text[num_texts];
    for (int i = 0; i < num_texts; i++) {
        string text = getInput();
        texts[i].addLine(text);
    }

    findTextWithMostVowels(texts, num_texts);

    return 0;
}

