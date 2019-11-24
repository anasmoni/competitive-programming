/**All articles on BST ->   http://www.geeksforgeeks.org/binary-search-tree/ **/


#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node *left , *right;
};

struct Node* newNode(int key){
    Node *n = new Node;
    n->key = key;
    n->left = n->right = NULL;
    return n;
}

struct Node* INSERT(struct Node *root, int key){

    if(root == NULL)return newNode(key);

    if(root->key > key){
        root->left = INSERT(root->left , key);
    }
    else{
        root->right = INSERT(root->right , key);
    }

    return root;
}

struct Node* SEARCH(struct Node *root , int key){
    if(root == NULL || root->key == key)return root;

    if(root->key > key){
        return SEARCH(root->left , key);
    }
    else  return SEARCH(root->right , key);
}

bool Normal_search(struct Node *root , int fnd){

    while(root!=NULL){
        if(root->key == fnd)return true;
        else if(root->key > fnd)root = root->left;
        else root = root->right;
    }
    return false;
}

void print_all_elements(struct Node *root){
    if(root!= NULL){
        print_all_elements(root->left);
        cout<<root->key<<" ";
        print_all_elements(root->right);
    }
}




int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */

    struct Node *root = NULL; // not new Node

    int a[234]= {50 , 70 , 60 , 80 , 30 , 40 , 20};
    root = INSERT(root,a[0]);
    for(int i=1 ; i<7; i++){
        INSERT(root,a[i]);
    }

    if(Normal_search(root,40))cout<<"Yep found normally \n";
    else cout<<"NOT found normally \n";

    if(SEARCH(root,50) != NULL)cout<<"found recursively\n";
    else cout<<"not found recursively\n";

    INSERT(root , 100);

    if(SEARCH(root,100) != NULL)cout<<"After Inserting 100 ->\nfound recursively\n";
    else cout<<"not found recursively\n";

    print_all_elements(root);


    return 0;
}
