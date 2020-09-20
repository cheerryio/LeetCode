#include <iostream>
#include <list>
#include <vector>

using namespace std;

/*
* ����һ�� û���ظ� ���ֵ����У����������п��ܵ�ȫ���С�

ʾ��:

����: [1,2,3]
���:
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
* �����˻����㷨�����˵ݹ�
* �ڵݹ麯�����棬�ȴ�û���ù���Ԫ����ѡ����һ��Ԫ�طŵ�����������棬Ȼ��ʼ��һ�εݹ顣
* ���ﲻ�����Ժ���Ժ�ĵݹ麯����ϸ�ڣ�ֻ���Ѿ��ҵ����Ժ�����飬���Ѿ�������ret���ݹ麯���Ѿ�����
* ���ˣ����ݵ���ԭ�������ղż����Ԫ��pop������
* �ְ�ѭ��ǰ��һλ��ʼ�ø�ǰ���λ�����ϸ������Ԫ�أ�
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