class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        int dpl[n];int dpr[n];
        memset(dpl,0,sizeof(dpl));memset(dpr,0,sizeof(dpr));
        int mi = arr[0];int cur_pro = 0;
        for(int i=1;i<n;i++){
            if(mi > arr[i]){
                mi = arr[i];
            }
            cur_pro = arr[i]-mi;
            dpl[i] = max(dpl[i-1], cur_pro);
        }
        int ma = arr[n-1];cur_pro = 0;
        for(int i=n-2;i>=0;i--){
            if(ma<arr[i]){
                ma=arr[i];
            }
            cur_pro = ma-arr[i];
            dpr[i] = max(dpr[i+1],cur_pro);
        }int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans, dpl[i]+dpr[i]);
        }
        return ans;
    }
};
