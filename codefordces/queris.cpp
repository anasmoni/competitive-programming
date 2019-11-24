#include<bits/stdc++.h>
#include<cstdlib>

using namespace std;

int a[1000005],n,x,b;
int main()
{
    cin>>n;

    while(n--)
    {
        char c;
        long long int k;
        x=1,b=0;
        cin>>c>>k;
        while(k)
        {
            if(k%2)b+=x;
            k/=10 ; x*=2;
        }
        if(c=='+')a[b]++;
        else if(c=='-')a[b]--;
        else cout<<a[b]<<endl;
    }

    return 0;
}
