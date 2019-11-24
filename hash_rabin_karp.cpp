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
#define ratoz(v) v.rbegin(),v.rend()
#define Fill(a,v) memset(a,v,sizeof(a))
#define sz(v) v.size()
#define fi first
#define se second
#define inf 1e9
#define pi acos(-1.0)
#define sqr(x) x*x
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define ten(n) (int)1e##n
#define tenll(n) (lli)1e##n

///http://codeforces.com/contest/271/problem/D

/// map - TLE, vector MLE for this problem

/// rabin-karp hash

/// can find number of unique substring .......

lli ans[4000000],len=0;

int main()
{
    ///freopen("debug.txt","w",stdout);
    /*
     ios_base::sync_with_stdio(false);
    cin.tie(0);
    */
    string s;
    cin>>s; /// given string

    string good;
    cin>>good; /// len - 26 , ith char is good if good[i] = '1'

    int k , n = sz(s); /// atmost k bad char can exist in substr that we have to count
    scn(k);


   for(int i=0; i<n; i++){

       for(lli tk=k , j=i , hsh=0 ; j<n; j++){

           if(good[s[j]-'a'] == '0' && !tk--) break;

           else ans[len++] = hsh = (hsh*131)^s[j];
       }
   }
    sort(ans,ans+len);
    cout<<(unique(ans,ans+len)-ans);



    return 0;
}
