#include<bits/stdc++.h>
using namespace std;

#define int64 long long
#define ss second
#define BIT(n) (1LL<<(n))
#define maxN 32

/**http://www.lightoj.com/volume_showproblem.php?problem=1032**/

int64 f[maxN][2];

void init()
{
    f[0][0] = f[0][1] = 0;

    for(int i=1 ; i<=maxN-1 ; ++i){
        f[i][0] = f[i - 1][0] + f[i - 1][1];
        f[i][1] = f[i][0] + BIT(i - 1);
    }

    /**
        f[i][0] + f[i][1]  == 0 to 2^(i+1)-1 range e total number of adjacent 1

        i==2 er jonno bit string 111 -> 7
        so, 0 to 7 e total number of adjacent 1 == f[2][0]+f[2][1] = 4;

        0 to 7 e
            11 -> 1 ta
            110 -> 1 ta
            111 -> 2 ta
            ------------
            total 4 ta adjacent 1

        ---------------------------
        tahole , f[i][1] e ki thake??


        x = f[i-1][0] + f[i-1][1]; /// x er meaning amra already jani;
        f[i][1] = x + 1<<(i-1);    /// baki add korsi  2^(i-1);



    **/

   /* for(int i=0 ; i<32 ;i++){
        cout<<f[i][0]<<" "<<f[i][1]<<endl;
    }*/
}

int main() {

    init();

    int cases, caseNo = 0, n;

    for (scanf("%d", &cases); cases--; ) {

        scanf("%d", &n);
        int hi = 0;

        for(int i=0 ; i<maxN ; ++i) hi = (n & BIT(i)) ? i : hi;

         /** hi+1 = len of n's bit representation .....if n=6 then n==110 , hi=2; **/

        int64 res = f[hi][0] + f[hi][1];

        /**
            now,
            res = 0 to (hi+1) length er bit string e total number of adjacent 1

            n=6 er jonno hi = 2
            so, res = 0 to 111  bit string e total num of addjacent 1
            but n-> 110
            so amke res theke kisu minus korte hobe....
            so , amake hi-1 that means 1(10) braket er part check korte hobe j sekhane 11 ase naki
            onno kisu....

            let's see how!!

        **/

        bool prev = true, cur;
        /** prev = previous bit 1 kina? ...1st e hi no. bit 1...so initialy prev = true**/
        int lost = 0;
        //cout<<res<<endl;

        for(int i=hi-1 ; i>=0 ; --i){ //

            cur = n & BIT(i);  /** cur is ith bit 1 or 0 **/

            if (prev && cur) lost++;

            if (!cur){   /** ith bit 0 holei amk res minus korte hobe**/

                res -= f[i][1]; /** i er right e joto nisilem extra sob bad*/

                res -= lost * BIT(i); /** i er left e joto nisilem extra sob bad**/

                if (prev) res -= BIT(i); /** prev 1 hole 2^i minus korbo*/
             }

            prev = cur; /** last jei bit niye kaj korsi seta prev e stor korsi*/
        }

        printf("Case %d: %lld\n", ++caseNo, res);
    }
    return 0;
}

/**

say amer input

        111011
        extra nisilem (0 ase i=2 te)

        111(100)
        111(101)
        111(110)
        111(111)   () er modhe joto adjacent ase = f[2][1].....so res theke eta minus korbo

        111.100
        111.101
        111.110
        111.111  . prev 1 ase means . deoa gulo extra.....so 2^i minus korbo


        [111]100
        [111]101
        [111]110
        [111]111  [] er lost*(2^i) extra nisi...so egulow minus korbo


**/
