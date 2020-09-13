// author:rmokerone
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] != i + 1) {
                if (nums[i] <= 0 || nums[i] > nums.size() || nums[i] == nums[nums[i] - 1])
                    break;
                // 将nums[i] 放置到对应位置上[1,2,3...]
                int idx = nums[i] - 1;
                nums[i] = nums[idx];
                nums[idx] = idx + 1;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != (i + 1)) {
                return (i + 1);
            }
        }
        return (nums.size() + 1);
    }
};

int main(void)
{
    vector<int> array = {-1,4,2,1,9,10};
    Solution mysolution;
    int ret = mysolution.firstMissingPositive(array);
    cout<<ret<<endl;
    return 0;
}