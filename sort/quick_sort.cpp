#include <iostream>
#include <vector>

using namespace std;

/*
クイックソート(最悪はO(n^2)だがほとんどすべての場合でO(nlogn))
入力配列から適当にpivotを選び、pivotの左はより小さな数、右はより大きな数となるようにソートする
https://qiita.com/drken/items/44c60118ab3703f7727f#6-%E3%82%AF%E3%82%A4%E3%83%83%E3%82%AF%E3%82%BD%E3%83%BC%E3%83%88-%E4%B9%B1%E6%8A%9E%E3%82%A2%E3%83%AB%E3%82%B4%E3%83%AA%E3%82%BA%E3%83%A0%E3%81%AE%E3%82%88%E3%81%84%E9%A1%8C%E6%9D%90
*/
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