#include<bits/stdc++.h>
using namespace std;
vector<int>v;
void sv(int n)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[n+1];
    memset(prime, true, sizeof(prime));

    for (int p=2; p*p<=n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }

    v.push_back(2);
    for (int p=3; p<=n; p+=2)
        if (prime[p])v.push_back(p);
}

vector<int>pev;
void ini()
{
    for(int i=4 ; i<=500000 ; i+=4)
    {
        if( (double)sqrt(i) == (int)sqrt(i))pev.push_back(i);
    }
}

int div(int n)
{

    vector<int>vv;
    int x=n;
    map<int,int>mp;
    int ans=1;
    for (long i = 2; i <= n / i; i++)
    {
        while (n % i == 0)
        {
            vv.push_back(i);
            n /= i;
        }
    }
    if (n > 1 )
    {
        vv.push_back(n);
    }
    for(int i=0 ; i<vv.size() ; i++)
    {
        int cnt=1;
        while(vv[i]==vv[i+1])
        {
            i++;
            cnt++;
        }
        ans*=++cnt;
    }
    //cout<<endl;
    return ans;
    /** prime divisors are in vevtor v**/

}

int prime_fact(int n)
{
    int cnt=0,ans=1;

    while (n%2 == 0)
    {
        cnt++;
        n = n/2;
    }
    ans*=++cnt;
// n must be odd at this point.  So we can skip one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        cnt=0;// While i divides n, print i and divide n
        while (n%i == 0)
        {
            cnt++;
            n = n/i;
        }
        ans*=++cnt;
    }

    if(n>2)ans=1;
    return ans;
}

int main()
{
    sv(500000);
    ini();
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int m=n;
        int ev=0,ans=1;
        for(int i=0 ; i<v.size() && v[i]<=n/2 && m; i++)
        {
            int cnt=0;
            while(m%v[i]==0)
            {
                cnt++;
                m/=v[i];
            }
            //cout<<v[i]<<" "<<cnt<<endl;
            ans*=(++cnt);
        }
        //cout<<ans<<" ";continue;
        for(int i=0 ; i<pev.size()&& pev[i]<=n/2 ; i++)
        {
            ev+=(n%pev[i]==0);
        }

        ans--;
        if(ev==0)
        {
            cout<<ev<<endl;
            continue;
        }
        int g=__gcd(ans,ev);
        ev/=g;
        ans/=g;
        printf("%d/%d\n",ev,ans);

    }

    return 0;
}
