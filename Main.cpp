#include "TrieNode.h"
#include <iostream>
using namespace std;


int main()
{
	setlocale(LC_ALL, "");
	TrieNode* Trie = getNewNode();
	//Trie::TrieNode* node = Trie.getNewNode();
	Trie->insert(Trie, "mama");
	Trie->insert(Trie, "man");
	Trie->insert(Trie, "mask");
	Trie->insert(Trie, "papa");
	Trie->insert(Trie, "pat");
	Trie->insert(Trie, "papua-guinea");
	string input;
	int res = 0;
	while (input != "q" and input != "Q")
	{
		cout << "�������:" << endl;
		cout << "1 - �������� ����� � �������" << endl;
		cout << "2 - �������������� ���������" << endl;
		cout << "q - ����� �� ���������" << endl;
		cin >> input;
		if (input == "1") res = 1;
		else if (input == "2") res = 2;
		else if (input == "q" or input == "Q") return 0;
		else cout << "������� �������� ��������!" << endl;
		cout << endl;
		switch (res)
		{
		case 1:
		{
			cout << "������� ����� �� �������� ��� ���������� � ������� " << endl;
			cout << "��� back ��� ������ � ����:" << endl;
			while (input != "back" and input != "Back")
			{
				cin >> input;
				if (input != "back" and input != "Back")
				{
					Trie->insert(Trie->root, input);
				}
			}
		}
		case 2:
		{
			cout << "������� ����� �� �������� " << endl;
			cout << "��� back ��� ������ � ����:" << endl;
			while (input != "back" and input != "Back")
			{
				cin >> input;
				if (input != "back" and input != "Back")
				{
					Trie->showVariants(Trie->root, input);
				}
			}
		}
		}
	}

	return 0;
}