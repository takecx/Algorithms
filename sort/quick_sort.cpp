#include <iostream>
#include <vector>

using namespace std;

void QuickSort(vector<int> &values, int leftIndex, int rightIndex)
{
    // 再帰終了条件
    if (rightIndex - leftIndex <= 1)
        return;

    // ピボット（ランダムらしいけど真ん中にする）
    int pivotIndex = (leftIndex + rightIndex) / 2;
    int pivotVal = values[pivotIndex];
    // pivotを最右要素と入れ替える
    swap(values[pivotIndex], values[rightIndex - 1]);

    // pivotより左はより小さい数、右はより大きい数になるようにする
    int i = leftIndex;
    for (int j = leftIndex; j < rightIndex - 1; j++)
    {
        if (values[j] < pivotVal)
        {
            swap(values[i], values[j]);
            i++;
        }
    }
    // pivotを適切な位置(i)に戻す
    swap(values[i], values[rightIndex - 1]);

    // 再帰的にソート
    QuickSort(values, leftIndex, i);      // pivotより小さい数群
    QuickSort(values, i + 1, rightIndex); // pivotより大きい数群
}

void ShowValues(vector<int> values)
{
    for (int i = 0; i < values.size(); i++)
    {
        cout << values[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> values{3, 6, 4, 1, 2, 8, 5};
    cout << "before" << endl;
    ShowValues(values);

    QuickSort(values, 0, values.size());

    cout << "after" << endl;
    ShowValues(values);
}