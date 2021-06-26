class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = -prices[0];
        int sold = 0;
        int cooldown = 0;
        for(int i=1;i<prices.size();i++){
            int ifbuytoday = cooldown-prices[i];
            if(buy > ifbuytoday){
                ifbuytoday = buy;
            }
            int ifsoldtoday = buy + prices[i];
            if(sold > ifsoldtoday){
                ifsoldtoday = sold;
            }
            int ifcooldown = sold;
            if(cooldown > ifcooldown){
                ifcooldown = cooldown;
            }
            buy = ifbuytoday;
            sold = ifsoldtoday;
            cooldown = ifcooldown;
        }
        return max(sold, cooldown);
    }
};
