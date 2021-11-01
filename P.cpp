#include<bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
const int N=3000;
int a[N][N],d[N][N];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int n,m;
bool check(int x,int y){
	return 1<=x&&x<=n&&1<=y&&y<=m;
}
void bfs(int x,int y){
	d[x][y]=1;
	queue<ii> q;
	q.push(ii(x,y));
	while(!q.empty()){
		ii t=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int u=t.fi+dx[i];
			int v=t.se+dy[i];
			if(check(u,v)&&a[u][v]==0&&d[u][v]==N){
				d[u][v]=d[t.fi][t.se]+1;
				q.push(ii(u,v));
			}
		}
	}
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int i0,j0;
    cin>>n>>m>>i0>>j0;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++) {cin>>a[i][j];d[i][j]=N;}
    }
	bfs(i0,j0);
	int ans=N;
	for(int i=1;i<=n;i++) ans=min(ans,min(d[i][1],d[i][m]));
	for(int i=1;i<=m;i++) ans=min(ans,min(d[1][i],d[n][i]));
	if(ans<N) cout<<ans;
	else cout<<-1;
	
}