#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;


class ScoreMax {
public:
    int gcd(int a, int b) {
        int temp;
        while (b) {
            temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }
    int ones(int x) {
        int num = 0;
        while (x) {
            num += (x & 1);
            x = x >> 1;
        }
        return num;
    }
    int maxScore(vector<int>& nums) {
        // dp
        int t = nums.size();
        vector<int> arr(1 << t, 0);
        int g[14][14] = { 0 };
        // precount gcd,
        for (int i = 0; i < t; i++) {
            for (int j = i + 1; j < t; j++) {
                g[i][j] = gcd(nums[i], nums[j]);
            }
        }

        // dp with bitmask
        int temp, temp1, temp2;
        for (int i = 1; i < (1 << t); i++) {
            temp = ones(i);
            if ((temp & 1) == 0) {
                for (int j = 0; j < t; j++) {
                    if (i & (1 << j)) {
                        temp1 = i ^ (1 << j);
                        for (int k = j + 1; k < t; k++) {
                            if (i & (1 << k)) {
                                temp2 = temp1 ^ (1 << k);
                                arr[i] = max(arr[i], arr[temp2] + g[j][k] * (temp / 2));
                            }
                        }
                    }
                }
            }
        }


        return arr[(1 << t) - 1];
    }
};

int main()
{
    ScoreMax sm;
    vector<int> nums = { 1,2 };
    int result = sm.maxScore(nums);
    cout << result << endl;

    nums = { 1,2,3,4,5,6 };
    result = sm.maxScore(nums);
    cout << result << endl;
}