#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

int main()
{
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    swap(s[0],s[1]);
    cout<<s;

    return 0 ;
}
