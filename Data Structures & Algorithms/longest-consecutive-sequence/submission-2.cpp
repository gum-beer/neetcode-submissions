class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int res = 0;

        for (int i : nums) {
            s.insert(i);
        }

        for (int i : nums) {
            // Start only if i is the beginning of a sequence
            if (!s.count(i - 1)) {
                int length = 1;
                //int curr = i;

                while (s.count(i+length)) {
                    //curr++;
                    length++;
                }

                res = max(res, length);
            }
        }

        return res;
    }
};