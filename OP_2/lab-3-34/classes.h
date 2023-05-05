#pragma once
using namespace std;

class Text {
private:
    string content;
public:
    Text();

    void addLine(string);

    int countVowels();
};