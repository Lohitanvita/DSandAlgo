#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Calculator
{
public:
    int calculate(string s)
    {
        stack<int> operation;                   // declaring a stack to keep track of sum and sign and operation in braces
        int sum=0;                              // initializing sum = 0 and sign = 1 which means positive sign
        int sign=1;

        for(int i=0;i<s.size();++i)             // traversing through the string s
        {
            char element = s[i];                 // storing the elements of the string in a character variable
            if(isdigit(element))                 // checking if th string character is an integer
            {
                int value = 0;
                while(i< s.size() && isdigit(s[i]))
                {
                    value = value*10 + (s[i]-'0');      // converting string to integer
                    ++i;
                }
                --i;
                value *= sign;                         // updating value and sum
                sum += value;
                sign = 1;
            }

            else if(element=='(')                     // if i the element in string is '(' then condition is true
            {
                operation.push(sum);                  // start a fresh operation by pushing the recorded sum and sign into stack
                operation.push(sign);
                sum=0;
                sign = 1;
            }

            else if(element==')')                    // if element ')' is true then add the all the elements of in the stack
            {
                sum *= operation.top();              // by keeping track of sign and pop till the corresponding '('
                operation.pop();
                sum += operation.top();
                operation.pop();
            }

            else if(element=='-')                    // if element is '-' then update sign as -1 to perform subtraction
            {
                sign = -1;
            }
        }
        return sum;                                 // return the sum of all the integer values in order following BODMAS rule
    }
};
int main()                                          // Driver function to call and test logical function
{
    Calculator cal;
    string evaluate = "(1+(4+5+2)-3)+(6+8)";
    int output = cal.calculate(evaluate);
    cout << output << endl;
    return 0;
}
