#include <iostream>
#include <vector>
#include <set>

using namespace std;




class ArrayGCD {
public:

    int gcd(int a, int b) {
        // Greatest Common Divisor
        while (b) {
            int r = a % b;
            a = b;
            b = r;
        }
        return a;
    }
    bool isGoodArray(vector<int>& nums) {
        // sort and remove duplicate.
        auto nums_set = set<int>(nums.begin(), nums.end());
        nums = vector<int>(nums_set.begin(), nums_set.end());

        // special case.
        if (nums[0] == 1) { return true; }
        else if (nums.size() < 2) { return false; }

        // calculate gcd
        int c = gcd(nums[0], nums[1]), i = 2;
        while (c != 1 and i < nums.size()) {
            c = gcd(c, nums[i]);
            i++;
        }
        return c == 1;
    }
};


int main()
{
    ArrayGCD agcd;
    vector<int> nums = { 12,5,7,23 };
    bool result = agcd.isGoodArray(nums);
    if (result == 1)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    nums = { 3, 6 };
    result = agcd.isGoodArray(nums);
    if (result == 1)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }




}