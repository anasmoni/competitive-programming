#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ; cin>>n ; char s[n+1] ; scanf("%s",s);

    int k=0,a[n];

    for(int i=0 ; s[i] ; i++)
    {
        int j=i;
        while(s[i]=='B')i++;
        if(i>j)a[k++]=i-j;
    }
    if(k)
    {
        cout<<k<<endl;
        for(int i=0 ; i<k ; cout<<a[i++]<<" ");
    }
    else cout<<"0";

    return 0;
}
