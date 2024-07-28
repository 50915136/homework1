#include <iostream>
using namespace std;

//阿克曼函數
int ackermann(int m, int n) 
{
    if (m == 0) 
    {
        return n + 1;//如果m=0，則回傳n + 1
    }
    else if (n == 0) 
    {
        return ackermann(m - 1, 1);//如果n=0，則回傳ackermann(m - 1, 1)的結果
    }
    else//如果是其他情況便開始遞迴，直到滿足m=0或n=0
    {
        return ackermann(m - 1, ackermann(m, n - 1));
    }
}

//主函數
int main() {
    int m, n;
    cout << "輸入 m 跟 n: ";
    cin >> m >> n;
    cout << "Ackermann(" << m << ", " << n << ") = " << ackermann(m, n) ;
    return 0;
}

