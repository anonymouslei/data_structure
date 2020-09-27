#include <iostream> 

using namespace std; 

int MaxSubseqSum4 (int A[], int N);

int main() { 
    int k;
    cin >> k;
    int a[k];
    for (int i = 0; i < k; i++){
        cin >> a[i];
    }
    int result = MaxSubseqSum4 (a, k);
    cout << result;
    return 0; 
    }

int MaxSubseqSum4 (int A[], int N){
    int ThisSum, MaxSum;
    int i;
    ThisSum = MaxSum = 0;
    for (i = 0; i < N; i++){
        ThisSum += A[i];
        if (ThisSum > MaxSum)
            MaxSum = ThisSum;
        else if(ThisSum < 0)
            ThisSum = 0;
    }
    return MaxSum;

}