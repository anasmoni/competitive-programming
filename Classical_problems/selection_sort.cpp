#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[10] = {4,7,8,5,20,-1,3,6,9,1};

    for(int i=0 ; i<10 ; i++)
    {
        for(int j=i+1 ; j<10 ; j++)
        {
            if(a[i]>a[j])swap(a[i],a[j]);
        }
    }

    for(int i=0 ; i<10 ; cout<<a[i++]<<" ");

    return 0;
}

