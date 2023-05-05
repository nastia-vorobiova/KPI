#include "header.h"

Text::Text() {
    content = "";
}
void Text::addLine(string line) {
    content += line + "\n";
}
int Text::countVowels() {
    int count = 0;
    for (int i = 0; i < content.length(); i++) {
        char c = tolower(content[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
    }
    return count;
}