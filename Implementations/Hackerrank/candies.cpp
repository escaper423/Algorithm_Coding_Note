//problem URL: https://www.hackerrank.com/challenges/candies/problem
#include <bits/stdc++.h>

using namespace std;

// Complete the candies function below.
long candies(int n, vector<int> arr) {
    vector<long> D(n);
    D[0] = 1;
    for (int i = 1; i < n; i++)
        D[i] = arr[i] > arr[i-1]?D[i-1]+1:1;
    
    for (int i = n-2; i >= 0; i--)
        if (arr[i] > arr[i+1] && D[i] <= D[i+1])
            D[i] = D[i+1] + 1;
    
    long mx = 0;
    for( int i= 0; i < n; i++)
        mx += D[i];
    return mx;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    long result = candies(n, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
