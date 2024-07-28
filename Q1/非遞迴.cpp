#include <iostream>
#include <stack>


using namespace std;

// 非遞迴實現的阿克曼函數
int ackermann_non_recursive(int m, int n) {
    // 使用堆疊模擬遞迴
    stack<pair<int, int>> s;//創建了一個名為S的堆疊
  
    s.push({m, n}); // 初始情況下將 (m, n) 入堆疊
    
    while (!s.empty())//確保在訪問 top 或調用 pop 之前，堆疊中有元素存在=進入遞迴。
      {
        
        auto [m, n] = s.top(); // 自動類型推導取得堆疊頂部的 m 和 n
        s.pop(); // 移除頂部元素
        
        if (m == 0)
        {
            // 如果 m 為 0，更新 n 值
            n = n + 1;
            if (!s.empty())
            {
                s.top().second = n; // 更新堆疊中上層元素的 n 值
            }
        } 
          
        else if (n == 0) 
        {
            // 如果 n 為 0，將 (m-1, 1) 推入堆疊
            s.push({m - 1, 1});
        } 

          
        else 
        {
            // 推入 (m-1, 0) 和 (m, n-1) 進行進一步計算
            s.push({m - 1, 0});
            s.push({m, n - 1});
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
