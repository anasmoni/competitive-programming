#include<bits/stdc++.h>

using namespace std;

int n,m,t,x,y,ans;

int main()
{

   char s[14] = "anasaass";
   sort(s,s+strlen(s));

   int i = unique(s,s+strlen(s))-s;

   cout<<i;

    return 0;
}

