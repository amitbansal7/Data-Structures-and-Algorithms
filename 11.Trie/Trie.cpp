#include <bits/stdc++.h>
using namespace std;

class Trie{
private:
	static const int Max_Children = 26;
	struct TrieNode
	{
		bool isLeaf;
		struct TrieNode* children[Max_Children];
	};

	struct TrieNode* root;

	struct TrieNode* NewNode()
	{
		struct TrieNode* newNode = new TrieNode;

		newNode->isLeaf = false;
		for(int i=0;i<Max_Children;i++)
			newNode->children[i] = NULL;

		return newNode;
	}

	bool isempty(TrieNode* root)
	{
		for(int i=0;i<Max_Children;i++)
			if(root->children[i])
				return 0;
		return 1;
	}

public:

	Trie()
	{
		root = NewNode();
	}

	bool empty()
	{
		return isempty(root);
	}

	int DeleteHelper(struct TrieNode* root, string s, int lvl, int len)
	{
		if(!root)
			return 0;

		if(lvl == len)
		{
			if(root->isLeaf)
			{
				root->isLeaf = false;
				if(isempty(root))
					return true;
			}
			return false;
		}
		else
		{
			if(DeleteHelper(root->children[s[lvl]-'a'],s ,lvl+1, len))
			{
				delete root->children[s[lvl]-'a'];
				root->children[s[lvl] - 'a'] = NULL;

				return isempty(root) && !root->isLeaf;
			}
		}
		return false;
	}

	void deleteKey(string s)
	{
		bool a = DeleteHelper(root, s, 0, s.size());
	}
	void insertKey(string s)
	{
		struct TrieNode* crawl = root;

		for(char c:s)
		{
			if(!crawl->children[c-'a'])
				crawl->children[c-'a'] = NewNode();

			crawl = crawl->children[c-'a'];
		}

		crawl->isLeaf = 1;
	}

	bool search(string s)
	{
		struct TrieNode* crawl = root;

		for(char c:s)
		{
			if(!crawl->children[c-'a'])
				return 0;

			crawl = crawl->children[c-'a'];
		}

		return crawl->isLeaf == 1;
	}
};


/*

	*Initialize the data structure
		Trie name;

	*Insert a string into trie
		name.insertKey("string");

	*Search for a string(return boolean variable)
		name.search("string")

	*Delete a string from trie
		name.deleteKey("string")

	*Check if trie is empty (return boolean variable)
		name.empty();
*/

int main()
{
	string Input[] = {"the","a","there","answer","any","by","bye","their"};

	Trie T;

	for(string s:Input)
		T.insertKey(s);

	printf("%d\n",T.search("the"));

	T.deleteKey("the");

	printf("%d\n",T.search("the"));
	printf("%d\n",T.search("there"));
	printf("%d\n",T.search("their"));
	printf("%d\n",T.search("thea"));

	return 0;
}
