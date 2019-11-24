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
#define ten(n) (int)1e##n
#define tenll(n) (lli)1e##n

const int MAX=1e6+9;
bool mark[MAX];
int f[MAX],k,n; /// f[i] = legnth of longest prefix which is also a suffix of the substring [s1,s2,s3....si]

///http://codeforces.com/contest/126/problem/B

int main()
{
	string s;
	cin>>s;
	n=s.size();

	for (int i=1;i<n;i++)
	{
		while (k && s[i]!=s[k]) k=f[k-1];

		if (s[i]==s[k]) k++;

		if (i<n-1) mark[k]=true; /// this line is just to solve this particular problem

		f[i]=k;
	}

	/// f[n-1] = legnth of longest prefix which is also a suffix of the string s

	mark[0]=true,k=f[n-1];

	while (k&&!mark[k]) k=f[k-1]; /// len of longest prefix (which is also suffix) wasn't marked...so if k is already marked the there exist a substr = this prefix

	if (k) cout<<s.substr(0,k);
	else cout<<"Just a legend";
}

