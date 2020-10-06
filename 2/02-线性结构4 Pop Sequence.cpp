/*
 * 这道题毫无思路，参考网上思路
 *
 * 思路： 1. 把第一个数字压入stack
          2. 循环（capacity of stack && pop sequence中的所有元素都比较完了）
				若一致： stack pop, 
						pop sequence + 1
				若不一致：
						按顺序压入下一个进入stack
		 3.若Pop sequence所有元素都比较了 =》YES
			否则：NO
 */
 #include <iostream>
#include <vector>
#include <stack>

using std::cin;
using std::vector;
using std::stack;

class PopSequence {
public:
    void input(); 
    void judgment();

private:
    int maxCapacity_;
    int lengthOfSeq_;
    int numOfSeq_;
    vector<vector<int>> sequences_;
};

void PopSequence::input() {
    cin >> maxCapacity_ >> lengthOfSeq_ >> numOfSeq_;
    for (size_t i = 0; i < numOfSeq_; i++)
    {
        vector<int> tmp;
        for (size_t j = 0; j < lengthOfSeq_; j++)
        {
            int a;
            cin >> a;
            tmp.push_back(a);
        }
        sequences_.push_back(tmp);
    }
}

void PopSequence::judgment() {
    for (size_t i = 0; i < numOfSeq_; i++)
    {
        int currentNum = 1;
        stack<int> stackSeq;
        stackSeq.push(currentNum);
        currentNum++;

        vector<int> sequence = sequences_[i];
        int num = 0;

        while (num < lengthOfSeq_ && stackSeq.size() != maxCapacity_+1)
        {
            if (!stackSeq.empty() && (stackSeq.top() == sequence[num]))
            {
                stackSeq.pop();
                num++;
            } else {
                stackSeq.push(currentNum);
                currentNum++;
            }
            
        }

        if (num == lengthOfSeq_)
        {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }
    
}

int main() {
    PopSequence test;
    test.input();
    test.judgment();
    return 0;

}