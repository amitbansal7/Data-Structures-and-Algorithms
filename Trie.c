#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ALPHABET_SIZE 26
#define false 0
#define true 1
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
#define FREE(n)\
	free(n);	\
	n = NULL;

// Trie insert , search and delete
struct Node 
{
	struct Node *children[ALPHABET_SIZE];
	int isLeaf;
};

int search(struct Node* root,const char *key)
{
	int level;
	int length = strlen(key);
	int index;
	struct Node* crawl = root;

	for(level=0;level<length;level++)
	{
		index = CHAR_TO_INDEX(key[level]);
		if(!crawl->children[index])
			return false;

		crawl = crawl->children[index];
	}

	return (crawl!=NULL && crawl->isLeaf);
}

struct Node* NewNode()
{
	struct Node* pNode = (struct Node*)malloc(sizeof(struct Node));

	if(pNode)
	{
		int i;
		pNode->isLeaf = false;

		for(i=0;i<ALPHABET_SIZE;i++)
			pNode->children[i] = NULL;

	}
	return pNode;
}

void insert(struct Node* root,const char *key)
{
	int level;
	int length = strlen(key);
	int index;

	struct Node* crawl = root;

	for(level=0; level<length; level++)
	{
		index = CHAR_TO_INDEX(key[level]);

		if(!crawl->children[index])
			crawl->children[index] = NewNode();

		crawl = crawl->children[index];
	}
	crawl->isLeaf = true;
}

int isEmptyNode(struct Node* pNode)
{
	int i;

	for(i=0;i<ALPHABET_SIZE;i++)
		if(pNode->children[i])
			return 0;
	return 1;
}

int DeleteKey(struct Node* pNode,const char *key,int level,int len)
{
	if(pNode)
	{
		if(level==len)
		{
			if(pNode->isLeaf)
			{
				pNode->isLeaf = false;

				if(isEmptyNode(pNode))
					return true;
			}
			return false;
		}

		else
		{
			int index = CHAR_TO_INDEX(key[level]);

			if(DeleteKey(pNode->children[index],key,level+1,len))
			{
				FREE(pNode->children[index]);

				return((pNode->isLeaf==0) && isEmptyNode(pNode));
			}
		}
	}

	return false;
}

void Delete(struct Node* root,const char *key)
{
	int len = strlen(key);

	if(key>0)
	{
		DeleteKey(root,key,0,len);

	}
}

int main()
{
	char strings[][10] = {"the","a","there","answer","any","by","bye","their"};
	char output[][30] = {"Not present in trie","Present in trie"};

	int total = sizeof(strings)/sizeof(strings[0]);

	struct Node* root = NewNode();

	int i;

	for(i=0;i<total;i++)
		insert(root,strings[i]);

	printf("\n%s---%s\n","these",output[search(root,"these")]);
	printf("%s---%s\n","the",output[search(root,"the")]);
	printf("%s---%s\n","that",output[search(root,"that")]);
	printf("%s---%s\n","this",output[search(root,"this")]);
	
	Delete(root,"the");
	printf("\nDeleting \"the\" \n\n");

	printf("%s---%s\n","the",output[search(root,"the")]);

	return 0;
}