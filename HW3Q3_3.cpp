#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculate(string s) {
int ret = 0;
bool neg = false;
stack<int> st;
char pre = '+';
for (int i = 0; i < s.size(); ++i) {
switch(s[i]) {
case ' ': break;
case '+':
case '-':
pre = s[i]; break;
case '(':
if (pre == '-') neg = !neg;
st.push(pre);
pre = '('; break;
case ')':
if (st.top() == '-') neg = !neg;
st.pop(); break;
default:
int start = i;
while(i < s.size() && isdigit(s[i])) ++i;
int num = stoi(s.substr(start, i-start));
--i;
if ((pre == '-') ^ neg) ret -= num;
else ret += num;
break;
}
}
return ret;
}
};

int main(){
    Solution calculate;
    string evaluate = "(1+(4+5+2)-3)+(6+8)";
    int sum = calculate.calculate(evaluate);
    cout << sum << endl;
}
