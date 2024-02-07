/*class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
		
		// iterating fromt 0 to n
        for(int i = 0; i<=n; i++)
        {
			// sum is initialised as 0
            int sum = 0;
            int num = i;
			// while num not equals zero
            while(num != 0)
            {
				// we have to count 1's in binary representation of i, therefore % 2
                sum += num%2;
                num = num/2;
            }
			// add sum to ans vector
            ans.push_back(sum);
        }
		// return 
        return ans;
    }
};*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);

        for (int i = 1; i <= n; i++) {
            ans[i] = ans[i >> 1] + (i & 1);
        }

        return ans;
    }
};

int main() {
    Solution solution;
    
    int n;
    cout << "Enter a value for n: ";
    cin >> n;

    vector<int> result = solution.countBits(n);

    cout << "Counts of set bits for numbers from 0 to " << n << ":" << endl;
    for (int i = 0; i <= n; i++) {
        cout << "Count of set bits for " << i << " is: " << result[i] << endl;
    }

    return 0;
}
