#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    scanf("%I64d",&n);
    cout<<"2\n";

    for(long long int i=2 ; i<=n ; i++)printf("%I64d\n",i*(i+1)*(i+1)-(i-1));

    return 0;
}
