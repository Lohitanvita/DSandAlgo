/*struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};*/

/*class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        l3 = new ListNode();
        list_head = l3;


      while( (l1 !=nullptr) && (l2 !=nullptr) )
      {
         sum = sum + (l1->val) + (l2->val);
         l3->val=(sum%10);
         sum = (sum/10);
         prev=l3;
         l3 = new ListNode();
         l3->next=nullptr;
         prev->next =l3;
         l1=l1->next;
         l2=l2->next;

      }

      while(l1 !=nullptr)
      {
         sum = sum + (l1->val);
         l3->val=(sum%10);
         sum = (sum/10);
         prev=l3;
         l3 = new ListNode();
         l3->next=nullptr;
         prev->next =l3;
         l1=l1->next;

      }

      while(l2 !=nullptr)
      {
         sum = sum + (l2->val);
         l3->val=(sum%10);
         sum = (sum/10);
         prev=l3;
         l3 = new ListNode();
         l3->next=nullptr;
         prev->next =l3;
         l2=l2->next;
      }

      if(sum ==0)
      {
        prev->next=nullptr;
        delete l3;
      }
      else
      {
        l3->val=sum;
        l3->next=nullptr;
      }

      return list_head;

    }

    int sum = 0;
    ListNode* prev = nullptr;
    ListNode* l3 = nullptr;
    ListNode* list_head = nullptr;
};
*/
