long long dp[10][1005];
	int arr[4][3] = {{1,2,3},{4,5,6},{7,8,9},{-1,0,-1}};
	long long dfs(int N,int i,int j){
	    if(N==1){
	        return 1;
	    }
	    if(dp[arr[i][j]][N]!=-1){
	        return dp[arr[i][j]][N];
	    }
	    long long a=0,b=0,c=0,d=0,e=0;
	    e = dfs(N-1,i,j);
	    
	    if(i-1>=0 and  arr[i-1][j]!=-1){
	        a=dfs(N-1,i-1,j);
	    }
	    if(i+1<=3 and  arr[i+1][j]!=-1){
	        b=dfs(N-1,i+1,j);
	    }
	    if(j-1>=0 and  arr[i][j-1]!=-1){
	       c= dfs(N-1,i,j-1);
	    }
	    if(j+1<=2 and  arr[i][j+1]!=-1){
	        d = dfs(N-1,i,j+1);
	    }
	    return dp[arr[i][j]][N] = a+b+c+d+e;
	}
	long long getCount(int N)
	{
	 dp[10][N+1];
	    memset(dp,-1,sizeof(dp));
	    long long ans = 0;
	    for(int i=0;i<=3;i++){
	        for(int j=0;j<=2;j++){
	            if(arr[i][j]!=-1){
	                ans += dfs(N,i,j);
	            }
	        }
	    }
	    return ans;
	}
