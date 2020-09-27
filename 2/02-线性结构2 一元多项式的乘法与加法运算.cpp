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
//        head_->coef = 0;
        head_->Next = NULL;
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
        //
        Polynomial P;
        PolynomialNode t1, t2, rear, t;
        int c, e;
        if (!head_ || P2.head_)
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
                    if (rear->Next->coef)
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
            }
            t1 = t1->Next;
        }

        t2 = P.head_;
        P.head_ = P.head_->Next;
        delete t2;
        return P;
    }

    Polynomial operator+(const Polynomial & P2)
    {
        Polynomial P;
        PolynomialNode t1, t2, rear, tmp;
        int sum;

        t1 = head_;
        t2 = P2.head_;
        P = Polynomial();
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
        tmp = P.head_; // 这个可能无法访问
        P.head_ = P.head_->Next;
        delete tmp;

        return P;
    }
    void PrintPoly();

private:
    PolynomialNode head_;

};

int main() {
//    int num_1, num_2;
//    cin >> num_1;
    Polynomial P1, P2, P3, P4;
    P1.ReadPoly();
    P2.ReadPoly();
    P3 = P1 + P2;
    P4 = P1 * P2;




//    for (auto i = 0; i < num_1; i++) {
//    }
    return 0;
}