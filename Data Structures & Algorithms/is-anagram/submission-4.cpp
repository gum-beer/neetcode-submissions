class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())
        {
            return false;
        }
       unordered_map<char,int> m;
       for(char ch: s)
       {
            m[ch]+=1;
       }
       for(char ch: t)
       {
            m[ch]-=1;
       }
    /* rather than using auto it in for loop we have expanded 
    that so we begin by creating another map element of same type to iterate 
    and then inside the loop we create a pair that points to it and if for
    that particular pair the value part is 0 then it works otherwise false */
    std::unordered_map<char, int>::iterator it = m.begin();
    std::unordered_map<char, int>::iterator end = m.end();
    for (; it != end; ++it) 
    {
        //std::pair<const char, int>& pair = *it;
        if (it->second != 0) 
            {
            return false;
            }
    }
       return true;
        
    }
};
