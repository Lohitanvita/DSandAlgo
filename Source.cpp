#include <iostream>
#include <vector>
#include <string>
#define NULL_CHAR

using namespace std;

class StringRotate
{
public:

    bool rotateString(string s, string goal)
    {
        if (s.size() != goal.size())
            return false;

        string text = s + s;

        vector<int> string_shift(goal.size(), 0);

        int i = 1, j = 0;

        while (i < goal.size())
        {
            if (goal[j] == goal[i])
            {
                string_shift[i] = j + 1;
                i++;
                j++;
            }
            else
            {
                if (j == 0)
                {
                    i++;
                }
                else
                {
                    j = string_shift[j - 1];
                }
            }
        }

        i = 0, j = 0;
        while (i < text.size() and j < goal.size())
        {
            if (text[i] == goal[j])
            {
                i++;
                j++;
            }
            else
            {
                if (j == 0)
                {
                    i++;
                }
                else
                {
                    j = string_shift[j - 1];
                }
            }
        }
        return j == goal.size();
    }

};


/*int main()
{
    StringRotate sr;

    string S = "abcde";
    string Goal = "cdeab";

    bool result = sr.rotateString(S, Goal);


    if (result == 1)
    {
        cout << "True" << endl;
    }
    else 
    {
        cout << "False" << endl;
    }
    return 0;
}*/


