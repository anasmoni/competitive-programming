#include<bits/stdc++.h>
using namespace std;

int a[30007];

int solve(int n)
{
    int ans=0,tem;
    int i=0,top;
    stack<int>stk;

    while(i<n)
    {
        if(stk.empty() || a[stk.top()]<=a[i]){stk.push(i++);}
        else
        {
            top = stk.top();
            stk.pop();
            tem = a[top]*(stk.empty()? i : i-stk.top()-1);
            //cout<<tem<<" tem \n";
            ans = max(ans,tem);
        }

    }

    while(!stk.empty())
    {
        top = stk.top();
        stk.pop();
        tem = a[top]*(stk.empty()? i : i-stk.top()-1);
        ans = max(ans,tem);
    }

    return ans;
}

int main()
{

    int t;
    scanf("%d",&t);
    for(int tc=1 ; tc<=t ; tc++)
    {
        int n;
        scanf("%d",&n);
        for(int i=0 ; i<n ; scanf("%d",&a[i++]));

        printf("Case %d: %d\n",tc,solve(n));
    }
    return 0;
}
/*
1
9
2 2 7 7 7 2 2 4 2*/

/**
// cleaner one 

int calc(stack<int>&stk, vector<int>&v , int i){
        
        int tp = stk.top();
        stk.pop();
        int now = v[tp] * (stk.size()>0 ? i-stk.top()-1 : i);

        return now;
    }
    
    int MaxRect(vector<int>v){
        
        if(v.size() == 0) return 0;
        
        stack<int>stk;
        
        int i=0, area = 0;
        
        while(i<v.size()){
            
            if(stk.size() == 0 || v[stk.top()]<=v[i]) stk.push(i++);    
            else{                
                area = max(area, calc(stk,v,i));
            }
        }
        
        while(stk.size()){
            area = max(area, calc(stk,v,i)); 
        }
       
        return area;
    }
**/
