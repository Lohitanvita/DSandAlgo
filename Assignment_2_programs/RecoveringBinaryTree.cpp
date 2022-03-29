#include <iostream>
#include <stack>
#include<vector>


using namespace std;

struct TreeNode{                 // defining the structure of a tree with left, right, data
   public:
   int val;
   TreeNode *left, *right;
   TreeNode(int data)
   {
      val = data;
      left = NULL;
      right = NULL;
   }
};

class Solution
{
   public:
       TreeNode* recoverFromPreorder(string traverse)
       {
        vector<TreeNode*> path_stk;                                  // declaring a stack to track the path traversed
        for (int i = 0, breadth, value; i < traverse.length();)      // using breadth first search
            {
            for (breadth = 0; traverse[i] == '-'; i++)                // traversing through the tree from level 0 to total length of the tree
                breadth++;
            for (value = 0; i < traverse.length() && traverse[i] != '-'; i++)  // keeping trach of '-' to update the child nodes
                value = value * 10 + traverse[i] - '0';                        // updating the value of the new node when new node is encountered
            TreeNode* node = new TreeNode(value);                              // creating a new node when it reaches next level
            while (path_stk.size() > breadth) path_stk.pop_back();             // checking th condition for stack size if it is greater than the level of tree always
            if (!path_stk.empty())
                if (!path_stk.back()->left) path_stk.back()->left = node;      // checking if stack does not contain left node of the current node then update the left node with the node
                else path_stk.back()->right = node;                            // if condition fails return the right node
            path_stk.push_back(node);                                           // store the stack with current node pointer (address)
        }
        return path_stk[0];
    }
};

main(){                                 // calling the function with class object and passing the test case arguments.
   Solution ob;
   TreeNode *root1 = ob.recoverFromPreorder("1-2--3--4-5--6--7");
   cout << root1 << endl;
   TreeNode *root2 = ob.recoverFromPreorder("1-2--3---4-5--6---7");
   cout << root2 << endl;

}

