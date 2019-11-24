#include<bits/stdc++.h>
using namespace std;
long long int f,l;
int main()
{
   // ios_base::sync_with_stdio(false);

   while(scanf("%lld%lld",&f,&l)==2)
   {
       long long int ans=0;
       if(!f && !l)return 0;
       for(long long int i=f ; i<=l ; i++)
       {
           long long int two = 2,cnt=0;
           while(i/two){cnt+=i/two;two*=2;}
           //cout<<cnt<<endl;
           two = 2; //ans+=(2+(i%2));

           for(long long int r=1; r<=i/2 ; r++)
           {
               long long int c=0;two=2;
               while(r/two || (i-r)/two)
               {
                   if(r/two)c+=r/two;
                   if((i-r)/two)c+=(i-r)/two;
                   two*=2;
               }
               //cout<<c<<endl;
               if(c==cnt)ans+=2;
           }
           ans+=2;

       }
       printf("%lld\n",ans);
   }



    return 0;
}







