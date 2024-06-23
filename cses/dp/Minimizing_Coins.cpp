#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define llu long long unsigned
#define f(i, n) for (int i = 0; i < n; i++)
#define fi(i, a, n) for (int i = a; i < n; i++)
#define fii(i, n, a) for (int i = n; i > a; i--)
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
#define pii pair<int, int>
#define vp vector<pii>
#define vl vector<loc>
#define vvb ve<vb>
#define vvl ve<vll>
#define vvi ve<vi> 
#define ev(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
 
void print(vector<ll> &a){
    f(i,a.size()){
        cout << a[i] << " ";
    }
    cout << endl;
}

int solvedp(vector <ll> coins,int x,int n, vector<int> &dp){
    
    f(i,x+1){
        int mini = INT_MAX;
        f(j,n){
            if(i-coins[j] >= 0){
                if(dp[i-coins[j]] != -1){
                    mini = min(mini,dp[i-coins[j]]);
                }
            }
        }
        if(mini != INT_MAX){
            dp[i] = 1+mini;
        }
    }
    return dp[x];
    
}

void solve(vector <ll>& result){
    ll n,x;
    cin>>n>>x;
    vector<ll> coins(n);
    fcin(n,coins);

    vector<int> dp(x+1,-1);
    dp[0] = 0;
    f(i,n){
        if(coins[i]<=x){
            dp[coins[i]] = 1;
        }
    }

    int ans = solvedp(coins,x,n,dp);
    
    result.pb(ans);
}

int main(){

    int t=1;
   
    vector<ll> result;

    while(t--){
        solve(result);
    };

    for(int i = 0; i < result.size();i++){
        cout << result[i] << endl;
    }
    return 0;
}