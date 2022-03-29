#include <vector>           // header file for utilizing vector type data
#include <iostream>        // header file for input and output stream
#include <unordered_map>  // header file for using hashmap

using namespace std;     // creating namespace for standard input/output

// This program uses one for loop that iterates through array nums once, time complexity is O(n)

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)  // declaring a vector function with two arguments
    {                                                  // integer vector nums and integer value target
        unordered_map<int, int> indices;               // declaring a hashmap variable indices that contains key-value pair
        for (int i = 0; i < nums.size(); i++)          // iterating through the array nums for accessing each element
        {
            int match = target - nums[i];              // initializing an integer variable match which is target - element of nums
            if (indices.find(match) != indices.end())  // finding value of match in the hashmap indices
            {
                return {indices[match], i};            // If match value is found in indices then return index of nums element and
            }                                          // index of match value that add upto to given target.
            indices[nums[i]] = i;                      // if element not found in hashmap then add the values to hashmap indices
                                                       // by iterating through nums where key is the element and values is the index
        } return {};                                   // return type vector

    }
};

int main()
{
    Solution sol;                   // creating object sol for solution class
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


