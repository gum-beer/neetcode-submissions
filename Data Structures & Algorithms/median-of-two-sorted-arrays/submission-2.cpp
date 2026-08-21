class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& A=nums1;
        vector<int>& B=nums2;
        if(nums1.size()>nums2.size())
        {
            swap(A,B);
        }
        int total=A.size()+B.size();
        int half=total/2;
        int l=0;
        int r=A.size();              // was A.size()-1  -> must be A.size()
        while(l<=r)
        {
            int i=l+((r-l)/2);       // count taken from A's left
            int j=half-i;            // count taken from B's left

            int aLeftMost   = i>0        ? A[i-1] : INT_MIN;
            int aRightFirst = i<A.size() ? A[i]   : INT_MAX;
            int bLeftMost   = j>0        ? B[j-1] : INT_MIN;   // B, and j-1
            int bRightFirst = j<B.size() ? B[j]   : INT_MAX;   // B not A

            if(aLeftMost<=bRightFirst && bLeftMost<=aRightFirst)
            {
                if(total%2==0)
                {
                    return (max(aLeftMost,bLeftMost)+min(aRightFirst,bRightFirst))/2.0;
                }
                else
                {
                    return min(aRightFirst,bRightFirst);
                }
            }
            else if(aLeftMost>bRightFirst)
            {
                r=i-1;
            }
            else{
                l=i+1;
            }
        }
        return -1;
    }
};