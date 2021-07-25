//problem URL: https://leetcode.com/problems/implement-trie-prefix-tree/
class Trie {
public:
    /** Initialize your data structure here. */
    bool isEnd = false;
    unordered_map<char, Trie* > m;
    
    Trie() {
           
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *cur = this;
        
        while(word.size()){
            char c = word[0];
            if (!cur->m[c]){
                cur->m[c] = new Trie();
            }
            cur = cur->m[c];
            word = word.substr(1);
        }
        
        cur->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *cur = this;
        while(word.size()){
            char c = word[0];
            if(!cur->m[c])
                return false;
            
            cur = cur->m[c];
            word = word.substr(1);
        }
        return cur->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *cur = this;
        while(prefix.size()){
            char c = prefix[0];
            if(!cur->m[c])
                return false;
            
            cur = cur->m[c];
            prefix = prefix.substr(1);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
