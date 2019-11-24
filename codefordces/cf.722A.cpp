#include<bits/stdc++.h>
using namespace std;

int n,h,m;

int main()
{
    cin>>n ;
    scanf("%d:%d",&h,&m);

    if(n==12)
    {
        if(m>0 && !h)h=1;
        if(h>12 || h<10)
        {
            h %= 10;
            if(h)
            {
                cout<<"0"<<h<<":";
            }
            else cout<<"10"<<":";

        }
        else
        {
            cout<<h<<":";
        }

        if(m>59 || m<10)
        {
            m %= 10;
            cout<<"0"<<m;
        }
        else cout<<m;
    }

    if(n==24)
    {

        if(h>23 || h<10)
        {
            h %= 10;
            cout<<"0"<<h<<":";
        }
        else cout<<h<<":";
        if(m>59 || m<10)
        {
            m %= 10;
            cout<<"0"<<m;
        }
        else cout<<m;
    }

    return 0;
}

