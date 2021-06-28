class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int l[nums.size()], r[nums.size()];
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(i< firstLen){
                sum+=nums[i];
                l[i] = sum;
            }
            else{
                sum = sum - nums[i-firstLen] + nums[i];
                l[i] = max(sum, l[i-1]);
            }
        }
        sum = 0;
        for(int i=nums.size()-1;i>=0;i--){
            if(i+secondLen >= nums.size()){
                sum+=nums[i];
                r[i] = sum;
            }
            else{
                sum = sum - nums[i+secondLen] + nums[i];
                r[i] = max(sum, r[i+1]);
            }
        }
        int ans =0;
        for(int i=firstLen-1 ;i<nums.size()-secondLen;i++){
            ans= max(ans, l[i]+r[i+1]);
        }
        memset(l,0,sizeof(l));
        memset(r,0,sizeof(r));
        sum=0;
        for(int i=0;i<nums.size();i++){
            if(i< secondLen){
                sum+=nums[i];
                l[i] = sum;
            }
            else{
                sum = sum - nums[i-secondLen] + nums[i];
                l[i] = max(sum, l[i-1]);
            }
        }
        sum = 0;
        for(int i=nums.size()-1;i>=0;i--){
            if(i+firstLen >= nums.size()){
                sum+=nums[i];
                r[i] = sum;
            }
            else{
                sum = sum - nums[i+firstLen] + nums[i];
                r[i] = max(sum, r[i+1]);
            }
        }
        for(int i=secondLen-1 ;i<nums.size()-firstLen;i++){
            ans= max(ans, l[i]+r[i+1]);
        }
        return ans;
    }
};
