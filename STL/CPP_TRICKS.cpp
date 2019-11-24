#include<bits/stdc++.h>
using namespace std;

#define line(n) cout<<"Line "<<n<<"->   "

#define print(v) {for(auto x: v)cout<<x<<" "; cout<<endl;}

#define block(x) cout<<"\nBlock "<<x<<"\n\n"

#define nl cout<<endl;

#define eb emplace_back

int main()
{
    block(1);

    {
        vector<int>v;

        v = {1,2,3,4};/////look/////

        print(v);

        pair<int,int>p;

        p = {1,2}; ////loook////

        line(24);
        cout<<p.first<<" "<<p.second<<endl;

        typedef pair<int,int> pii; ////look////

        vector<pii>vec;


        for(int i=1; i<6; i++){
            //vec.push_back({i,i*i});///look/////
            vec.eb(i,i*i);///faster
        }

        line(44);
        for(auto x : vec)cout<<x.first<<" "<<x.second<<endl;
        nl;

        pair<int,pair<char,double> >pic;

        pic = {1,{'a',12.2}};

        line(45);
        cout<<pic.first<<" "<<pic.second.first<<" "<<pic.second.second<<endl;
        nl;

        set<int>s;
        s = {2,2,3,3,4,5,5};

        line(56);
        print(s); // 2,3,4,5
        nl;

        list<int>lst;
        lst = {1,4,2,1,4};

        line(63);
        print(lst);
        nl;
    }


    block(2);

    {
        //print( __builtin_ffs(10));
    }


    return 0;
}
