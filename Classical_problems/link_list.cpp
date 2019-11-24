#include<bits/stdc++.h>
using namespace std;

struct node{
    node *next;
    int roll;
};

node *root=NULL;

void append(int r){
    if(root==NULL){
        root = new node();
        root->roll=r;
        root->next=NULL;
    }
    else{
        node *current_node = root;
        while(current_node->next!=NULL){
            current_node=current_node->next;
        }
        node *temp = new node();
        temp->next=NULL;
        temp->roll =r;
        current_node->next=temp;
    }
}

void print(){
    node *temp = root;
    while(temp->next!=NULL){
        cout<<temp->roll<<" ";
        temp=temp->next;
    }
    cout<<temp->roll<<endl;
}

void delete_node(int r){
    node *cn = root;
    node *prev = NULL;
    while(cn->roll!=r){
        prev=cn;
        cn=cn->next;
    }
    if(prev==NULL){
        node *temp = root;
        root=root->next;
        delete(temp);
    }
    else{
        prev->next=cn->next;
        delete(cn);
    }

}

void Reverse(){
    node *cn = root;
    stack<int>st;
    while(1){
        st.push(cn->roll);
        if(cn->next==NULL)break;
        cn = cn->next;
    }
    free(root);
    root=NULL;
    while(st.size()){
        //cout<<st.top()<<" ";
        append(st.top());
        st.pop();
    }
    print();
}


void Sort() {
	node * temp = root;
	node * curr;
	for(bool didSwap = true; didSwap; ) {
		didSwap = false;
		for(curr = root; curr->next != NULL; curr = curr->next) {
			if(curr->roll > curr->next->roll) {
				swap(curr->roll , curr->next->roll);
				didSwap = true;
			}
		}
	}
	print();
}

void Sort_with_stl(){
    node *cn = root;
    multiset<int>ms;
    while(1){
        ms.insert(cn->roll);
        if(cn->next==NULL)break;
        cn = cn->next;
    }
    free(root);
    root=NULL;
    multiset<int>::iterator it;
    it = ms.begin();
    while(it!=ms.end()){
        append(*it);
        it++;
    }
    print();
}

int main(){

    for(int i=1 ; i<10 ; append(i++));
    print();
    delete_node(5);
    print();
    delete_node(1);
    print();
    Reverse();
    append(2);
    append(1);
    Sort_with_stl();
    Reverse();
    Sort();


    return 0;
}
