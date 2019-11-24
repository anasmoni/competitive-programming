#include<bits/stdc++.h>

using namespace std;

int main()
{
    char s[23] ;
    int a=123 ;
    itoa(a,s,10);
    cout<<s[2]<<endl; /** output = 3 */

    itoa(a,s,2);
    cout<<s<<endl; /** binary of a */

    a = 298;
    itoa(a,s,8);
    cout<<s<<endl; /** octal */

    itoa(a,s,16);
    cout<<s<<endl; /** Hexa : 12a */

    string str ;
/**    itoa(298,str,16); /** ERROR */


    return 0 ;
}
