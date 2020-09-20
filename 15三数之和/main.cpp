#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include <deque>
#include <limits>
#include <algorithm>

using namespace std;

/*
* 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

 

示例：

给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

/*
* 比如对第一个i1来说，如果向前移动一次还和原来的那个数一样，那么此次运算必定有和上一次重复的结果....
* 对i2同样如此。 当i1没有改变，i2移动了一下还和上一次i2数值相同，那么又有重复的结果
* 
* 解题使用了双指针法。  有两个数在移动。前一个数的增大会导致后一个数变小。那么前面那个数正向动，
* 后面那个数反向动，就可以让复杂度变成o(N)
*/

class Solution {
public:

	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> r;
		if (nums.size() < 3)
			return r;
		sort(nums.begin(), nums.end());
		for (int i1 = 0; i1 < nums.size() - 2; i1++) {
			if (i1 != 0 && nums[i1] == nums[i1 - 1])
				continue;
			int i3 = nums.size() - 1;
			for (int i2 = i1 + 1; i2 < i3; i2++) {
				if (i2 != i1 + 1 && nums[i2] == nums[i2 - 1])
					continue;
				while (nums[i1] + nums[i2] + nums[i3] > 0 && i3>i2) {
					i3--;
				}
				if (i3 <= i2)
					continue;
				if (nums[i1] + nums[i2] + nums[i3] == 0)
					r.push_back(vector<int> {nums[i1], nums[i2], nums[i3]});
			}
		}
		return r;
	}
};

ostream& operator<<(ostream& output, const vector<vector<int>>& nums) {
	for (int i1 = 0; i1 < nums.size(); i1++) {
		for (int i2 = 0; i2 < nums[i1].size(); i2++) {
			output << nums[i1][i2] << " ";
		}
		output << endl;
	}
	return output;
}

int main() {
	Solution a;
	vector<int> nums = { 1, 2, -2, -1 };
	auto result = a.threeSum(nums);
	cout << result << endl;
	return 0;
}