#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> v(2,2) ;

    int a[5] = {1,4,7,8,5} , *p ;
    p = a ;
    p++;
    cout<<*p<<endl;  /** output is 4 */

    vector<int>::iterator it ;
    it = v.begin() ; /** it pointed on the first element of v */

    cout<< *it << endl; /** output = first element of v */
    v.push_back(5);

    cout<< *it <<endl;  /** garbage */

    it = v.end() ; /** pointed on the end of last element */
    cout<<*(--it)<<endl; /** *(it--) prints garbage */













    return 0 ;
}
