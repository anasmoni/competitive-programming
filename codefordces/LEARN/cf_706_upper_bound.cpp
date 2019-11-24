#include<bits/stdc++.h>

using namespace std;

int main()
{
    int i , n ,q ,m;
    scanf("%d",&n);
    int a[n] ;

    for(i=0 ; i<n ; i++)
    {
        scanf("%d",&a[i]);
    }

    sort(a,a+n);
    scanf("%d",&q);

    while(q--)
    {
        scanf("%d",&m);
        cout<<upper_bound(a,a+n,m)-a<<endl ;
        /**cout<<"dfdff   "<<*upper_bound(a,a+n,m)<<"   "<<a<<endl;*/
        }

    return 0 ;
}
