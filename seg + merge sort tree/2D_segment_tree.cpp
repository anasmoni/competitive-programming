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
#define N 400005

///https://codeforces.com/contest/558/problem/E

int tree[N][26] , lazy[N][26] , charCount[26];
char s[100005];

void build(int i, int lo ,int hi){

    if(lo == hi){
        tree[i][s[lo]-'a'] = 1;
        return;
    }

    int mid = (lo+hi)/2;
    int L = i*2+1;

    build(L,lo,mid);
    build(L+1,mid+1,hi);

    for(int j=0; j<26; j++) tree[i][j] = tree[L][j] + tree[L+1][j];
    ///char ('a'+j) comes tree[i][j] times in the segment [lo,hi]
}

int query(int i ,int lo, int hi, int x, int y , int j){

    if(lazy[i][j] != -1){ /// has lazy value to propagate

        tree[i][j] = (hi-lo+1)*lazy[i][j];

        if(lo<hi){
            lazy[i*2+1][j] = lazy[i*2+2][j] = lazy[i][j];
        }

        lazy[i][j] = -1;
    }

    if(x<=lo && hi<=y){

        return tree[i][j];
    }

    if(hi<x || y<lo) return 0;

    int mid = (lo+hi)/2;
    int L = i*2+1;

    return query(L,lo,mid,x,y,j) + query(L+1,mid+1,hi,x,y,j);
}

void update(int i ,int lo, int hi, int x, int y ,int val, int j){

    if(lazy[i][j] != -1){/// lazy propagation

        tree[i][j] = (hi-lo+1)*lazy[i][j];

        if(lo<hi){
            lazy[i*2+1][j] = lazy[i*2+2][j] = lazy[i][j];
        }

        lazy[i][j] = -1;
    }

    if(x<=lo && hi<=y){

        tree[i][j] = val*(hi-lo+1);

        if(lo<hi){
            lazy[i*2+1][j] = lazy[i*2+2][j] = val; /// 0<= val <= 1 ...so, lazy[i][j] indicates
            /// that all char in [lo,hi] is (j+'a')
        }
        lazy[i][j] = -1;
        return;
    }

    if(hi<x || y<lo) return;

    int mid = (lo+hi)/2;
    int L = i*2+1;

    update(L,lo,mid,x,y,val,j) ;
    update(L+1,mid+1,hi,x,y,val,j);

    tree[i][j] = tree[L][j] + tree[L+1][j];
}

void FinalString(int i, int lo, int hi, int j){

    if(lazy[i][j] != -1){ /// lazy propagation

        tree[i][j] = (hi-lo+1)*lazy[i][j];

        if(lo<hi){
            lazy[i*2+1][j] = lazy[i*2+2][j] = lazy[i][j];
        }

        lazy[i][j] = -1;
    }

    if(tree[i][j] == 0)return;

    if(lo == hi){
        s[lo] = 'a'+j;
        return;
    }

    int mid = (lo+hi)/2;
    int L = i*2+1;

    FinalString(L,lo,mid,j) ;
    FinalString(L+1,mid+1,hi,j);
}

int main()
{
    ///freopen("output.txt","w",stdout);
    ///freopen("input.txt","r",stdin);
    /*
     ios_base::sync_with_stdio(false);
    cin.tie(0);
    */

    int n,q;
    scn2(n,q);
    scanf("%s",s);

    Fill(lazy,-1);

    build(0,0,n-1);


    for(int x,y,z; q; q--){

        scn3(x,y,z);
        x--,y--;

        for(int j=0; j<26; j++) charCount[j] = query(0,0,n-1,x,y,j);

        int start = z? x : y ;

        for(int j=0; j<26; j++){

            if(charCount[j] == 0) continue;

            update(0,0,n-1,x,y,0,j);/// val is 0 here ,

            if(z){
                update(0,0,n-1,start,start+charCount[j]-1,1,j);/// updating with maintaining increasing order
                start += charCount[j];
            }
            else{
                update(0,0,n-1,start-charCount[j]+1,start,1,j);/// updating with maintaining decreasing order
                start -= charCount[j];
            }
        }

    }

    for(int j=0; j<26; j++){
        FinalString(0,0,n-1,j);
    }

    printf("%s",s);




    return 0;
}
