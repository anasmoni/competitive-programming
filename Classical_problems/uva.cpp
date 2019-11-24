#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin>>n ;

    while(n--)
    {
        int len , idx,ans=0 ;
        cin>>len>>idx;
        vector<int>v;
        queue< pair<int,int> >q ; priority_queue<int>pq ;
        for(int i=0 , k ; i<len ; i++)
        {
            cin>>k;
            v.push_back(k);
            q.push(make_pair(k,i));
            pq.push(k);
        }


        while(!q.empty())
        {
            if(q.front().first == pq.top())
            {
                ans++;
                if(q.front().second == idx)
                {
                    cout<<ans<<endl; break;
                }
                q.pop(); pq.pop();
            }
            else
            {
                q.push(q.front());
                q.pop();
            }
        }


    }


    return 0;
}

