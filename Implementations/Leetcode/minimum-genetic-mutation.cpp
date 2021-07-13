//problem URL: https://leetcode.com/problems/minimum-genetic-mutation/
class Solution {
public:
    int getDiffChar(string s1, string s2){
        int cnt = 0;
        for(int i = 0; i < s1.length(); i++){
            if (s1[i] != s2[i])
                cnt++;
        }
        return cnt;
    }
    
    int minMutation(string start, string end, vector<string>& bank) {
        queue<pair<string,int>> q;
        q.push({start,0});
        
        while(!q.empty()){
            string cur = q.front().first;
            int cnt = q.front().second;
            //cout << cur << " " << cnt << endl;
            q.pop();
            
            if(!cur.compare(end)) return cnt;
            
            for(int i = 0; i < bank.size(); i++){
                //cout << str << endl;
                if (getDiffChar(cur,bank[i]) == 1){
                    q.push({bank[i],cnt+1});
                    bank.erase(find(bank.begin(),bank.end(),bank[i]));
                    i--;
                }
            }
        }
        
        return -1;
    }
};

