#include<bits/stdc++.h>
using namespace std;

#define sz 1005
int idx[sz];
vector<int>V[sz];
/**http://acm.timus.ru/problem.aspx?space=1&num=1280*/

bool fun(int n){

    for(int i=1 ; i<=n ; i++){
        for(int x: V[i]){
            if(idx[x]<idx[i])return false;
        }
    }

    return true;
}

int main()
{
   int n,m;
   scanf("%d%d",&n,&m);

   for(int i=1 ; i<=m ; i++){
        int u,v;
        scanf("%d%d",&u,&v);
        V[u].push_back(v);
   }

   for(int i=1 ; i<=n ; ++i){
        int x;
        scanf("%d",&x);
        idx[x]=i;
   }

   if(fun(n))cout<<"YES";
   else cout<<"NO";


    return 0;
}
