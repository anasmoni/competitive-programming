#include<bits/stdc++.h>
#include<cstdlib>
using namespace std;

int main()
{
    char  str[45] = "23/3/2016";
    int d,m,y;

    sscanf(str,"%d%*c%d%*c%d",&d,&m,&y);

    cout<<d<<"/"<<m<<"/"<<y<<endl;

    strcpy(str,"9.4hello");
    double x ;
    sscanf(str,"%lf%*c",&x);
    cout<<x<<endl;



    return 0 ;
}
