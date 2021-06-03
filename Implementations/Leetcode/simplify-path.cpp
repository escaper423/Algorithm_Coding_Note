//problem URL: https://leetcode.com/problems/simplify-path/
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stac;
        string res = "";
        string cur("");
        
        if(path.back() != '/')
            path.push_back('/');
        
        for(auto &it : path){
            if (it == '.' || it != '/'){
                cur += it; 
                continue;
            }
            
            if (!cur.compare(".")){
                cur = "";
                continue;
            }
            
            if (!cur.compare("..") && !stac.empty()){
                stac.pop();
            }
            if (cur.compare("..")){
                if(cur.length() > 0)
                    stac.push(cur);
            }
            cur = "";
        }
        
        while(!stac.empty()){
            if (stac.top().compare("")){
                res = stac.top() + '/'+ res;    
            }
            stac.pop();
        }

        res = '/' + res;
        if(res.length() > 1)
            res.pop_back();
        
        return res;
    }
};
