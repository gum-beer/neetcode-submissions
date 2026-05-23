class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        
        for(auto it : strs)
        {
            vector<int> count (26,0);
            for(char c:it)
            {
            count[c-'a']++;
            }
            string res=to_string(count[0]);
            for(int i=1;i<26;i++){
                res+= ','+to_string(count[i]);
            }
            mp[res].push_back(it);
        }
        vector<vector<string>>fin;
        for(const auto& pair :mp)
        {
         
            fin.push_back(pair.second);
        }
        return fin;
    }
};
