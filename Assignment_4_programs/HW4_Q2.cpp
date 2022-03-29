#include <iostream>
#include <string>
#define NULL_CHAR

using namespace std;

class MatchNeedle{
 public:
    int string_match(string haystack, string needle)
    {
        int haystack_len = haystack.length();
        int needle_len=needle.length();
        int count = 0;
        if(needle == "NULL_CHAR")
         {
                return 0 ;
         }
        if(haystack.length()<needle_len)
        {
            return -1;
        }
        for(int i=0 ; i<=haystack_len - needle_len ; i++)
        {
            if(haystack[i]==needle[0])
            {
                count=0;

                for(int j=0; j<needle_len; j++)
                {
                    if(haystack[i+j]== needle[j])
                    {
                            count++;
                    }
                }
                if(count == needle_len)
                {
                        return i;
                }
            }
        }
        return -1;

    }
};



int main()
{
    MatchNeedle mn;

    string haystack = "hello";
    string needle = "ll";

    cout << "test case 1" <<endl;
    cout << "Haystack: " << haystack << " and Needle: " << needle << endl;
    int result = mn.string_match(haystack, needle);
    cout<< "Needle found in Haystack at index: " << result<< endl;

    haystack = "aaaaa";
    needle = "bba";

    cout << endl;
    cout << "test case 2" <<endl;
    cout << "Haystack: " << haystack << " and Needle: " << needle << endl;
    result = mn.string_match(haystack, needle);
    cout<< "Needle found in Haystack at index: " << result<< endl;

    haystack = "";
    needle = "";

    cout << endl;
    cout << "test case 3" <<endl;
    cout << "Haystack: " << haystack << " and Needle: " << needle << endl;
    result = mn.string_match(haystack, needle);
    cout<< "Needle found in Haystack at index: " << result<< endl;



    return 0;

}
