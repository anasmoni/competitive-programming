#include<bits/stdc++.h>
using namespace std;
int prime[100009];
vector<int>mp;

void seive(){
     for (int p=2; p*p<=100005; p++)
    {
        if (prime[p] == 0)
        {
            for (int i=p*2; i<=100005; i += p)prime[i]=1;
        }
    }

    for(int i=2 ; i<=100005 ; i++){
        if(!prime[i])mp.push_back(i);
    }

}

bool prm(int n)
{
    for(int i=0 ; mp[i]*mp[i]<=n && i<mp.size() ; i++)
    {
        //cout<<mp[i]<<endl;
        if(n%mp[i]==0)return 0;
    }
    return 1;
}

int main()
{
    int n;
    seive();
    scanf("%d",&n);

    if(n%2==0)
    {
        if(n!=2) cout<<"2"<<endl ; // prime1 + prime2 == n (n is even)
        else cout<<"1"<<endl ;
    }
    else{
        if( prm(n) ) cout<<"1"<<endl ;
        else if( prm(n-2) ) cout<<"2"<<endl ;
        else cout<<"3"<<endl ; // any n = prime1 + prime2 + prime3(3);
    }


    return 0;
}

