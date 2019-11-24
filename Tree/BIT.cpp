#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vec;

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define scn(n) scanf("%d",&n)
#define scn2(n,m) scanf("%d%d",&n,&m)
#define atoz(v) v.begin(),v.end()
#define fill(a,v) memset(a,v,sizeof(a))
#define sz(v) v.size()
#define fi first
#define se second
#define inf 1e9
#define pi acos(-1.0)
#define sqr(x) x*x
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))

int tree[100005];

int query(int idx){
       int sum=0;
       while(idx>0){
             sum+=tree[idx];
             idx -= idx & (-idx);
       }
       return sum;
}

void update(int idx, int x, int n) //n is the size of the array, x is the number to add
{
       while(idx<=n)
       {
             tree[idx]+=x;
             idx += idx & (-idx);
       }
}

int main()
{

    int t;
    scn(t);

    for(int tc=1; tc<=t; tc++){

        int n,q;
        scn2(n,q);
        fill(tree,0);

        for(int x,i=1; i<=n; i++){
            scn(x);
            update(i,x,n);
        }

        printf("Case %d:\n",tc);

        while(q--){

            int c,i,j,v;
            scn(c);

            if(c==1){
                scn(i);
                i++;
                int ans = query(i)-query(i-1);
                printf("%d\n",ans);
                update(i,-ans,n);
            }
            else if(c==2){
                scn2(i,v);
                i++;
                update(i,v,n);
            }
            else{
                scn2(i,j);
                i++;j++;
                int ans = query(j)-query(i-1);
                printf("%d\n",ans);
            }

        }

    }

    return 0;
}
/*
4
2 2
1 1 0
1 2 1
2 3
1 1 0
1 2 1
2 1 0
3 2
2 2 0
2 3 1
3 3
1 2 1
2 3 1
1 3 1
*/
