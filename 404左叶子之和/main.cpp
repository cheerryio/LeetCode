#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include <deque>
#include <limits>

using namespace std;

/*
* ���������������������Ҷ��֮�͡�

ʾ����

    3
   / \
  9  20
    /  \
   15   7

������������У���������Ҷ�ӣ��ֱ��� 9 �� 15�����Է��� 24

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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        if (root == NULL)
            return 0;
        if (root->left != NULL && root->left->left == NULL && root->left->right == NULL)
            sum+=root->left->val;
        sum += sumOfLeftLeaves(root->left);
        sum += sumOfLeftLeaves(root->right);
        return sum;
    }
};

int main() {
    Solution a;
    return 0;
}