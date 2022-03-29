#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;


class Solution {
public:
    int calPoints(vector<string>& ops)
    {
        stack<int> score_record;
        int final_score = 0;

        for (int i = 0; i < ops.size(); i++)   // parsing through the ops array of string
        {
            if (ops[i] == "+")                 // if ith element of ops is '+' then condition is true
            {

                int last_ele = score_record.top();  // get the top most element of stack and store value into a variable
                score_record.pop();                 // then pop it from stack to be able to retrieve the second last element of stack

                int second_last = score_record.top();   // get the second lat element which is the top element in the stack and store in variable
                score_record.pop();                      // pop it again

                int sum = last_ele + second_last;       // do the addition operation

                score_record.push(second_last);        // and record all the score by pushing them in sequence in the stack
                score_record.push(last_ele);
                score_record.push(sum);
            }
            else if (ops[i] == "C")                  // if we encounter 'C' in the ops array then condition is true
            {
                score_record.pop();                  // invalidate the previous score record by popping out the top element in stack
            }
            else if (ops[i] == "D")                   // if encounter 'D' in the ops array then condition is true
            {
                score_record.push(score_record.top() * 2);   // double the previous score and store it into the stack
            }
            else
            {
                score_record.push(stoi(ops[i]));        // if ith element of ops are neither '+', 'C', 'D' or if the element are integers
            }                                           // convert the string to integer and push them into stack for score record
        }

        while (!score_record.empty())                   // now to get the final score or sum of all the integers

        {                                               // iterate through the stack till its empty and pop the element and add them
            final_score += score_record.top();
            score_record.pop();
        }

        return final_score;                               // return the sum of all the integers as the final score
    }
};

int main(){                                              // Driver function for calling and testing the logic function
    Solution game;
    vector<string> ops = {"5", "2", "C", "D","+"};
    int result = game.calPoints(ops);
    cout << result << ""<< endl;

    vector<string> new_record = {"5","-2","4","C","D","9","+","+"};
    result = game.calPoints(new_record);
    cout << result << ""<< endl;

    vector<string> new_input = {"1"};
    result = game.calPoints(new_input);
    cout << result << "" << endl;

    return 0;

}
