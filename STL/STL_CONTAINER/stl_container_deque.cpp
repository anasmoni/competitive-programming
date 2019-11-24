/** deque is just like vector and using it we can delete or insert operatin from the begining */

#include<iostream>
#include<deque>

using namespace std;

int main()
{
    deque<int> dq(5,-1);

    for(int i=0 ; i<5 ; i++)cout<<dq[i]<<" " ;

    dq.pop_front();

    cout<<"\nsize = "<<dq.size()<<endl ; /** now size is = 4 */

    dq.push_front(120);

    cout<<"\nsize = "<<dq.size()<<endl<<dq[0]<<endl  ;



    return 0 ;
}
