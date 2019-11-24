#include<bits/stdc++.h>
using namespace std;

int main()
{
    char a[1090005],b[1090009];
    gets(a);
    gets(b);

    int i=0,ib=0 ;

    while(a[i]=='0')i++;
    while(b[ib]=='0')ib++;

    int lena = strlen(a)-i , lenb = strlen(b)-ib ;
    //cout<<lena<<" "<<lenb<<endl;
    if(lena==lenb)
    {
        while(a[i]==b[ib] && a[i] && b[ib])i++,ib++;
        if(i==strlen(a) && ib==strlen(b) )cout<<"=";
        else if(a[i]>b[ib])cout<<">";
        else cout<<"<";
    }
    else
    {
        if(lena>lenb)cout<<">";
        else cout<<"<";
    }

    return 0;
}
