//problem URL: https://leetcode.com/problems/map-sum-pairs/
class Trie{
public:
    bool isEnd = false;
    Trie* children[26];
};

class MapSum {
public:
    /** Initialize your data structure here. */
    
    unordered_map<string,int> m;
    Trie *trie;
    MapSum() {
        trie = new Trie();
    }
    
    int getSum(Trie *head, string str){
        int res = 0;
        if (m.find(str) != m.end()){
            res+=m[str];   
        }
        
        for(int i = 0; i < 26; i++){
            if (head->children[i] != nullptr){
                res += getSum(head->children[i], str + (char)(i + 'a'));
            }
        }
        return res;
    }
    
    void insert(string key, int val) {
        m[key] = val;
        Trie* cur = trie;
        while(key.length() > 0){
            if (cur->children[key[0] - 'a'] == nullptr){
                cur->children[key[0] - 'a'] = new Trie();
            }
            cur = cur->children[key[0]-'a'];
            key = key.substr(1);
        }
        cur->isEnd = true;
    }
    
    int sum(string prefix) {
        Trie *cur = trie;
        string cs = "";
        while(prefix.length() > 0){
            if(cur->children[prefix[0] - 'a'] != nullptr){
                cur = cur->children[prefix[0] - 'a'];
                cs += prefix[0];
                prefix = prefix.substr(1);
            }
            else{
                return 0;
            }
        }
        return getSum(cur,cs);
        
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
