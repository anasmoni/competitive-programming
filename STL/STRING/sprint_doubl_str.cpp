#include<bits/stdc++.h>
using namespace std;

int main()
{
    char c[10]  , s[14] = "Hello world!";
    double x = 14.52;
    int n=2;
    char N[45]; /** string doesn't work */
    sprintf(c,N,"%lf%d",x,n); /** doesn't work,....c and N = null*/

    strcat(s,c);
    cout<<s<<endl; /** output = op = "Hello World!" */

    sprintf(N,"%d",n);
    sprintf(c,"%lf",x);

    strcat(s,N);
    strcat(s,c);

    cout<<s;

    return 0 ;
}

