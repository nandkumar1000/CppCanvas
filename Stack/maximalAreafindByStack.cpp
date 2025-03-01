#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution
{
private:
  vector<int> nextSmaller(int *arr, int n)
  {
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
      int curr = arr[i];
      while (s.top() != -1 && arr[s.top()] >= curr)
      {
        s.pop();
      }
      ans[i] = s.top();
      s.push(i);
    }
    return ans;
  }

  vector<int> prevSmaller(int *arr, int n)
  {
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
      int curr = arr[i];
      while (s.top() != -1 && arr[s.top()] >= curr)
      {
        s.pop();
      }
      ans[i] = s.top();
      s.push(i);
    }
    return ans;
  }

  int largestRectangleArea(int *arr, int n)
  {
    vector<int> next = nextSmaller(arr, n);
    vector<int> prev = prevSmaller(arr, n);
    int area = 0;

    for (int i = 0; i < n; i++)
    {
      if (next[i] == -1)
      {
        next[i] = n;
      }
      int length = arr[i];
      int breadth = next[i] - prev[i] - 1;
      int newArea = length * breadth;
      area = max(area, newArea);
    }
    return area;
  }

public:
  int maximalRectangle(vector<vector<char>> &matrix)
  {
    if (matrix.empty())
      return 0;

    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> heights(m, 0);
    int maxArea = 0;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (matrix[i][j] == '1')
        {
          heights[j] += 1;
        }
        else
        {
          heights[j] = 0;
        }
      }
      maxArea = max(maxArea, largestRectangleArea(heights.data(), m));
    }
    return maxArea;
  }
};

int main()
{
  Solution solution;
  vector<vector<char>> matrix = {{'1', '0', '1', '0'},
                                 {'1', '0', '1', '1'},
                                 {'1', '1', '1', '1'},
                                 {'1', '1', '1', '1'},
                                 {'1', '1', '1', '1'}};
  int result = solution.maximalRectangle(matrix);
  return 0;
}