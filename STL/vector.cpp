#include<bits/stdc++.h>
using namespace std;

#define line(n) cout<<"\nLine "<<n<<" ->   "

#define nl cout<<endl

#define print(v) { for(auto x : v)cout<<x<<" "; cout<<endl; }

#define pb push_back

void block1() /** basic*/
{
    vector<int>v(4),v1(5,4);/**-------look---------*/

    line(12);
    print(v); // 0 0 0 0
    nl;

    line(16);
    print(v1) // 4 4 4 4 4
    nl;

    v = {1,2,3,4,5}; /**-------look---------*/

    line(23);
    print(v) // 1 2 3 4 5
    nl;
}

void block2() // assign, count, clear
{

    vector<int>v1,v2,v3;

    for(int i=1 ; i<6 ; i++)
    {
        v1.pb(i*i);
        v2.pb(i);
        v3.pb(i);
    }

    line(43);
    print(v1);
    nl;

    v2.assign(v1.begin(),v1.end());

    /**
    v2.assign(v1.begin(),v1.end()-1); /**-------look---------
    v2 = {1,4,9,16}
    */
    line(53);
    print(v2);
    nl;

    v3.assign(7,4);// 7 times 4

    line(59);
    print(v3);
    nl;

    line(64);
    cout<<"4 comes "<<count(v3.begin(),v3.end(),4)<<" times\n";

    v3.assign({12,23,34});

    line(68);
    print(v3);
    nl;

    v3.clear();

    cout<<v3.size()<<endl;
}

void block3()// sort, rev_sort, reverse
{
    vector<int>v;

    for(int i=7 ; i>0 ; i--)v.pb(i);

    sort(v.begin(),v.end());

    line(85);
    print(v);
    nl;

    sort(v.rbegin(),v.rend());

    line(91);
    print(v);
    nl;

    v = {1,2,3,4,5};

    reverse(v.begin(),v.end());

    line(101);
    print(v);
    nl;
}

void block4() // struct/class in vector,
{

    struct job
    {
        int s,e,w;

        job(int ss, int ee, int ww)
        {
            s = ss;
            e = ee;
            w = ww;
        }
    };

    vector<job>v;

    for(int i=0; i<5; i++) v.pb(job(i,i+i,i*i));


    line(134);
    for(auto x : v)cout<<x.s<<" "<<x.e<<" "<<x.w<<endl;

    v.clear();

    class man
    {

    public:
        int h,w;
        man(int hi , int wei)
        {
            h=hi;
            w=wei;
        }

    };

    vector<man>vec;

    cout<<"Classs in vector\n";

    for(int i=0; i<5; i++)
    {
        vec.push_back(man(i+i,i*i));
    }

    line(141);
    for(auto x : vec)cout<<x.h<<" "<<x.w<<endl;

}

void block5()// erase, insert, max_size, v2=v1
{
    vector<int>v;

    for(int i=0; i<5; i++) v.push_back(i);

    //v.erase(v.begin());// 0th element erased
    // v.erase(v.begin()+4);// 4 erased...(5th element)
    v.erase(v.begin()+3);

    line(158);
    for(auto x : v)cout<<x<<" "; // 0 1 2 4
    cout<<endl;

    v.insert(v.begin()+3,33);

    line(164);
    print(v) // 0 1 2 33 4
    cout<<"\nMax size of vector "<<v.max_size()<<endl;

    vector<int>v2;

    v2 = v; /**-------look---------*/

    line(172);
    print(v2); // 0 1 2 33 4
    nl;
}

void block6()// tuple, pair in vector, emplace_back
{

    {
        vector<tuple<int,int,char> >vt;

        #define mt make_tuple


        for(int i=1 ; i<=5 ; i++) vt.pb(mt(i,i+i,'a'+i));

        line(190);

        for(auto x : vt)
        {
            int a,b;
            char c;
            tie(a,b,c) = x;
            cout<<a<<" "<<b<<" "<<c<<endl;
        }
        cout<<endl;
    }

    {


        typedef pair<int,int> pii; ////look////
        #define eb emplace_back

        vector<pii>vec;

        line(218);
        for(int i=1; i<6; i++)
        {
            //vec.push_back({i,i*i});/**------------look---------*/
            vec.eb(i,i*i);///faster
        }
    }
}

void block7() // array to vect, max/min elemnt, sum/accumulate
{

    int a[] = {1,2,3,4,5};

    vector<int>v(a,a+5); // len of a = 5

    line(232);
    print(v);

    cout<<"MAX = "<<*max_element(v.begin(),v.end())<<endl;

    cout<<"Min = "<<*min_element(v.begin(),v.end())<<endl;

    cout<<"sum = "<<accumulate(v.begin(),v.end(),0)<<endl;

}

void block8() // find, binary_search, lower_bound, upper_bound, unique
{

    vector<int>v;
    v = {1,3,1,2,4};

    int x = find(v.begin(), v.end(), 3)-v.begin();
     // x=idx of 3 if found...else v.size
    // if not found then --- find(v.begin(), v.end(), 3) == v.end();
    line(253);
    cout<<x<<endl;

    v = {1,2,3,4,5,6,7};
    // must be sorted
    line(258);
    cout<<binary_search(v.begin(),v.end(),5); // true
    nl;
    cout<<binary_search(v.begin(),v.end(),12); // false
    nl;

    // should be sorted
    v = {2, 4, 6, 7, 9, 12};

    x = lower_bound(v.begin(),v.end(),5) - v.begin();
    line(268);
    cout<<x; // x = i ; v[i]>=5; x=2;
    nl;

    x = upper_bound(v.begin(),v.end(),6) - v.begin();
    line(273);
    cout<<x; // x = i ; v[i]>6; x=3;
    nl;

    v = {2, 3 , 3 ,3 ,4 ,5, 6 ,6 }; // should be sorted

    line(279);
    cout<<unique(v.begin(),v.end())-v.begin(); // 5 unique elemnt
    nl;

    v = {2,2,3,3,4,4,5,5,6};

    v.erase(unique(v.begin(),v.end()),v.end());
    line(285);
    print(v);


}



int main()
{
    int blk;

    cout<<"\nEnter block number......0 to exit......\n";
    cin>>blk;

    if(blk==0)return 0;

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
    case 5:
        block5();
        break;
    case 6:
        block6();
        break;
    case 7:
        block7();
        break;
    case 8:
        block8();
        break;
    }



    return main();
}
