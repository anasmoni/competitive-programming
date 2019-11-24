#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef pair<int,int> pii;

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

int num[200007] , temp[200007];
lli inv;

int max_less(int lo, int hi, int val){

    int mid;

    while(lo<=hi){

        mid = (lo+hi)/2;

        if(num[mid] >= val) hi = mid-1;

        else{
            if(mid+1<=hi && num[mid+1]< val)lo = mid+1;
            else return mid;
        }
    }
    return -1;

}

void mergesort(int lo , int hi)
{
    if(lo==hi)return;

    int mid = (lo+hi)/2 ;

    mergesort(lo,mid);
    mergesort(mid+1,hi);

    int i,j,k;
    int yup=0;
    int ii;

    for(i=ii=lo , j=mid+1,k=lo ; k<=hi ; k++)
    {
        if(ii<=mid){

            int idx = max_less(mid+1,hi,num[ii]);

            if(idx!=-1) inv += ( idx-(mid+1) )+1;

            ii++;
        }

        if(i==mid+1)temp[k]=num[j++];

        else if(j==hi+1) temp[k]=num[i++];

        else if(num[i]<num[j])temp[k]=num[i++];

        else temp[k]=num[j++];
    }

    for(k=lo ; k<=hi ; k++)num[k]=temp[k];

}

int main()
{
    int t;
    scn(t);

    while(t--)
    {
        int n;
        cin>>n;

        if(!n)return 0;
        inv=0;

        for(int i=1 ; i<=n ; cin>>num[i++]);

        mergesort(1,n);

        printf("%lld\n",inv);
    }
    return 0;
}

