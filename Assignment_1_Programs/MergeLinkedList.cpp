#include <iostream>
#include <algorithm>
 using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

static bool listsHeap(ListNode* n1, ListNode* n2) { // comparing function for min_heap
        return n1->val > n2->val;
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {       //make_heap
    ListNode rootNode(0);
    ListNode *curNode = &rootNode;
    vector<ListNode*> res_heap;
    for(int i =0; i<lists.size(); i++)
    {
        if(lists[i]) res_heap.push_back(lists[i]);
    }
    make_heap(res_heap.begin(), res_heap.end(), listsHeap); //creating a heap data structure from lists

    while(res_heap.size()>0)
    {                                                    // while heap is not null
        curNode->next=res_heap.front();
        pop_heap(res_heap.begin(), res_heap.end(), listsHeap); //popping out first elements of heap and comparing them to be lowest value rootnode and storing into resulting list
        res_heap.pop_back();
        curNode = curNode->next;
        if(curNode->next)
         {
            res_heap.push_back(curNode->next);
            push_heap(res_heap.begin(), res_heap.end(), listsHeap);
        }
    }
    return rootNode.next;
    }
};
