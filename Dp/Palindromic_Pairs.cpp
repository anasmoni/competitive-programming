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

/// how many non-overlapping palindromic pairs are there?
///aaa = 5
/// assd = 8
///aa=2

int main(){
    string s;
    cin>>s;
    int n=sz(s);
    int dp[n+1][n+1] , temp[n+1][n+1];

    for(int i=0; i<=n; i++){

        for(int j=0; j<=n; j++) dp[i][j] = temp[i][j] = (i==j);
    }

    for(int L=2; L<=n; L++){
        for(int i=1 ; i<=n-L+1; i++){
            int j = i+L-1;

            dp[i][j] = ((dp[i+1][j-1] ||L==2)&& s[i-1]==s[j-1]); /// dp[i][j]=1 if substring(i,j) = palindrome

        }
    }
/*
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++)cout<<dp[i][j]<<" ";
        cout<<endl;
    }

*/
    for(int i=n-1; i>=1; i--){
        for(int j=i+1 ; j<=n ; j++)temp[i][i]+=dp[i][j];

        for(int j=i+1 ; j<=n ; j++)temp[i][i]+=dp[j][i];
        temp[i][i] += temp[i+1][i+1];

        ///temp[i][i] = how many palindromes are in substr(i,n);

    }
/*
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++)cout<<temp[i][j]<<"\t";
        cout<<endl;
    }
*/
    lli ans=0;
    for(int i=1; i<n; i++){
        for(int j=i ; j<n; j++){
            if(dp[i][j]){///jth char is last char of a palindrome
                ans += temp[j+1][j+1]; /// how many palindroms in substring(j+1,n)
            }
        }
    }
///
    cout<<ans;
    return 0;
}
