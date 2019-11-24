#include<iostream>
#include<list>
#include<algorithm>

using namespace std;

int main()
{
    int a[14] = {1,4,2,5,5,4,4,4,4,1,8,4,5,5};
    list<int>lt(a,a+14);
    list<int>::iterator it ;

    it = find(lt.begin(),lt.end(),8);

    cout<<*it<<endl;

    lt.unique(); /** list is = 1,4,2,5,1,8,4,5 (only neighbors) */
    it = find(lt.begin(),lt.end(),542);

    do
    {
        cout<<*(--it)<<" ";
    }while(it != lt.begin()); cout<<endl;


    lt.remove(8) ;/** list is = 1,4,2,5,1,4,5 */

    lt.sort() ; /** list is = 1,1,2,4,4,5,5  */
    lt.reverse();

    it = find(lt.begin(),lt.end(),542);

    do
    {
        cout<<*(--it)<<" ";
    }while(it != lt.begin()); cout<<endl;

    lt.unique();

    it = lt.end();

    do
    {
        cout<<*(--it)<<" ";
    }while(it != lt.begin()); cout<<endl;


    list<int>l2(a,a+2);

    lt.merge(l2) ;

    it = lt.begin();

    do
    {
        cout<<*(it++)<<" ";
    }while(it != lt.end()); cout<<endl;











    return 0 ;
}
