class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start=0,end=numbers.size()-1;
        while(start<end)
        {
           int curSum=numbers[start]+numbers[end];
           if(curSum>target)
           {
            end--;
           }
           if(curSum<target)
           {
            start++;
           }
           if(target==curSum)
           {
            return{start+1,end+1};
           }


        }
    }
};
