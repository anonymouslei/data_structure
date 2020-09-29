#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#define MaxSize 100000

/*
 * 刚开始的时候使用string来存储地址，然后想再排序，再reverse.后来发现这样子太麻烦了，
 * 没有想到很好的排序的方法。后来参考网上的资料发现可以直接用hash表的思想，节点地址左右
 * index。但是也不知道这是不是最好的方法，是不是浪费太多空间了
 * 参考网上的C++代码，直接用了reverse函数
 */
using namespace std;

//typedef struct LinkedNode * LinkedNodeP;
struct LinkedNode {
    int data, next, pos;
};

class ReversingLinkedList {
public:

    void readLinkedList() {
        cin >> front_ >> num_ >> lengthOfSublist_;
        for (int i = 0; i < num_; ++i) {
            int current, data, next;
            cin >> current >> data >> next;

            nodes_[current].pos = current;
            nodes_[current].data = data;
            nodes_[current].next = next;
        }
        int tmp = front_;
        while (tmp != -1) {
            lists_.push_back(nodes_[tmp]);
            tmp = nodes_[tmp].next;
        }
        num_ = lists_.size();
    }

    void reverseLink() {
        for (int i = 0; i < num_/lengthOfSublist_; ++i) { //使用list_.size()而不是num_就会解决当多余节点不在链表上的情况
            std::reverse(lists_.begin()+i*lengthOfSublist_, lists_.begin()+(i+1)*lengthOfSublist_);
        }
    }

    void printResult() {
        for (int i = 0; i < num_; i ++) {
            cout << setw(5) << setfill('0') << lists_[i].pos;
            cout << " " << lists_[i].data << " ";
            if (i == num_-1)
                cout << -1 << '\n';
            else
                cout << setw(5) << setfill('0') << lists_[i+1].pos << '\n';
        }
    }

private:
    int num_;
    int lengthOfSublist_;
    int front_;
    LinkedNode nodes_[MaxSize];
    vector<LinkedNode> lists_;

};

int main() {
    ReversingLinkedList test;
    test.readLinkedList();
    test.reverseLink();
    test.printResult();
    return 0;
}

/*
函数方法：
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

const int MaxSize = 100000 + 100;

/*
 * 刚开始的时候使用string来存储地址，然后想再排序，再reverse.后来发现这样子太麻烦了，
 * 没有想到很好的排序的方法。后来参考网上的资料发现可以直接用hash表的思想，节点地址左右
 * index。但是也不知道这是不是最好的方法，是不是浪费太多空间了
 * 参考网上的C++代码，直接用了reverse函数

using namespace std;

struct LinkedNode {
    int data, next, pos;
};

LinkedNode nodes_[MaxSize];
vector<LinkedNode> lists_;

int main() {
    int front_, num_, lengthOfSublist_;

    cin >> front_ >> num_ >> lengthOfSublist_;
    for (int i = 0; i < num_; ++i) {
        int current, data, next;
        cin >> current >> data >> next;

        nodes_[current].pos = current;
        nodes_[current].data = data;
        nodes_[current].next = next;
    }
    int tmp = front_;
    while (tmp != -1) {
        lists_.push_back(nodes_[tmp]);
        tmp = nodes_[tmp].next;
    }

    for (int i = 0; i < (int)lists_.size()/lengthOfSublist_; ++i) { //使用list_.size()而不是num_就会解决当多余节点不在链表上的情况
        std::reverse(lists_.begin()+i*lengthOfSublist_, lists_.begin()+(i+1)*lengthOfSublist_);
    }

    for (int i = 0; i < lists_.size(); i ++) {
        cout << setw(5) << setfill('0') << lists_[i].pos;
        cout << " " << lists_[i].data << " ";
        if (i == lists_.size()-1)
            cout << -1 << '\n';
        else
            cout << setw(5) << setfill('0') << lists_[i+1].pos << '\n';
    }
}
 */

00100 1 1
00100 4 -1
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218