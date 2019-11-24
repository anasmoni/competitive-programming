#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vec;

#define ones(x) __builtin_popcount(x)
#define onesl(x) __builtin_popcountl(x)
#define onesll(x) __builtin_popcountll(x)

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

string pat,txt;
int mx = 0;

void computeLPSArray(int M , int *lps)
{
    int len = 0;

    lps[0] = 0;

    int i = 1;

    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0) {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch()
{
    int M = pat.size();
    int N = txt.size();

    int lps[M];

    computeLPSArray(M, lps);

    int i = 0 , j = 0;

    while (i < N) {

        if (pat[j] == txt[i]) {
            j++;
            i++;
            if(i==N)mx = max(mx,j);
        }

        if (j == M) {
            j = lps[j - 1];
            break;
        }

        else if (i < N && pat[j] != txt[i]) {

            if (j != 0) j = lps[j - 1];

            else i = i + 1;
        }
    }
}


int main()
{
    //freopen("output.txt","w",stdout);
    ///freopen("input.txt","r",stdin);

    int t;
    scn(t);

    for(int cs=1; cs<=t ;cs++){


        cin>>txt;
        pat = txt;
        reverse(atoz(pat));
        mx = 1;
        KMPSearch();

        int n = txt.size();

        /// mx = longest palindromic suffix


        printf("Case %d: %d\n",cs,2*n - mx);
    }


    return 0;
}
