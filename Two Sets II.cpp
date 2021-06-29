#include<bits/stdc++.h>
using namespace std;
#define int              long long
#define all(xs)          xs.begin(), xs.end()
#define rall(xs)         xs.rbegin(), xs.rend()
#define sz(x)            (int)((x).size())
#define pb               push_back
#define ppb              pop_back
#define pf               push_front
#define ppf              pop_front
#define ff               first
#define ss               second
#define prec(n)          fixed<<setprecision(n)
#define debug(x)         cout << (#x) << " is " << (x) << "\n"
#define debug2(x, y)     cout << #x << "=" << x << "," << #y << "=" << y << "\n"
#define debug3(x, y,z)   cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << "\n"
#define yes              cout<<"YES";
#define no               cout<<"NO";
#define ll               cout<<"\n";
#define SZ               2e9
int gcd(int A,int B){    return (B == 0) ? A : gcd(B, A % B);}
int lcm(int A,int B){    return A * B / gcd(A, B);}
const int N=1e6+10;
const int NN=1e9+10;
const int mod = 1e9 + 7;
//============================================================================================================
 
 
int dp[5001][5001];
int ans =0;
 
void dfs(vector<int>& arr, int pos, int sum, int target){
    if(sum == target){
        ans ++;
        return;
    }
    if(pos < 0){
        return ;
    }
    dfs(arr,pos-1,sum+arr[pos], target);
    dfs(arr,pos-1,sum,target);
}
 
void solve(){
    int n;
      cin >> n;
      int target = n*(n+1)/2;
      if (target%2) {
        cout << 0 << endl;
        return ;
      }
      target /= 2;
 
      vector<vector<int>> dp(n,vector<int>(target+1,0));
      dp[0][0] = 1;
      for (int i = 1; i < n; i++) {
        for (int j = 0; j <= target; j++) {
          dp[i][j] = dp[i-1][j];
          int left = j-i;
          if (left >= 0) {
        (dp[i][j] += dp[i-1][left]) %= mod;
          }
        }
      }
      cout << dp[n-1][target] << endl;
}
 
signed main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t=1;
    // cin>>t;
    for(int i=0;i<t;i++){
        // cout<<"Case #"<<i+1<<": "; 
        solve();                                                    
    }
}
