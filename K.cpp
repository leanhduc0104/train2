#include<bits/stdc++.h>
using namespace std;
int a[100010],b[100010];
int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    b[n]=a[n];
    for(int i=n-1;i>0;i--)b[i]=min(b[i+1],a[i]);
    for(int i=1;i<=n;i++){
        int k=lower_bound(b+i+1,b+1+n,a[i])-b-2-i;
        cout<<k<<" ";
    }
    return 0;
}