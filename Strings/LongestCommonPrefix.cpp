#include <iostream>
#include <string>
#include <vector>
using namespace std;

string longestCommonPrefixUtil(string s1, string s2)
{
   int i =0; 
   int j=0;

   string str = "";

   for (i=0, j =0 ; i <s1.length(), j < s2.length() ; i++, j++)
   {
      if (s1[i] != s2[j])
      {
        break;
      }
      str +=s1[i];
   }
    return str;
}

string longestCommonPrefix(vector<string> s)
{
    string prefix = s[0];

    for (int i =0;i < s.size();i++)
    {
        prefix = longestCommonPrefixUtil(prefix, s[i]);
    }
    return prefix;
}

int main()
{
    vector<string> s= {"geeksforgeeks", "geeksf", "geek", "gee"};

    auto commonPrefix = longestCommonPrefix(s);
    cout <<"Longest Common Prefix: "<< commonPrefix;

    return 0;
}