class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, int> mps;

        for (char c : s) {
            mps[c]++;
        }

        for (char c : t) {
            mps[c]--;
        }

        for (auto it : mps) {
            if (it.second != 0) {
                return false;
            }
        }

        return true;
    }
};