#include<bits/stdc++.h>
using namespace std;
long long int ans;

int main(){

    long long  n ;cin>>n;

    long long temp = n*(n-1)*(n-2)*(n-3)*(n-4)/120;
    long long t2 = temp*(n-5)/6;
    long long t3 = t2*(n-6)/7;

    cout<<t2+t3+temp;

    return 0;
}
