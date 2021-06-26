class Solution {
public:
    int dp[31][1001]; // our DP-Table
    int dfs(int d, int f,int target){ 
        if(dp[d][target] != -1){ // if we already have answer return 
            return dp[d][target];
        }
        if(d==1){
            if(target==0){
                return 0;
            }
            if(target <= f){
                return 1;
            }
            return 0;
        }
        
        int total = 0;
        for(int i=1;i<=f;i++){
            int left = dfs(1, f,i);
            int right = target - i >=0 ? dfs(d-1, f, target-i) : 0;
            total += (left*right)%1000000007;
            total %=  1000000007;
        }
        return dp[d][target] = total;
    }
    int numRollsToTarget(int d, int f, int target) {
        memset(dp,-1,sizeof(dp));
        return dfs(d,f,target);
    }
};
