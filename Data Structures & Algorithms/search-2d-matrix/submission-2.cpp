class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row_num=matrix.size();
        int col_num=matrix[0].size();
       int top = 0, bot = row_num - 1;
int row = -1;
while (top <= bot) {
    int mid = (top + bot) / 2;
    if (target < matrix[mid][0])
        bot = mid - 1;
    else if (target > matrix[mid][col_num - 1])
        top = mid + 1;
    else {
        row = mid;   // save the found row
        break;
    }
}
if (row == -1) return false;  // no candidate row found
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
