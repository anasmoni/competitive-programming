#include<bits/stdc++.h>
#define nmax(a,b,c) (max(a,b)>c ? max(a,b) : c)
#define nmin(a,b,c) (min(a,b)<c ? min(a,b) : c)

using namespace std;

int main()
{
    int t ;
    cin>>t;
    for(int i=1 ; i<=t ; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        cout<<"case "<<i<<": "<<a+b+c-nmax(a,b,c)-nmin(a,b,c)<<endl;

    }
    return 0;
}
