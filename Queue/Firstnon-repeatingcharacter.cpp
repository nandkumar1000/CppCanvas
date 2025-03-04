#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

string firstNonRepeating(string s)
{
  unordered_map<char, int> count;
  queue<char> q;
  string ans = "";

  for (char ch : s)
  {
    count[ch]++;
    q.push(ch);

    while (!q.empty() && count[q.front()] > 1)
    {
      q.pop();
    }

    ans += q.empty() ? '#' : q.front();
  }

  return ans;
}

int main()
{
  string s;
  cin >> s;
  cout << firstNonRepeating(s) << endl;
  return 0;
}
