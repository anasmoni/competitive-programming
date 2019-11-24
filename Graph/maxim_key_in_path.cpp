/** Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80

    maximum element / key in the path between 20 to 60 is = 70;


       **/


#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node *left , *right;
};

struct Node* newNode(int key)
{
    Node *n = new Node;
    n->key = key;
    n->left = n->right = NULL;
    return n;
}

struct Node* INSERT(struct Node *root, int key)
{

    if(root == NULL)return newNode(key);

    if(root->key > key)
    {
        root->left = INSERT(root->left , key);
    }
    else
    {
        root->right = INSERT(root->right , key);
    }

    return root;
}

struct Node* SEARCH(struct Node *root , int key)
{
    if(root == NULL || root->key == key)return root;

    if(root->key > key)
    {
        return SEARCH(root->left , key);
    }
    else  return SEARCH(root->right , key);
}

bool Normal_search(struct Node *root , int fnd)
{

    while(root!=NULL)
    {
        if(root->key == fnd)return true;
        else if(root->key > fnd)root = root->left;
        else root = root->right;
    }
    return false;
}

void maxim_key(struct Node *root  , int a , int b)
{
    while(root!=NULL)
    {
        if(a<root->key && b<root->key)root = root->left;
        else if(a>root->key && b>root->key)root = root->right;
        else if(a<=root->key && b>=root->key)
        {
            Node *node = NULL;
            node = root;
            int mx = -1;

            while(root!=NULL)
            {
                if(mx<root->key)mx = root->key;
                if(root->key == a)break;
                else if(root->key > a)root = root->left;
                else root = root->right;
            }
            root=node;
            while(root!=NULL)
            {
                if(mx<root->key)mx = root->key;
                if(root->key == b)break;
                else if(root->key > b)root = root->left;
                else root = root->right;
            }

            cout<<"Maximum element in the path between a & b is -> "<<mx<<endl;
            break;
        }
    }
}


int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80
              \
              35*/
    struct Node *root = NULL; // not new Node

    int a[234]= {50 , 70 , 60 , 80 , 30 , 40 , 20,35};
    root = INSERT(root,a[0]);
    for(int i=1 ; i<7; i++)
    {
        INSERT(root,a[i]);
    }

    maxim_key(root, 20 , 60);
    maxim_key(root, 30,35);



    return 0;
}
