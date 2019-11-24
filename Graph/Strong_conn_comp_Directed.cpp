#include<bits/stdc++.h>
using namespace std;

#define sz 100005

vector<int>V[sz];
vector<int>trans[sz];
int n,m;

void DFS(int v, bool visited[])
{
    visited[v] = true;
    cout << v << " ";

    for (int i : trans[v]){

        if (!visited[i])  DFS(i, visited);
    }
}

void Transpose()
{
    for (int v = 1 ; v <= n; v++)
    {
        for(int i : V[v]) trans[i].push_back(v);
    }
}

void Order(int v, bool visited[], stack<int> &Stack)
{
    visited[v] = true;

    for(int i : V[v]){

        if(!visited[i])  Order(i, visited, Stack);
    }

    Stack.push(v);
}

void printSCCs()
{
    stack<int> Stack;

    bool visited[n+1];

    for(int i = 1; i <= n ; i++) visited[i] = false;

    for(int i = 1; i <= n; i++){

        if(!visited[i]) Order(i, visited, Stack);
    }

    /** a decreasing sequence(according to their fin time) in the stack  */

    Transpose();

    for(int i = 1; i <= n; i++) visited[i] = false;

    while (Stack.empty() == false)
    {
        int v = Stack.top();
        Stack.pop();

        if (visited[v] == false)
        {
            DFS(v, visited);//printing scc
            cout << endl;
        }
    }
}

int main(){

    scanf("%d%d",&n,&m);

    while(m--){

        int u,v;
        scanf("%d%d",&u,&v);
        V[u].push_back(v);
    }

    printSCCs();

    return 0;
}
