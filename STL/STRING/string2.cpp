#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s = "Hello World!";

    int pos = s.find('W');
    cout<<s.substr(pos)<<endl;/** output = World */
    cout<<s.substr(pos,3)<<endl; /** output = Wor */
    swap(s[pos],s[pos+1]);
    cout<<s.substr(pos,3)<<endl; /** output = oWr */

    s.replace(pos,23," ");
    cout<<s<<"ww"<<endl; /**output = Hello ww*/

    s.erase(1,3);
    cout<<s<<endl; /** Ho */

    s.erase(); /** now s is empty */






    return 0 ;
}
