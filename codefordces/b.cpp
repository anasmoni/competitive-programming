#include<bits/stdc++.h>
using namespace std;

int a[2][2];

int main()
{
    int n ; cin>>n ; char c;

    for(int i=0 ; i<n ; i++){ cin>>c; ++a[i%2][c=='r'] ;}

    cout<<min(max(a[0][0],a[1][1]),max(a[0][1],a[1][0]));
    return 0;
}
