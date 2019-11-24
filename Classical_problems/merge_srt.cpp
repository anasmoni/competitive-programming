#include<bits/stdc++.h>
using namespace std;

int num[1000] , temp[1000];


void mergesort(int lo , int hi)
{
    if(lo==hi)return;

    int mid = (lo+hi)/2 ;

    mergesort(lo,mid);
    mergesort(mid+1,hi);

    int i,j,k;

    for(i=lo , j=mid+1,k=lo ; k<=hi ; k++)
    {
        if(i==mid+1)temp[k]=num[j++];
        else if(j==hi+1)temp[k]=num[i++];
        else if(num[i]<num[j])temp[k]=num[i++];
        else temp[k]=num[j++];
    }

    for(k=lo ; k<=hi ; k++)num[k]=temp[k];
    for(k=lo ; k<=hi ; cout<<num[k++]<<" ");
    cout<<endl;
}



int main()
{
    while(1)
    {
        cout<<"press 0 to exit....\n";
        int n;
        cin>>n;

        if(!n)return 0;

        for(int i=1 ; i<=n ; cin>>num[i++]);

        mergesort(1,n);
        cout<<"oka]n\n";
        for(int i=1 ; i<=n ; cout<<num[i++]<<" ");
        cout<<endl;
    }
    return 0;
}

