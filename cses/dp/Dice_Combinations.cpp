#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define f(i, n) for (int i = 0; i < n; i++)
#define fcin(n, arr)            \
    for (int i = 0; i < n; i++) \
    {                           \
        cin >> arr[i];          \
    }

#define sorta(a) sort(a.begin(),a.end())
#define sortd(a) sort(a.begin(),a.end(),greater<int>())

#define pb push_back
 
void print(vector<ll> &a){
    f(i,a.size()){
        cout << a[i] << " ";
    }
    cout << endl;
}

int solvedp(int n){
    const int mod = 1e9+7;
    int m = max(n,7);
    vector<int> dp(m+1,0);
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    dp[3]=4;
    dp[4]=8;
    dp[5]=16;
    dp[6]=32;
    if(n<=6) return dp[n];
    for(int i=7;i<=n;i++){
        int temp=0;
        temp = (temp+dp[i-6])%mod;
        temp = (temp+dp[i-5])%mod;
        temp = (temp+dp[i-4])%mod;
        temp = (temp+dp[i-3])%mod;
        temp = (temp+dp[i-2])%mod;
        temp = (temp+dp[i-1])%mod;
        dp[i] = temp;
    }
    return dp[n];
}

void solve(vector <ll>& result){
    int n;
    cin >> n;
    int indx = 0;
    int ans = solvedp(n);
    result.pb(ans);
}

int main(){

    int t = 1;
    // cin >> t;
    vector<ll> result;

    while(t--){
        solve(result);
    };

    for(int i = 0; i < result.size();i++){
        cout << result[i] << endl;
    }
    return 0;
}