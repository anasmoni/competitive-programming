#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> v ;  /** zero size...*/

    cout<<"Initial size = "<<v.size()<<endl;

    for(int i=0 ; i<5 ; i++)v.push_back(i);

    cout<<"Current size = "<<v.size()<<endl;

    for(int i=0 ; i<5 ; i++)cout<<v[i]<<" ";  /** just like an array..*/

    cout<<endl;

    for(int i=1  ; i<5 ; i++)v.push_back(i*2);

    cout<<"Current size = "<<v.size()<<endl;

    for(int i=0 ; i<9 ; i++)cout<<v[i]<<" "; /** vector always add or delet somethong from the end..*/

    for(int i=9 ; i>5 ; i--)v.pop_back();

    cout<<endl;

    for(int i=0 ; i<5 ; i++)cout<<v[i]<<" "; /** delete elements from the last....


    return 0 ;
}
