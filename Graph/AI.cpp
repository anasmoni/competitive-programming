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
#define mod 1000000007

int cann, miss, cap,node_limit;


map<pair<pii,int>,bool>visited;
bool found = false;
int node_expanded = 0;

bool OK(int i, int j, int m, int c, int side) {

    int new_m = i + miss - m;
    int new_c = j + cann - c;

    if( (i+j == 0) || (i+j)>cap || (new_c>new_m && new_m) || visited[ {pii(new_m,new_c),side^1}] ) return false;

    return true;
}

bool Done(int m,int c, int side) {

    return ( (m == miss && c == cann && side) || (m==0 && c==0 && side==0) );
}

void dfs(int m, int c, int side=0) {

    if(found) return;

    for(int i=0; i<=m; i++) {

        for(int j=0; j<=c; j++) {

            if(OK(i,j,m,c,side) == false) continue;

            int new_m = i + miss - m;
            int new_c = j + cann - c;

            visited[ {pii(new_m,new_c),side^1}] = true;

            node_expanded++;

            if(node_expanded>node_limit) {

                if(found==false) cout<<"DFS : Node limit exceeded...still not found..";

                found = true;

                return;
            }

            if(Done(new_m,new_c,side^1)) {
                cout<<"Possible using DFS, expanding "<<node_expanded<<" nodes";
                found = true;
                return;
            }

            dfs(new_m,new_c,side^1);
        }
    }
}


void bfs() {

    queue<pair<pii,int> >Q;
    visited.clear();

    node_expanded = 0;

    visited[ {pii(miss,cann),0}] = true;
    Q.push({pii(miss,cann),0});

    while(Q.empty() == false) {

        pair<pii,int>p = Q.front();
        Q.pop();

        int m = p.fi.fi, c = p.fi.se, side = p.se;

        //cout<<m<<" "<<c<<" "<<side<<endl;

        for(int i=0; i<=m; i++) {

            for(int j=0; j<=c; j++) {

                if(OK(i,j,m,c,side) == false) continue;

                int new_m = i + miss - m;
                int new_c = j + cann - c;

                pair<pii,int> New_node = {pii(new_m,new_c),side^1};

                visited[New_node] = true;

                node_expanded++;

                if(node_expanded>node_limit) {

                    cout<<"BFS : Node limit exceeded...still not found..";

                    return;
                }

                if(Done(new_m,new_c,side^1)) {
                    cout<<"Possible using BFS, expanding "<<node_expanded<<" nodes";

                    return;
                }

                Q.push(New_node);
            }
        }

    }

}


int main() {

    ///freopen("output.txt","w",stdout);
    ///freopen("input.txt","r",stdin);



    cout<<"Enter Number of missionaries ...\n";
    cin>>miss;
    cout<<"Enter Number of cannibals  ...\n";
    cin>>cann;

    if(cann>miss) {
        cout<<"Impossible\n";
        return 0;
    }

    cout<<"Enter Boat capacity ...\n";
    cin>>cap;

    if(cap<2) {
        cout<<"Impossible\n";
        return 0;
    }

    cout<<"Enter Max number of nodes can be expanded...\n";
    cin>>node_limit;

    dfs(miss,cann,0);
    cout<<"\n\n";
    bfs();


    return 0;

}
