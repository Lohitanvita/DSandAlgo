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
        for (int i = 0; i < strb_size / stra_size + 2; i++) {
            s += a;
        }

        int k = 0;  // no need a array
        for (int i = 0; i < s.size(); i++) {
            while (k > 0 && b[k] != s[i]) {
                k = count_idx[k - 1];
            }
            if (b[k] == s[i]) {
                k++;
            }
            //cout << k << " ";
            if (k == strb_size) return i / a.size() + 1;
        }
        return -1;
    }
};


/*int main()
{
    string A = "abcd";
    string B = "cdabcdab";

    StringRepeat sr;
    cout << sr.repeatedStringMatch(A, B);


    return 0;

}*/
