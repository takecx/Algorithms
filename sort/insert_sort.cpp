#include <iostream>
#include <vector>

int main()
{
    // g++ -std=c++11 -o insert_sort.out insert_sort.cpp

    // # 挿入ソート(O(n^2))
    // > 前から順番に、i 番目の要素を適切な場所へ挿入することを繰り返す

    // ```
    // Before: 4 1 3 5 2
    // After Step 1: 1 4 3 5 2
    // After Step 2: 1 3 4 5 2
    // After Step 3: 1 3 4 5 2
    // After Step 4: 1 2 3 4 5
    // ```

    std::vector<int> values{4, 1, 3, 7, 5, 2};
    for (int i = 0; i < values.size(); i++)
        std::cout << values[i] << " ";
    std::cout << std::endl;

    for (int i = 1; i < values.size(); i++)
    {
        int value = values[i];

        int j = i;
        for (; j > 0; --j)
        {
            if (values[j - 1] > value)
            {
                values[j] = values[j - 1];
            }
            else
                break;
        }
        values[j] = value;
    }
    for (int i = 0; i < values.size(); i++)
        std::cout << values[i] << " ";
    std::cout << std::endl;
}