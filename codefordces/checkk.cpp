#include<bits/stdc++.h>
#include<set>
#include<cstdlib>
using namespace std;

class String
{
private:
    char *s;
    int len;
public:
    void setString(char *p)
    {
        len = strlen(p) ;
        s = new char[len+1];
        strcpy(s,p);
        delete p;
    }

    char *getString(){return s;}

};

int main()
{
    String ob;
    ob.setString("fdfgd");
    cout<<ob.getString();

    return 0;
}




