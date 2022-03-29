#include <iostream>
#include <vector>
#include <string>

using namespace std;




  struct TreeNode
   {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class SubtreeKmp {
public:
    void preorder(TreeNode *root,string &pre)
    {
        if(root==NULL)
        {
            pre+='#';
            return;
        }
        pre+=','+to_string(root->val);
        preorder(root->left,pre);
        preorder(root->right,pre);
    }
	// Pre-processing the Longest Prefix Suffix array
    void preprecessLPS(string t1,int lps[])
    {

        lps[0]=0;
        int len=0;
        int i=1;
        while(i<t1.size())
        {
            if(t1[i]==t1[len])
            {

                lps[i++]=++len;

            }
            else{
                if(len!=0)
                {
                    len=lps[len-1];

                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }

    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

	   /* Converting root and subRoot to its serialize form*/
        string root1;

        preorder(root,root1);

        string subRoot1;

        preorder(subRoot,subRoot1);

        int lps[subRoot1.size()];
        preprecessLPS(subRoot1,lps);
        int i=0,j=0;

		// Pattern Matching
        while(i<root1.size())
        {
            if(root1[i]==subRoot1[j])
            {
                i++;
                j++;
            }
            if(j==subRoot1.size())
            {
                return true;

            }
            else if(i<root1.size()&&root1[i]!=subRoot1[j])
            {
                if(j!=0)
                {
                    j=lps[j-1];
                }
                else{
                    i++;
                }
            }
        }
        return false;



    }
};

main()
{
    SubtreeKmp skmp;

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);

    TreeNode *subRoot = new TreeNode(4);
    subRoot-> left = new TreeNode(1);
    subRoot -> right = new TreeNode(2);

    bool output = skmp.isSubtree(root, subRoot);
    if (output ==1 )
    {
        cout <<  "True" <<endl;
    }
    else
    {
        cout << "False" << endl;
    }


}
