class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row_num=matrix.size();
        int col_num=matrix[0].size();
        int top=0;
        int bot=row_num-1;
        while(top<=bot)
        {
            int row=(top+bot)/2;
            if(target<matrix[row][0])
            {
                bot=row-1;
            }
            else if(target>matrix[row][col_num-1])
            {
                top=row+1;
            }
            else{
                break;
            }
        }
        if(!(top<=bot))
        {
            return false;
        }
        int row=(top+bot)/2;
        int l=0;
        int r=col_num-1;
        while(l<=r)
        {
            int mid=l+((r-l)/2);
            if(target<matrix[row][mid])
            {
                r=mid-1;
            }
            else if(target>matrix[row][mid])
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
