class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0;
        // int r=1;
        int prof=0;
        int maxProf=0;
        for(int r=1;r<prices.size();r++)
        {
            if(prices[l]<prices[r])
            {
                prof=prices[r]-prices[l];
                maxProf=max(prof,maxProf);
            }
            else{
                l=r;
            }
            // r++;
        }
        return maxProf;
    }
};
