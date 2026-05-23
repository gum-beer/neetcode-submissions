class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m1;
        for(int i=0;i<nums.size();i++)
        {
            int diff=target-nums[i];
            if(m1.find(diff)!=m1.end())
            {
                return {m1[diff],i};
            }

            m1[nums[i]]=i;
        }
    }
};
