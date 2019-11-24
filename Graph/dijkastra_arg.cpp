#include <iostream>
#include <cstdio>
#include <cstring>
#include  <cmath>
#include  <queue>
#include  <stack>
#include  <string>
#include  <vector>
#include  <map>
#include <algorithm>

using namespace std ;

vector <int> graph[100005] ;
vector <int> cost[100005] ;

int par[100005] ;

long long int d[100005] ;

struct node {
    int city ;
    long long int distance;
    bool operator < ( const node& p ) const {
        return distance > p.distance;
    }
};

long long int dijkstra(int n)
{
    memset(d,63,sizeof(d)) ;

    memset(par, -1, sizeof(par)) ;

    priority_queue <node> q ;

    long long int i , j , k , l ;

    struct node u , v ;

    u.city = 1; u.distance = 0 ; q.push(u) ; d[1] = 0 ;

    while(!q.empty()){

        u = q.top() ; q.pop() ;

        k = u.city ; l = u.distance ;

        if(k==n) return l ;

        for( i = 0 ; i<graph[k].size() ;  i++){

            j = graph[k][i] ;

            if(d[j]> d[k]+cost[k][i] ){

                d[j] = d[k] + cost[k][i] ;

                par[j] = k ;

                v.city = j ; v.distance = d[j] ;

                q.push(v) ;

            }

        }

    }

    return -1 ;
}


int main()
{
    int n , e , u , v , cst, i  ;

    vector <int> out ;

    scanf("%d %d",&n,&e) ;

    for( i = 1 ; i<= e ; i++ ){

            scanf("%d %d %d",&u,&v,&cst) ;

            graph[u].push_back(v) ;
            graph[v].push_back(u) ;

            cost[u].push_back(cst) ;
            cost[v].push_back(cst) ;
    }

    long long int ans = dijkstra(n) ;

    if(ans==-1) printf("-1\n");

    else{

        u = n ;

        while(u!=-1){

            out.push_back(u) ;

            u = par[u] ;
        }

        for( i = out.size()-1  ; i>0 ; i--) printf("%d ",out[i]) ;

        printf("%d\n",out[i]) ;
    }

    return 0 ;

}
