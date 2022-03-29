#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    string removeOuterParentheses(string S)
    {
        stack<char> stk;                                   // stack declared to keep track of complete parenthesis pair
        string res;

        for (int i = 0; i< S.length(); i++)
        {
            char ch = S[i];

            if (stk.empty())                                // to push the outer open parenthesis
            {
                stk.push(ch);
            }
            else
            {
                if (stk.top() == '(' && ch == ')')            // if closed bracked encountered then keep track respective open bracket and pop from the stack
                {
                    stk.pop();                               // if it is outer parenthesis pair stack becomes empty after pop and  do not added to result string
                }
                else                                           
                {
                    stk.push(ch);                           // if open bracket then push to stack
                }
                if (!stk.empty())                            // then pushing both inner open and closed parenthesis into the result string 
                {
                    res += ch;
                }
            }
        }
        return res;
    }
};

/*int main()
{
    Solution ans;

    string s = "(()())(())";
    string result = ans.removeOuterParentheses(s);
    cout << result << endl;

    s = "(()())(())(()(()))";
    result = ans.removeOuterParentheses(s);
    cout << result << endl;

    return 0;
}*/