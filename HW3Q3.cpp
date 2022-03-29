#include <iostream>
#include <stack>
#include <string>

using namespace std;


class Solution {
public:
    int calculate(string s) {
        stack<int> operand;
        stack<pair<int, bool>> stackSize;
        bool sign = true;
        int retVal = 0;
        int startIdx = 0;
        for (int i = 0; i <= s.length(); ++i) {
            if (i == s.length() || s[i] == ')') {
                int remainingSize = 0;
                bool localSign = true;
                if (!stackSize.empty()) {
                    remainingSize = stackSize.top().first;
                    localSign = stackSize.top().second;
                }
                int temp = 0;
                while (operand.size() != remainingSize) {
                    temp += operand.top();
                    operand.pop();
                }
                if (localSign == false) {
                    temp *= -1;
                }
                if (i != s.length()) operand.push(temp);
                else retVal = temp;
                stackSize.pop();
            } else if (s[i] == '(') {
                stackSize.push({operand.size(), sign});
                sign = true;
            } else if (s[i] >= '0' && s[i] <= '9') {
                if (i > 0 && !(s[i - 1] >= '0' && s[i - 1] <= '9')) {
                    startIdx = i;
                }
                if (i == s.length() - 1 || !(s[i + 1] >= '0' && s[i + 1] <= '9')) {
                    int num = stoi(s.substr(startIdx, i - startIdx + 1));
                    if (!sign) num *= -1;
                    operand.push(num);
                }
            } else if (s[i] == '+') {
                sign = true;
            } else if (s[i] == '-') {
                sign = false;
            }
        }
        return retVal;
    }
};


int main(){
    Solution calculate;
    string evaluate = "(1+(4+5+2)-3)+(6+8)";
    int sum = calculate.calculate(evaluate);
    cout << sum << endl;

}
