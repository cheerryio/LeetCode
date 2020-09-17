
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <queue>

using namespace std;

/*
*
* from  中序遍历 1,2,3,4,6,7,9
*     4
*   /   \
*  2     7
* / \   / \
*1   3 6   9
*
* to    中序遍历 9,7,6,4,3,2,1
*     4
*   /   \
*  7     2
* / \   / \
*9   6 3   1
*
*/

/**
* 
* 
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    TreeNode* invertTreeMiddleOrder(TreeNode* root) {
        TreeNode* p = NULL;
        if (root == NULL)
            return NULL;
        p = root->left;
        root->left = root->right;
        root->right = p;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }

    /*
    * 采用层序遍历交换left和right的位置
    * 会用到队列queue
    * 
    */
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL)
            return NULL;
        queue<TreeNode*> q;
        TreeNode *t = NULL,*l=NULL,*r=NULL,*temp=NULL;
        q.push(root);
        while (!q.empty()) {
            t = q.front();          /*奇怪的是q.front()之后元素并没有拿出队列，还要调用q.pop()!!!!!!!!*/
            q.pop();
            if (t->left != NULL)
                q.push(t->left);
            if (t->right != NULL)
                q.push(t->right);
            temp = t->left;
            t->left = t->right;
            t->right = temp;
        }
        return root;
    }
};

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
	return 0;
}