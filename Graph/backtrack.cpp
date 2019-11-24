/**
https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=60
**/


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

string sp,cons,s;
bool big[30][30];
bool taken[30];

bool check(string t, char c)
{
    for(int i=0;i<t.size(); i++){
        if(t[i]==c || big[c-'a'][t[i]-'a'])return false;
    }
    return true;
}


void dfs(){

    for(int i=0; i<s.size(); i++){

        int ii = s[i]-'a';

        for(int j=0; j<s.size(); j++){

            int jj = s[j]-'a';

            if(big[ii][jj]){
                for(int k=0; k<s.size(); k++){
                    int kk = s[k]-'a';
                    if(big[jj][kk])big[ii][kk]=1;
                }
            }
        }
    }
}

void fun(int idx, string t)
{

    if(t.size()==s.size())
    {
        cout<<t<<endl;
        return;
    }

    if(idx==s.size())return;

    for(int i=0; i<s.size(); i++)
    {

        //if(sz(t) && t[sz(t)-1]>s[i])continue;
        //cout<<t<<" char "<<s[i]<<" dies "<<check(t,s[i],t.size())<<endl;

        if(check(t,s[i])==false)continue;


        if(taken[i]==false)
        {

            taken[i]==true;
            fun(idx+1,t+s[i]);
            taken[i]==false;
        }
    }
}


int main()
{
    int c=0;

    while(getline(cin,sp))
    {

        getline(cin,cons);

        if(c++)cout<<endl;



        Fill(big,0);
        Fill(taken,0);


        for(int i=0; i<cons.size(); i+=4) {

            int x = cons[i]-'a';
            int y = cons[i+2]-'a';

            big[x][y]=1;
        }

        for(int i=0; i<sp.size(); i+=2)s+=sp[i];
        sort(atoz(s));

        dfs();

        fun(0,"");

        s.clear();
        //cout<<sp<<endl<<cons<<endl;
    }

    return 0;
}
