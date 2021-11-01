#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int m,n,N;
	int getIndex(int i,int j){
	return i*N+j;
	}
	pair<int,int> getPair(int index){
	    return {index/N,index%N};
	}
	
	void check(queue<int> &q,int i,int j,unordered_map<int,int > &vis){
	    if(i<0 || i>m || j>n || j<0)
	    return ;
	    
	    int idx=getIndex(i,j);
	    
	    if(vis[idx]==1)
	    return;
	    
	    q.push(idx);
	    
	    vis[idx]=1;
	}
	int minSteps(int m, int n, int d)
	{
	    if(m>n)
	    swap(m,n);
	    
	    
	    if(d>n)
	    return -1;
	    
	    int N=n+10;
	   this->n=n;
	   this->m=m;
	   this->N=N;
	    
	    unordered_map<int,int> vis;
	    queue<int> q;
	    vis[0]=1;
	    q.push(0);
	    int time=0;
	    while(!q.empty()){
	        int t=q.size();
	        for(int k=0;k<t;k++){
	            
	            auto curr=getPair(q.front());
	            q.pop();
	            if(curr.first==d || curr.second==d)
	            return time;
	            
	            int i=curr.first;
	            int j=curr.second;
	            check(q,0,j,vis);
	            check(q,i,0,vis);
	            check(q,0,i+j,vis);
	            check(q,i+j,0,vis);
	            check(q,m,j,vis);
	            check(q,i,n,vis);
	            check(q,i-(n-j),n,vis);
	            check(q,m,j-(m-i),vis);
	        }
	        time++;
	    }
	    return -1;
	}
};

// { Driver Code Starts.
int main(){
	int tc=1;
//	cin >> tc;
	while(tc--){
		int n, m, d;
		cin >> m >> n >> d;
		Solution ob;
		int ans = ob.minSteps(m, n, d);
		cout << ans <<"\n";
	}  
	return 0;
}  // } Driver Code Ends