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


int main()
{
    int n,nn;
    scn(n);

    vector<pii>V;

    lli ans=0;

    for(int i=1; i<=n; i++){
        int x,y;
        scn2(x,y);
        V.pb(pii(x,y));
    }
    ///any two point make a line == they r in same line!

    for(int i=0; i<n; i++){ /// lets calc how many triangles contains ith point , say ith point is 1st point of triangle

        map<double,int>slope; /// slope of point i and any j will b same if they are in same line

        for(int j=i+1 ; j<n; j++){

            if(V[i].fi==V[j].fi)slope[10000]++; /// to avoid div by 0

            else slope[(V[j].se*1.0-V[i].se)/(V[j].fi*1.0-V[i].fi)]++; /// how many points are in same line with ith point
        }

        lli tmp=0LL;

        for(auto x : slope){ /// map size == number of lines can b draw with ith and any jth points such that i<j

            tmp += x.se*(n-i-1-x.se);  /// x.se = num of points we r taking as 2nd point.....

            ///(n-i-1-x.se) = num of points we r taking as 3rd point of the triangle.....
            /// n-x.se  means we can't take 3rd point from any of x.se points...cause ith,all x.se points are in same line
            /// n-i-1  means ith point already calculated for o to i-1 points
        }

        tmp/=2LL; /// same point taken as 2nd and 3rd point...that means they are counted 2 times
        ans += tmp;
    }

    cout<<ans;


    return 0;
}
