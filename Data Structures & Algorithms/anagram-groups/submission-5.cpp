class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m1;
        for(auto it:strs)
        {
            vector<int> count(26,0);
            for(auto it1:it)
            {
                count[it1-'a']++;
            }
            string key=to_string(count[0]);
            for(int i=0;i<26;i++)
            {
                key +=','+to_string(count[i]);
            }
        m1[key].push_back(it);

        }
        vector<vector<string>> res;
        for(const auto& it:m1)
        {
            res.push_back(it.second);
        }
        return res;
    }
};
