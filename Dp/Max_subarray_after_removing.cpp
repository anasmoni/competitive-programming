#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vec;

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define scn(n) scanf("%d",&n)
#define scnll(n) scanf("%lld",&n)
#define scn2(n,m) scanf("%d%d",&n,&m)
#define scn3(n,m,w) scanf("%d%d%d",&n,&m,&w)
#define scn2ll(n,m) scanf("%lld%lld",&n,&m)
#define atoz(v) v.begin(),v.end()
#define Fill(a,v) memset(a,v,sizeof(a))
#define sz(v) v.size()
#define fi first
#define se second
#define inf 1e9
#define pi acos(-1.0)
#define sqr(x) x*x
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define N 100005

lli dp[N][2], sum[N];
int a[N], Q[N];

///https://csacademy.com/contest/archive/task/array-removal/

/// aproach...we traverse in a reverse order ...each time we check whether current query idx can merger
/// it's left or right subarrays;

int main()
{
    int n;
    scn(n);
    Fill(dp,-1);

    for(int i=1; i<=n; i++){
        scn(a[i]);
    }

    for(int i=1; i<=n; i++){
        scn(Q[i]); /// offline algo...so store all queries
    }

    stack<lli>stk; /// we r solving in a reverse order .....so  using stack to store ans
    lli mx=-1LL; /// current max....each time we marge   (....idx-2, idx-1),( idx ),(idx+1, idx+2..)sub arrays
    /// and update max

    for( ; n ; n--){

        int l = Q[n]-1;     /// start point of left subarray
        int r = Q[n]+1;     /// start point of right subarray
        int rr = dp[r][1]; /// end point of right subarray
        int ll = dp[l][0]; /// end point of left subarray

        if(rr == ll && rr == -1){ /// no left or right subarray found to merge

            mx = max((lli)a[Q[n]],mx);
            stk.push(mx);
            dp[Q[n]][0] = dp[Q[n]][1] = Q[n];
            sum[Q[n]] = a[Q[n]];
        }
        else if(rr == -1){ /// left subarry found so merge with it

            sum[Q[n]] = sum[ll] = a[Q[n]] + sum[l]; /// keep sum of merged array  into the two end points
            mx = max(mx,sum[ll]);
            stk.push(mx);

            /// update new endpoint (left,right) of merged array
            dp[Q[n]][0] = ll;
            dp[ll][1] = dp[Q[n]][1] = Q[n];

        }
        else if(ll == -1){

            sum[Q[n]] = sum[rr] = a[Q[n]] + sum[r];
            mx = max(mx,sum[rr]);
            stk.push(mx);

            dp[Q[n]][1] = rr;
            dp[rr][0] = dp[Q[n]][0] = Q[n];
        }
        else{
            sum[ll] = sum[rr] = a[Q[n]] + sum[l] + sum[r];
            mx = max(mx,sum[ll]);
            stk.push(mx);

            dp[ll][1] = rr;
            dp[rr][0] = ll;
        }
    }

    while(!stk.empty()){
        cout<<stk.top()<<endl;
        stk.pop();
    }

    return 0;
}


