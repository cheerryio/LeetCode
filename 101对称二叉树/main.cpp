#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include <deque>
#include <limits>

using namespace std;

/*
* 给定一个二叉树，检查它是否是镜像对称的。

 

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3

*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSymmetryLayer(vector<int> nums) {
        for (int i = 0; i < nums.size() / 2; i++) {
            if (nums[i] != nums[nums.size() -1- i])
                return false;
        }
        return true;
    }

    bool isSymmetric(TreeNode* root) {
        deque<TreeNode*> queue;
        TreeNode* node = NULL;
        vector<int> nums;
        bool end = true;
        int size = 0;
        queue.push_back(root);
        while (!queue.empty()) {
            nums.clear();
            end = true;
            size = queue.size();
            for (int i = 0; i < size; i++) {
                node = queue.front();
                queue.pop_front();
                if (node != NULL) {
                    nums.push_back(node->val);
                    queue.push_back(node->left);
                    queue.push_back(node->right);
                    if (node->left != NULL || node->right != NULL)
                        end = false;
                }
                else {
                    nums.push_back(INT32_MAX);
                }
            };
            if (!isSymmetryLayer(nums))
                return false;
            if (end)
                return true;
        }
        return true;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    Solution a;
    cout << a.isSymmetric(root) << endl;

    return 0;
}