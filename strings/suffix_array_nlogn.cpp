#include <bits/stdc++.h>
using namespace std;

#define si(n) scanf("%d",&n)
#define ll long long
#define MAX 100005  ///=================> careful here

// *************Manual by isti **********
// this is a O(nlogn) implementation by tonmoy : https://github.com/tanmoymollik/algos/blob/master/suffix_array.cpp
// Declare suffixArray object globally otherwise will get program crush due to memory stack size
//sorted suffix can be found in pos[] array
// lcp[i] array contains lcp of i th and (i-1) th suffix
//****************************************

#define pb push_back
int Count[MAX], output[MAX];
struct suffixArray {
   #define MAX_lg 18 ///=============> careful here
   #define minchar '`' ///=================> careful here
   #define Index(a) (((a) < len) ? index[mlgn][a] : -1)
   int pos[MAX], index[MAX_lg][MAX], lcp[MAX], len, mlgn;

   suffixArray() {}

   void CountSort(int add) {
      int to = max(len, 26);                        ///careful here
      memset(Count, 0, sizeof(Count));
      for(int i = 0; i < len; i++) ++Count[ Index(pos[i] + add) + 1 ];
      for(int i = 1; i <= to; i++) Count[i] += Count[i-1];
      for(int i = len-1; i >= 0; i--) output[ --Count[ Index(pos[i] + add) + 1 ] ] = pos[i];
      for(int i = 0; i < len; i++) pos[i] = output[i];
   }
   int Lcp(int x, int y) { //=============> starting position of two arbitrary suffix
      int ret = 0;
      for(int i = mlgn; i >= 0 && x < len && y < len; i--) if(index[i][x] == index[i][y])
         x += (1 << i),
         y += (1 << i),
         ret += (1 << i);
      return ret;
   }
   void create(const char *S) {
      len = strlen(S), mlgn = 0;
      for(int i = 0; i < len; i++) index[0][i] = S[i] - minchar;
      for(int done = 1; done < len; done <<= 1) {
         for(int i = 0; i < len; i++) pos[i] = i;
         CountSort(done);
         CountSort(0);
         for(int i = 0; i < len; i++) {
            int sc1 = (i > 0) ? Index(pos[i-1] + done) : -1;
            int sc2 = Index(pos[i] + done);
            index[mlgn+1][pos[i]] = (i > 0 && index[mlgn][pos[i]] == index[mlgn][pos[i-1]] && sc1 == sc2) ? index[mlgn+1][pos[i-1]] : i;
         }
         mlgn++;
      }
      lcp[0] = 0;
      for(int i = 1; i < len; i++) lcp[i] = Lcp(pos[i], pos[i-1]);
   }

   int solve(int a, int b)
    {
        int ret = 0;
        vector<int>now;

        for(int i=0; i<len; i++)
        {
            if(pos[i]<a) now.pb(pos[i]);
        }

        if(a<b)
        {
            ret = a-now[0];
            for(int i=1; i<now.size(); i++)
            {
                ret += max(0,a-now[i]-Lcp(now[i-1],now[i]));
            }
            return ret;
        }
        vector<int>bad;
        for(int i=0; i<now.size(); i++){

            int l = Lcp(now[i],a+1);
            //cout<<now[]
            if(l == b) bad.pb(now[i]);
        }
        sort(bad.begin(),bad.end());

        int idx = lower_bound(bad.begin(),bad.end(),now[0])-bad.begin();
        if(idx == bad.size()) ret = max(0,a-now[0]);
        else{
            int len = bad[idx]+b-1-now[0];
            ret = max(len,0);
        }
       // cout<<ret<<" "<<idx<<" "<<now.size()<<endl;
        for(int i=1; i<now.size(); i++){

            int l = Lcp(now[i],now[i-1]);

            idx = lower_bound(bad.begin(),bad.end(),now[i])-bad.begin();
            if(idx == bad.size()) ret += max(0,a-now[i]-l);
            else{
                int len = bad[idx]+b-1-now[i] - l;
                ret += max(len,0);
            }
        }

        return ret;
    }

};

suffixArray node1,node2;
char A[MAX],B[MAX],C[MAX],str[MAX];


int main()
{
    freopen("output.txt","w",stdout);
    freopen("input.txt","r",stdin);

    int i,j,t,l,r;
    si(t);
    for(int cs=1;cs<=t;cs++){


        scanf("%s",A);
        scanf("%s",B);

        int a=strlen(A);
        int b=strlen(B);

        strcpy(str,A);
        strcat(str,"`");  ///careful
        strcat(str,B);

        node1.create(str);

        printf("Case %d: %d\n",cs,node1.solve(a,b));
    }
}
