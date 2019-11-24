#include<bits/stdc++.h>
using namespace std;

string s;
int toggle[500005];

/**http://www.lightoj.com/volume_showproblem.php?problem=1080**/

void update(int idx , int lo , int hi , int l , int r)
{

    if(r<lo || hi<l)return;

    if(l<=lo && hi<=r)
    {
        toggle[idx]^=1;
        //cout<<"tog "<<lo<<" "<<hi<<endl;
        return;
    }

    int mid = (lo+hi)/2;

    update(idx*2 , lo , mid , l,r);
    update(idx*2+1 , 1+mid ,hi, l,r);
}

int query(int idx , int lo , int hi , int pos)
{

    if(pos<lo || pos>hi)return 0;

    if(lo==hi)return toggle[idx];

    int mid = (lo+hi)/2;

    if(pos<=mid)return toggle[idx]^query(idx*2,lo,mid,pos);
    else return toggle[idx]^query(idx*2+1,1+mid,hi,pos);

}


int main()
{
    int t;
    scanf("%d",&t);

    for(int tc = 1 ; tc<=t ; tc++)
    {

        cin>>s;
        int q;
        scanf("%d",&q);
        memset(toggle,0,sizeof(toggle));
        int n = s.size();
        printf("Case %d:\n",tc);

        while(q--)
        {

            int lo,hi;
            char c[3];
            scanf("%s",c);

            if(c[0]=='I')
            {
                scanf("%d%d",&lo,&hi);
                update(1,1,n,lo,hi);
            }
            else
            {
                scanf("%d",&lo);
                int x = s[lo-1]-'0';
                lo = query(1,1,n,lo);
                printf("%d\n",lo^x);

            }
        }
    }
    return 0;
}

/**     IT'S OKEY TOO*/

/**
#include<bits/stdc++.h>
using namespace std;

#define MAX 100005

int cnt, sum[MAX * 4];
char s[MAX];


void update(int idx, int lo, int hi, int l, int r)
{
    if(lo == l && hi == r)
    {
        sum[idx]++;
        return;
    }

    int mid = (lo + hi)/2;

    if(r<=mid)update(idx*2, lo, mid, l, r);

    else if(mid<l)update(idx*2+1, mid+1,hi,l,r);

    else
    {
        update(idx*2,lo, mid,l, mid);
        update(idx*2+1, mid+1,hi, mid+1, r);
    }
}





int query(int idx, int lo, int hi, int pos)
{
    if(lo == hi && pos == hi)return sum[idx];

    int mid = (lo + hi)/2;

    if(pos <= mid)return sum[idx] + query(idx*2,lo, mid, pos);

    else return sum[idx] + query(idx*2+1, mid+1,hi, pos);

}



int main()
{
    int t;
    scanf("%d",&t);
    char c[3];

    for(int tc=1 ; tc<=t ; ++tc)
    {
        memset(sum, 0,sizeof(sum));

        scanf("%s",s);
        int len = strlen(s);

        for(int i=0 ; i<len ; i++){
            if(s[i]=='1'){
                update(1,1,len,i+1,i+1);
            }
        }

        int q,l,r;
        scanf("%d",&q);
        printf("Case %d:\n",tc);

        while(q--)
        {
            scanf("%s",c);
            if(c[0] == 'I')
            {
                scanf("%d%d",&l,&r);
                update(1, 1, len,l,r);
            }
            else
            {
                scanf("%d",&l);
                printf("%d\n", query(1, 1,len,l)%2);
            }
        }
    }
    return 0;
}

**/
