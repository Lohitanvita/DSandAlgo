#include <iostream>
#include <string>
#include <vector>

using namespace std;


class PalindromeKMP {
public:
    string shortestPalindrome(string s)
     {
        int str_len = s.length();

        if (str_len <= 1)
        {
            return s;
        }

        vector<int> palin_repeat(str_len, 0);

        int i = 1, len = 0;
        while (i < n)
        {
            if (s[i] == s[len])
            {
                palin_repeat[i++] = ++len;
            }
            else
            {
                if (len == 0) ++i;
                else len = palin_repeat[len-1];
            }
        }

        i = 0;
        int j = n - 1;
        while (j >= 0)
        {
            if (s[j] == s[i])
            {
                 --j; ++i;
            }
            else
            {
                if (i == 0)
                {
                    --j;
                }
                else
                {
                    i = palin_repeat[i-1];
                }
            }
        }

        string previous_str = "";
        for (int j = str_len - 1; j >= i; --j)
        {
            previous_str += s[j];
        }

        return previous_str + s;
    }
};

main()
{
    PalindromeKMP pkmp;
    string S = "aacecaaa";
    cout << "The shortest Palindrome of string S " << S  <<" will be : " << pkmp.shortestPalindrome(S)<< endl;

    S = "abcd";
    cout << "The shortest Palindrome of string S " << S <<" will be : " << pkmp.shortestPalindrome(S) << endl;

}



