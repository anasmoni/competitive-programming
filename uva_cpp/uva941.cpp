#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int main()
{
    int n ;
    string s;
    cin>>n;
    while(n--)
    {
        int m , fact=1 ;
        cin>>s>>m;
        sort(s.begin(),s.end());
        for(int j = s.size() ; j>1 ; j--)fact *= j ;

        while(m)
        {
            int f = fact/s.size() ;
            for(int i=s.size()-1  ; m && i>1 && f ; i-- , m-- , f--)
            {
                swap(s[i],s[i-1]);
                if(i==2 && f)i = s.size() ;
            }
            if(m)swap(s[0],s[1]);
        }
        cout<<s<<endl;

    }
    return 0 ;
}
