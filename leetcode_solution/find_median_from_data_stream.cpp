#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
/*
1.每次求中位数时进行排序，会超时
2.维护两个堆，左边是最大堆，右边是最小堆，这样获取中位数的复杂度为O(1),每次插入完毕后，需要调整
两边数字的个数，注意c++中priority_heap是最大堆
*/
class MedianFinder {
public:
	// Adds a number into the data structure.
	void addNum(int num) 
	{
		left.push(num);
		//保证左边堆的数字比右边堆小
		right.push(-left.top());
		left.pop();
		if (left.size() < right.size())
		{
			left.push(-right.top());
			right.pop();
		}
	}

	// Returns the median of current data stream
	double findMedian() 
	{
		if (right.size() == 0)
		{
			return left.top();
		}
		if (left.size() == right.size())
		{
			return (left.top() - right.top()) / 2.0;
		}
		else
		{
			return left.top();
		}
	}
private:
	priority_queue<int>left, right;
};

/*
int main()
{
	MedianFinder mf;
	while(true)
	{
		int number;
		cin >> number;
		mf.addNum(number);
		cout << mf.findMedian() << endl;
	}

	system("pause");
}
*/
// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();