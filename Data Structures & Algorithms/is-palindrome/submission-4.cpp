class Solution {
public:
    bool isPalindrome(string s) {
        int left =0,right=s.size()-1;
        while(left<right)
        {
            
            while(left<right && !isalnum(s[right]))
            {
                right--;
            }
            while(left<right && !isalnum(s[left]))
            {
                left++;
            }
            if(tolower(s[left])==tolower(s[right]))
            {
                left++;
                right--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
