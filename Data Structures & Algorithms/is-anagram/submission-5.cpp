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
            if(m[ch] == 0) {
            m.erase(ch);
        }
       }
    //    std::unordered_map<char, int>::iterator it = m.begin();
     
        // std::unordered_map<char, int>::iterator end = m.end();
        if(m.empty())
        {
            return true;
        }    
        return false;
    }

};
/* this again uses same logic but insted we clean
 the map once the map.value is zero and then we
  simply see if map is empty*/