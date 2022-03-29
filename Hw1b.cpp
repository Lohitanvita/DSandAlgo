#include <iostream>

/*struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};*/

/*class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *temp1 = l1;
        ListNode *temp2 = l2;
        ListNode *l3 = new ListNode();
        ListNode *list3 = l3;

        int i = 0;
        int j = 0;
        long int num1 = 0;
        long int num2 = 0;

        while(temp1 != NULL){
            num1 += temp1->val*pow(10,i);
            temp1 = temp1->next;
            i += 1;
        }
        while(temp2 != NULL){
            num2 += temp2->val*pow(10,j);
            temp2 = temp2->next;
            j += 1;
        }
        num1 = num1 + num2;
        if (num1 == 0){
            ListNode *node = new ListNode(num1);
            list3->next = node;
            list3 = list3->next;
        }
        while(num1){
                long int num1_q = num1/10;
                int num1_r = num1%10;
                ListNode *node = new ListNode(num1_r);
                list3->next = node;
                list3 = list3->next;
                num1=num1_q;
            }
        return l3->next;
    }
};

int main(){
    ListNode L11(2);
    ListNode L12(4);
    ListNode L13(3);
    L11->next = L12;
    L12->next = L13;
    Solution sol;
    int num = sol.addTwoNumbers(L11);
    cout << num;
}
*/
