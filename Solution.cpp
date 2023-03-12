#include <bits/stdc++.h>
using namespace std;

int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("./input-small.txt", "r", stdin);
    // freopen("./output-small.txt", "w", stdout);
    // #endif

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int N, D;
        cin >> N >> D;

        int maximumPlantation = (N * 0.4) - 1;
        long long totalIncome = 0;
        int remainingTrees = N;

        vector<vector<int>> treeData = {
            {12000, 10},
            {10000, 6},
            {27500, 15},
            {7500, 5},
            {8000, 15}};

        vector<int> treeIncome;

        for (auto it : treeData)
        {
            long long income = it[0] * (D / it[1]);
            treeIncome.push_back(income);
        }

        sort(treeIncome.begin(), treeIncome.end(), greater<int>());

        for (auto it : treeIncome)
        {
            totalIncome += it;
            remainingTrees--;
        }

        int index = 0;
        while (remainingTrees > 0)
        {
            if (remainingTrees > maximumPlantation)
            {
                totalIncome += (treeIncome[index] * maximumPlantation);
                remainingTrees -= maximumPlantation;
            }
            else
            {
                totalIncome += (treeIncome[index] * remainingTrees);
                remainingTrees = 0;
                break;
            }
            index++;
        }
        cout << "Case #" << (i + 1) << ": " << totalIncome << endl;
    }
    return 0;
}