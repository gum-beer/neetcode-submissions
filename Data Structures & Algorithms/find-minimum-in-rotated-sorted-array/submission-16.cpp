class Solution {
public:
    int findMin(vector<int> &nums) {
        int l=0;
        int r=nums.size()-1;
        int res=nums[0];
        while(l<=r)
        {
            if(nums[l]<nums[r])
            {
                res= min(res,nums[l]);
            }
            int m=l+((r-l)/2);
            if(nums[l]<=nums[m])
            {
                l=m+1;
            }
            else{
                r=m;
            }
            res=min(res,nums[m]);
        }
        return res;
    }
};
