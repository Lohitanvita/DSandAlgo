#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class FreqStack 
{
public:
    unordered_map <int, int> freq_count;      // declared a hashmap to store count of each element
    unordered_map <int, stack<int>> freq_element; // declared a hashmap with int as key and stack as value to keep track of element indices with their frequency count
    int maximum_freq;

    FreqStack()
    {
        maximum_freq = 0;
    }

    void push(int val) 
    {
        int frequency = freq_count[val] + 1;       // updating the hashmap with frequency count of pushed integer value   
        freq_count[val] = frequency;
        freq_element[frequency].push(val);
        maximum_freq = max(maximum_freq, frequency);   // updating count of integer  with maximum occurance

    }

    int pop() 
    {
        int result = freq_element[maximum_freq].top();  // popping the element from stack top with maximum frequency count
        freq_element[maximum_freq].pop();
        freq_count[result] -= 1;
        if (freq_element[maximum_freq].empty())
        {
            maximum_freq -= 1;                         // updating the frequency count after element pop
        }

        return result;

    }
};


/*int main()                         // driver code
{
    FreqStack* obj = new FreqStack();
    obj->push(5);
    obj->push(7);
    obj->push(5);
    obj->push(7);
    obj->push(4);
    obj->push(5);
    cout << obj->pop() << ", ";
    cout << obj->pop() << ", ";
    cout << obj->pop() << ", ";
    cout << obj->pop();
}*/