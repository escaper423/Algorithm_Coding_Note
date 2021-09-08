#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;
unordered_map<string, vector<int>> m;


void addCandidate(string str){
    stringstream token(str);
    vector<string> tokens;
    string t;
    
    while (token >> t){
        tokens.push_back(t);
    }
    
    for(int i = 16; i < (1 << 5); i++){
        string infostr = "";
        for(int k = 0; k < 5; k++){
            if (i & (1 << k) && k != 4){
                infostr += tokens[k];
            }
        }
        m[infostr].push_back(stoi(tokens.back()));
    }
}


vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    for(const auto& str: info){
        addCandidate(str);
    }
    
    for(auto& it: m){
        sort(it.second.begin(), it.second.end());
    }
    
    for(const auto& q: query){
        stringstream ss(q);
        string token = "";
        string queryString = "";
        int queryScore;
        
        while(ss >> token){
            if (!token.compare("and") || !token.compare("-")){
                continue;
            }
        
            else if (token.length() != 0 && isdigit(token[0])){
                queryScore = stoi(token);
            }
          
            else{
                queryString += token;
            }
        }
        int idx = 0;
        auto it = m.find(queryString);
        
        if (it != m.end()){
            idx = lower_bound(it->second.begin(), it->second.end(), queryScore) - it->second.begin();
            answer.push_back(it->second.size() - idx);
        }
        else
            answer.push_back(0);
    }
    return answer;
}

/*
  문제가 됬던 점
  - 쿼리에 해당하는 지원자를 찾을 수 없을 때는 0을 삽입하면 됨.
  - 리스트를 경우의 수 별로 생성하여 저장할 수 있다는 점을 익힘.
  
*/
