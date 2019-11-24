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
#define N 100003

/// https://codeforces.com/contest/813/problem/E

vector<int>indexesOF[N];

struct Node{
    int cnt;
    Node *left , *right;

    Node(int c , Node *l , Node *r){
        cnt = c;
        left = l;
        right = r;
    }
};

Node *sentinel = new Node(0,NULL,NULL);
Node* tree[N];

Node* update(Node *root , int lo , int hi , int x){

    if(x<lo || hi<x) return root;

    if(hi == lo) return new Node(root->cnt+1,sentinel,sentinel);

    int mid = (lo+hi)/2;

    return new Node(root->cnt+1,update(root->left,lo,mid,x),update(root->right,mid+1,hi,x));
}

int query(Node *root , int lo ,int hi , int x){

    if(hi<=x) return 0;

    if(x<lo) return root->cnt;

    int mid = (lo+hi)/2;

    return query(root->left,lo,mid,x) + query(root->right,mid+1,hi,x);
}

int main()
{
    ///freopen("output.txt","w",stdout);
    ///freopen("input.txt","r",stdin);
    /*
     ios_base::sync_with_stdio(false);
    cin.tie(0);
    */

    int n,k;
    scn2(n,k);
    int a[n+1] , kthOccurance[n+1];

    for(int i=1; i<=n; i++) scn(a[i]);

    for(int i=n; i ; i--){ /// setting the kth occurance of ith element

        if(indexesOF[a[i]].size()<k) kthOccurance[i] = n+1;
        else kthOccurance[i] = indexesOF[a[i]][indexesOF[a[i]].size()-k];

        indexesOF[a[i]].pb(i);
    }

    tree[0] = sentinel->left = sentinel->right = sentinel; /// to avoid NULL caused crush

    for(int i=1; i<=n; i++){
        tree[i] = update(tree[i-1],1,n+1,kthOccurance[i]); /// we're building seg tree on kth occurance
    }

    /// what cnt in node(cnt,lo,hi) in tree[i] represents??


    int q , last=0;
    scn(q);

    while(q--){
        int x,y;
        scn2(x,y);

        int l = (x+last)%n + 1;
        int r = (y+last)%n + 1;

        if(l>r) swap(l,r);

        int ans = query(tree[r],1,n+1,r) - query(tree[l-1],1,n+1,r); ///we're sending r

        printf("%d\n",ans);

        last = ans;
    }



    return 0;
}
