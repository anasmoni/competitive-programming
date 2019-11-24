#include<bits/stdc++.h>
using namespace std;



long long int largest_prime_factor(long long int n){

    long k = 2;
    while (k * k <= n)
    {
        if (n % k == 0)
        {
            n /= k;
        }
        else
        {
            ++k;
        }
    }

    return n;
}


int main(){

    int t; scanf("%d",&t);

    while(t--){
        long long int n;
        scanf("%lld",&n);
        printf("%lld\n",largest_prime_factor(n));
    }

    return 0;
}
