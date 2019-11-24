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
///http://codeforces.com/problemset/problem/339/C
vector<int>num;
stack<int>ans;

int fun(int m , int prev_wt=12 ,int diff=0){

    if(m==0)return 1;

    int len = sz(num);

    if(len && num[len-1] <= diff ) return -1; /// can't cover this diff with the max num

    if(len>1){
        if(num[len-1]==prev_wt && num[len-2]<=diff) return -1; /// largest = prev and 2nd max can't cover diff
    }


    for(auto x : num){

        if(x>diff && x!=prev_wt){
            if(fun(m-1,x,x-diff)==1){
                ans.push(x);
                return 1;
            }
        }
    }

    return -1;
}


int main()
{
    char s[23];
    scanf("%s",s+1);
    int m;
    scn(m);

    for(int i=1; i<=10 ; i++){
        if(s[i]=='1')num.pb(i);
    }

    if(fun(m)==-1)
    {
        cout<<"NO";
    }
    else{
        cout<<"YES\n";
        while(!ans.empty()){
            cout<<ans.top()<<" ";
            ans.pop();
        }
    }

    return 0;
}
