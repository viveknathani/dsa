#include<iostream>

using namespace std;

class treeNode
{
public:
  int data;
  treeNode *left;
  treeNode *right;
};

treeNode* create(int value)
{
  treeNode *n=new treeNode;
  n->data=value;
  n->left=n->right=NULL;
  return n;
}

treeNode* Insert(treeNode* root, int data)
{
  if(root==NULL)
  {
    root=create(data);
  }
  else if(data<=root->data)
  {
    root->left=Insert(root->left, data);
  }
  else
  {
    root->right=Insert(root->right, data);
  }
  return root;
}

void inorder(treeNode *root)
{
  if(root==NULL) { return; }
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}

treeNode* findmin(treeNode *root)
{
  treeNode *current=root;
  while(current->left!=NULL)
  {
    current=current->left;
  }
  return current;
}

treeNode* Delete(treeNode *root, int key)
 {
   //base case
   if(root==NULL) { return root; }

   if(key<root->data)
   {
     root->left=Delete(root->left, key);
   }

   else if(key>root->data)
   {
     root->right=Delete(root->right, key);
   }

   else
   {
     if(root->left==NULL && root->right==NULL)
     {
       delete root;
       root=NULL;
     }

     else if(root->left==NULL)
     {
       treeNode *temp=root;
       root=root->right;
       delete temp;
     }

     else if(root->right==NULL)
     {
       treeNode *temp=root;
       root=root->left;
       delete temp;
     }
     else
     {
       treeNode *temp=findmin(root->right);
       root->data=temp->data;
       root->right=Delete(root->right, temp->data);
     }
   }
   return root;
 }

int main()
{
  treeNode *root=NULL;
  root=Insert(root, 5);
  root=Insert(root, 6);
  root=Insert(root, 2);
  root=Insert(root, 1);
  root=Insert(root, 78);
  root=Insert(root, 11);
  inorder(root);
  cout<<endl;
  root=Delete(root, 78);
  inorder(root);
  cout<<endl;
  return 0;
}
