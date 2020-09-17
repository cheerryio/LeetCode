
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> r(2);
        for (vector<int>::iterator i = nums.begin(); i < nums.end(); i++) {
            r[0] = distance(nums.begin(), i);
            for (vector<int>::iterator m = i + 1; m < nums.end(); m++) {
                if (*i + *m == target) {
                    r[1] = distance(nums.begin(), m);
                    return r;
                }
            }
        }
        return r;
    }
};

int main() {
    Solution a;
    vector<int> nums = { 2,7,11,15 };
    int target = 9;
    auto b = a.twoSum(nums, target);
    for (vector<int>::iterator i = b.begin(); i < b.end(); i++) {
        cout << *i << endl;
    }
    return 0;
}