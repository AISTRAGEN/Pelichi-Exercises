#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct PrevIndex 
{
    int row;
    int col;
    PrevIndex(int r = 0, int c = 0) : row(r), col(c) {}
};
int calculateLCS(const string& seq1, const string& seq2, vector<vector<int>>& lcsTable, vector<vector<PrevIndex>>& direction) {
    int length1 = seq1.size();
    int length2 = seq2.size();
    for (int i = 0; i <= length1; ++i) 
    {
        for (int j = 0; j <= length2; ++j) 
        {
            if (i == 0 || j == 0) 
            {
                lcsTable[i][j] = 0;
                direction[i][j] = PrevIndex();
            }
            else if (seq1[i - 1] == seq2[j - 1]) 
            {
                lcsTable[i][j] = lcsTable[i - 1][j - 1] + 1;
                direction[i][j] = PrevIndex(i - 1, j - 1);
            }
            else if (lcsTable[i - 1][j] >= lcsTable[i][j - 1]) 
            {
                lcsTable[i][j] = lcsTable[i - 1][j];
                direction[i][j] = PrevIndex(i - 1, j);
            }
            else 
            {
                lcsTable[i][j] = lcsTable[i][j - 1];
                direction[i][j] = PrevIndex(i, j - 1);
            }
            cout << "Step: (" << i << ", " << j << "), LCS Length: " << lcsTable[i][j] << endl;
        }
    }
    return lcsTable[length1][length2];
}

void reconstructLCS(int i, int j, const string& seq, const vector<vector<PrevIndex>>& direction) 
{
    if (i == 0 || j == 0) return;

    const PrevIndex& prev = direction[i][j];
    if (prev.row == i - 1 && prev.col == j - 1) 
    {
        reconstructLCS(i - 1, j - 1, seq, direction);
        cout << seq[i - 1];
    }
    else if (prev.row == i - 1) 
    {
        reconstructLCS(i - 1, j, seq, direction);
    }
    else {
        reconstructLCS(i, j - 1, seq, direction);
    }
}
int main()
{
    string seq1, seq2;
    cout << "Enter sequence X: ";
    cin >> seq1;
    cout << "Enter sequence Y: ";
    cin >> seq2;
    int length1 = seq1.size();
    int length2 = seq2.size();
    vector<vector<int>> lcsTable(length1 + 1, vector<int>(length2 + 1, 0));
    vector<vector<PrevIndex>> direction(length1 + 1, vector<PrevIndex>(length2 + 1));
    int lcsLength = calculateLCS(seq1, seq2, lcsTable, direction);
    cout << "\nLength of LCS: " << lcsLength << endl;
    cout << "LCS: ";
    reconstructLCS(length1, length2, seq1, direction);
    cout << endl;
    return 0;
}