#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vii;

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

/** http://www.spoj.com/problems/XMEN*/

/**>> all array elliment between 1-N

>> let's the LCS is a,b,c,d and their idx in array a[] is ai,bi,ci,di

>>note that as LCS, a,b,c,d comes in same order in array b[] as it comes in array a[]

>>if I replace a,b,c,d of array b[] with ai,bi,ci,di, it will be LIS of new array b[]
cuz, ai<bi<ci<di
*/

int fun(int b[], int lo, int hi, int val){
    int mid;
    while(lo<=hi){

        mid = (lo+hi)/2;

        if(b[mid]>val) hi = mid-1;
        else if(b[mid]<val)lo = mid+1;
        else break;
    }
   // cout<<mid<<" mid\n";
    return mid + (b[mid]<val);
}


int LIS(int a[], int b[] , int n){

    int len = 1;
    b[0] = a[0];

    for(int i=1 ; i<n; ++i){

        if(a[i] < b[0]) b[0] = a[i];

        else if(a[i] > b[len-1]) b[len++] = a[i];

        else {
            int idx = fun(b, 0, len-1, a[i]);
           // cout<<idx<<" idx\n";
            b[idx] = a[i];
        }

        /*for(int k=0 ; k<len; cout<<b[k++]<<" ");
        cout<<endl;*/

    }

    return len;
}

int main(){

    int t;
    scn(t);

    while(t--){

        int n;
        scn(n);
        int a[n+1],b[n+1], MAP[n+1];

        for(int i=1; i<=n; i++){
            scn(a[i]);
            MAP[a[i]]=i;
        }
        for(int i=1; i<=n; i++){
            scn(b[i]);
            b[i-1] = MAP[b[i]]; // as my lis function use 0 indexing
            a[i-1]=0;
        }

        printf("%d\n",LIS(b,a,n));


    }

    return 0;
}

/**
>>small variation of this problem...here

>> https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1576

>> https://ideone.com/fork/vWQYDo
*/
