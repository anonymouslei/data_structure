#include <iostream>

using namespace std;

typedef struct PolyNode *PolynomialNode;
struct PolyNode {
    int coef;
    int expon;
    PolynomialNode Next;
};

class Polynomial{
public:
    Polynomial()
    {
        head_ = new PolyNode;
        head_->Next = NULL;
    }
    Polynomial & operator = (const Polynomial & p1)
    {
        head_ = p1.head_;
        return * this;
    }
    Polynomial(Polynomial & P) {
        head_ = P.head_;
        head_->Next = P.head_->Next;
    }

    ~Polynomial()
    {
        delete head_;
    }

    void ReadPoly() {
        int num, coef, expon;
        cin >> num;
        PolynomialNode rear = head_;
        PolynomialNode t;

        while (num--) {
            cin >> coef >> expon;
            Attach(coef, expon, rear);
        }

        t = head_;
        head_ = head_->Next;
        delete t;
    }
    void ReadPoly(int input[]) {
        int num, coef, expon;
        num = input[0];
        PolynomialNode rear = head_;
        PolynomialNode t;

        for (int i = 1; i < num+1; ++i) {
            coef = input[2*i - 1];
            expon = input[2*i];
            Attach(coef, expon, rear);
        }

        t = head_;
        head_ = head_->Next;
        delete t;
    }

    void Attach(int coef, int expon, PolynomialNode & rear) {
        PolyNode *P = new PolyNode;
        P->coef = coef;
        P->expon = expon;
        P->Next = NULL;
        rear->Next = P;
        rear = P;
    }

    Polynomial operator*(const Polynomial & P2) {
        Polynomial P;
        PolynomialNode t1, t2, rear, t;
        int c, e;
        if (!head_ || !P2.head_)
            return P;

        t1 = head_;
        t2 = P2.head_;
        rear = P.head_;
        while (t2)  // 先用P1的第一项乘以P2, 得到P
        {
            Attach(t1->coef*t2->coef, t1->expon+t2->expon, rear);
            t2 = t2->Next;
        }
        t1 = t1->Next;
        while (t1)
        {
            t2 = P2.head_;
            rear = P.head_;
            while (t2) {
                e = t1->expon + t2->expon;
                c = t1->coef * t2->coef;
                while (rear->Next && rear->Next->expon > e) //持续判断，直到rear到达第一个比e小或者等于e的地址
                    rear = rear->Next;
                if (rear->Next && rear->Next->expon == e) { //如果系数相等
                    if (rear->Next->coef + c)
                        rear->Next->coef += c;
                    else { // 计算结果等于零，就把这一项删掉
                        t = rear->Next;
                        rear->Next = t->Next;
                        delete t;
                    }
                } else { // 小于，就申请新的节点，进行赋值
                    t = new PolyNode;
                    t->coef = c;
                    t->expon = e;
                    t->Next = rear->Next;
                    rear->Next = t;
                    rear = rear->Next;
                }
                t2 = t2->Next;
            }
            t1 = t1->Next;
        }

        t2 = P.head_;
        P.head_ = P.head_->Next;
        delete t2;
        return P;
    }

    Polynomial & operator+(const Polynomial & P2)
    {
        Polynomial P;
        PolynomialNode t1, t2, rear, tmp;
        int sum;

        t1 = head_;
        t2 = P2.head_;
//        P = Polynomial();
        rear = P.head_;
        while (t1 && t2) {
            if (t1->expon == t2->expon) {
                sum = t1->coef + t2->coef;
                if (sum)
                    Attach(sum, t1->expon, rear);
                t1 = t1->Next;
                t2 = t2->Next;
            } else if (t1->expon > t2 ->expon) {
                Attach(t1->coef, t1->expon, rear);
                t1 = t1->Next;

            } else {
                Attach(t2->coef, t2->expon, rear);
                t2 = t2->Next;

            }
        }
        while (t1) {
            Attach(t1->coef, t1->expon, rear);
            t1 = t1->Next;

        }
        while (t2) {
            Attach(t2->coef, t2->expon, rear);
            t2 = t2->Next;

        }
        rear ->Next = NULL;

        return P;
    }

