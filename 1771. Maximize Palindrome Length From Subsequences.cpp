class Solution {
public:
    int ans, mid ;
    string s;
    int dp[1001][1001];
    int dfs(string s, int i, int j){
        if(i>j){
            return  0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(i==j){
            return  dp[i][j] =  1 + dfs(s,i+1,j-1);
        }
        
        
        if(s[i]==s[j]){
            int len = 2+dfs(s,i+1,j-1);
            if(i<mid and j>=mid){
                ans = max(ans, len);
            }
            return len;
            
        }
        else{ 
            return dp[i][j] = max(dfs(s,i+1,j), dfs(s,i,j-1));
        }
    }
    
    
    int longestPalindrome(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        s = word1+word2;
        mid = word1.length();
        dfs(s,0,s.length()-1);
        return ans;
    }
};
