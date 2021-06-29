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
const int N=2e5+10;
const int NN=1e9+10;
const int mod = 1e9 + 7;
//============================================================================================================


struct job{
    int s,e,p;
};

bool compare(job a, job b){
    return a.e < b.e;
}

int bsearch(job arr[], int i){
    int lo = 0,  hi = i-1;
    while(lo <= hi){
        int mid = (lo + ((hi-lo)/2));
        if(arr[mid].e < arr[i].s){
            if(arr[mid+1].e < arr[i].s){
                lo = mid+1;
            }
            else{
                return mid;
            }
        }
        else{
            hi = mid -1;            
        }
    }
    return -1;
}


void solve(){
    int n;cin>>n;
    job arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].s>>arr[i].e>>arr[i].p;
    }
    sort(arr,arr+n, compare);
    vector<int>dp(n,0);
    dp[0] = arr[0].p;
    for(int i=1;i<n;i++){
        int inc = arr[i].p;
        int idx = bsearch(arr, i);
        if(idx!=-1){
            inc += dp[idx];
        }
        int exc = dp[i-1];
        dp[i] = max(inc, exc);
    }
    cout<<dp[n-1];return;
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
