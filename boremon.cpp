#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
int cnt[100111];
int dp[100111];
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
    	int x;
    	cin>>x;
    	cnt[x]++;
    }
    dp[1]=cnt[1];
    for(int i=2;i<100111;i++){
    	dp[i]=max(dp[i-1],dp[i-2]+cnt[i]*i);
    }
    cout<<*max_element(dp,dp+100111);
}