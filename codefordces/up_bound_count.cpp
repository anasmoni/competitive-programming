#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[5] = {1,2,3,4,4};
    cout<<count(a,a+5,5)<<endl;
    cout<<upper_bound(a,a+5,3)-a<<endl<<lower_bound(a,a+5,3)-a;

    return 0;
}


