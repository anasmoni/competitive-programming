#include<bits/stdc++.h>
#include<string>

using namespace std;

int main()
{
    string s = "Hello" , c = "World" ;

    s = s + " " + c ;

    cout<<s<<endl;

    int found = s.find("ll") ;
    cout<<found<<endl; /** output = 2 return the index where the string 1st found */

    int fd = s.find("dH"); /** output = -1 */
    cout<<fd<<endl;
    /** fd == string::npos  , if fd doesn't find the string assigned in find */
    if(fd==string::npos)cout<<"Dosen't find\n" ;

    size_t fnd = s.find("rl") ;
    cout<<fnd<<endl; /** output = 8 */

    cout<<(('4')-48)/4 << endl ;

    return 0 ;
}
