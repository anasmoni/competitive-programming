#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector< pair<int,int> >v;

    for(int i=1 ; i<11 ; i++)v.push_back(make_pair(i,i*i));

    for(int i=0 ; i<10 ; i++)cout<<v[i].first<<" "<<v[i].second<<endl;;



    return 0;
}

