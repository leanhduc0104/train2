#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
int b[maxn]={0};
stack<int>demo;
stack<int>de;
vector<int>ans;
string a;
int main()
{
    while(!demo.empty())demo.pop();
    while(!de.empty())de.pop();
    ans.clear();     
    cin>>a;
    int n=a.size();
    for(int i=0;i<a.size();i++)
    {
        if(a[i]=='(') b[i]=-2;
        else  if(a[i]==')') b[i]=2;
        else if(a[i]=='[') b[i]=-1;
        else b[i]=1;
    }
    for(int i=0;i<n;i++){
        if(demo.empty()||b[i]==-1||b[i]==-2)
        {
            demo.push(b[i]);
            de.push(i);
        }
        else if(b[i]+demo.top()==0)
        {
            demo.pop();
            de.pop();
        }
    else{
            demo.push(b[i]);
            de.push(i);
        }
    }
    if(demo.empty())
    {
        int res=0;
        for(int i=0;i<a.size();i++) if(a[i]=='[') res++;
        cout<<res<<endl<<a<<endl;
        return 0;
    }
    while(!de.empty())
    {
        ans.push_back(de.top());
        de.pop();
    }
    ans.push_back(n);
    sort(ans.begin(),ans.end());
    
    int l,r=-1,ml,mr,res=0,maxi=0;
     for(int i=0;i<ans.size();i++)
    {
        l=r+1;
        r=ans[i];
        res=0;
        for(int i=l;i<r;i++)
        {
            if(a[i]=='[') res++;
        }
        if(res>maxi)
        {
            ml=l;mr=r-1;
            maxi=res;
        }
    }
    if(maxi==0){
        cout<<0<<endl;
        return 0;
    }
    cout<<maxi<<endl;
    for(int i=ml;i<=mr;i++)  cout<<a[i];
    cout<<endl;
}
