#include <iostream>
using namespace std;

int N = 8;
int solutions = 0;

void solve(int row, int cols, int leftDiag, int rightDiag)
{
  if (row == N)
  {
    solutions++;
    return;
  }

  int availablePositions = ((1 << N) - 1) & ~(cols | leftDiag | rightDiag);

  while (availablePositions)
  {
    int pos = availablePositions & -availablePositions;
    availablePositions -= pos;

    solve(row + 1, cols | pos, (leftDiag | pos) << 1, (rightDiag | pos) >> 1);
  }
}

int main()
{
  solve(0, 0, 0, 0);
  cout << "Total solutions: " << solutions << endl;
  return 0;
}
