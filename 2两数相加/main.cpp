
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
* 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
*/


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3=NULL,*head=NULL;
        int sum = 0;
        bool carry = false;
        while (l1 != NULL || l2 != NULL) {
            sum = 0;
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }
            if (carry)
                sum++;
            if (head == NULL) {
                l3 = new ListNode(sum % 10);
                head = l3;
            }
            else {
                l3->next= new ListNode(sum % 10);
                l3 = l3->next;
            }

            carry = sum / 10;
        }
        if(carry)
            l3->next = new ListNode(1);
        return head;
    }
};


int main() {
    Solution a;
    return 0;
}
