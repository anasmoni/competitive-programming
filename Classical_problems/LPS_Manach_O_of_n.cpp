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

/// http://leetcode.com/2011/11/longest-palindromic-substring-part-ii.html
///https://youtu.be/kbUiR5YWUpQ
/**
Even with the extra while loop inside,
it is guaranteed in the worst case the algorithm completes in 2*n steps.
**/

int Manachers(string str)
{
    int n = str.size();
    int c,l,r,i,mirror;
    int p[n];

    for(int i=0; i<n; i++) p[i] = 0;

    c = l = r = 1;

    for(int i=1 ; i<(n-1); i++)
    {
        int mirror = (c-(i-c));

        if(i < r)p[i] = min(p[mirror],(r-i));//

        int j = 1+p[i];

        while(((i+j)<n)&&((i-j)>-1)&&(str[i+j] == str[i-j]))//
        {
            p[i]++;
            j = 1+p[i];
        }
        if((i+p[i]) > r)//
        {
            c = i;
            r = (i+p[i]);
            l = (i-p[i]);
        }
    }

    int mx = INT_MIN;

    for(int i=0; i<n; i++) mx = max(mx,p[i]);

    return mx;
}

string seperation(string str)
{
    int n = str.size();
    string ans = "$#";

    for(int i=0; i<n; i++)
    {
        ans += str[i];
        ans += "#";
    }
    ans += "@";
    return ans;
}


int main()
{
    string str;
    cin >> str;
    str = seperation(str);

    cout << Manachers(str) << endl;

    return 0;
}
