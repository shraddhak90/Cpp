#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//string txt = "forxxorfxdofr";
//string pat = "for";
int search(string &pat, string &txt) 
{
    int i=0, j=0;
    unordered_map<char,int> map;
    int k = pat.size();
    
    int ans=0;
    
    for (int k=0;k <pat.size();k++)
    {
        map[pat[k]]++;
    }
    
    int count = map.size();
    while ( j < txt.size())
    {
        if (map.find(txt[j]) != map.end())
        {
            map[txt[j]]--;
            if (map[txt[j]] == 0)
            {
                count--;
            }
        }
        
        
        if (j-i+1 < k)
        {
            j++;
        }
        else if (j-i+1 == k)
        {
            if (count == 0)
            {
                ans++;
            }
            
            if (map.find(txt[i]) != map.end())
            {
                map[txt[i]]++;
                if (map[txt[i]] == 1 )
                {
                    count++;
                }
            }
            i++;
            j++;
        }
    }
    return ans;
}

int main()
{
    string txt = "forxxorfxdofr";
    string pat = "for";
    int result = search(pat, txt);
    cout << "Count of anagram occurrences of '" << pat << "' in '" << txt << "' is: " << result << endl;
    return 0;
}