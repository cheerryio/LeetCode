#include <iostream>
#include <list>
#include <vector>

using namespace std;
/*
* ɾ�������е��ڸ���ֵ val �����нڵ㡣

ʾ��:

����: 1->2->6->3->4->5->6, val = 6
���: 1->2->3->4->5
*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};


/*
* ɾ�������е��ڸ���ֵ val �����нڵ㡣

ʾ��:

����: 1->2->6->3->4->5->6, val = 6
���: 1->2->3->4->5
*/

/*
* ���Գ������һ��������val��ͷ�ڵ㣬�Ϳ�������ͷ�ڵ�==valȻ���ƶ�head���ж�
* �õ�prev->next!=NULL��Ϊѭ���������ж�
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