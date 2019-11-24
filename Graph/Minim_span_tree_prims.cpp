#include<bits/stdc++.h>
using namespace std;

/** for baisc code see page 151 shanto vi cz it's an implementation
.....problem lightOj 1041 - Road Construction*/

typedef pair<string,int>pii;

int inf = 1e9;

struct Node{
    int cost;
    string s;
    Node(){};//default constructor;
    Node(string ss,int c){
        s=ss;
        cost=c;
    }

};

bool operator<(Node A,Node B){
    return A.cost>B.cost;
    //as we use priority queue ....but wanting increasing order
}

priority_queue<Node>pq;


int prims(int n){

    map<string,bool>taken;
    map<string,int>cost;
    map<string,vector<pii> >mp;
    set<string>st;

    string s,c;

    while(n--){
        int co;
        cin>>s>>c>>co;

        mp[s].push_back(make_pair(c,co));
        mp[c].push_back(make_pair(s,co));
        st.insert(s);
        st.insert(c);

        cost[s]=inf;
        cost[c]=inf;
    }

    pq.push(Node(s,0));
    int ans=0;
    cost[s]=0;

    while(pq.empty()==false){

        Node nd =  pq.top();
        pq.pop();

        if(taken[nd.s])continue;
        taken[nd.s]=true;
        ans += nd.cost;
       //cout<<nd.cost<<endl;
        vector<pii>:: iterator p = mp[nd.s].begin();

        for(;p!=mp[nd.s].end();p++){
            pair<string,int>&key(*p);
            if(taken[key.first])continue;
            if(cost[key.first]>key.second){
                pq.push(Node(key.first,key.second));
                cost[key.first] = key.second;
            }
        }
    }
    set<string>::iterator it = st.begin();
    for( ; it!=st.end() ; it++){
        if(cost[*it]==inf){ans=-1;break;}
    }

    return ans;

}

int main()
{
    int t;scanf("%d",&t);
    for(int tc=1 ; tc<=t ; tc++){
        int n;
        scanf("%d",&n);
        n = prims(n);
        if(n>=0)printf("Case %d: %d\n",tc,n);
        else cout<<"Case "<<tc<<": Impossible\n";
    }
    return 0;
}
