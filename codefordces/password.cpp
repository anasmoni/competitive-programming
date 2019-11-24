#include<bits/stdc++.h>
using namespace std;

char s[150] , pass[105];
int n,k,b,w,j,a[150];

int main()
{
    cin>>n>>k ;

    while(n--)
    {
        scanf("%s",s);
        a[j++] = strlen(s);
    }

    scanf("%s",pass);
    int plen = strlen(pass);
    sort(a,a+j);
    int h=j;

    h = upper_bound(a,a+j,plen)-a;
    j = lower_bound(a,a+j,plen)-a;

    w = h + ((h-1)/k)*5;

    b = j+1 + (j/k)*5;

    cout<<b<<" "<<w;


    return 0;
}
