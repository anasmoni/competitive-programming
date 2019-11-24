#include<bits/stdc++.h>
using namespace std;

int n,temp,m;
bool T = false ;

int main()
{
    for(cin>>n ; cin>>n; temp = n)
    {
        while(!(n%2))n/=2;
        while(!(n%3))n/=3;
        if(temp && temp-n)T = true;
    }

    cout<<(T?"NO":"YES");

    return 0;
}
