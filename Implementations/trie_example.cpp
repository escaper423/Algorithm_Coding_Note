#include <vector>
#include <iostream>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <string>
using namespace std;

class TrieNode
{
public:
	unordered_map<char, TrieNode*> nodes;
	bool isEnd;
	TrieNode()
	{
		isEnd = false;
	}
};

void insertTrie(TrieNode *root, string s)
{
	TrieNode *current = root;
	for (auto &it : s)
	{
		if (current->nodes[it] == nullptr)
		{
			current->nodes[it] = new TrieNode();
		}
		current = current->nodes[it];
	}
	current->isEnd = true;
}

string printElements(TrieNode *root)
{
	TrieNode *current = root;
	string str;
	for (auto &it : current->nodes)
	{
		str += it.first;
		if(current->nodes[it.first])
		str += printElements(current->nodes[it.first]);
		str += '\n';
	}
	return str;
}

bool findPrefix(TrieNode *root, string s)
{
	TrieNode *current = root;
	
	for (auto &it : s)
	{
		if (current->nodes[it])
			current = current->nodes[it];
		else
		{
			current->nodes.erase(it);
			return false;
		}
	}
	return true;
}

bool findWholeWord(TrieNode *root, string s)
{
	TrieNode *current = root;

	for (auto &it : s)
	{
		if (current->nodes[it])
			current = current->nodes[it];
		else
		{
			current->nodes.erase(it);
			return false;
		}
	}
	if (current->isEnd == true)
		return true;
	else return false;
}

bool deleteTrie(TrieNode *cur, string s, int idx)
{
	if (idx == s.length())
	{
		if (cur->isEnd == false)
			return false;

		cur->isEnd = false;
		return cur->nodes.size() == 0;
	}

	char c = s[idx];
	TrieNode *nod = cur->nodes[c];
	if (nod == nullptr)
		return false;

	bool is_to_delete = deleteTrie(nod, s, idx + 1);
	if (is_to_delete)
	{
		cur->nodes.erase(c);
		return cur->nodes.size() == 0;
	}
	return false;
}

int main()
{
	TrieNode *trie = new TrieNode();
	insertTrie(trie, "adbsd");
	insertTrie(trie, "addvc");
	insertTrie(trie, "adfk");
	insertTrie(trie, "adf");
	cout << findPrefix(trie, "adb") << endl;
	cout << findWholeWord(trie, "adfk") << endl;
	cout << findWholeWord(trie, "adf") << endl;
	deleteTrie(trie, "adf", 0);
	deleteTrie(trie, "adfk", 0);
	cout << findPrefix(trie, "adf") << endl;
	cout << findWholeWord(trie, "adfk") << endl;
	cout << findWholeWord(trie, "adf") << endl;
	system("pause");
	return 0;
}
