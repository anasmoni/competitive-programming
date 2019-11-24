#include<bits/stdc++.h>

using namespace std;

long long int digit , num , base,nd,num1;

char sym[3] = {'=','>','<'};

void dothis(){for(cin>>nd>>base ; nd ; nd--){cin>>digit; num = num*base + digit;}}

int main()
{
   dothis(); num1 = num ; num=0;  dothis(); cout<<sym[(num1>num) + (num1<num)*2];


	return 0;
}
