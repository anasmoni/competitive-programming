#include<bits/stdc++.h>
using namespace std;


typedef long long int lli;
typedef pair<int,int> pii;

#define pb push_back
#define ppk pop_back
#define mp make_pair
#define mt make_tuple
#define scn(n) scanf("%d",&n)
#define atoz(v) v.begin(),v.end()
#define fill(a,v) memset(a,v,sizeof(a))
#define sz(v) v.size()
#define fi first
#define se second
#define inf 1e9
#define pi acos(-1.0)
#define sqr(x) x*x
#define max3(a,b,c) max(a,max(b,c))

/**
int n;
    cin >> n;
    cin >> ws; // stream out any whitespace...use ws...it's like a command
    for(int i = 0; i < n; i++)
    {
        string local;
        getline(cin, local);

    }
**/


void print(string s)
{
    cout<<s<<endl;
}

void block1() // getline, push_back, pop_back, resize, capacity, shrink_to_fit, copy, swap
{

    string s;

    getline(cin,s); // anas mony

    cout<<s<<endl; // anas mony

    s.pb('p');

    cout<<s<<endl; // anas monyp

    s.ppk();
    cout<<s<<endl; // anas mony


    string str = "amer soner bangla ami tomay valobashi";

    str.resize(10);

    print(str);// amer soner

    cout<<"capacity "<<str.capacity()<<endl;

    str.shrink_to_fit();

    cout<<"capacity after shrink "<<str.capacity()<<endl; // 10

    char c[23] = "oka";
    str.copy(c,5,0); // should be char array

    cout<<c<<endl; // amer (0 to 5 of str)

    str.swap(s);

    print(str); // anas mony
    print(s);// amer soner
}

void block2() // init, clear, append
{
    string s(5,'$');

    print(s); // 5 times '$'

    string t(s,1,3); // 3 char starting from idx 1 of s

    print(t);

    t.clear();
    t += "anas";
    print(t);//anas

    s.append(t,1,3);

    print(s); // $$$$$nas , 3 char starting from idx 1 of t

}

void block3() // find, substr, erase, replace, reverse
{
    string s = "anasmony" , t = "mony", str = "oka";

    cout<<s.find(t)<<endl; // 4

    cout<< (s.find(str) == string::npos) << endl; // 1

    print(s.substr(4,3)); // mon, 3 chars from idx 4

    print(s.substr(4)); // mony , all from idx 4

    s += str; // "anasmonyoka"

    s.erase(4,5); // erase 5 char starting from idx 4
    print(s); // anaska

    s.replace(4,2,"mony"); // replace 2 char starting from idx 4
    print(s); //anasmony

    reverse(atoz(s));
    print(s); // reverse of s

}


void block4() // compare, rfind , empty
{
    string s="anas" , t = "anas mony anas";

    cout<<s.compare("anas")<<endl; // 0 if equal , -1 if not equal

    cout<<t.rfind(s)<<endl; // 10, last occurence

    cout<<t.empty()<<endl;// 0 if not empty , 1 if empty
}

int main()
{
    int blk;
    cin>>blk;

    cout<<"Enter 0 to exit....\n";
    if(!blk)return 0;

    switch(blk)
    {
        case 1:
            block1();
            break;
        case 2:
            block2();
            break;
        case 3:
            block3();
            break;
        case 4:
            block4();
            break;
    }


    return main();
}
