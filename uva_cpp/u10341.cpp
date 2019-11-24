#include<bits/stdc++.h>
#include<math.h>
using namespace std;

int main()
{
    double p, q, r, s, t ,u;
    while(scanf("%lf%lf%lf%lf%lf%lf",&p,&q,&r,&s,&t,&u)==6)
    {
        //printf("%lf %lf %lf %lf %lf %lf \n",p,q,r,s,t,u);
        for(double x=0 ; x<=1 ; x+=.1)
        {
            u = p/exp(x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u ;
            cout<<u<<endl;
            if(u == 0)
            {
                cout<<x<<endl;
                p = -0.5;
                break;
            }
        }
        if(p==-0.5)cout<<"No solution"<<endl;
    }
    return 0 ;
}
