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
       for (auto& pair : m) {
        if (pair.second != 0) {
            return false;
        }
       }
       return true;
        
    }
};
