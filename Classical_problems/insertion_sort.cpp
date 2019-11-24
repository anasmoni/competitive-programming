#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[10] = {4,7,8,5,20,-1,3,6,9,1};

    for(int i=1 ; i<10 ; i++)
    {
        int x = a[i] , j = i-1 ;

        while(a[j]>x && j>=0 ){a[j+1] = a[j];j--;}
        a[j+1] = x;

    }

    for(int i=0 ; i<10 ; cout<<a[i++]<<" ");

    return 0;
}
