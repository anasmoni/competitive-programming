#include<bits/stdc++.h>
#define fi(n, m) for(int i=n; i<=m; i++)
#define fd(n, m) for(int i=n; i>=m; i--)
using namespace std;
int pr[10001], n, m;
set<int>st;
/**http://www.lightoj.com/volume_showproblem.php?problem=1059 */
struct edge{
    int u, v, w;
}one[100001];

bool comp(edge f, edge s){
    return f.w<s.w;
}

int find(int p){
    if(pr[p]==p) return p;
    else return find(pr[p]);
}

int mst(){
    int sm=0, xx, yy, cnt=0;
    fi(1, n) pr[i]=i;
    fi(0, m-1){
        xx=find(one[i].u);
        yy=find(one[i].v);
        if(xx!=yy){
            pr[yy]=xx;
            cnt++;
            sm+=one[i].w;
        }
        if(cnt==n-1) return sm;
    }
    return sm;
}

int main(){
    int t, c, cs=1, sz, ans, u, v, w, an;
    cin>>t;
    while(t--){
        an=0;
        cin>>n>>m>>c;
        fi(0, m-1){
            cin>>u>>v>>w;
            if(w<c){
                one[i].u=u;
                one[i].v=v;
                one[i].w=w;
            }
            else{            // special case
                one[i].u=u;
                one[i].v=u;
                one[i].w=0;
            }
        }
        sort(one, one+m, comp);
        ans=mst();
        fi(1, n){
            st.insert(find(pr[i])); /**great to find munber of componenets*/
        }
        sz=st.size();
        cout<<"Case "<<cs++<<": "<<ans+(sz*c)<<" "<<sz<<endl;
        st.clear();
    }
    return 0;
}
