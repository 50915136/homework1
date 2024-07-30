//程式碼皆由用chatGTP撰寫，由Dev C++編譯執行
#include <iostream>
using namespace std;

// 遞迴函數用來生成集合 S 的冪集
void generatePowerSet(int S[], int n, int index, int current[], int currentSize) 
//n 集合大小、index 是當前處理的元素索引、current[] 是暫時儲存當前子集的陣列、currentSize 是當前子集的大小。
{
  
    // 當前子集完成，輸出結果
    if (index == n) 
    {
        cout << "{ ";
        for (int i = 0; i < currentSize; ++i)
          {
            cout << current[i] << " ";
        }
        cout << "}" << endl;
        return;
    }

    // 選擇不包含當前元素的情況
    generatePowerSet(S, n, index + 1, current, currentSize);

    // 選擇包含當前元素的情況
    current[currentSize] = S[index];
    generatePowerSet(S, n, index + 1, current, currentSize + 1);
}

主函式
int main() {
    int n;
    cout << "輸入陣列大小: ";
    cin >> n;

    int S[n]; // 陣列大小由用戶輸入的數量決定
    cout << "輸入鎮列內容: ";
    for (int i = 0; i < n; ++i) {
        cin >> S[i];
    }

    int current[n]; // 保存當前子集的陣列
    cout << "The power set is:\n";
    
    // 計算冪集
    generatePowerSet(S, n, 0, current, 0);

    return 0;
}
