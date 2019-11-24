#include<bits/stdc++.h>
using namespace std;

///UVa 12716 GCD XOR ---------shanto sir's book page 40

/// given N <= 30000000  count how many A,B exist such that GCD(A,B) == XOR(A,B) when 1 <= B <= A <= N

/// we know that (A - B) <= XOR(A,B)  and
///GCD(A,B) <= (A-B).....so if GCD(A,B) == XOR(A,B) then GCD(A,B) == XOR(A,B) == A-B

#define N 30000000

int ans[N+3];

void Init(){

    for(int gcd = 1; gcd <= N; gcd++){

            for(int A=gcd*2 ; A<= N; A += gcd){

                int B = A-gcd;
                /// ans[A] += (gcd== (A^B));
                ///OMG-----------if we do this it takes 12s and got TLE where below one takes ~= 3s Got AC !!!
                if(gcd == (A^B)) ans[A]++;

            }
    }

    for(int i=1; i<=N; i++)ans[i] += ans[i-1];
}

int main()
{
    //freopen("debug.txt","w",stdout);
    /**
     ios_base::sync_with_stdio(false);
    cin.tie(0);
    */

    Init();

    int t;
    scanf("%d",&t);

    for(int n,tc=1; tc<=t; tc++){
        scanf("%d",&n);

        printf("Case %d: %d\n",tc,ans[n]);
    }


    return 0;
}

