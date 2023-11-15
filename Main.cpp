#include "TrieNode.h"
#include <iostream>
using namespace std;


int main()
{
	setlocale(LC_ALL, "");
	TrieNode Trie;
	//Trie::TrieNode* node = Trie.getNewNode();
	Trie.insert(Trie.root, "Mama");
	Trie.insert(Trie.root, "Man");
	Trie.insert(Trie.root, "Mask");
	Trie.insert(Trie.root, "Papa");
	Trie.insert(Trie.root, "Pat");
	Trie.insert(Trie.root, "Papua-guinea");
	string input;
	int res = 0;
	while (input != "q" and input != "Q")
	{
		cout << "‘ункции:" << endl;
		cout << "1 - добавить слово в словарь" << endl;
		cout << "2 - протестировать программу" << endl;
		cout << "q - выход из программы" << endl;
		cin >> input;
		if (input == "1") res = 1;
		else if (input == "2") res = 2;
		else if (input == "q" or input == "Q") return 0;
		else cout << "¬ведена неверна€ комманда!" << endl;
		cout << endl;
		switch (res)
		{
		case 1:
		{
			cout << "¬ведите слово на латинице дл€ добавлени€ в словарь " << endl;
			cout << "или back дл€ выхода в меню:" << endl;
			while (input != "back" and input != "Back")
			{
				cin >> input;
				if (input != "back" and input != "Back")
				{
					Trie.insert(Trie.root, input);
				}
			}
		}
		case 2:
		{
			cout << "¬ведите слово на латинице " << endl;
			cout << "или back дл€ выхода в меню:" << endl;
			while (input != "back" and input != "Back")
			{
				cin >> input;
				if (input != "back" and input != "Back")
				{
					Trie.showVariants(Trie.root, input);
				}
			}
		}
		}
	}

	return 0;
}