#include <iostream>
#include <stack>


using namespace std;

struct TreeNode{
   public:
   int val;
   TreeNode *left, *right;
   TreeNode(int data){
      val = data;
      left = NULL;
      right = NULL;
   }
};
void inord(TreeNode *root){
   if(root != NULL){
      inord(root->left);
      cout << root->val << " ";
      inord(root->right);
   }
}
class Solution {
   public:
   TreeNode* recoverFromPreorder(string S) {
      stack<TreeNode*> st;
      int i = 0;
      int n = S.size();
      int lvl = 0;
      int num = 0;
      while (i < n) {
         for (lvl = 0; S[i] == '-'; lvl++, i++)
         ;
         num = 0;
         while (i < n && S[i] != '-') {
            num = num * 10 + (S[i] - '0');
            i++;
         }
         while (st.size() > lvl)
         st.pop();
         TreeNode* temp = new TreeNode(num);
         if (!st.empty() && !st.top()->left) {
            st.top()->left = temp;
         }
         else if (!st.empty()) {
            st.top()->right = temp;
         }
         st.push(temp);
      }
      while (st.size() > 1)
      st.pop();
      return st.empty() ? NULL : st.top();
   }
};
main(){
   Solution ob;
   TreeNode *root1 = ob.recoverFromPreorder("1-2--3--4-5--6--7");
   inord(root1);
   cout << root1 << endl;
   TreeNode *root2 = ob.recoverFromPreorder("1-2--3---4-5--6---7");
   inord(root2);
   cout << root2 << endl;

}

