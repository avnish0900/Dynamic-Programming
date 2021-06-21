class Solution{
public:
    bool dp[501][501];
    bool pal(string s){
        int  n = s.length();
        for(int g=0;g<s.length();g++){
            for(int i=0,j=g;j<n;i++,j++){
                if(g==0){
                    dp[i][j]=1;
                }
                else if (g==1){
                    if(s[i]==s[j]){
                        dp[i][j]=1;
                    }
                    else{
                        dp[i][j]=0;
                    }
                }
                else{
                    if(s[i]==s[j] and dp[i+1][j-1]==1){
                        dp[i][j]=1;
                    }
                    else{
                        dp[i][j]=0;
                    }
                }
            }
        }
    }


    int palindromicPartition(string str){
        
    }
};
