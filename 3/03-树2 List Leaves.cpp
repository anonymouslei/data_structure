#include <iostream>
#include <vector>
#include <queue>

#define MaxTree 10
#define Tree int
#define Null -1

using namespace std;

struct TreeNode {
    Tree data;
    Tree Left;
    Tree Right;
};

class ListLeaves {
public:
    void buildTree() {
        int n;
        cin >> n;
        int check[MaxTree];
        for (int i = 0; i < n; ++i)    check[i] = 0;
        for (int i = 0; i < n; ++i) {
            T_[i].data = i;
            char j, k;
            cin >> j >> k;
            if (j != '-') {
                T_[i].Left = j - '0';
                check[T_[i].Left] = 1;
            } else
                T_[i].Left = Null;

            if (k != '-') {
                T_[i].Right = k - '0';
                check[T_[i].Right] = 1;
            } else
                T_[i].Right = Null;
        }
        for (int i = 0; i < n; ++i) {
            if (!check[i]) {
                root_ = i;
                break;
            }
        }
    }

    void printLeaves() {
        deque<int> Q; // queue可以访问两端，但是只能修改队头。
                      // deque可以放问两端，并且可以在队首队尾删除和插入元素
        Q.push_back(root_);
        while (!Q.empty()) {
            int node = Q.front();
            Q.pop_front();
            if (T_[node].Right == Null && T_[node].Left == Null) {
                if (!Q.empty())
                    cout << T_[node].data << ' ';
                else
                    cout << T_[node].data;
            }
            if (T_[node].Left != Null)
                Q.push_back(T_[node].Left);
            if (T_[node].Right != Null)
                Q.push_back(T_[node].Right);
        }
    }

private:
    TreeNode T_[MaxTree];
    int root_;
};

int main() {
    ListLeaves test;
    test.buildTree();
    test.printLeaves();

    return 0;
}