#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i , k ,j;

    char s[1005] ;
    string c = "oOxXIYwWUMATVvH";

    gets(s);
    if(strlen(s)==1)
    {
        if(c.find(s[0]) != c.npos){cout<<"TAK"; return 0;}
        else{ cout<<"NIE"; return 0 ;}
    }

    for(i=0 , k=strlen(s)-1;k>=i; i++ , k--)
    {
        if(s[i]==s[k]){if(c.find(s[i]) == c.npos){cout<<"NIE"; return 0;}}
        else
        {
            if((s[i]=='p' && s[k]=='q') || (s[i]=='q' && s[k]=='p'));
            else if((s[i]=='b' && s[k]=='d') || (s[i]=='d' && s[k]=='b'));
            else {cout<<"NIE";return 0 ;}
        }
        if((k==i))break;
    }

    cout<<"TAK";

    return 0;
}
