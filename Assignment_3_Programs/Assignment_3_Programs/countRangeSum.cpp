#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <iterator>
using namespace std;



class RangeSum
{
public:
    typedef vector<long long int> Pii;
    typedef Pii :: iterator Pit;
    int l, u;
    int countRangeSum(vector<int>& nums, int lower, int upper) {

        int n = nums.size() ;
        Pii x(n + 1, 0);

        int res = 0;
        l = lower , u = upper;

        for(int i = 0; i < n ; i ++)
            x[i + 1] = x[i] + nums[i];

        merge(x.begin() , x.end() , res);
        return res;
    }

    void merge(Pit beg , Pit end , int& res){

        if(end - beg <= 1)
            return;

        auto mid = beg + (end - beg) / 2;

        merge(beg , mid , res);
        merge(mid , end , res);

        auto j = mid , k = mid;
        for(auto i = beg ; i != mid ; i++){

            while(j != end && *j - *i  < l)
                j++;
            while(k != end && *k - *i  <= u)
                k++;

            res += k - j;

        }

        inplace_merge(beg , mid, end);

    }
};

main()
{
    RangeSum rs;
    vector<int> range_sums = {-2,5,-1};
    int l_bound = -2;
    int up_bound = 2;
    int output = rs.countRangeSum(range_sums, l_bound, up_bound);
    cout << output;

}
