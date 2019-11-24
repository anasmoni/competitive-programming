#include<bits/stdc++.h>

using namespace std;

int a[50000],piv;

int get_median(int lo,int hi,int kth);

int get_part(int lo , int hi , bool mom = false)
{
    int x;

    x = mom?get_median(lo,hi,(hi-lo+1)/2 + (hi-lo+1)%2 ):a[hi];
    if(mom)swap(a[hi],a[piv]);
    x = a[hi];
    int i=lo-1;
    for(int j=lo ; j<=hi-1 ; j++){

        if(a[j]<=x)swap(a[j],a[++i]);
    }
    swap(a[hi],a[++i]);
    return i;
}

void quick(int lo, int hi){
    if(lo<hi){
        int p = get_part(lo,hi,true);
        quick(lo,p-1);
        quick(p+1,hi);
    }
}

void print(int n){
    for(int i=1 ; i<=n ; printf("%d ",a[i++]));
}

int get_median(int lo , int hi , int kth){

    while(1){
        piv = get_part(lo,hi);
        int len = piv-lo+1;

        if(kth==len)return a[piv];
        else if(kth<len)hi = piv-1;
        else {
            kth -= len;
            lo = piv+1;
        }
    }
}

int main()
{
    printf("press 0 to exit.....\n");
    while(1){
        int n;
        scanf("%d",&n);

        for(int i=1 ; i<=n;scanf("%d",&a[i++]));

        quick(1,n);
        print(n);
        //cout<<get_median(1,n,n/2 + n%2)<<endl;
        if(!n)break;
    }
    return 0;
}
