#include<bits/stdc++.h>
using namespace std;
int mod = 1e5;

/** 5454 = 2^1 * 3^3 * 101^1.....prime factorization
    all div of 5454 = (1+1)*(3+1)*(1+1) = 16;
    even div of 5454 = (1-1+1)*(3+1)*(1+1) = 8;
**/


int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;scanf("%d",&n);
        if(n%2){cout<<0<<endl;continue;}
        vector<int>v;
        int x=n;
        map<int,int>mp;
        int ans=1;
        for (long i = 2; i <= n / i; i++) {
            while (n % i == 0) {
                v.push_back(i);
                n /= i;
            }
        }
        if (n > 1 ) {v.push_back(n);}

        for(int i=0 ; i<v.size() ;i++){
            int cnt=(v[i]!=2);
            while(v[i]==v[i+1]){i++;cnt++;}
            ans*=++cnt;
        }
        //cout<<endl;
        printf("%d\n",ans);
        /** prime divisors are in vevtor v**/

    }
    return 0;
}
