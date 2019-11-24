#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ; cin>>n ; int a[n+1] ;
    int b[n+1];
    long long int sum=0;
    for(int i=1 ; i<=n ; i++){scanf("%d",&a[i]); b[a[i]]=i;}

    for(int i=1 ; i<n ; i++)sum += abs(b[i]-b[i+1]);


    printf("%I64d",sum);

    return 0;
}
