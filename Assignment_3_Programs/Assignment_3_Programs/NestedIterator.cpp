#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;
class NestedInteger {
public:
      bool isInteger() const;

      int getInteger() const;

      const vector<NestedInteger> &getList() const;
  };

class NestedIterator {
private:
    queue<int> q;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        addList(nestedList);
    }

    void addList(vector<NestedInteger> &nestedList)
    {
        for(int i=0; i<nestedList.size(); i++)
        {
            if(nestedList[i].isInteger())
                q.push(nestedList[i].getInteger());
            else
                addList(nestedList[i].getList());
        }
        return;
    }

    int next() {
        int res = q.front();
        q.pop();
        return res;
    }

    bool hasNext() {
        return (!q.empty());
    }
};

main(){
    NestedIterator fl;
    vector<NestedInteger> nestedList = {1,[1,2],3};
    vector<int> flattened_list = fl.NestedIterator(nestedList)
    for (auto x : flattened_list)
    {
        cout << x < " ";

    }



}
