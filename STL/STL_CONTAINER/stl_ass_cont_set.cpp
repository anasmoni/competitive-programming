/** set stores unique element in a specific order , default is increasing*/

#include<iostream>
#include<set>

using namespace std;

int main()
{
    int a[6] = {4,7,7,5,8,1};

    set<int>s(a,a+6); /** s = 1,4,5,7,8 */
    multiset<int>ms(a,a+6); /** ms = 1,4,5,7,7,8 */

    s.insert(10) ;  /** s = 1,4,5,7,7,8 ,10 */
    ms.insert(15);  /** ms = 1,4,5,7,7,8,15 */
    ms.insert(15);

    cout<<"How many 7 in multiset ms ? : "<<ms.count(7)<<endl;
    cout<<"How many 7 in set s ? : "<<s.count(7)<<endl;

    ms.erase(15);
    cout<<"Now after erasing, how many 7 in multiset ms ? : "<<ms.count(7)<<endl;

    set<int>::iterator it_s ;
    set<int>::iterator it_ms ;


    it_s = s.find(5);
    it_ms = ms.find(7) ; /** it_ms pointing on 1st 7  , see line 31 */

    cout<<*(++it_ms)<<endl;

    it_ms = ms.lower_bound(6); /** ms = 1 4 5 7 7 8 */

    cout<<*(--it_ms)<<endl; /** it_ms pointing on the the 1st element which is >= 6 */

    it_ms = ms.upper_bound(5);

    cout<<*(--it_ms)<<endl; /** it_ms pointing in the first element which is > 5 */







    return 0 ;
}
