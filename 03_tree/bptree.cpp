#include<bits/stdc++.h>

using namespace std;

int MAX=100;

class bpTreeNode
{
  int *keys;
  bool leaf;
  bpTreeNode **C;
  int Size;
  friend class bPlusTree;

public:
  bpTreeNode();
};

class bPlusTree
{
  bpTreeNode *root;

public:
  bPlusTree();
  void search(int);
  void insert(int);
  void print(bpTreeNode*);
  bpTreeNode* getRoot();
};

int main()
{
  return 0;
}

bpTreeNode::bpTreeNode()
{
  keys=new int[MAX];
  C=new bpTreeNode*[MAX+1];
}

bPlusTree::bPlusTree()
{
  root=NULL;
}

void bPlusTree::search(int x)
{
  if(root==NULL) { cout<<"Tree empty\n"; }

  else
  {
    bpTreeNode *pointer=root;

    while(pointer->leaf==true)
    {
      for(int i=0; i<pointer->Size; i++)
      {
        if(x<pointer->keys[i])
        {
          pointer=pointer->C[i];
          break;
        }
        if(i==pointer->Size-1)
        {
          pointer=pointer->C[i+1];
          break;
        }
      }
    }

    for(int i=0; i<pointer->Size; i++)
		{
			if(pointer->keys[i] == x)
			{
				cout<<"Found\n";
				return;
			}
		}
		cout<<"Not found\n";
  }
}
