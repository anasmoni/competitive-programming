#include<bits/stdc++.h>
using namespace std;
vector<long long int> a;
int arr[200005];
int main(){
    int n;
    cin>>n;
    a.resize(n);
    for(int i=0;i<n;i++) scanf("%lld",&a[i]);

    sort(a.rbegin(),a.rend());//reversely sorting

    long long ans=0;

    for(int k=1;k<=n;k=k*4){
            ans+=accumulate(a.begin(),a.begin()+k,0);//http://www.cplusplus.com/reference/numeric/accumulate/
           // cout<<ans<<endl;
// sum all elelments upto k
    }
    //for(int i=0 ; i<n ; cout<<a[i++]<<" ");

    printf("%I64d",ans);
}
