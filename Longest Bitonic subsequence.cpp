class Solution{
    
    
	public:
	int LongestBitonicSequence(vector<int>arr){
	    int n = arr.size();
	    int lis[n];
	    int lds[n];
	    lis[0] = 1;
	    for(int i=1;i<n;i++){
	        int mx = 0;
	        for(int j=0; j<i;j++){
	            if(arr[j] < arr[i]){
	                if(mx < lis[j]){
	                    mx = lis[j];
	                }
	            }
	        }
	        lis[i] = mx+1;
	    }
	    lds[n-1] = 1;
	    for(int i=n-2;i>=0;i--){
	        int mx = 0;
	        for(int j=n-1;j>i; j--){
	            if(arr[j] < arr[i]){
	                if(mx < lds[j]){
	                    mx = lds[j];
	                }
	            }
	        }
	        lds[i] = mx+1;
	    }
	    int max = lis[0] + lds[0] - 1;
       for (int i = 1; i < n; i++)
         if (lis[i] + lds[i] - 1 > max)
             max = lis[i] + lds[i] - 1;
        return max;
	}
};
