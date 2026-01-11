#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

void firstNonRepeating(string stream)
{
    queue<char> q;
    unordered_map<char, int> map;

    for (auto c : stream)
    {
        map[c]++;
        q.push(c);

        while (!q.empty() && map[c] > 1)
        {
            q.pop();
        }

        if (q.empty())
        {
            cout <<"-1"<<" ";
        }
        else
        {
            cout <<q.front()<<" ";
        }
    }
}

int main()
{
    string stream   = "aabcbdd";
    firstNonRepeating(stream);
    return 0;
}