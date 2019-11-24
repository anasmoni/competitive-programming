#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t  ; scanf("%d",&t);

    while(t--){
        vector< pair<int,int> >v;
        map< pair<int,int> , int >mp;

        int n; scanf("%d",&n);
        int app[2*n+1] , orng[2*n+1];
        for(int i=0 ; i<2*n-1 ; i++){
            scanf("%d%d",&app[i],&orng[i]);
            v.push_back(make_pair(app[i],orng[i]));
            mp[v[i]]=i;
        }
        sort(v.begin(),v.end()); cout<<"YES\n";

        for(int i=2*n-2 ; i>=n-1 ; i--){
            printf("%d",1+mp[v[i]]);
            if(i>n-1)cout<<" ";
            else cout<<endl;
        }

    }

    return 0;
}
