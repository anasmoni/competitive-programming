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
#define N 1000005

/// http://codeforces.com/problemset/problem/490/C

/// given a huge number X with at most 1e6 digits , and 2 int a, b <=1e8............check if X can be split in two parts x,y such that
/// x%a = y%b = 0......y shouldn't have any leading zeros

int Left[N],Right[N];

int main(){
    string s;
    cin>>s;
     lli a,b;
     int len = sz(s);
    scn2ll(a,b);


    Left[0]=1;
    lli hi=len-1 , m=1 , lsum=0LL, rsum=0LL;

    for(int lo=1   ; lo<=len ; lo++,hi--,m*=10LL)
    {
        lsum = lsum*10 + s[lo-1]-'0';
        lsum %= a;

        Left[lo] = lsum; /// prefix

        rsum = (s[hi]-'0')*m + rsum;  /// suffix
        rsum %= b;

        Right[hi] = rsum;
        m %= b;
    }


    for(int i=0; i<len; i++){
       // if(!Left[i])cout<<i<<endl;

        if(!Left[i] && !Right[i] && s[i]!='0'){
            cout<<"YES\n";
            for(int j=0; j<i; j++)cout<<s[j];
            cout<<endl;
            for(int j=i ; j<len; j++)cout<<s[j];
            return 0;
        }
    }
    //cout<<Left[len]<<" "<<Right[0];
    cout<<"NO";
    return 0;
}
