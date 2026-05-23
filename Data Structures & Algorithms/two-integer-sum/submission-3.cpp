class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        int n=nums.size();
        /* Here we insert the array into the map 
        so basically array and index is stored as key and vaule
        i.e. if array is [1,3,2,7,5,10]
        its being stored as 
        1->0
        3->1
        2->2
        7->3
        5->4
        10->5  */
        for(int i=0;i<n;i++)
        {
            m[nums[i]]=i;
        }
        for(int i=0;i<n;i++)
        {
            int difference =target-nums[i];
            if(m.count(difference) && m[difference] != i)
            /* m.count(difference) is critical because when we dont have an
             element in map and we do m[difference] it automatically creates one
             with index part being 0 eg in the array 6 was not there so m.count(diff)
             will stop the if bock then and there itself */
            {
                return{i,m[difference]};
            }
        }
        return{};
    }
};
