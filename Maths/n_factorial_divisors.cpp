/**
    How many soln r there .....

            1/x + 1/y = 1/n!

            ans -> num of divisors of   (n!)^2

            how to clac it modulo 1e9+7?

            here it goes......
**/


#include <bits/stdc++.h>
#define  mo 1000007
using namespace std;
bool isPrime(long p)
{
    bool num = false;
	if(p==2||p==3)
	return true;

	for(long i=2;i<=sqrt(p);++i)
	{
		if(p%i==0)
            {
            num = false;
            break;
        }
        else
            num = true;

	}
	return num;
}
int main()
{
	int n;  cin>>n;
	long long int r = 1;
	long x = n;
	for(int i=2;i<=x;++i)
	{
		if(isPrime(i))
		{
			int k = 1;
			long powe = 0;
			while(pow(i,k)<=x) // Wah! it's prime factorization!!
			{
				powe = powe + (n/pow(i,k));
				k++;
			}
			r = r*(2*powe+1);
            r = r%mo;
		}

	}

	cout<<r<<endl;
}
