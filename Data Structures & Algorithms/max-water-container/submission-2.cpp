class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i=0;
        int j=heights.size()-1;
        int area=0;
        int maxArea=0;
        while(i<j)
        {
            area=min(heights[i],heights[j])*(j-i);
            if(heights[i]<heights[j])
            {
                i++;
            }
            else{
                j--;
            }
            maxArea=max(area,maxArea);
        }
        return maxArea;
    }
};
