#include <iostream>
#include <stack>
#include <string>

using namespace std;



/* Definition for a binary tree node.*/
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class IdenticalTree 
{
public:
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        stack<TreeNode*> tree_1; 
        stack<TreeNode*> tree_2;             // declaring two stacks to comparing tree nodes values

        while (true) 
        {

            if (((p != nullptr) && (q == nullptr)) || ((p == nullptr) && (q != nullptr)))
            {
                return false;                                            // if one of the tree nodes is NULL then trees are not identical
            }

            else if (p != nullptr)
            {
                if (p->val != q->val) return false;                   // if tree node values do not match then trees are not identical

                tree_1.push(p);                                       // push the tree node values into the stacks
                tree_2.push(q); 
                p = p->left;                                          // performing an DFS preorder trvaersal, so after root node traversing through left node
                q = q->left;
            }
            else {
                if (tree_1.empty()) break;                            // then traversing through right nodes of two trees

                p = tree_1.top()->right;
                tree_1.pop();

                q = tree_2.top()->right; 
                tree_2.pop();
            }
        }
        return true;
    }
};

string PrintFunc(TreeNode* t1, TreeNode* t2)            // function to get the output of logic
{
   IdenticalTree it;
   bool result = it.isSameTree(t1, t2);
   if (result == 1) return "True";
   else return "False";
   
}


/*int main()                                    // driver code
{
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    TreeNode* q = new TreeNode(1);
    q->right = new TreeNode(2);

    string output = PrintFunc(p, q);
    cout << output << endl;

    TreeNode* a = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    TreeNode* b = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    output = PrintFunc(a, b);
    cout << output << endl;
   
    return 0;
   

}*/