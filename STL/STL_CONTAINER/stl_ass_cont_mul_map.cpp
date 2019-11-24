#include<iostream>
#include<map>
#include<utility>
using namespace std;

int main()
{
    multimap<string,int>id_phone;

    id_phone.insert(make_pair("Anas",54));
    id_phone.insert(make_pair("Anas",87));
    id_phone.insert(make_pair("Nafis",45));
    string s ;
    cout<<"Enter :";
    cin>>s;
    /**cout<<id_phone[s];  ERROR */

    multimap<string,int>::iterator it;

    it = id_phone.lower_bound(s);

    for(;it != id_phone.upper_bound(s);it++)cout<<it->second<<endl ;




    return 0 ;
}
