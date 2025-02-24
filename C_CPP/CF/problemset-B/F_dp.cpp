// auther:cjtsai
#include <bits/stdc++.h>
using namespace std;

signed main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        map<int, int> mp;
        mp[0]=1;
        int ans=0;
        int sum=0;
        for(int i=1; i<=n; i++){
            int a;cin>>a;
            sum+=a;
            ans+=mp[sum-2024];
            mp[sum]++;
        }
        cout<<ans<<'\n';
    }
}