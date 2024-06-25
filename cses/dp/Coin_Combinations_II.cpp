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
 
#define ve vector
#define vi vector<int>
#define vll vector<ll>
#define vs vector<string>
#define vb vector<bool>
#define pb push_back
 
void print(vector<ll> &a){
    f(i,a.size()){
        cout << a[i] << " ";
    }
    cout << endl;
}

string binary(ll n) {
    if (n == 0) return "0";
    
    string binary = "";
    while (n > 0) {
        binary = (n % 2 == 0 ? "0" : "1") + binary;
        n /= 2;
    }
    
    return binary;
}

ll solvedp(vector<int> a,int n,int x,int in,vector<vector<int>> &dp){

    const int mod = 1e9+7;

    if(x==0) return 1;
    if(x<0) return 0;
    if(in == n-1){
        if(x%a[in] == 0){
            return 1;
        }else{
            return 0;
        }
    }

    if(dp[in][x] != -1) return dp[in][x];

    ll ans = 0;

    for(int i = in;i<n;i++){
        ans = (ans+solvedp(a,n,x-a[i],i,dp))%mod;
    }

    return dp[in][x] = ans;

}

ll solvetab(vector<int> a,int n,int value,vector<vector<int>> &dp){

    const int mod = 1e9+7;

    for(int i=n-1;i>=0;i--){
        for(int sum=1;sum<=value;sum++){
            int inc = 0;
            int exc = 0;
            if(a[i]<=sum){
                inc = dp[i][sum-a[i]];
            }
            exc = dp[i+1][sum];
            dp[i][sum] = (inc+exc)%mod;
        }
    }

    return dp[0][value];

}

void solve(vector <ll>& result){
    int n,x;
    cin >> n >> x;
    vector<int> a(n);
    fcin(n,a);

    sortd(a);

    vector<vector<int>> dp(n+1,vector<int>(x+1,0));

    for(int i=0;i<=n;i++){
        dp[i][0] = 1;
    }

    ll ans = solvetab(a,n,x,dp);
    result.pb(ans);
}

int main(){

    int t=1;
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