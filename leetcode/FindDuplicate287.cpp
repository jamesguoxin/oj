#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int findDuplicate(vector<int>& nums){
        int entry;
        for (entry=0; entry < nums.size(); entry++){
            if (entry != nums[entry])
                break;
        }

        int fast = entry;
        int slow = entry;

        do {
            fast = nums[nums[fast]];
            slow = nums[slow];
        } while (fast != slow);

        slow = entry;
        while (slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};

int main(int argc, char** argv){
    vector<int> test = {2, 5, 1, 1, 4, 3};
    Solution s;
    int d = s.findDuplicate(test);
    cout << d << endl;
    return 0;
}
