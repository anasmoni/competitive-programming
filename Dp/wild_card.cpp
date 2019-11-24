#include <bits/stdc++.h>
using namespace std;

string a,b,c(256,0);
int n,i,j,al,bl,y;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        cin>>a;
        al=a.size();

        cin>>b;
        bl=b.size();
        y=1;

        for (i=j=0; y && i<al; i++)
        {
            if (a[i]=='*')
            {
                while (j<bl-(al-i-1))j++;
                    //if (c[b[j++]]) y=0;
            }
            else
            {
                if(a[i]=='?'? j<bl: a[i]==b[j]) j++;

                else y=0;
            }
        }

        if (j<bl) y=0;
        cout<<y<<endl;

    }
}
