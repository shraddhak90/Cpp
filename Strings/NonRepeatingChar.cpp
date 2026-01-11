#include <iostream>
#include <vector>
using namespace std;
const int MAX_CHAR = 26;

char NonRepeatingChar(const string& str)
{
    vector<int> freq(MAX_CHAR, 0);

    for (char ch :str)
    {
        freq[ch - 'a']++;
    }

    for (char ch : str)
    {
        if (freq[ch - 'a'] == 1)
        {
            return ch;
        }
    }
    return '\0';
}

int main()
{
    std::string str = "hraddha";

    cout << "First Non-repeating character : "<< NonRepeatingChar(str) << std::endl;
}