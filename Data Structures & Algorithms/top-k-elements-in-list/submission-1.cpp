class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m1;
        for(int i=0;i<nums.size();i++)
        {
            m1[nums[i]]++;
        }
        vector<vector<int>> buck (nums.size()+1);
        for(const auto p:m1){
        buck[p.second].push_back(p.first);
        }
        vector<int>res;
        for(int i=nums.size();i>0;i--)
        {
            for(int n:buck[i])
            {
            res.push_back(n);
            if(res.size()==k)
            {
                return res;
            }
        }
        }
        return res;
        
    }
};
