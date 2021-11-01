#include<bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define fi first
#define se second
#define pb emplace_back
int cnt[2111][2111];
void solve(){
	for(int i=0;i<2111;i++) for(int j=0;j<2111;j++) cnt[i][j]=0;
	vector<ii> a,b;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int x;
			cin>>x;
			if(x==1) a.pb(ii(i,j));
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int x;
			cin>>x;
			if(x==1) b.pb(ii(i,j));
		}
	}
	int s1=(int) a.size();
	int s2=(int) b.size();
	for(int i=0;i<s1;i++){
		for(int j=0;j<s2;j++){
			cnt[a[i].fi-b[j].fi+1000][a[i].se-b[j].se+1000]++;
		}
	}
	int ans=0;
	for(int i=0;i<2111;i++){
		for(int j=0;j<2111;j++) ans=max(ans,cnt[i][j]);
	}
	cout<<ans<<'\n';
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tt;
	cin>>tt;
	while(tt--) solve();}