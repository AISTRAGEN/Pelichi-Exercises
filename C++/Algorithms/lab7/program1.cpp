#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> calculateMaxWeightPath(vector<vector<int>>& grid, int& maxWeight) 
{
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<int>> maxWeightMatrix(rows, vector<int>(cols, 0));
    maxWeightMatrix[0][0] = grid[0][0];
    for (int i = 1; i < rows; ++i) 
    {
        maxWeightMatrix[i][0] = maxWeightMatrix[i - 1][0] + grid[i][0];
    }
    for (int j = 1; j < cols; ++j) 
    {
        maxWeightMatrix[0][j] = maxWeightMatrix[0][j - 1] + grid[0][j];
    }
    for (int i = 1; i < rows; ++i) 
    {
        for (int j = 1; j < cols; ++j) 
        {
            maxWeightMatrix[i][j] = grid[i][j] + max(maxWeightMatrix[i - 1][j], maxWeightMatrix[i][j - 1]);
        }
    }
    maxWeight = maxWeightMatrix[rows - 1][cols - 1];
    return maxWeightMatrix;
}

int main() 
{
    vector<vector<int>> grid = 
    {
        {7, 10, 8, 20},
        {12, 13, 17, 14},
        {3, 20, 27, 9},
        {5, 8, 25, 16}
    };
    int maxWeight;
    auto maxWeightPath = calculateMaxWeightPath(grid, maxWeight);
    cout << "Матрица с максимальной массой пути:\n";
    for (const auto& row : maxWeightPath) {
        for (int weight : row) {
            cout << weight << "\t";
        }
        cout << endl;
    }
    cout << "Максимальный вес пути: " << maxWeight << endl;
    return 0;
}