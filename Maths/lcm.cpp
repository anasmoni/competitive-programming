#include<bits/stdc++.h>
using namespace std;

int arr[570];

long long int findlcm(int lo ,int hi)
{
    long long int ans = lo;

    for (long long int i=lo+1; i<=hi; i++)ans = ( i*ans) / (__gcd(i, ans) );

    return ans;
}

int main()
{
    int lo , hi ,t=70;
    while(t--){
    long long int n;
    scanf("%I64d",&n);int l,h;
    cin>>l>>h;
lo=min(l,h);hi=max(l,h);
   printf("lcm -> %I64d\n",findlcm(lo,hi));

    printf("output -> %I64d",n/findlcm(lo,hi));

cout<<endl;
    }
    return 0;
}
