#include <iostream>
#include <vector>
#include <string>
#include <algorithm>  // for using reverse function

using namespace std;

struct TreeNode{       // defining the structure of a tree
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
public:

    string smallestFromLeaf(TreeNode* root, string prev_val="") {

        // construct string with current root value and previous node string
        prev_val+= ('a' + root->val);

        // leaf node => return reverse of the previous node string
        if(!root->left && !root->right)
        {
            reverse(prev_val.begin(),prev_val.end());
            return prev_val;
        }

        // both left and right child exists and return min between their subtree string
        if(root->left && root->right)
            return min(smallestFromLeaf(root->left,prev_val),smallestFromLeaf(root->right,prev_val));

        // only left child and so return its subtree string
        else if(root->left)
            return smallestFromLeaf(root->left,prev_val);

        // only right child and so return its subtree string
        else return smallestFromLeaf(root->right,prev_val);

    }
};

main(){                              // creating an object of the class and passing the argument to function for testing
   Solution lexicograph;
   TreeNode *root = new TreeNode(0);      // creating a binary tree with root, left, right and their child nodes
   root->left = new TreeNode(1);
   root->right = new TreeNode(2);
   root-> left->left = new TreeNode(3);
   root-> left->right = new TreeNode(4);
   root-> right->left = new TreeNode(3);
   root-> right->right = new TreeNode(4);
   string result;
   result = lexicograph.smallestFromLeaf(root, "");
   cout << result << ""<< endl;

}
