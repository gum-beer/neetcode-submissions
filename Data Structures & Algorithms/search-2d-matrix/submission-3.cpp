class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int col_num=matrix[0].size();
        int row_num=matrix.size();
        int l=0;
        int r=(col_num * row_num)-1;
        while(l<=r)
        {
            int mid=l+((r-l)/2);
            int row=mid/col_num;
            int col=mid%col_num;
            if(target<matrix[row][col])
            {
                r=mid-1;
            }
            else if(target>matrix[row][col])
            {
                l=mid+1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
