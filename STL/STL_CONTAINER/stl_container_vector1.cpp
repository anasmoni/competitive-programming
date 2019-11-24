#include<iostream>
#include<vector>

using namespace std ;

int main()
{
    vector<int>v ; /** size zero...*/

    vector<int>v1(5) ; /** size 5... all elements bydefault zero...line 11,13 */

    /**cout<<"Initial size = "<<v1.size()<<endl;

    for(int i=0 ; i<5 ; i++)cout<<v1[i]<<" ";*/

    vector<int>v2(5,-1); /** size 5... all elements -1.... line 17 */

    /**for(int i=0 ; i<5 ; i++)cout<<v2[i]<<" ";*/

    v1.clear();  /** size zero hoe jabe...*/

    cout<<v1.size()<<endl;

    cout<<v2[890]<<endl;  /** as [] doesn't provide bound checking...output garbage value*/

   /** cout<<v.at(468); /** check bound and stop working giving messege in console....*/

    cout<<v1.empty()<<endl<<v2.empty()<<endl;  /** 1 that means true...and 0 == false*/

    /** Current size of v2 is = 5 */

    v2.resize(7); /** now size is 7... extended blocks and cntain bydefult 0 ;*/

    cout<<v2.size()<<endl;

    v2.resize(9,2); /** now the extended blocks contains 2 and current size is 9 */

    v2.push_back(20);

    cout<<v2.size()<<endl; /** output = 10 */

    v2.reserve(100); /** Reserves 100 element size , tha means memory alocation won't be needed until the size exceeds 100 elementa*/

    cout<<v2.size()<<endl;









    return 0 ;
}
