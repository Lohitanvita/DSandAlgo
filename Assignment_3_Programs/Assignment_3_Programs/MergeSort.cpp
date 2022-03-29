#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;


 struct ListNode
 {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class MergeSort
{
public:
    ListNode *merge_two(ListNode *first,ListNode *second)       // function to sort two nodes of a linked list in ascending order
    {
        if(!first)                                              // if first node is null then return second node and vice versa
        {
            return second;
        }
        if(!second)
        {
            return first;
        }
        if(first->val > second->val)                           // after sorting the length of the linked list until two nodes
        {                                                      // compare the two final splitted nodes and return in ascending order
            return merge_two(second,first);
        }
        first->next = merge_two(first->next,second);             // then update to the next node of first half of splitted list and
        return first;                                          // and pass it to merge_two function for futher comparison else return first
    }
    ListNode* sortList(ListNode* head)                          // calling the logical function by passing head of the listnode
    {
        if(!head || !head->next)                                // if there is no node other than head then return head node
        {
            return head;
        }
        ListNode *slow = head;                                     // initialize three List Node pointers to head node
        ListNode *fast = head;
        ListNode *tmp = head;

        while(slow && fast && fast->next)                        // if the pointers are not null then update to next node
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        while(tmp && tmp->next && tmp->next!=slow)                //these two loops splits the length of list into length/2 till one node is left and sort them independently by comparing the values
        {
            tmp = tmp->next;
        }
        tmp->next=NULL;

        ListNode *first = sortList(head);                        // passing the head node and slow node to sortList function
        ListNode *second = sortList(slow);
        ListNode *sortedList = merge_two(first,second);          // after splitting the length of linked lists till 2 nodes left and pass them to merge_two function

        return sortedList;                                       // return the sorted list which return node values in ascending order
    }
};
main()                                                          // driver function to call and test the logical function
{
    MergeSort ms;
    ListNode *head = new ListNode(4);
    head -> next = new ListNode(2);
    head -> next-> next = new ListNode(1);
    head -> next-> next-> next = new ListNode(3);
    ListNode *result = ms.sortList(head);
    while (result != nullptr){
        cout << result->val << " ";
        result = result -> next;
    }

}
