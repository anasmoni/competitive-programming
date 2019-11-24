#include<bits/stdc++.h>
using namespace std;

struct job{

    int w,e,s;

    job(int ss, int ee, int ww){

        s = ss;
        e = ee;
        w = ww;
    }
};

vector<job>v;

bool operator<(job A, job B){ return A.e<B.e; }


int bin(int i){

    int mid, lo=0, hi=i-1;

    while(lo<=hi){

        mid = (lo+hi)/2;

        if(v[mid].e <= v[i].s){

            if(v[mid+1].e <= v[i].s)lo = mid+1;
            else return mid;
        }
        else hi = mid-1;
    }

    return -1;
}


int fun(){

    sort(v.begin(),v.end());

    int n = v.size();

    int dp[n];
    dp[0] = v[0].w;

    for(int i=1; i<n; i++){

        int idx = bin(i);
        int temp = v[i].w;

        if(idx != -1) temp += v[idx].w;

        dp[i] = max(dp[i-1], temp);

    }

    return dp[n-1];
}



int main()
{
    int n;

    scanf("%d",&n);

    while(n--){

        int s,e,w;
        cin>>s>>e>>w;
        v.push_back(job(s,e,w));
    }

    cout<<fun();


    return 0;
}
