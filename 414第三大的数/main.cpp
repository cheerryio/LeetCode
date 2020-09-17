
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class Solution {
public:
    /*
    * 维护三个变量m1,m2,m3。m1>m2>m3，一次将新进来的数与m1,m2,m3比较，更改这三个变量的值
    */
    int thirdMax(vector<int>& nums) {
        int64_t m1 = INT64_MIN, m2 = INT64_MIN,m3 = INT64_MIN;
        int temp;
        bool flag = false;
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] != m1 && nums[i] != m2 && nums[i] != m3) {
                if (nums[i] > m1) {
                    m3 = m2;
                    m2 = m1;
                    m1 = nums[i];
                    continue;
                }
                else if (nums[i] > m2) {
                    m3 = m2;
                    m2 = nums[i];
                    continue;
                }
                else if (nums[i] > m3) {
                    flag = true;
                    m3 = nums[i];
                }
            }
        }
        if (m3 != INT64_MIN)
            return m3;
        return m1;
    }
};

int main() {
    vector<int> nums1 = {1,2,2,5,3,5};
    vector<int> nums2 = { 1, 2, -2147483648 };
    Solution a;
    int m3_1 = a.thirdMax(nums1);
    int m3_2 = a.thirdMax(nums2);
    cout << m3_1 << endl;
    cout << m3_2 << endl;
    return 0;
}
