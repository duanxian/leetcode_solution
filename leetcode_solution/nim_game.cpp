#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
	//�ݹ�
	bool canWinNim(int n)
	{
		return n % 4 != 0;
	}
};