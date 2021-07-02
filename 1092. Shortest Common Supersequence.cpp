class Solution {
public:
    int dp[1001][1001];
    int path[1001][1001];
    string dfs(string s, string t){
        int n = s.length();
        int m = t.length();
        dp[0][0] = 0;
        if(s[0]==t[0]){
            dp[0][0] = 1;
            path[0][0] = 2;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i>0){
                    dp[i][j] = dp[i-1][j];
                    path[i][j] = 0;
                }
                if(j>0){
                    if(dp[i][j-1]>dp[i][j]){
                        dp[i][j] = dp[i][j-1];
                        path[i][j] = 1;
                    }
                }
                if(s[i]==t[j]){
                    int ans =1;
                    if(i>0 and j>0){
                        ans=1+dp[i-1][j-1];
                    }
                    if(dp[i][j] < ans){
                        dp[i][j] = ans;
                        path[i][j] = 2;
                    }
                }
            }
        }
        string ans;
        int i = n-1;int j=m-1;
        while(i>=0 and j>=0){
            if(path[i][j]==0){
                i--;
            }
            else if(path[i][j]==1){
                j--;
            }
            else{
                ans.push_back(s[i]);
                i--;
                j--;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans ;
    }
    
    string shortestCommonSupersequences(string X, string Y){
        string lcs = dfs(X, Y);
        string ans ="" ;
        int i=0,j=0;
        for(char c:lcs){
            while(X[i]!=c){
                ans+=X[i];
                i++;
            }
            while(Y[j]!=c){
                ans+=Y[j];
                j++;
            }
            ans+=c;
            i++;j++;
        }
        ans += Y.substr(j);
        ans+= X.substr(i);
        return ans;
    }
    
    string shortestCommonSupersequence(string str1, string str2) {
        return  shortestCommonSupersequences(str1, str2);
    }
};
