#include<bits/stdc++.h>
using namespace std;

map<string,bool>exist;
string str[120];
int idx;
string s;

void func(int lo, int hi){
    if(lo==hi)return;

    for(int i=lo+1 ; i<=hi ; i++){
        string tmp = s.substr(lo,i);
        cout<<tmp<<endl;
        if(exist[tmp]){
            if(lo==0)str[idx]="("+tmp;
            else if(lo<hi)str[idx]+= " " + tmp;
            if(i==hi){str[idx++]+=" )";}
            func(i,hi);
            idx++;
        }

    }
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);

        while(n--){cin>>s; exist[s]=true;}
        cin>>s;
        func(0,s.size());
        for(int i=0 ; i<idx;i++){
            cout<<str[i]<<endl;
        }
        idx=0;
        exist.clear();

    }
    return 0;
}
