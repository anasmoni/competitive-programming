#include<bits/stdc++.h>
using namespace std;

/*http://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/*/

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

int main()
{
    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;

        int a[n], b[n] ;

        for(int i=0 ; i<n ; i++){

            scanf("%d",&a[i]);
            b[i] = 0;
        }

        cout<<LIS(a, b, n)*(n>0)<<endl;

    }

    return 0;
}

/*
9
2 5 3 7 11 8 10 13 6
*/