    void Add(const Polynomial & P2, Polynomial & P)
    {
//        Polynomial P;
        PolynomialNode t1, t2, rear, tmp;
        int sum;

        t1 = head_;
        t2 = P2.head_;
//        P = Polynomial();
        rear = P.head_;
        while (t1 && t2) {
            if (t1->expon == t2->expon) {
                sum = t1->coef + t2->coef;
                if (sum)
                    Attach(sum, t1->expon, rear);
                t1 = t1->Next;
                t2 = t2->Next;
            } else if (t1->expon > t2 ->expon) {
                Attach(t1->coef, t1->expon, rear);
                t1 = t1->Next;

            } else {
                Attach(t2->coef, t2->expon, rear);
                t2 = t2->Next;

            }
        }
        while (t1) {
            Attach(t1->coef, t1->expon, rear);
            t1 = t1->Next;

        }
        while (t2) {
            Attach(t2->coef, t2->expon, rear);
            t2 = t2->Next;

        }
        rear ->Next = NULL;

        tmp = P.head_;
        P.head_ = P.head_->Next;
        delete tmp;
    }

    void Mul(const Polynomial & P2, Polynomial & P) {
//        Polynomial P;
        PolynomialNode t1, t2, rear, t;
        int c, e;
        if (!head_ || !P2.head_)
            return ;

        t1 = head_;
        t2 = P2.head_;
        rear = P.head_;
        while (t2)  // 先用P1的第一项乘以P2, 得到P
        {
            Attach(t1->coef*t2->coef, t1->expon+t2->expon, rear);
            t2 = t2->Next;
        }
        t1 = t1->Next;
        while (t1)
        {
            t2 = P2.head_;
            rear = P.head_;
            while (t2) {
                e = t1->expon + t2->expon;
                c = t1->coef * t2->coef;
                while (rear->Next && rear->Next->expon > e) //持续判断，直到rear到达第一个比e小或者等于e的地址
                    rear = rear->Next;
                if (rear->Next && rear->Next->expon == e) { //如果系数相等
                    if (rear->Next->coef + c)
                        rear->Next->coef += c;
                    else { // 计算结果等于零，就把这一项删掉
                        t = rear->Next;
                        rear->Next = t->Next;
                        delete t;
                    }
                } else { // 小于，就申请新的节点，进行赋值
                    t = new PolyNode;
                    t->coef = c;
                    t->expon = e;
                    t->Next = rear->Next;
                    rear->Next = t;
                    rear = rear->Next;
                }
                t2 = t2->Next;
            }
            t1 = t1->Next;
        }

        t2 = P.head_;
        P.head_ = P.head_->Next;
        delete t2;
    }
    void PrintPoly() {
        int flag = 0;
        PolynomialNode tmp = head_;

        if (!tmp) {
            cout << "0 0";
            return;
        }
        while (tmp) {
            if (!flag) flag = 1;
            else
                cout << " ";
            cout << tmp->coef << " " << tmp->expon;
            tmp = tmp->Next;
        }
        cout << endl;
    }

private:
    PolynomialNode head_;

};

int main() {
    Polynomial P1, P2;
    int input1[5] = {2, 2, 1, 1, 0};
    int input2[5] = {2, -2, 1, -1, 0};
//    int input1[9] = {4, 3, 4, -5, 2, 6, 1, -2, 0};
//    int input2[7] = {3, 5, 20, -7, 4, 3, 1};

    P1.ReadPoly(input1);
    P2.ReadPoly(input2);
//    Polynomial P5 = P2;
    Polynomial P3;
    Polynomial P4;
    P1.Add(P2, P3);
//    Polynomial P3 = P1 + P2;
//    Polynomial P4 = P1 * P2;
    P1.Mul(P2, P4);
    P4.PrintPoly();
    P3.PrintPoly();
    return 0;
}