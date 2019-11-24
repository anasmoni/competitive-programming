#include<bits/stdc++.h>
using namespace std;
char s[110];
int main()
{
    int n;
    cin>>n ;
    int a[n] ;
    string str = "aeiouy";

    for(int i=0 ; i<n ; i++)scanf("%d",a+i);
    gets(s);
    for(int i=0 ; i<n ; i++)
    {
        gets(s);
        int sum=0;
        for(int j=0 ; s[j] ; j++)
        {
            if(str.find(s[j])!=string::npos)sum++;
        }
        if(sum!=a[i]){ cout<<"NO"; return 0;}
    }

    cout<<"YES";

    return 0;
}
