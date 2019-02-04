#include <iostream>
#include <vector>

void ShowValues(std::vector<int> values, int leftIndex, int rightIndex)
{
    for (int i = leftIndex; i < rightIndex; i++)
    {
        std::cout << values[i] << " ";
    }
    std::cout << std::endl;
}

void MergeSort(std::vector<int> &values, int leftIndex, int rightIndex)
{
    std::cout << "(before)" << std::endl;
    ShowValues(values, leftIndex, rightIndex);

    // 再帰の終了条件
    if (rightIndex - leftIndex == 1)
        return;

    int midIndex = leftIndex + (rightIndex - leftIndex) / 2;

    // 再帰(左側をソート）
    MergeSort(values, leftIndex, midIndex);
    // 再帰(右側をソート）
    MergeSort(values, midIndex, rightIndex);

    std::vector<int> sortTargetValues;
    for (int i = leftIndex; i < midIndex; ++i)
    {
        sortTargetValues.push_back(values[i]);
    }
    for (int i = rightIndex - 1; i >= midIndex; --i)
    {
        sortTargetValues.push_back(values[i]);
    }

    // マージ処理
    int iter_left = 0;
    int iter_right = (int)sortTargetValues.size() - 1;
    for (int i = leftIndex; i < rightIndex; i++)
    {
        if (sortTargetValues[iter_left] <= sortTargetValues[iter_right])
        {
            values[i] = sortTargetValues[iter_left];
            iter_left++;
        }
        else
        {
            values[i] = sortTargetValues[iter_right];
            iter_right--;
        }
    }

    std::cout << "(after)" << std::endl;
    ShowValues(values, leftIndex, rightIndex);
}

int main()
{
    std::vector<int> values{5, 1, 3, 4, 6, 9, 2};

    MergeSort(values, 0, values.size());
}