#include "files.h"

int main()
{
	int act;
	cout << "Clear (0) or append (1)? : ";	//��������� �� ����� �� ��������
	cin >> act;
	input(act);
	string pattern;
	cout << "\nWord-pattern: ";
	cin >> pattern;
	editing("input.txt", "edited.txt", pattern); //������� ����, ������ ������� ����� � �����
	
	cout << "Entered file:\n";
	output("input.txt");
	
	cout << "\nEdited file:\n";
	output("edited.txt");
	
	renaming("edited.txt", "input.txt");
	
	writing("input.txt", "output.txt");

	cout << "\nCreated file:\n";
	output("output.txt");
}