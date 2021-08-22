#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> queens;

    int totalNQueens(int n) {
        return backtrack(0, 0, n);
    }

    int backtrack(int row, int count, int n) {
        for (int col = 0; col < n; col++) {
            if (isValid(row, col)) {
                queens.emplace_back(row, col);
                if (row + 1 == n) { count++; }
                else { count = backtrack(row + 1, count, n); }
                queens.pop_back();
            }
        }
        return count;
    }

    bool isValid(int i, int j) {
        bool is_valid = true;
        for (auto queen: queens) {
            if (not is_valid) { break; }
            int row = queen.first;
            int col = queen.second;
            is_valid = not((i == row or j == col or abs(i - row) == abs(j - col)));
        }
        return is_valid;
    }
};

int main() {
    auto s = new Solution();
    cout << s->totalNQueens(8);
    return 0;
}