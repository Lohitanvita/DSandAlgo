#include <iostream>
#include <string>
#include <stack>

using namespace std;

class StrgBlanace {
public:
    int minimumDeletions(string str)
    {
        stack<char> balance;         // Initialised the stack
        int count = 0;

        balance.push(str[0]);         // Pushed the first char of the string

        for (int i = 1; i < str.length(); i++)
        {
            if (balance.empty())
            {
                balance.push(str[i]);
            }
            else if (balance.top() == 'b' && str[i] == 'a')
            {
                count += 1;               // Increased the count of deletions
                balance.pop();        // Pop the top of stack
            }
            else
            {
                balance.push(str[i]);
            }

        }
        return count;
    }
};

/*int main()
{                                     // driver code
    StrgBlanace sb;
    string s = "aababbab";
    int result = sb.minimumDeletions(s);
    cout << result << endl;

    s = "bbaaaaabb";
    result = sb.minimumDeletions(s);
    cout << result << endl;

    return 0;
}*/