#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> maxNumberFromOneArray(vector<int>& nums, int k) {
            vector<int> ans(k, 0);
            int n = nums.size();
            if (nums.empty() || k == 0) return ans;
            for (int i = 0, j = 0; i < n; ++i) {
                while (n - i + j > k && j > 0 && ans[j - 1] < nums[i]) j--;
                if (j < k) ans[j++] = nums[i];
            }
            return ans;
        }
};

int main(int argc, char* argv[]) {
    vector<int> nums {9, 1, 2, 5, 8, 3};
    Solution solution;
    vector<int> ans = solution.maxNumberFromOneArray(nums, 2);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << endl;
    }
    return 0;
}
