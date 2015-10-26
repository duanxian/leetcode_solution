#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
	void split(string str, vector<string>& words)
	{
		size_t pos = 0;

		while (pos != string::npos)
		{
			size_t pre;
			if (pos == 0)
			{
				pre = 0;
			}
			else
			{
				pre = pos + 1;
			}
			pos = str.find_first_of(' ', pre);
			words.push_back(str.substr(pre, pos - pre));
		}
	}
	bool wordPattern(string pattern, string str) 
	{
		unordered_map<char, string>mapping;
		unordered_map<string, char>mapping2;
		vector<string>words;

		split(str, words);
		if (words.size() != pattern.length())
		{
			return false;
		}
		for (int i = 0; i < pattern.length(); i++)
		{
			if (mapping[pattern[i]] == "")
			{
				mapping[pattern[i]] = words[i];
			}
			else if (mapping[pattern[i]] != words[i])
			{
				return false;
			}
			if (mapping2[words[i]] == NULL)
			{
				mapping2[words[i]] = pattern[i];
			}
			else if (mapping2[words[i]] != pattern[i])
			{
				return false;
			}
		}

		return true;
	}
};