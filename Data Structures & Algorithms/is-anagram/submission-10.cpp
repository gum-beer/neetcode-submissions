class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
        {
            return false;
        }
        unordered_map<char,int> st,st2;
        for(int i=0;i<s.size();i++)
        {
            st[s[i]]++;
        }
        for(int i=0;i<t.size();i++)
        {
            st2[t[i]]++;
        }
        if(st==st2)
        {
            return true;
        }
        return false;
    }
};
