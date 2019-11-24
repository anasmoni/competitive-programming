#include<iostream> /** we can insert or delete something within the list */
#include<list>

using namespace std;

int main()
{
    int arr[5] = {1,2,3,4,5};

    list <int> l(arr,arr+5) ; /** size = 5 */

    list<int>::iterator it ;

    it = l.begin() ; /** it pointed on 1 , ++it pointed on 2(idx = 1) */
    l.insert(++it,99); /** list = 1,99,2,3,4,5 ; still it pointend on 2(idx = 2) */

    l.insert(it,2,55) ; /** list = 1,99,55,55,2,3,4,5 ; still it pointing on 2(idx = 4) */
    cout<<*it; /** output = 2 */
    l.erase(it); /** list = 1,99,55,55,3,4,5;*/

    /**  AS WE WRASED , SO WE HAVE TO INITIALIZE THE IRERATOR AGAIN */







    return 0 ;
}
