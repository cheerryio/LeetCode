#include <iostream>
#include <list>
#include <vector>

using namespace std;
/*
* 删除链表中等于给定值 val 的所有节点。

示例:

输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5
*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};


/*
* 删除链表中等于给定值 val 的所有节点。

示例:

输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5
*/

/*
* 可以尝试添加一个不等于val的头节点，就可以少了头节点==val然后移动head的判断
* 用当prev->next!=NULL作为循环的条件判断
*/
class Solution {
public:
    void outputList(ListNode* head) {
        ListNode* p = head;
        while (p != NULL) {
            cout << p->val << endl;
            p = p->next;
        }
    }

    ListNode* constructList(vector<int> nums) {
        ListNode* p = new ListNode(nums[0]);
        ListNode* head = p;
        for (int i = 1; i < nums.size(); i++) {
            p->next = new ListNode(nums[i]);
            p = p->next;
        }
        return head;
    }

    ListNode* removeElements(ListNode* head, int val) {
        ListNode* p = head, * prev = NULL;
        while (p != NULL && p->val == val) {
            p = p->next;
            head = p;
        }
        prev = head;
        while (p != NULL) {
            if (p->val == val) {
                prev->next = p->next;
                p = p->next;
            }
            else {
                prev = p;
                p = p->next;
            }
        }
        return head;
    }
};

int main() {
    Solution a;
    ListNode* head = a.constructList(vector<int> { 1,2,3,4 });
    head = a.removeElements(head, 2);
    a.outputList(head);
    return 0;
}