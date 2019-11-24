/** if it is possible to make two subset of equal sum using the all element of arrry**/
#include <bits/stdc++.h>
using namespace std;

/**
coin change!!....using coins not more than one....make value...use val = sum/2
*/

bool findPartiion (int arr[], int n , int sum)
{
    int i, j;

    bool part[sum/2+1][n+1];

    // initialize top row as true
    for (i = 0; i <= n; i++) part[0][i] = true; /// cz , we can make 0

    // initialize leftmost column, except part[0][0], as 0

    for (i = 1; i <= sum/2; i++) part[i][0] = false; /// cz , we can't make i with 0 elemnts

     /// Fill the partition table in botton up manner
     for (i = 1; i <= sum/2; i++)
     {
       for (j = 1; j <= n; j++)
       {
         part[i][j] = part[i][j-1]; /// ignoring jth element
         if (i >= arr[j])
           part[i][j] = part[i][j] || part[i - arr[j]][j-1];
           /// is it possible to make (i-arr[j]) without jth element if so then take jth element
           /// else check if it possible to make i without taking jth element (p[i][j] = p[i][j-1])
       }
     }
/*
     // uncomment this part to print table
     for (i = 0; i <= sum/2; i++)
     {
       for (j = 0; j <= n; j++)
          printf ("%d ", part[i][j]);
       printf("\n");
     }
*/
     return part[sum/2][n];
}

int main() {
	//code
	int t;cin>>t;
	while(t--){
	    int n;cin>>n;
	    int a[n+1]; int sum=0;
	    for(int i=1 ; i<=n ; i++){
	        cin>>a[i];
	        sum+=a[i];
	    }
	    if(sum%2||n==1)cout<<"NO\n";
	    else if(findPartiion(a,n,sum)==false)cout<<"NO\n";
	    else cout<<"YES\n";
	}
	return 0;
}
