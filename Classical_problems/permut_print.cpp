#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vec;

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define scn(n) scanf("%d",&n)
#define scnll(n) scanf("%lld",&n)
#define scn2(n,m) scanf("%d%d",&n,&m)
#define scn3(n,m,w) scanf("%d%d%d",&n,&m,&w)
#define scn2ll(n,m) scanf("%lld%lld",&n,&m)
#define atoz(v) v.begin(),v.end()
#define Fill(a,v) memset(a,v,sizeof(a))
#define sz(v) v.size()
#define fi first
#define se second
#define inf 1e9
#define pi acos(-1.0)
#define sqr(x) x*x
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))


int Set(int N,int pos)
{
    return N=N | (1<<pos);
}
int reset(int N,int pos)
{
    return N= N & ~(1<<pos);
}
bool check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}

string s;

void fun(int i,string t)
{

    if(i==s.size())
    {
        cout<<"("<<t<<")";
        return ;
    }

    fun(i+1,t+s[i]);

    fun(i+1,t+" "+s[i]);

}

bool taken[200];
int per[200],num=2;

void permut(int idx)
{

    if(idx>num)
    {


        for(int k=0; k<=num; k++)cout<<per[k]<<" ";
        cout<<endl;
        return;
    }

    for(int l=0; l<=num; l++)
    {

        if(taken[l]==false)
        {
            taken[l]=true;
            per[idx]=l;
            permut(idx+1);
            taken[l]=false;
        }
    }
}

void str_permut(string s, int lo,int hi){

    if(lo==hi){
        cout<<s<<endl;
        return;
    }

    for(int i=lo; i<hi; i++){

        swap(s[i],s[lo]);
        str_permut(s,lo+1,hi);
        swap(s[i],s[lo]); ///backtrack
    }
}

int main()
{
    /*
    {
        string s;
        cin>>s;
        str_permut(s,0,s.size());
        return 0;
    }

    {
        Fill(taken,0);

        permut(0);
        return 0;
    }
    */

    {
        int t;
        scn(t);

        while(t--)
        {
            cin>>s;

            fun(0,"");
            cout<<endl;
        }
        return 0;
    }


    return 0;
}
