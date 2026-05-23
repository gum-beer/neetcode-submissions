class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // int n=nums.size();
        // for(int i=0;i<n;i++)
        // {
        //     if(nums[i]==nums[i+1])
        //     {
        //         return true;
        //     }
        // }
        // return false;
        unordered_set<int> s;
        for(int i:nums)
        {
            if(s.count(i)){
                return true;
            }
            s.insert(i);
        }
        return false;
    }

};