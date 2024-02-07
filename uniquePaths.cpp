#include <iostream>

class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = n + m - 2;
        int r = m - 1;
        double res = 1;
        for (int i = 1; i <= r; i++)
            res = res * (N - r + i) / i;
        return (int)res;
    }
};

int main() {
    Solution solution;
    int m, n;

    // Input the values of m and n
    std::cout << "Enter the value of m: ";
    std::cin >> m;
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    // Calculate and output the unique paths
    int result = solution.uniquePaths(m, n);
    std::cout << "The number of unique paths from (0,0) to (" << m - 1 << "," << n - 1 << ") is: " << result << std::endl;

    return 0;
}
