#include<bits/stdc++.h>
#include<set>
#include<map>
using namespace std;
long  idx=0 , mxa=0 , mxs=0 ,m,n;
map<long,long>ms;
int main()
{

    cin>>n ;
    long int a[n];

    for(long i=0 ; i<n ; i++){ cin>>a[i]; ms[a[i]]++ ;}

    cin>>m ;

    long aud[m] , sub[m] ;

    for(long i=0 ; i<m ; i++)cin>>aud[i];
    for(long i=0 ; i<m ; i++)cin>>sub[i];

    for(long i=0 ; i<m ; i++)
    {
        if(ms[aud[i]]>mxa   ||  (ms[aud[i]]==mxa && (ms[sub[i]]>mxs) ))
        {
            mxa = ms[aud[i]] ;
            mxs = ms[sub[i]];
            idx = i+1;
        }
    }

    !idx ? cout<<"1" : cout<<idx;


    return 0;
}
