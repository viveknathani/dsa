#include<bits/stdc++.h>
using namespace std;

class bTreeNode
{
  int *keys;
  int t; //minimum degree
  bTreeNode **C; //array of child pointers
  int n; //current number of keys
  bool leaf; //true when node is leaf

public:
  bTreeNode(int _t, bool _leaf);
  void traverse();
  bTreeNode *search(int k);
  void insertNonFull(int k);
  void splitChild(int i, bTreeNode *y);

//make bTree friend of this class so that bTree functions
//can access the private members of this class
friend class bTree;
};

class bTree
{
  bTreeNode *root;
  int t;

public:
  bTree(int _t) { root=NULL; t=_t; }
  void traverse() { if(root!=NULL) root->traverse(); }
  bTreeNode* search(int k)
  { return (root==NULL) ? NULL : root->search(k); }
  void insert(int k);
};

bTreeNode::bTreeNode(int _t, bool _leaf)
{
  t=_t; leaf=_leaf;

  keys=new int[2*t-1];
  C=new bTreeNode *[2*t];

  n=0;
}

void bTreeNode::traverse()
{
  int i;
  for(i=0; i<n; i++)
  {
    if(leaf==false) { C[i]->traverse(); }
    cout<<keys[i]<<" ";
  }

  if(leaf==false) { C[i]->traverse(); }
}

bTreeNode *bTreeNode::search(int k)
{
  int i=0;

  while(i<n && k>keys[i]) { i++; }

  if(keys[i]==k) { return this; }

  if(leaf==true) { return NULL; }

  return C[i]->search(k);
}

void bTree::insert(int k)
{
  if(root==NULL)
  {
    root=new bTreeNode(t, true);
    root->keys[0]=k;
    root->n=1;
  }
  else
  {
    if(root->n==2*t-1)
    {
      bTreeNode *s=new bTreeNode(t, false);
      s->C[0]=root;
      s->splitChild(0, root);

      int i=0;
      if(s->keys[0]<k) { i++; }
      s->C[i]->insertNonFull(k);
      root=s;
    }
    else { root->insertNonFull(k); }
  }
}

void bTreeNode::insertNonFull(int k)
{
  int i=n-1;

  if(leaf==true)
  {
    while(i>=0 && keys[i]>k)
    {
      keys[i+1]=keys[i];
      i--;
    }

    keys[i+1]=k;
    n=n+1;
  }

  else
  {
    while(i>=0 && keys[i]>k) { i--; }

    if(C[i+1]->n==2*t-1)
    {
      splitChild(i+1, C[i+1]);

      if(keys[i+1]<k) { i++; }
    }

    C[i+1]->insertNonFull(k);
  }
}

void bTreeNode::splitChild(int i, bTreeNode *y)
{
  bTreeNode *z=new bTreeNode(y->t, y->leaf);
  z->n=t-1;

  for(int j=0; j<t-1; j++)
  {
    z->keys[j]=y->keys[j+t];
  }

  if(y->leaf==false)
  {
    for(int j=0; j<t; j++)
    {
      z->C[j]=y->C[j+t];
    }
  }

  y->n=t-1;

  for(int j=n; j>=i+1; j--)
  {
    C[j+1]=z;
  }

  C[i+1]=z;

  for(int j=n-1; j>=i; j--)
  {
    keys[j+1]=keys[i];
  }

  keys[i]=y->keys[t-1];

  n=n+1;
}

int main()
{
  bTree t(3);

  t.insert(30);
  t.insert(3);
  t.insert(7);
  t.insert(14);
  t.insert(28);
  t.insert(8);
  t.insert(16);

  t.traverse();

  (t.search(6)!=NULL) ? cout<<"\nPresent\n" : cout<<"\nNot found.\n";
  (t.search(14)!=NULL) ? cout<<"\nPresent\n" : cout<<"\nNot found.\n";

  return 0;
}
