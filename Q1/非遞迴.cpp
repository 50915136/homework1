//程式碼皆由用chatGTP撰寫，由Dev C++編譯執行
#include <iostream>
#include <stack>
#include <utility> 

using namespace std;

int ackermann_non_recursive(int m, int n) {
    stack<pair<int, int> > s; //創建了一個名為s的堆疊
    
    s.push(make_pair(m, n)); 
    
    while (!s.empty())
        {
        pair<int, int> top = s.top();
        s.pop();//移除頂部的元素
        m = top.first;//first 和 second 分別代表這個 pair 中的第一個和第二個元素，top.first 的值賦給變量 m。
        n = top.second;//top.second 的值賦給變量 n。
        
        if (m == 0) //如果m=0，則回傳n+1
        {
            n = n + 1;
            if (!s.empty())
            {
                s.top().second = n;//將top.second 的值替換成新的n。
            }
        } 
        else if (n == 0)//如果n=0，則回傳A(m - 1, 1)的結果
        {
            s.push(make_pair(m - 1, 1));
        }
        else //當n不為0且m也不為0時，需要計算 A(m - 1, A(m, n - 1))。
        {
            s.push(make_pair(m - 1, 0));
            s.push(make_pair(m, n - 1));
        }
    }

    return n;
}

int main() {
    int m, n;
    cout << "輸入 m 跟 n: ";
    cin >> m >> n;
    cout << "Ackermann(" << m << ", " << n << ") = " << ackermann_non_recursive(m, n) << endl;
    return 0;
}
