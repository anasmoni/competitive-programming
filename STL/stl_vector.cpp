#include<bits/stdc++.h>
using namespace std;


int main()
{
    vector<int>v = {2,3,4};

    cout<<binary_search(v.begin(),v.end(),22)<<endl;

    cout<<binary_search(v.begin(),v.end(),3)<<endl;

    // v must be sorted

    return 0;
}
