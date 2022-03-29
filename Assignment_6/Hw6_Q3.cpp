#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class PrimeFactors 
{
public:
    int countPrimes(int n)
    {
        vector<bool> prime_nums(n, false);
        int prime_count = 0;

        if (n <= 2) return 0;          

        for (int i = 2; i <= sqrt(n); i++)  
        {
            if (prime_nums[i] == false)
            {
                for (int j = i * i; j < n; j += i)
                {
                    prime_nums[j] = true;
                }
            }
        }


        for (int k = 2; k < n; k++)
        {
            if (prime_nums[k] == false)
            {
                prime_count += 1;
            }
        }
        return prime_count;

    }
};

int main()
{
    PrimeFactors pf;
    int n = 120;
    cout << pf.countPrimes(n) << endl;

    n = 10;
    cout << pf.countPrimes(n) << endl;

    n = 0;
    cout << pf.countPrimes(n) << endl;

    n = 2;
    cout << pf.countPrimes(n) << endl;


    return 0;
}