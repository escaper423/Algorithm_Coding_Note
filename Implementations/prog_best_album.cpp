#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

struct Music {
    int played;
    int index;
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    int n = genres.size();

    map<string, int> freq;
    map<string, vector<Music>> m;

    vector<int> answer;

    for (int i = 0; i < n; i++) {
        freq[genres[i]] += plays[i];
        m[genres[i]].push_back(Music{ plays[i],i });
    }

    vector<pair<int, string>> v;
    for (auto& it : freq) {
        v.push_back({ it.second,it.first });
    }

    sort(v.begin(), v.end(), [](auto p1, auto p2) {
        return p1.first > p2.first;
        });

    for (int i = 0; i < v.size(); i++) {
        if (v.size() < i + 1)
            break;

        auto iter = v[i];
        string gen = iter.second;
        //cout << gen << endl;

        sort(m[gen].begin(), m[gen].end(),
            [](Music& m1, Music& m2)
            {
                if (m1.played > m2.played)
                    return true;
                else if (m1.played < m2.played)
                    return false;
                else {
                    return (m1.index < m2.index) ? true : false;
                }
            }
        );
        for (int k = 0; k < 2; k++) {
            if (m[gen].size() == 0)
                break;

            auto item = m[gen].begin();
            answer.push_back(item->index);
            m[gen].erase(m[gen].begin());
        }

    }

    return answer;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

    int n;
    
    cin >> n;

    vector<string> inGenres(n);
    vector<int> inPlayed(n,0);
	
    for (int i = 0; i < n; i++) {
        cin >> inGenres[i];
        cin >> inPlayed[i];
    }

    auto res = solution(inGenres, inPlayed);
    for (auto& i : res) {
        cout << i << " ";
    }

	return 0;
}
