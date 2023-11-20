#include "TrieNode.h"
#include <iostream>

using namespace std;

//TrieNode::TrieNode()
//{
//    root = getNewNode();
//}

TrieNode::~TrieNode()
{
    TrieNode* node;
    while (root != nullptr)
    {
        node = root;
        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
            if (node->children[i] != nullptr and isEmpty(node->children[i])) delete node->children[i];
            else if (node->children[i] != nullptr) node = node->children[i];
        }
        delete node;
    }
}

// Вставляет ключ в дерево, если его нет, 
// иначе если ключ явлется префксом узла дерева 
// помечает вкачестве литового т.е. конец слова
void TrieNode::insert(TrieNode* root, string key)
{
    TrieNode* node = root;

    for (int i = 0; i < key.length(); i++)
    {
        // вычисляем индекс в алфите через смещение отнситьельно первой буквы
        int index = key[i] - 'a';

        // если указатель пустрой, т.е. детей с таким префиксом нет
        // создаем новый узел
        if (!node->children[index]) node->children[index] = getNewNode();

        node = node->children[index];
    }

    // помечаем последний узлел как лист, т.е. конец слова
    node->isEndOfWord = true;
}

// Возврашает true если ключ есть в дереве, иначе false 
bool TrieNode::search(struct TrieNode* root, string key)
{
    struct TrieNode* node = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!node->children[index])
            return false;

        node = node->children[index];
    }

    return (node != nullptr && node->isEndOfWord);
}

// Вохвращает true если root имеет лист, иначе false 
bool TrieNode::isEmpty(TrieNode* root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return false;
    return true;
}

// Рекурсивная функция удаления ключа из дерева 
TrieNode* TrieNode::remove(TrieNode* root, string key, int depth)
{
    // Если дерево пустое 
    if (!root)
        return nullptr;

    // если дошли до конца ключа 
    if (depth == key.size()) {

        // Этот узел больше не конец слова 
        if (root->isEndOfWord)
            root->isEndOfWord = false;

        // Если ключ не евляется префиксом, удаляем его
        if (isEmpty(root)) {
            delete (root);
            root = nullptr;
        }

        return root;
    }

    // Если не дошли до конца ключа, рекурсивно вызываем для ребенка 
    // соответствующего символа 
    int index = key[depth] - 'a';
    root->children[index] = remove(root->children[index], key, depth + 1);

    // Если у корня нет дочернего слова 
    // (удален только один его дочерний элемент), 
    // и он не заканчивается другим словом. 
    if (isEmpty(root) && root->isEndOfWord == false) {
        delete (root);
        root = nullptr;
    }

    // возвращаем новый корень
    return root;
}

//Функция вывода возможных вариантов продолжения слова для введенной пользователем части
void TrieNode::showVariants(TrieNode* root, std::string key)
{
    TrieNode* node = root;
    std::string res = key;
    int size = key.size();

    //проходимся по дереву до последней буквы введеного слова
    for (int i = 0; i < size; i++)
    {
        // вычисляем индекс в алфите через смещение отнситьельно первой буквы
        int index = key[i] - 'a';

        // если указатель пустрой, т.е. детей с таким префиксом нет
        // выходим из функции

        if (!node->children[index]) return;

        node = node->children[index];
    }

    //если введеная пользователем часть не является
    //концом слова и есть продолжение в словаре
    //выводим возможные варианты слов
    if (!node->isEndOfWord and !isEmpty(node))
    {
        cout << "Возможно вы имели ввиду:" << endl;
        TrieNode::T9(node, res);
        cout << endl;
    }
}

void TrieNode::T9(TrieNode* root, std::string result)
{
    TrieNode* node = root;
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (node->children[i])
        {
            result.push_back(i + 'a');
            if (node->children[i]->isEndOfWord)
            {
                for (int j = 0; j < result.size(); j++)
                    cout << result[j];
                cout << endl;
            }
            T9(node->children[i], result);
            result.pop_back();
        }
    }
}

TrieNode* getNewNode(void) 
{
    // Выделяем память по новый узел
    struct TrieNode* pNode = new TrieNode;

    // устанавливаем флаг конца слова в false
    pNode->isEndOfWord = false;

    // инициализируем детей нулевым уазателем
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = nullptr;

    return pNode;
}