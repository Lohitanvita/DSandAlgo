#include <iostream>        // header file for input and output stream
#include <vector>          // header file for utilizing vector type data

using namespace std;       // creating namespace for standard input/output

//This program code uses two for loops one inside other and the time complexity is O(n^2)

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target) // declaring a vector function with two arguments integer vector nums and integer value target
    {
        vector<int> result;                           // declaring a integer vector result
        for(int i=0; i<nums.size(); i++)              // iterating through the array nums for accessing each element
        {
            int match = target - nums[i];             // initializing an integer variable match which is target - element of nums
            for(int j=i+1; j<nums.size(); j++)        // simultaneously iterating and comparing next element of nums
            {                                         // to check the values that adds upto target value.
                if(match == nums[j])                  // if the value mathces then pushing their respective indices into
                {                                     // results variable and returning to the function
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        } return result;

    }
};

int main()
{
    Solution sol;             // creating object sol for solution class
    vector<int> nums;
    int target;
    vector<int> result;

    // Below are four different test cases that are tested to verify the code logic
    nums = {2,7,11,15};
    target =9;
    result= sol.twoSum (nums, target);   // calling the twoSum function of solution class using sol obj.
    cout << "case 1: " << endl;
    cout << "The indices of values in nums = {2,7,11,15} that add upto  " << target << " are: " << endl;
    for (int x: result)
    {
        cout << x << " " << endl;
    }

    cout << "case 2: " << endl;
    nums= {3,3};
    target = 6;
    result = sol.twoSum (nums, target);
    cout << "The indices of values in nums= {3,3} that add upto  " << target << " are: " << endl;
    for (int x: result)
    {
        cout << x << " "<< endl;
    }

    cout << "case 3: " << endl;
    nums = {3,2,4};
    target = 7;
    result = sol.twoSum (nums, target);
    cout << "The indices of values in nums = {3,2,4} that add upto  " << target << " are: " << endl;
    for (int x: result)
    {
        cout << x << " "<< endl;
    }

    cout << "case 4: " << endl;
    nums = {-8,1,14};
    target = -7;
    result = sol.twoSum (nums, target);
    cout << "The indices of values in nums = {-8,1,14} that add upto  " << target << " are: " << endl;
    for (int x: result)
    {
        cout << x << ""<< endl;
    }
    return 0;

};
