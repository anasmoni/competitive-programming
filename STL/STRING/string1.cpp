#include<bits/stdc++.h>
#include<cstdlib>
#include<cstdio>
#include<string>

using namespace std;

int main()
{
    string s = "Hello World!" ;
    /** cin>>s; /** like scanf cin treat white space as end of string */
    /** gets(s); /** ERROR */
    cout<<s.size()<<endl;

    s.replace(0,5,"Hi The",5);
    cout<<s<<endl; /** s = Hi Th World! */

    s.replace(0,5,"Hey");
    cout<<s<<endl; /** s = Hey World! */


    string email = "mohammadanas.cse@gmail.com";
    size_t position = email.find("anas");

    string domain ;
    if(position != string::npos) domain = email.substr(position,4);

    cout<<domain<<endl; /** output = anas */

    size_t found = email.find(".cse");

    if(found != string::npos)email.replace(found,4,"");

    cout<<email<<endl;










    return 0 ;
}
