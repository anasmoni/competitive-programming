#include<bits/stdc++.h>

using namespace std;

int main()
{
    double cl=0 , hg , up , dn , pr , x ;


    while(1)
    {
        cin>>hg>>up>>dn>>pr ;
        if(!hg)break;
        x=up ;
        for(int i=0 ; ; )
        {
            cl += up ;
            i++ ;
            if(cl>hg)
            {
                cout<<"success on day "<<i<<endl;
                break ;
            }
            up -=  x * (pr/100) ;
            cl -= dn ;
            if(cl<0)
            {
                cout<<"failure on day "<<i<<endl;
                break;
            }

            if(cl+up<dn )
            {

                cout<<"failure on day "<<++i<<endl;
                break ;
            }
        }
        cl=0 ;

    }



}
