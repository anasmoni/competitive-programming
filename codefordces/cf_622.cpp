#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m ; cin>>n>>m; int a[n];

    for(int i=0 ; i<n ; cin>>a[i++]);



    while(m--)
    {
        int l,x,r,v;  scanf("%d%d%d",&l,&r,&x);
        v = count(a+l-1,a+r,x);
        if(v != r-l+1)
        {
            int bn=0;
            int *p; p = upper_bound(a+l,a+r,x);
            //cout<<"p   "<<*p<<endl;
            if(*p!=x){cout<<p-a<<endl;bn=1;}
            else
            {
                int *q;
                q = lower_bound(a+l,a+r,x);
                //cout<<"its q  "<<*q<<endl;
                if(*q!=x){cout<<q-a<<endl;bn=1;}
            }

        }
        else cout<<"-1\n";
    }

    return 0;
}
