class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        
        unordered_map< string, vector<string> > mp;
        vector<vector<string>> ans;
        
        for(int i=0;i<s.size();i++)
        {
            string temp=s[i];
            sort(s[i].begin(),s[i].end());   
            
            mp[s[i]].push_back(temp);
            
        }
        
        for(auto it:mp)
            ans.push_back(it.second);
        
        return ans;
    
    }
};