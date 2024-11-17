#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int l = 0;
        int r = height.size() - 1;

        while (l < r) {
            const int minHeight = min(height[l], height[r]);
            ans = max(ans, minHeight * (r - l));
            if (height[l] < height[r])
                ++l;
            else
                --r;
        }

        return ans;
    }
};

// Function to test the solution
void runTest(vector<int>& height, int expectedOutput) {
    Solution solution;
    int result = solution.maxArea(height);
    cout << "Input: [";
    for (int i = 0; i < height.size(); i++) {
        cout << height[i];
        if (i < height.size() - 1) cout << ",";
    }
    cout << "]\n";
    cout << "Output: " << result << "\n";
    cout << "Expected: " << expectedOutput << "\n";
    cout << (result == expectedOutput ? "PASSED" : "FAILED") << "\n\n";
}

int main() {
    // Test Case 1
    vector<int> height1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    runTest(height1, 49);

    // Test Case 2
    vector<int> height2 = {1, 1};
    runTest(height2, 1);

    // Additional Test Case 3
    vector<int> height3 = {4, 3, 2, 1, 4};
    runTest(height3, 16);

    // Additional Test Case 4
    vector<int> height4 = {1, 2, 1};
    runTest(height4, 2);

    return 0;
}
