#include<bits/stdc++.h>
#include<cstring>
#include<set>

using namespace std;
int a[8] = {2,3,5,7,13,17,19,31};
set<int>st(a,a+8);
char s[100000];

int main()
{
    int n;  cin>>n;

    scanf("%s",s);
    while(--n)
    {
        char c[100000];
        int l=0;
        for(int i=0, ; s[i]!=',' && s[i] ; i++)c[l++]=s[i];

        c[l]='\0';
        if(l<=2 && st.count(atoi(c))==1 ) cout<<"YES\n";
        else cout<<"NO\n" ;

    }

    return 0;
}
