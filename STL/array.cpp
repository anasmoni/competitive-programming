#include<bits/stdc++.h>
using namespace std;

void print(int a[] , int n){
    for(int i=0 ; i<n; cout<<a[i++]<<" ");
    cout<<endl;
}

int main() // lower,upper_bound, copy_n, sort, binary_search, iota
{
    int a[] = {9,4,8,6,1,12};
    int n = 6;

    sort(a,a+n); // 1,4,6,8,9,12
    // should be sorted

    cout<<lower_bound(a,a+n,7)-a<<endl; // i = (a[i]>=7) = 3

    cout<<upper_bound(a,a+n,8)-a<<endl; // i =  (a[i]>8) = 4

    // if x > max of a then output of these both functon == n

    cout<<binary_search(a,a+n,11)<<endl; // 0

    cout<<binary_search(a,a+n,8)<<endl; // 1

    int b[6];

    copy_n(a,n,b);
    print(b,n);

    iota(b,b+n,10); //10 11 12 13 14 15
    print(b,n);

    return 0;
}
