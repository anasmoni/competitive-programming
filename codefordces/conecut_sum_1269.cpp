#include<stdio.h>
#include<algorithm>
   #include<string.h>
  #include<stdlib.h>
   #include<iostream>
   using namespace std;
   typedef long long LL;
   LL ans[500005];
 int id[32];
  struct node
  {
      node *p[2];
      node()
      {
          memset(p,0,sizeof(p));
      }
  };
  node *root;
  void in(int *v)
  {
      int i,j,k;
      node *c=root;
      for(i=30; i>=0; i--)
      {
            int pre=v[i];
          if(c->p[v[i]]==NULL)
          {
              c->p[v[i]]=new node();
          }
          c=c->p[v[i]];
      }
  }
  LL ma(int *v)
  {
      LL sum=0;
      LL l=1;
      node*c=root;
      int i;
      for(i=30; i>=0; i--)
      {
          int pre=v[i];
          if(c->p[(pre+1)%2]==NULL)
          {
              c=c->p[pre];
              sum*=2;
              sum+=0;
          }
          else
          {
              c=c->p[(pre+1)%2];
              sum*=2;
              sum+=1;
          }
      }
      return sum;
  }
  LL mi(int *v)
  {
      LL sum=0;
      LL l=2;
     node*c=root;
      int i;
      for(i=30; i>=0; i--)
      {
          int pre=v[i];
          if(c->p[pre]==NULL)
          {
              c=c->p[(pre+1)%2];
              sum*=2;
              sum+=1;
          }
          else
          {
              c=c->p[pre];
              sum*=2;
              sum+=0;
          }
      }
      return sum;
  }
  void del(node *c)
  {
      for(int i=0; i<2; i++)
      {
          if(c->p[i]!=NULL)
              del(c->p[i]);
      }
      free(c);
  }
  int main(void)
  {
      int i,j,k;
      scanf("%d",&k);
      int s;
      int n,m;
      for(s=1; s<=k; s++)
      {
          scanf("%d",&n);
          for(i=1; i<=n; i++)
         {
             scanf("%lld",&ans[i]);
             ans[i]^=ans[i-1];
         }
         root=new node();
         LL maxx=0;
         LL minn=1e12;
         memset(id,0,sizeof(id));
         in(id);
         for(i=1; i<=n; i++)
         {
             memset(id,0,sizeof(id));
             LL kk=ans[i];
             int cnt=0;
             while(kk)
             {
                 id[cnt++]=kk%2;
                 kk/=2;
             }
             maxx=max(maxx,ma(id));
             minn=min(minn,mi(id));
             in(id);
         }del(root);
         printf("Case %d: ",s);
         printf("%lld %lld\n",maxx,minn);
     }return 0;
}
