#include <iostream>
#include <vector>
 
using namespace std;
 
int combination(int n, int k) {
    if (k == 0 || k == n) return 1;
    return combination(n - 1, k - 1) + combination(n - 1, k);
}
 
vector<int> count_ways(const vector<pair<int, int>>& scores) {
    vector<int> results;
    for (const auto& score : scores) {
        int x = score.first;
        int y = score.second;
        results.push_back(combination(x + y, x));
    }
    return results;
}
 
int main() {
    int N;
    cin >> N;
 
    vector<pair<int, int>> scores(N);
    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        scores[i] = {x, y};
    }
 
    vector<int> results = count_ways(scores);
    for (int result : results) {
        cout << result << endl;
    }
 
    return 0;
}
