#include<bits/stdc++.h>
using namespace std;

int main()
{
    char c[10]  , s[1544] = "Hello world!";
    double x = 14.52;
    int n=223;
    char N[45]; /** string doesn't work */
    sprintf(c,N,"%lf%d",x,n); /** doesn't work,....c and N = null*/

    strcat(s,c);
    cout<<s<<endl; /** output = op = "Hello World!" */

    sprintf(N,"%d",n);
    sprintf(c,"%lf",x);

    strcat(s,N);
    strcat(s,c);

    cout<<s<<endl;

    sscanf(s,"%*c%d",&n); /** first jekhane char(that is %*c) paise ter ager int k n er addres e assign kore dise*/
    cout<<n<<endl; /** op = 223 */

    char str[54] = "3.6hello sscanf2.5";

    sscanf(str,"%lf%*c",&x);
    cout<<x<<endl; /** output = 3.6 */

    sscanf(str,"%*c%lf",&x);
    cout<<x<<endl; /** output = 0.6 */

    return 0 ;
}

