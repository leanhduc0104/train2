#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        if(n==0) return 0;
        stack<int> stk;
        vector<int> leftSml(n);
        vector<int> rightSml(n);
        
        for(int i=0;i<n;i++){    
            
            while(!stk.empty() && heights[stk.top()]>=heights[i]){
                stk.pop();
            }
            
            leftSml[i]=stk.empty()?0:stk.top()+1;
                
            stk.push(i);
        }
       
       while(!stk.empty()){   //empty stack to reuse it
           stk.pop();
       }
        
        for(int i=n-1;i>=0;i--){   //iterate from right to left
            
            while(!stk.empty() && heights[stk.top()]>=heights[i]){
                stk.pop();
            }
            
            rightSml[i]=stk.empty()?n-1:stk.top()-1;  
                 
            stk.push(i);
        }
        
       
        int res=INT_MIN;
        for(int i=0;i<n;i++){
            res=max(res,(rightSml[i]-leftSml[i]+1)*heights[i]);
        }
        
        
        return res;
    }

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int tt;
    int n;
    while(cin>>n){
    if(n==0) return 0;
    vector<int> v;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        v.pb(x);
    }
    cout<<largestRectangleArea(v)<<'\n';}
}