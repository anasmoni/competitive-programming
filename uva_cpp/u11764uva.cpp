#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t ;
    cin>>t;
    for(int j=1 ; j<=t ; j++)
    {
        int n , l=0 , h=0 ;
        cin>>n;
        if(n)
        {

            int a[n];
            for(int i=0 ; i<n ; i++)
            {
                cin>>a[i];
                if(i && a[i]>a[i-1])h++;
                if(i && a[i]<a[i-1])l++;
            }
            cout<<"case "<<j<<": "<<h<<" "<<l<<endl;
        }
    }
    return 0 ;
}
