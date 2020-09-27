#include <iostream> 

using namespace std; 

int MaxSubseqSum4 (int A[], int N, int & firstPos, int & secondPos);

int main() { 
    int k;
    cin >> k;
    int a[k];
    for (int i = 0; i < k; i++){
        cin >> a[i];
    }
    int firstPos = 0;
    int secondPos = 0;
    int result = MaxSubseqSum4 (a, k, firstPos, secondPos);
    cout << result << ' ' << a[firstPos] << ' ' << a[secondPos] << endl;
    return 0; 
    }

int MaxSubseqSum4 (int A[], int N, int & firstPos, int & secondPos){
    int ThisSum, MaxSum;
    ThisSum = 0;
    MaxSum = -1;
    for (auto i = 0; i < N; i++){
        ThisSum += A[i];
        if (ThisSum > MaxSum)
        {
            MaxSum = ThisSum;
            secondPos = i;
        }
        else if(ThisSum < 0)
        {
            ThisSum = 0;
        }
    }
    if (MaxSum < 0)
    {
        firstPos= 0;
        secondPos = N-1;
        return 0;
    }
    int tmp = MaxSum;
    for (auto i = secondPos; i >= 0; i--)
    {
        tmp -= A[i];
        if(tmp == 0)
        {
            firstPos = i;
        }
    }
    return MaxSum;
}