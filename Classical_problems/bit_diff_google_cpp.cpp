#include<bits/stdc++.h>
using namespace std;



int main(){

    int n; cin>>n; int  mx=0;

    int cnt[70][2];

    memset(cnt,0,sizeof(cnt));

    for(int i=0 ; i<n ; i++){

        int temp , j=0;
        cin>>temp;

        for( ;temp ;j++ ,temp >>= 1 ){

            cnt[j][0] += temp&1;
            cnt[j][1] += (temp%2 ==0);
            mx = max(j,mx);
        }

        for(int k=j ; k<32 ; k++)cnt[k][1]++;
    }

    int ans=0;

    for(int i=0 ; i<=mx ; i++){
        ans += cnt[i][1] * cnt[i][0];
        cout<<cnt[i][1] <<" "<< cnt[i][0]<<endl;
    }

    cout<<ans<<endl;

    return main();
}
