class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<vector<int>, vector<string>> m1;

        for (auto it : strs) {

            vector<int> count(26, 0);

            for (auto ch : it) {
                count[ch - 'a']++;
            }

            m1[count].push_back(it);
        }

        vector<vector<string>> res;

        for (auto it : m1) {
            res.push_back(it.second);
        }

        return res;
    }
};