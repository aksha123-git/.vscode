/*1272. Remove Interval
Level
Medium

Description
Given a sorted list of disjoint intervals, each interval intervals[i] = [a, b] represents the set of real numbers x such that a <= x < b.

We remove the intersections between any interval in intervals and the interval toBeRemoved.
Return a sorted list of intervals after all such removals.

Example 1:

Input: intervals = [[0,2],[3,4],[5,7]], toBeRemoved = [1,6]

Output: [[0,1],[6,7]]

Example 2:

Input: intervals = [[0,5]], toBeRemoved = [2,3]

Output: [[0,2],[3,5]]

Constraints:

1 <= intervals.length <= 10^4
-10^9 <= intervals[i][0] < intervals[i][1] <= 10^9
*/

#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> removeInterval(std::vector<std::vector<int>>& intervals, std::vector<int>& toBeRemoved) {
        int x = toBeRemoved[0], y = toBeRemoved[1];
        std::vector<std::vector<int>> ans;
        for (auto& e : intervals) {
            int a = e[0], b = e[1];
            if (a >= y || b <= x) {
                ans.push_back(e);
            } else {
                if (a < x) {
                    ans.push_back({a, x});
                }
                if (b > y) {
                    ans.push_back({y, b});
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;

    // Sample input intervals and toBeRemoved
    std::vector<std::vector<int>> intervals = {{0, 2}, {3, 4}, {5, 7}};
    std::vector<int> toBeRemoved = {1, 6};

    // Call the removeInterval function
    std::vector<std::vector<int>> result = solution.removeInterval(intervals, toBeRemoved);

    // Display the result
    std::cout << "Modified Intervals:" << std::endl;
    for (const auto& interval : result) {
        std::cout << "[" << interval[0] << ", " << interval[1] << "]" << std::endl;
    }

    return 0;
}
