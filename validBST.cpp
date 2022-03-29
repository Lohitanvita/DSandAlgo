#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution{
public:
    bool isValidBST(TreeNode *root){
        return valid(root, LONG_MIN, LONG_MAX);
    }
    bool valid(TreeNode *root, long min, long max){
        if(!root){
            return true;
        }
        if(root->val <= min || root-> val >= max){
            return false;
        }
        return valid(root->left, min, root->val) && valid(root-> right,root->val, max);
    }
};

main(){
   Solution ob;
   TreeNode *root = new TreeNode(2);
   root->left = new TreeNode(1);
   root->right = new TreeNode(3);
   bool result;
   result = ob.isValidBST(root);
   if(result == 0){
    cout << "False" << "";
   }
   if(result == 1){
    cout << "True" << "";
   }

}
