#include <iostream>
#include <string>
#include <vector>

using namespace std;


class PrefixString {
public:
    string longestPrefix(string s)
    // Returns length of the longest prefix which is also suffix and the two do not overlap
     {
        vector<int>prefix_suffix(s.size());
        int i = 0,j = 1;
        while(j < s.size())
        {
            if(s[i]==s[j])
            {
                prefix_suffix[j] = i+1;
                i++;j++;
            }
            else
            {
                if(i==0)
                {
                    j++;
                }
                else
                {
                    i = prefix_suffix[i-1];
                }
            }
        }

        string res="";

        for(int k=0; k< prefix_suffix[prefix_suffix.size()-1]; k++)
        {
            res+=s[k];
        }
        return res;
    }
};






// Driver program to test above function
int main()
{
    PrefixString ps;

    string s = "ababab";
    cout << ps.longestPrefix(s)<< endl;

    s = "level";
    cout << ps.longestPrefix(s)<< endl;

    return 0;
}


