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

long long solvedp(vector<int> coins, int n, int x, vector<int> &dp){
    const int mod = 1e9+7;
    for(int i = 1;i<x+1;i++){
        long long ans = 0;
        f(j,n){
            if(i-coins[j] >= 0){
                if(dp[i-coins[j]] != 0){
                    ans = (dp[i-coins[j]]+ans)%mod;
                }
            }
        }
        
        dp[i] = ans;
    }
    return dp[x];
}

void solve(vector <ll>& result){
    
    int n,x;
    cin >> n >> x;
    vector<int> a(n);
    fcin(n,a);
    vector<int> dp(x+1,0);
    dp[0]=1;
    long long ans = solvedp(a,n,x,dp);
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