#include<bits/stdc++.h>

using namespace std;

int a[100000];

int main()
{
    int n , p , lft=0 , rgt=2 , x,y ;
    cin>>n>>x;

    int mn=x , mx = -2e12 ;

    for(int i=0 ; i<n ; i++)
    {
        cin>>x;

        if(mn>=x)a[lft++] = x , a[lft++] = mn , mn=x ;
        else


    }



    return 0 ;
}
