#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef unsigned long long int ulli;
typedef pair<int,int> pii;
typedef priority_queue< int, vector< int >, greater< int > >  minHeap;

#define ones(x) __builtin_popcount(x)
#define onesl(x) __builtin_popcountl(x)
#define onesll(x) __builtin_popcountll(x)

#define pb push_back
#define eb emplace_back
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
#define fi first
#define se second
#define inf 1e9
#define pi acos(-1.0)
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define mod 1000000007
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define bug(x) cerr << __LINE__ << " says: " << #x << " = " << (x) << "\n"

int Set(int N,int pos)
{
    return N=N | (1<<pos);
}
int reset(int N,int pos)
{
    return N = N & ~(1<<pos);
}
bool check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}


inline int addmod(int x ,int y){return (x%mod + y%mod)%mod;}
inline int submod(int x ,int y){return (x%mod - y%mod + mod)%mod;}
inline int mulmod(int x ,int y){return (x%mod *1LL* y%mod)%mod;}
inline int nextSubMask(int i , int mask) {return (i-1)&mask;} /// returns next  submask

template<typename T>
void we_r_done(T mssg){cout<<mssg; exit(0);}

const int MX = 5001;
#define SQ 79

struct bs{
    lli A[SQ];
    void clr(){
        Fill(A,0);
    }
    void tr(int H){
        for(int n=H>>6 , i=0; i<n; i++)A[i]=-1;
        for(int k= H-(H&63) ; k<H; k++) ad(k);
    }
    bool is(bs &r){
        for(int i=0; i<SQ; i++){
            if(A[i]&r.A[i])return 1;
        }
        return 0;
    }
    void operator|=(bs &r){
        for(int i=0; i<SQ; i++) A[i] |= r.A[i];
    }
    void operator&=(bs &r){
        for(int i=0; i<SQ; i++) A[i] &= r.A[i];
    }
    void operator^=(bs &r){
        for(int i=0; i<SQ; i++) A[i] ^= r.A[i];
    }
    void ad(int u){
        A[u>>6] |= 1ull<<(u&63);
    }
    void cg(int u){
        A[u>>6] ^= 1ull<<(u&63);
    }
    bool ct(const int v){
        return (A[v>>6]>>(v&63))&1;
    }
    int bt(){
        int l(0);
        for(int i=0; i<SQ; i++) l += __builtin_popcountll(A[i]);
        return l;
    }
    bool any(){
        for(int i=0; i<SQ; i++){
            if(A[i])return 1;
        }
        return 0;
    }
    int AND(const bs&r){
        for(int i=0; i<SQ; i++){
            if(A[i]&r.A[i])return i+1;
        }
        return 0;
    }

}bs[MX],inp[MX] , temp;

int main()
{
    ///freopen("output.txt","w",stdout);
    ///freopen("input.txt","r",stdin);

    FastIO;

    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        for(int j=0; j<s.size(); j++){
            if(s[j] == '1'){
                inp[i].ad(j);
                bs[j].ad(i);
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == j) continue;
            if(inp[i].ct(j) == 0 || bs[i].AND(inp[j]) == false) continue;

            temp = bs[i];
            temp &= (inp[j]);

            if(temp.any()){
                i++,j++;
                for(int k=0; k<n; k++){
                    if(temp.ct(k)){
                        cout<<k+1<<" "<<i<<" "<<j;
                        return 0;
                    }
                }
            }
        }
    }
    cout<<-1;


    return 0;

}

///sin and cos expect input in radians not degrees. so use , sin(degrees * pi / 180)
///using bs = bitset<MX>; // how many distinct number can be form?
///sort(atoz(v), [](const data x, const data y){return (x.a==y.a?x.b>y.b : x.a<y.a);});
