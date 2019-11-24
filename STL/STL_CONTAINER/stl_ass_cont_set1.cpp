/** set stores unique element in a specific order , default is increasing*/

#include<iostream>
#include<set>

using namespace std;

int main()
{
    int a[6] = {4,7,7,5,8,1};

    set<int>s(a,a+6); /** s = 1,4,5,7,8 */

    multiset<int>ms(a,a+6); /** s = 1,4,5,7,7,8 */

    s.insert(10) ;  /** s = 1,4,5,7,7,8 ,10 */
    ms.insert(15);  /** s = 1,4,5,7,7,8,15 */

    cout<<"How many 7? : "<<ms.count(7)<<endl;







    return 0 ;
}
