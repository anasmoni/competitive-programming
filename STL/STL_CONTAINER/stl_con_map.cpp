#include<iostream>
#include<map>
#include<utility>
using namespace std;

int main()
{
    map<string,int>std_id ;

    std_id["Anas"] = 1505087 ;
    std_id["Mushfiq"] = 1505086;
    std_id.insert(make_pair("Nafis",1505077));
    string s ;
    cout<<"Enter a name : ";
    cin>>s;
    cout<<"student id of "<<s<<" is : "<<std_id[s]<<endl;

    map<string,int>::iterator it ;
    it = std_id.find("Mushfiq");
    std_id.erase(it);

    cout<<"student id of "<<s<<" is : "<<std_id[s]<<endl;


    return 0 ;
}
