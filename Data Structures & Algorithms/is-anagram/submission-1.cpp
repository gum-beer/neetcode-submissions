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
       std::unordered_map<char, int>::iterator it = m.begin();
std::unordered_map<char, int>::iterator end = m.end();
for (; it != end; ++it) {
    std::pair<const char, int>& pair = *it;
    if (pair.second != 0) {
        return false;
    }
}
       return true;
        
    }
};
