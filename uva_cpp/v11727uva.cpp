#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    int t ;
    cin>>t;
    for(int i=1 ; i<=t ; i++)
    {
        int a,b,c,m;
        cin>>a>>b>>c;

        cout<<"case "<<i<<": "<<nmid(a,b,c)<<endl;

    }
    return 0;
}
