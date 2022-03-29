#include <vector>
#include <iostream>
#include <unordered_map>


using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vec_result;
        for(int i=0; i<nums.size(); i++){
            int match = target - nums[i];
            for(int j=i+1; j<nums.size(); j++){
                if(match == nums[j]){
                    vec_result.push_back(i);
                    vec_result.push_back(j);
                    return vec_result;
                }
            }
        } return vec_result;

    }
};


int main(){
    Solution sol;
    vector<int> nums;
    int target;
    int som_input;
    vector<int> result;

    nums = {2,7,11,15};
    target =9;
    result= sol.twoSum (nums, target);
    for (int x: result){
            cout << x << " ";
    }

    nums= {3,3};
    target = 6;
    result = sol.twoSum (nums, target);
    for (int x: result){
            cout << x << " ";
    }


    nums = {3,2,4};
    target = 6;
    result = sol.twoSum (nums, target);
    for (int x: result){
            cout << x << " ";
    }


    nums = {-8,1,14};
    target = 6;
    result = sol.twoSum (nums, target);
    for (int x: result){
            cout << x << " ";
    }
    return 0;

};
