#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//problem URL: https://leetcode.com/problems/minimum-size-subarray-sum/
//using two pointer
/*
int minSubArrayLen(int target, vector<int>& nums) {

    int n = nums.size();
    int minSize = INT_MAX;

    vector<int> prefixSum(n, 0);

    prefixSum[0] = nums[0];

    for (int i = 1; i < n; i++)
        prefixSum[i] += prefixSum[i - 1] + nums[i];

    int l = 0, r = 0;

    while (r < n) {

        int pSum = prefixSum[r] - ((l == 0) ? 0 : prefixSum[l - 1]);
        //cout << "l: "<<l << " r: " <<r << " sum: "<<pSum << endl;
        if (pSum == target) {
            minSize = min(minSize, r - l + 1);
            r++;
        }
        else if (pSum < target) {
            r++;
        }
        else {
            minSize = min(minSize, r - l + 1);
            l++;
        }

        if (l > r)
            r = l;
    }
    return minSize == INT_MAX ? 0 : minSize;
}
*/
//using prefix sum and binary search
int minSubArrayLen(int target, vector<int>& nums) {

    int n = nums.size();
    int minSize = INT_MAX;

    vector<int> prefixSum(n, 0);

    prefixSum[0] = nums[0];

    for (int i = 1; i < n; i++)
        prefixSum[i] += prefixSum[i - 1] + nums[i];

    for (int i = 0; i < n; i++) {
        int r = prefixSum[i];
        if (r >= target) {
            auto idx = upper_bound(prefixSum.begin(), prefixSum.end(), r - target);

            if (idx != prefixSum.end()) {
                int dist = distance(prefixSum.begin(), idx);
                minSize = min(minSize, i - dist + 1);
            }
        }

    }

    return minSize == INT_MAX ? 0 : minSize;
}


int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

    int n;
    cin >> n;

    int target;
    cin >> target;

	vector<int> arr(n,0);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

    cout << minSubArrayLen(target, arr);
	return 0;
}
