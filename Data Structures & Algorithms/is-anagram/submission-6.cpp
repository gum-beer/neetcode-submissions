/* Here in the first approach we compare string sizes and if not
same then its already false. After that we insert the string to hashmap
 and then we decrement the hash map for the other string so it looks 
 like this
 eg. s1=racecar s2=carrace
 so map looks like
 r->2
 a->2
 e->1
 c->2

 and when decremented map looks like 
 
 r->0
 a->0
 e->0
 c->0 
 
 then we create a pair of the <key,value> in map and iterate it
 to see if all the value element in map is 0 ad if yes then the 2 strings
 are anagram */
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
        //std::pair<const char, int>& pair 
        //underlying logic of auto
        if (pair.second != 0) {
            return false;
        }
       }
       return true;
        
    }
};
