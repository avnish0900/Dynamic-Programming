class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> psum (n), left(n), right(n);
        int sum = 0;
        psum[0] = nums[0];
        for(int i=1;i<n;i++){
            psum[i] += psum[i-1] + nums[i];
        }
        sum = 0;
        for(int i=0;i<n;i++){
            if(i<k){
                sum+=nums[i];
                left[i] = sum;
            }
            else{
                sum += nums[i] - nums[i-k];
                left[i] = max(left[i-1], sum);
            }
        }
        sum = 0;
        for(int i= n-1; i>=0;i--){
            if(i+ k >=n){
                sum+= nums[i];
                right[i]=sum;
            }
            else{
                sum+=nums[i] - nums[i+k];
                right[i] = max(sum, right[i+1]);
            }
        }
        int maxsum = 0, rsum = 0, lsum =0 , start = 0;
        for(int i=k; i<= n-(2*k); i++){
            if( left[i-1] + right[i+k] + (psum[i+k-1] - psum[i-1]) > maxsum ){
                maxsum =  left[i-1] + right[i+k] +( psum[i+k-1] - psum[i-1]);
                lsum = left[i-1];
                rsum = right[i+k];
                start = i;
            }
        }
        vector<int> ans ;
        for(int i=k-1; i<start; i++){
            if(psum[i] - (i-k < 0 ? 0: psum[i-k]) == lsum){
                ans.push_back(i-k+1);
                break;
            }
        }
        ans.push_back(start);
        for(int i=start + (2*k) -1 ;i<n;i++){
            if(psum[i] - psum[i-k] == rsum){
                ans.push_back(i-k+1);
                break;
            }
        }
        return ans;
    }
};
