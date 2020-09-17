#include <iostream>
#include <list>
#include <vector>

using namespace std;

/*
* �������� �ǿ� ���������������Ǹ��������������λλ������ʼλ�á����ǵ�ÿ���ڵ�ֻ�洢һλ���֡�����������ӻ᷵��һ���µ�����
����Լ���������� 0 ֮�⣬���������ֶ��������㿪ͷ��
���ף�
��������������޸ĸ���δ������仰˵���㲻�ܶ��б��еĽڵ���з�ת��
ʾ����
���룺(7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
�����7 -> 8 -> 0 -> 7
*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};


/*
* ������һ�㶼Ҫ�õ�ջ��
* ��ջ����֮��ֱ����Ӿͺ�....
*/
class Solution {
public:
    static ListNode* numberToList(int x) {
        ListNode* head = NULL, * p = NULL,*later=NULL;
        if (x == 0)
            head = new ListNode(0);
        else {
            later = new ListNode(x % 10);
            x /= 10;
            while (x != 0) {
                p = new ListNode(x % 10);
                p->next = later;
                later = p;
                x /= 10;
            }
            head = later;
        }
        return head;
    }

    static void outputList(ListNode* l) {
        ListNode* p = l;
        while (p != NULL)
            cout << p->val, p = p->next;
        return;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = 0, len2 = 0;
        ListNode* p1 = NULL, *p2 = NULL;
        ListNode* head = NULL;
        ListNode* p = NULL, *later = NULL;
        vector<ListNode*> p1Pointers, p2Pointers;
        for (p1 = l1, len1 = 1; p1->next != NULL; p1=p1->next) {
            p1Pointers.push_back(p1);
            len1++;
        }
        p1Pointers.push_back(p1);
        for (p2 = l2, len2 = 1; p2->next != NULL; p2 = p2->next) {
            p2Pointers.push_back(p2);
            len2++;
        }
        p2Pointers.push_back(p2);
        int iterateTimes = max(len1, len2);
        int sum=0;
        bool carry=false;
        int i=0;
        while (iterateTimes > 0) {
            sum = 0;
            if (len1>0) {
                p1 = p1Pointers[len1-1];
                len1--;
                sum += p1->val;
            }
            if (len2>0) {
                p2 = p2Pointers[len2-1];
                len2--;
                sum += p2->val;
            }
            if (carry)
                sum += 1;

            p = new ListNode(sum % 10);
            if (later != NULL)
                p->next = later;
            later = p;
            carry = sum / 10;
            iterateTimes--;
        }
        if (carry) {
            p = new ListNode(1);
            p->next = later;
            later = p;
        }
        head = later;

        return head;
    }
};

int main() {
    ListNode* l1 = Solution::numberToList(5);
    ListNode* l2 = Solution::numberToList(5);
    Solution a;
    ListNode* l3 = a.addTwoNumbers(l1, l2);
    Solution::outputList(l3);
    return 0;
}
