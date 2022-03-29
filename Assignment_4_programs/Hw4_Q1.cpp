#include <iostream>
#include <string>

using namespace std;

// Function to implement the KMP algorithm
void KMP_Algorithm(string text, string pattern)
{
    int txt_len = text.length();
    int patt_len = pattern.length();

    // if pattern is an empty string
    if (patt_len == 0)
    {
        cout << "Empty Pattern String" << endl;
        return ;
    }

    // if text's length is less than that of pattern's
    if (txt_len < patt_len)
    {
        cout << "Pattern not found" << endl;
        return ;
    }

    // next[i] stores the index of the next best partial match
    int next[patt_len + 1];

    for (int i = 0; i < patt_len + 1; i++) {
        next[i] = 0;
    }

    for (int i = 1; i < patt_len; i++)
    {
        int j = next[i + 1];

        while (j > 0 && pattern[j] != pattern[i]) {
            j = next[j];
        }

        if (j > 0 || pattern[j] == pattern[i]) {
            next[i + 1] = j + 1;
        }
    }
// comparing the pattern string with text string by keeping track of matched and unmatched string
    for (int i = 0, j = 0; i < txt_len; i++)
    {
        if (text[i] == pattern[j])
        {
            if (++j == patt_len) {
                cout << "The Pattern matches the Text at index: " << i - j + 1 << endl;

            }
        }
        else if (j > 0)
        {
            j = next[j];
            i--;
        }
    }
}

// Driver function to test cases
main()
{
    string text = "ABCABAABCABAC";
    string pattern = "CAB";
    cout << "test case 1: "<< endl;
    cout << "Text:" << text << " and Pattern: " << pattern << endl;

    KMP_Algorithm(text, pattern);


    text = "THE";
    pattern = "TEST";
    cout << endl;
    cout << "test case 2: "<< endl;
    cout << "Text:" << text << " and Pattern: " << pattern << endl;

    KMP_Algorithm(text, pattern);

    text = "TESTING";
    pattern = "";
    cout << endl;
    cout << "test case 3: "<< endl;
    cout << "Text:" << text << " and Pattern: " << pattern << endl;

    KMP_Algorithm(text, pattern);

}
