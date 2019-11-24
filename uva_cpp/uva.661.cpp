#include<bits/stdc++.h>
#include<map>

using namespace std;

int main()
{
    int current=0 , n,m,A ,mx=0 ;

    for(int i=1 ;scanf("%d%d%d",&n,&m,&A)==3 ; i++)
    {
        int a[25]={0};
        map<int,int>v ;

        if(!n && !m && !A)break;

        for(int j=1 ; j<=n ; )cin>>v[j++];

        for(current=0 ; m ; m--)
        {
            int x ;
            cin>>x;

            if(!a[x])
            {
                a[x]++;
                current += v[x];
            }
            else
            {
                a[x]-- ;
                current -= v[x] ;
            }

            if(current>A)
            {
                cout<<"Sequence "<<i<<endl<<"Fuse was blown.\n";
                break;
            }
            if(current>mx)mx = current ;

        }
        if(current<=A)cout<<"\nSequence "<<i<<endl<<"Fuse was not blown.\n"<<"Maximal power consumption was "<<mx<<" amperes.\n";



    }

    return 0 ;
}
