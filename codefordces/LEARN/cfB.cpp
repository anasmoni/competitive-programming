#include<bits/stdc++.h>
using namespace std;
int n;
map<int,int>v;
int main()
{
    cin>>n ;
    int a[n],j=1 ;


    for(int i=0 ; i<n ; i++){ scanf("%d",&a[i]); v[a[i]]++;}

    for(int i=0 ; i<n ; i++)
    {
        for(; v[j] ; j++);

        if(v[a[i]]>1 || a[i]>n)
        {
            v[a[i]]--;
            a[i]=j;
            v[j]++;
        }


    }

    for(int i=0 ; i<n ; printf("%d ",a[i++]));

    return 0;
}
