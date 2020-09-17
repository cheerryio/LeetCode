
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class Solution {
public:
    /*
    * 找到三个数字相乘的最大乘积。
    * 维护p1,p2,p3变量，这三个变量都是正数，他们是数组中最大的三个正数
    * 维护n2,n3变量，他们是数组中最小的两个负数，其中n1<n2<n3,|n1|>|n2|>|n3|
    * 
    * 
    * 
    * 好聪敏啊啊啊啊！！！！直接sort 结果=max(最大三个数相乘，最小两个数*最大一个数)
    */
    int maximumProductMine(vector<int>& nums) {
        int r=0;
        int p1 = -1, p2 = -1, p3 = -1, n1 = 1, n2 = 1, n3 = 1;
        bool flag = false;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                if (nums[i] > p1) {
                    p3 = p2;
                    p2 = p1;
                    p1 = nums[i];
                }
                else if (nums[i] > p2) {
                    p3 = p2;
                    p2 = nums[i];
                }
                else if (nums[i] > p3) {
                    p3 = nums[i];
                }
            }
            else if (nums[i] < 0) {
                if (nums[i] < n1) {
                    n3 = n2;
                    n2 = n1;
                    n1 = nums[i];
                }
                else if (nums[i] < n2) {
                    n3 = n2;
                    n2 = nums[i];
                }
                else if (nums[i] < n3) {
                    n3 = nums[i];
                }
            }
        }
        if (p3 > 0 && n2 < 0)
            flag=true,r = max<int>(r,max<int>(p1 * p2 * p3, p1 * n2 * n3));
        if (p3 > 0 && n1 > 0)
            r = max<int>(r,p1 * p2 * p3);
        if (p3 < 0 && n3 < 0)
            r = r==0 && !flag?n1*n2*n3:max<int>(r,n1 * n2 * n3);
        if (p1 > 0 && n2 < 0)
            r = max<int>(r,p1 * n1 * n2);
        return r;
    }
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return max(nums[0] * nums[1] * nums[nums.size() - 1], nums[nums.size() - 1] * nums[nums.size() - 2] * nums[nums.size() - 3]);
    }
};

int main() {
    vector<int> nums = {-4, -3, -2, -1, 60};
    Solution a;
    cout << a.maximumProduct(nums) << endl;
    return 0;
}