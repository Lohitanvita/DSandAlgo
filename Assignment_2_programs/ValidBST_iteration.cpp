#include <iostream>
#include <vector>
#include <stack>
#include <climits>

using namespace std;


struct TreeNode                     // defining the structure of a tree
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution                                    // using inorder way to check if the given binary search tree is valid
 {
public:
    bool isValidBST(TreeNode* root)               // a function that returns boolean type and takes treenode pointer (address) as argument
    {
        // long min is the Minimum value for a variable of type long = -2147483647 - 1
        long previous_node = LONG_MIN;            // node to compare whether current node is always larger than previous node,
        stack<TreeNode*> path_stk;                // a stack to keep track of the path traversed
        while (root || !path_stk.empty())         // checking the condition id root node value or the stack is empty
        {                                         // if not empty then enter the loop
            while (root) {                        // if root node not null then enter the loop
                path_stk.push(root);              // pushing the current node value to stack
                root = root -> left;              // update root to left child of root till it reaches left leaf node
            }
            // root node becomes null when it reaches leaf node because left of leaf node is null
            root = path_stk.top();                // updating the root with last or the top value in the stack
            path_stk.pop();                       // popping the last value from the track as it returned the last value
            if (root -> val <= previous_node)     // now checking the condition for valid binary tree
            {                                     // if root node is smaller than left child and right node is smaller than root node
                return false;                     // then it return false that is not a valid BST
            }
            previous_node = root -> val;          // updating the precious node value
            root = root -> right;                 // updating root value to right child node until it reaches the leaf node
        }
        return true;                              // if root node is greater than left child and right node is greater than root node then return true
    }
};

main()                                         // main function that calls the above funtion in the solution to pass the argument and test cases
{
   Solution valid_bst;                         // creating object of the class
   TreeNode *root = new TreeNode(2);           // creating a binary tree with root, left and right nodes
   root->left = new TreeNode(1);
   root->right = new TreeNode(3);
   bool result;
   result = valid_bst.isValidBST(root);           // passing the root node to the function using class object and returning the bool output
   if(result == 0)
   {
    cout << "False" << "";
   }
   if(result == 1)
   {
    cout << "True" << "";
   }

}

