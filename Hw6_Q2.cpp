#include <iostream>
#include <vector>

using namespace std;

class HCFSolution {
public:
	int GCD(vector<int>& arr_nums)
	{
		int min_num = arr_nums[0];
		int max_num = arr_nums[0];
		for (int i = 0; i < arr_nums.size(); i++)   // iterating through input array till its length
		{
			min_num = min(min_num, arr_nums[i]);    // updating min_num with the minimum value of input array by comparing current element with last minimum element
			max_num = max(max_num, arr_nums[i]);    // similarly updating with the maximum number of input array
		}
		if (max_num % min_num == 0)                 // if the maximum number is divisible by minimum number then the minimum number is the greatest common divisor
		{
			return min_num;
		}
		else
		{
			int output = 0;                             // else iterating until minimum number to get the greatest number divisable by both minimum and maximum number of array
			for (int j = 1; j < min_num; j++)
			{
				if (min_num % j == 0 && max_num % j == 0)
				{
					output = max(output, j);                    // return the highest number number from 1 to min_num that is divisable with min and max_num
				}

			}return output;
		} return 1;
	}

};

int main()
{
	HCFSolution hcf;
	vector<int> nums = { 2, 5, 6, 9, 10 };
	cout << hcf.GCD(nums) << endl;

	nums = {7, 5, 6, 8, 3};
	cout << hcf.GCD(nums) << endl;

	nums = { 6, 7,9 };	
	cout << hcf.GCD(nums) << endl;

	return 0;

}
