#include <iostream>
#include<string>

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



class Solution {
    string answer = "~";
public:     void recure(TreeNode* root,string s){
            if (!root) return;
            if (!root->left && !root->right){
                answer = min(answer,char(root->val+'a')+s);
            }
            recure(root->left,char(root->val+'a')+s);
            recure(root->right,char(root->val+'a')+s);
}
    string smallestFromLeaf(TreeNode* root) {
        recure(root,"");
        return answer;
    }
};

main(){
   Solution ob;
   TreeNode *root = new TreeNode(0);
   root->left = new TreeNode(1);
   root->right = new TreeNode(2);
   root-> left->left = new TreeNode(3);
   root-> left->right = new TreeNode(4);
   root-> right->left = new TreeNode(3);
   root-> right->right = new TreeNode(4);
   string result;
   result = ob.smallestFromLeaf(root);
   cout << result << ""<< endl;

}
