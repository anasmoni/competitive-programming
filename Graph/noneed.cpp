 /** https://www.hackerrank.com/challenges/journey-to-the-moon**/

#include<bits/stdc++.h>
using namespace std;

int arr[100005],k=0;

class Graph {
    int V;
    list <int> * adj;
    void DFSUtil(int v, bool visited[], int &cnt);  // A function used by DFS

public:

    Graph(int V);
    void addEdge(int V, int w );
    void DFS();    // prints DFS traversal of the complete graph
    void BFS();

};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int V, int w) {
    this->adj[V].push_back(w); // push back to add to the linked list
}

void Graph::DFSUtil(int v , bool visited[] , int &cnt) {
    visited[v] = true;
    //cout << v << " ";
    cnt++;
    list<int>:: iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i) {
        if (!visited[*i]) {
            DFSUtil(*i, visited,cnt);
        }
    }

}

void Graph::DFS(){

    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;

    // Call the recursive helper function to print DFS traversal
    // starting from all vertices one by one
    for(int i = 0; i < V; i++){
        int cnt=0;
        if(visited[i] == false){
            cnt=0;
            DFSUtil(i, visited,cnt);
            if(cnt){arr[k++]=cnt;}//cout<<i<<" "<<cnt<<endl;}

        }
    }

}

// To implement
void Graph::BFS(){
    queue <int> myQueue;
    bool * visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;

    if (visited[0] == false) {

        myQueue.push(0);
        visited[0] = true;
        while (!myQueue.empty()) {
            list<int>::iterator i;
            int node = myQueue.front();
            for (i = adj[node].begin(); i != adj[node].end(); i++) {
                if (!visited[*i]) {
                    cout << *i <<endl;
                    visited[*i] = true;
                    myQueue.push(*i);
                }

            }
            myQueue.pop();
        }
    }
}



int main(){
    int n,m; scanf("%d%d",&n,&m);

    Graph G(n);
    int mx=-1;
    for(int i=0 ; i<m ; i++){
        int x,y; scanf("%d%d",&x,&y);
        G.addEdge(x,y);
        G.addEdge(y,x);
        mx = max( max(x,y) , mx);
    }

    G.DFS();
    long long int ans=0,temp=0;
    for(int i=0 ; i<k; i++){
        temp += arr[i];
    }
    for(int i=0 ; i<k; i++){
        if(temp>0)ans += arr[i]*(temp-arr[i]);
        temp-=arr[i];
    }

    printf("%lld",ans);



    return 0;
}
