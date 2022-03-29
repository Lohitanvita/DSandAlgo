#include <iostream>
#include <string>
#include <stack>

using namespace std;


class Solution
{
public:
    string decodeString(string str)
    {
    stack<int> integer_stk;        // declaring a stack for storing integer values of input string
    stack<char> string_stk;        // declaring another stack to parallely store the string values of input string
    string temp = "", decoded_string = "";


    for (int i = 0; i < str.length(); i++)      // Traversing the string
    {
        int count = 0;

        if (str[i] >= '0' && str[i] <='9')            // If number, convert it into number
        {
            while (str[i] >= '0' && str[i] <= '9')
            {
                count = count * 10 + str[i] - '0';
                i++;
            }

            i--;
            integer_stk.push(count);                      // and push it into integerstack.
        }



        else if (str[i] == ']')                     // If closing bracket ']', pop element until
        {                                           // '[' opening bracket is not found in the  character stack.
            temp = "";
            count = 0;

            if (! integer_stk.empty())
            {
                count = integer_stk.top();
                integer_stk.pop();
            }

            while (! string_stk.empty() && string_stk.top()!='[' )
            {
                temp = string_stk.top() + temp;
                string_stk.pop();
            }

            if (! string_stk.empty() && string_stk.top() == '['){
                string_stk.pop();
            }


            for (int j = 0; j < count; j++){                       // Repeating the popped string 'temo' count
                decoded_string = decoded_string + temp;            // number of times.
            }

            for (int j = 0; j < decoded_string.length(); j++)       // Push it in the character stack.
            {
                string_stk.push(decoded_string[j]);
            }
            decoded_string = "";
        }

        else if (str[i] == '[')                                           // If '[' opening bracket, push it into character stack.
        {
            if (str[i-1] >= '0' && str[i-1] <= '9'){
                string_stk.push(str[i]);
            }
            else
            {
                string_stk.push(str[i]);
                integer_stk.push(1);
            }
        }

        else
            string_stk.push(str[i]);
    }

    while (! string_stk.empty())                                 // Pop all the element, make a string and return.
    {
        decoded_string = string_stk.top() + decoded_string;
        string_stk.pop();
    }

    return decoded_string;
    }
};


int main(){                                       // driver function to call and test the logical function
    Solution decode_str;
    string s = "3[a2[bc]]ef";
    string result = decode_str.decodeString(s);
    cout << result << endl;

}
