#include <iostream>
#include <vector>

using namespace std;

void ShowValues(vector<int> values)
{
    for (int i = 0; i < values.size(); i++)
    {
        cout << values[i] << " ";
    }
    cout << endl;
}

// ヒープ作成(O(nlogn))
void CreateHeap(vector<int> &values)
{
    vector<int> temp;
    int index;
    for (int i = 0; i < values.size(); i++)
    {
        // 最後に追加
        temp.push_back(values[i]);
        // ShowValues(temp);
        index = temp.size() - 1;
        // ルートにたどり着くまで
        while (index > 0)
        {
            // ノードkの親ノードのインデックス（(k-1)/2）
            int parentIndex = (index - 1) / 2;
            if (temp[parentIndex] <= temp[index])
            {
                // cout << "Swap : " << temp[parentIndex] << " <--> " << temp[index] << endl;
                swap(temp[parentIndex], temp[index]);
                index = parentIndex;
            }
            else
            {
                // 途中でヒープ条件を満たした場合は終了
                break;
            }
        }
    }
    // 結果
    for (int i = 0; i < values.size(); i++)
    {
        values[i] = temp[i];
    }
}

// ルートの要素をヒープ条件にあうように移動させる(O(logn))
void AdjustHeapTop(vector<int> &heap)
{
    // ルート要素は添字0なので子供を算出しても添字0になってしまう

    int index = 0;
    while (index < heap.size() - 1)
    {
        int child1 = index == 0 ? 1 : heap[index * 2];
        int child2 = index == 0 ? 2 : heap[index * 2 + 1];
        int childIndex = child1 > child2 ? index * 2 : index * 2 + 1;
        if (heap[index] < heap[childIndex])
        {
            swap(heap[index], heap[childIndex]);
            index = childIndex;
        }
        else
        {
            break;
        }
    }
}

// ルート要素を取り出してヒープを再構築する(O(logn))
int pop(vector<int> &heap)
{
    int result = heap[0];

    // ヒープの再構築
    // 最後の要素をトップにもってくる
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();

    // ヒープを再構築
    // これだと全要素分やるとO(n^2logn)になっちゃう
    // CreateHeap(heap);

    // ルートに移動させた要素だけに着目する
    AdjustHeapTop(heap);

    return result;
}

// ヒープソート(O(nlogn))
void HeapSort(vector<int> &values)
{
    vector<int> temp = values;
    for (int i = 0; i < values.size(); i++)
    {
        values[i] = pop(temp);
    }
}

int main()
{
    vector<int> values{3, 2, 8, 4, 6, 1, 5};

    // ヒープを構築
    CreateHeap(values);
    ShowValues(values);

    HeapSort(values);
    ShowValues(values);
}