#include<iostream>
#include<algorithm>
#include<list>

using namespace std;

int main()
{
    int a[5] = {1,2,3,4,5} ;

    list<int> lt (a,a+5) ;

    list<int>::iterator it ;

    it = find(lt.begin(),lt.end(),3); /** it pointing on idx = 2*/

    cout<<*it<<endl;  /** output = 3 */

    it = find(lt.begin(),lt.end(),50); /** as 50 is not in the list so it pointing on the ned of the list*/
    --it ;
    cout<<*it<<endl; /** output is 5 */





    return 0 ;

}
