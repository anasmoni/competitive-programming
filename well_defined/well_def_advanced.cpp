#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long int lli;
typedef pair<int,int> pii;

#define ones(x) __builtin_popcount(x)
#define onesl(x) __builtin_popcountl(x)
#define onesll(x) __builtin_popcountll(x)

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define scn(n) scanf("%d",&n)
#define scnll(n) scanf("%lld",&n)
#define scn2(n,m) scanf("%d%d",&n,&m)
#define scn3(n,m,w) scanf("%d%d%d",&n,&m,&w)
#define scn2ll(n,m) scanf("%lld%lld",&n,&m)
#define atoz(v) v.begin(),v.end()
#define ratoz(v) v.rbegin(),v.rend()
#define Fill(a,v) memset(a,v,sizeof(a))
#define sz(v) v.size()
#define fi first
#define se second
#define inf 1e9
#define pi acos(-1.0)
#define sqr(x) x*x
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define ten(n) (int)1e##n
#define tenll(n) (lli)1e##n
#define mod 1000000007

int Set(int N,int pos)
{
    return N=N | (1<<pos);
}
int reset(int N,int pos)
{
    return N= N & ~(1<<pos);
}
bool check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

/**

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

(for multiset)
**/

/**
    ordered_set X;

    X.insert(1);
    X.insert(2);
    X.insert(4);
    X.insert(8);
    X.insert(16);

    cout<<*X.find_by_order(1)<<endl; // 2
    cout<<*X.find_by_order(2)<<endl; // 4
    cout<<*X.find_by_order(4)<<endl; // 16
    cout<<(end(X)==X.find_by_order(6))<<endl; // true

    cout<<X.order_of_key(-5)<<endl;  // 0
    cout<<X.order_of_key(1)<<endl;   // 0
    cout<<X.order_of_key(3)<<endl;   // 2
    cout<<X.order_of_key(4)<<endl;   // 2
    cout<<X.order_of_key(400)<<endl; // 5
*/

/** MIN_HEAP

(1)    priority_queue <int, vector<int>, greater<int> > min_heap;


(2) class myComparator
    {
    public:
        int operator() (const myClass& p1, const myClass& p2)
        {
            return p1.getX() > p2.getX();
        }
    };

    priority_queue <myClass, vector<myClass>, myComparator > min_heap;

*/

/*

    class minHeapComp{
        public:
            bool operator() (int a ,  int b){ // minheap asking if a is greater then b, but sort function of vector asking if a is less then b
                return abs(a)>abs(b);
            }
    };
    class maxHeapComp{
        public:
            bool operator() (int a ,  int b){
                return abs(a)<abs(b);
            }
    };

    priority_queue<int, vector<int>, minHeapComp> p;
    priority_queue<int, vector<int>, maxHeapComp> pq; // maxHeap using meanHeap
    
    vector<int> v = {3,4,-12,5,6,-1};
    for(int i : v){
        p.push(i);
        pq.push(i);
    }
    while(p.size()){
        cout<<p.top()<<" "<<pq.top()<<endl;
        p.pop();
        pq.pop();
    }
   -------------------output --------------------------
   -1 -12
    3 6
    4 5
    5 4
    6 3
    -12 -1
    
    
    vector<int> v = {3,4,-12,5,6,-1};
    sort(v.begin(), v.end(), minHeapComp());
    for(int i : v) cout<<i<<" ";
    sort(v.begin(), v.end(), maxHeapComp());
    cout<<endl;
    for(int i : v) cout<<i<<" ";
    
    -12 6 5 4 3 -1 
    -1 3 4 5 6 -12 
    

*/


/**

int month[]={-1,31,28,31,30,31,30,31,31,30,31,30,31};  //Not Leap Year

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1}; //4 Direction

int dx[]={1,1,0,-1,-1,-1,0,1};
int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction

int dx[]={2,1,-1,-2,-2,-1,1,2};
int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction (horse)

**/

int main()
{
    ///freopen("output.txt","w",stdout);
    ///freopen("input.txt","r",stdin);

    ios::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}
