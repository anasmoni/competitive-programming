#include<bits/stdc++.h>
using namespace std;

/**http://www.lightoj.com/volume_showproblem.php?problem=1138*/

int fun(int n){
    int f=5,cnt=0;
    while(n/f){
        cnt += n/f;
        f*=5;
    }
    return cnt;

}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1 ; i<=t; i++){
        int n,q;
        scanf("%d",&n);
        q=n;
        n *= 4;
        if(n%5)n += (5 - n%5);
        printf("Case %d: ",i);

        for( ; ; n+=5){
            int temp = fun(n);
            if(temp==q){printf("%d\n",n);break;}
            else if(temp>q){cout<<"impossible\n";break;}
        }

    }
    return 0;
}
