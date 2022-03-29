#include <iostream>
#include <vector>
#include <stack>
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


// an iterative function that return inorder path of a binary tree
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)  // a function that returns vector of integers values
    {
        vector<int> inorder_res;                  // declaring a vector of integers variable that stores result
        if(root == nullptr)
        {                                         // base function that returns empty vector of there is no root node in a tree
            return inorder_res;
        }
        stack<TreeNode*> path_track;              // declaring a stack that keeps track of path traversed, that is root nodes of child nodes
        TreeNode *curNode = root;                 // initializing a current node variable of TreeNode pointer type to root node to manipulate with the input without changing the actual input
        while (curNode || !path_track.empty())
        {                                         // checking the condition if root node and the stack are not null values
            while(curNode != nullptr)
            {                                     // if current node is not equal to null then it enters the loop
                    path_track.push(curNode);     // pushing the current node value into stack to track the path traversed
                    curNode = curNode-> left;     // updating the current node until it reaches the left leaf node
            }
            // when pointer reaches leaf node then left of leaf node will be null and current node equates to null.
            curNode = path_track.top();           // therefore equating current node with the last value or top value in stack
            inorder_res.push_back(curNode->val);  // then updating the result with current node value
            path_track.pop();                     // after updating the output variable, job is done and the respective value is popped out of stack
            if(curNode)
            {                                     // now after printing left node and root node checking the right nodes
                curNode = curNode->right;
            }

        }return inorder_res;                      // returning the result vector variable inorder_res


    }


};

main()                                  // passing the test case to the function
{
   Solution inorder_1;                  // creating an object of the class solution
   TreeNode *root = new TreeNode(1);    // creating a binary tree with root node value as 1
   root->left = new TreeNode(2);        // left child of root node with value 2
   root->right = new TreeNode(3);       // right child of root node with value 3
   vector<int> output;
   output = inorder_1.inorderTraversal(root);   // passing the TreeNode type root argument to the function using the class object
   for (int x: output)                          // printing the result stored in vector variable output
    {
        cout << x << " ";
    }
}


