/** minimum number of changes to make the given array strictly increasing */
/** result = n - LIS */

#include<bits/stdc++.h>
using namespace std;

int pos(int b[], int lo, int hi, int val){

    int mid;

    while(lo<=hi){

        mid = (lo+hi)/2;

        if(b[mid] < val) lo = mid +1;

        else if(b[mid] > val) hi = mid-1;

        else break;

    }

    return (mid + (b[mid]<val));
}




int LIS(int a[], int n){

    int temp[n], len=0;

    temp[len++] = a[0];

    for(int i=1;  i<n; ++i){

        if(a[i] < temp[0]) temp[0] = a[i];

        else if(a[i] > temp[len-1]) temp[len++] = a[i];

        else{

            int idx = pos(temp,0,len-1,a[i]);
            temp[idx] = a[i];
        }
    }

    return len;

}

int main()
{

    while(1){

        cout<<"Enter 0 to exit....\n";

        int n;
        scanf("%d",&n);

        if(!n) break;

        int a[n];

        for(int i=0 ; i<n; scanf("%d",&a[i++]));

        printf("%d\n",n-LIS(a,n));
    }

    return 0;
}


