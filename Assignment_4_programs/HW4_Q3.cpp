#include <iostream>
#include <vector>
#include <string>

using namespace std;


class StringRepeat
{
public:
    int repeatedStringMatch(string a, string b)
    {
        int stra_size = a.size();
        int strb_size = b.size();

        vector<int> count_idx(strb_size, 0);
        for (int i = 1; i < strb_size; i++)
        {
            int k = count_idx[i - 1];
            while (k > 0 && b[k] != b[i])
            {
                k = count_idx[k - 1];
            }
            if (b[k] == b[i])
            {
                k++;
            }
            count_idx[i] = k;
        }

        string s;
        for (int i = 0; i < strb_size / stra_size + 2; i++)
        {
            s += a;
        }

        int n = 0;
        for (int i = 0; i < s.size(); i++)
        {
            while (n > 0 && b[n] != s[i])
            {
                n = count_idx[n - 1];
            }
            if (b[n] == s[i])
            {
                n++;
            }

            if (n == strb_size)
            {
                return i / stra_size + 1;
            }
        }

        return -1;
    }
};


int main()
{
    StringRepeat sr;

    string A = "abcd";
    string B = "cdabcdab";

    cout << " B is a substring of A that repeats: " << sr.repeatedStringMatch(A, B) << " times" << endl;

    A = "a";
    B = "aa";

    cout << " B is a substring of A that repeats: " << sr.repeatedStringMatch(A, B) << " times" << endl;



    return 0;

}
