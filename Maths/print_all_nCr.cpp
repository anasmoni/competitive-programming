#include <iostream>
using namespace std;
int m=1e9;
/** nth line of pascale triangle*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        n = n+1;
        long long arr[n][n];
        for (int line = 0; line < n; line++)
        {
            for (int i = 0; i <= line; i++)
            {
                if (line == i || i == 0)
                    arr[line][i] = 1;
                else
                    arr[line][i] = arr[line-1][i-1] + arr[line-1][i];
                if(arr[line][i]>1000000000)
                    arr[line][i]=arr[line][i]%1000000000;
                if(line==n-1)
                    cout<<arr[line][i]<<" ";
            }
        }
        printf("\n");
    }
}
