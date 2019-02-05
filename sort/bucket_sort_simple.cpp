#include <iostream>
#include <vector>

using namespace std;

static const int MAX = 100000;

void ShowValues(vector<int> values)
{
    for (int i = 0; i < values.size(); i++)
    {
        cout << values[i] << " ";
    }
    cout << endl;
}

/*
計数ソート(O(n+A))
ただし、ソート対象の値は1からAまでの整数とする
A=O(n)とすると計数ソートはO(n)となる
*/
int main()
{
    vector<int> values{3, 6, 2, 5, 7, 1, 4, 7, 6, 2, 4, 6};
    ShowValues(values);

    // 対応するバケツにいれていく
    int bucket[MAX] = {0};
    for (int i = 0; i < values.size(); i++)
    {
        bucket[values[i]]++;
    }

    // 小さい順に出力していく
    vector<int> sortedValues;
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < bucket[i]; j++)
        {
            sortedValues.push_back(i);
        }
    }

    ShowValues(sortedValues);
}