#include<bits/stdc++.h>
using namespace std;

int main()
{
    queue<int>p;

    priority_queue<int>pq;

    for(int i=0 ; i<10 ; i++)
    {
        p.push(i); pq.push(i*i);
    }

    while(!p.empty()){cout<<p.front()<<" ";p.pop();}
    cout<<endl;
    while(!pq.empty()){cout<<pq.top()<<" ";pq.pop();}

    return 0;
}
