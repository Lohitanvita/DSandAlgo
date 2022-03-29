#include <iostream>
/*#define LINKLIST_H*/

using namespace std;



struct ListNode {                           // defining a structure of singly linked list
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3 = new ListNode();
        ListNode *list_temp = l3;
        int add_over = 0;

        while(l1!= nullptr || l2!= nullptr || add_over)      // adding every element of nodes and returning their results into
        {
            int addition = 0;                                 // new linked list l3
            if(l1!= nullptr)
            {
                addition += l1->val;
                l1 = l1->next;
            }
            if(l2!= nullptr)
            {
                addition += l2->val;
                l2 = l2->next;
            }
            addition += add_over;
            list_temp->next = new ListNode(addition % 10);
            list_temp = list_temp->next;
            add_over = addition/10;
        }
        return l3->next;
        }
};


