#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef pair<int,int> pii;

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define scn(n) scanf("%d",&n)
#define scn2(n,m) scanf("%d%d",&n,&m)
#define llscn(n) scanf("%I64d",&n)
#define llscn2(n,m) scanf("%I64d%I64d",&n,&m)
#define atoz(v) v.begin(),v.end()
#define fill(a,v) memset(a,v,sizeof(a))
#define sz(v) v.size()
#define fi first
#define se second
#define inf 1e9
#define pi acos(-1.0)
#define sqr(x) x*x
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))



int fun(int a[], int n){

    int max_end_here = 0, max_so_far=INT_MIN;

    for(int i=0; i<n; i++){

        max_end_here += a[i];

        max_so_far = max(max_so_far, max_end_here);

        max_end_here = max(0,max_end_here);
    }

    return max_so_far;
}

int main()
{
    int t;
    scn(t);

    while(t--){

        int n;
        scn(n);
        int a[n];

        for(int i=0 ; i<n; i++)scn(a[i]);

        printf("%d\n",fun(a,n));
    }

    return 0;
}
