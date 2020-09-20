#include <iostream>
#include <list>
#include <vector>

using namespace std;

/*
* 给定一个 没有重复 数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

/*
* 是用了回溯算法，用了递归
* 在递归函数里面，先从没有用过的元素里选出第一个元素放到结果数组里面，然后开始下一次递归。
* 这里不考虑以后的以后的递归函数的细节，只想已经找到了以后的数组，并已经放入了ret，递归函数已经返回
* 好了，回溯到了原来，将刚才加入的元素pop出来。
* 又把循环前进一位开始让更前面的位置填上更后面的元素！
*/

class Solution {
public:
    vector<bool> status;
    vector<vector<int>> ret;

    void backTrack(int slot,vector<int> &elem,vector<int> &nums) {
        if (slot == nums.size()) {
            ret.push_back(elem);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!status[i]) {
                elem.push_back(nums[i]);
                status[i] = true;
                backTrack(slot + 1, elem, nums);
                elem.pop_back();
                status[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        status.resize(nums.size(), false);
        vector<int> elem;
        backTrack(0, elem, nums);
        return ret;
    }
};

ostream& operator<<(ostream& output, vector<vector<int>> &nums) {
    for (int i1 = 0; i1 < nums.size(); i1++) {
        for (int i2 = 0; i2 < nums[i1].size(); i2++) {
            output << nums[i1][i2] << " ";
        }
        output << endl;
    }
    return output;
}

int main() {
    vector<int> nums = { 1,2,3,4 };
    Solution a;
    auto result = a.permute(nums);
    cout << result;
	return 0;
}