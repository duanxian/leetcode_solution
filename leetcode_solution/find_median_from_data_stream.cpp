#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
/*
1.ÿ������λ��ʱ�������򣬻ᳬʱ
2.ά�������ѣ���������ѣ��ұ�����С�ѣ�������ȡ��λ���ĸ��Ӷ�ΪO(1),ÿ�β�����Ϻ���Ҫ����
�������ֵĸ�����ע��c++��priority_heap������
*/
class MedianFinder {
public:
	// Adds a number into the data structure.
	void addNum(int num) 
	{
		left.push(num);
		//��֤��߶ѵ����ֱ��ұ߶�С
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