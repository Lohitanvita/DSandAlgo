#include <iostream>
#include <vector>

using namespace std;


// defining the structure of a Tree
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

// using recursion method
// this method tracks the path of binary tree in the order => left, root node, right node, that is tracks DFS inorder path
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode* root) // defining a function that returns vector of integers
     {
        vector<int> inorder_traverse;            // a vector of integer variable to store the inorder path of binary tree
        LNR_path(inorder_traverse, root);        // a recursive function with two arguments
        return inorder_traverse;                 // returning a vector variable
    }
    void LNR_path(vector<int>& inorder_traverse, TreeNode* root) // defining the recursive function with output vector and input node
     {
        if (!root)                                  // base function for the recursive function
        {
            return;                                 // if root = null then return null since this is a void function
        }
        LNR_path(inorder_traverse, root->left);     // traversing through left nodes till reaches a leaf node
        inorder_traverse.push_back(root->val);      // pushing the value of the current root into vector variable
        LNR_path(inorder_traverse, root->right);    // traversing through right nodes till reaches a leaf node
    }
};

main()                                            // main function to call the above function and pass the test case
{
   Solution inorder;                              // object of the class solution
   TreeNode *root = new TreeNode(1);              //created a binary tree with root node as 1, left node value 2, right node value 3
   root->left = new TreeNode(2);
   root->right = new TreeNode(3);
   vector<int> result;
   result = inorder.inorderTraversal(root);       // calling the function of the solution using class object and storing output in the vector result
   for (int x: result)
    {
        cout << x << " ";                           // printing the values of vector result that contains inorder_traverse variable values
    }
}
