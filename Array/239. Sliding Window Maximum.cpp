/* 239. Sliding Window Maximum */
/* Solution 1: Heap */

/* Solution 2: Deque */

template<class Type>
class DequeNode
{
public:
	DequeNode(Type data) { this->data = data; }
	DequeNode() {};

private:
	DequeNode* front = NULL;
	DequeNode* next = NULL;
	Type data;
};

template<class Type>
class Deque
{
public:
	Deque() { head = new DequeNode<Type>; }

private:
	DequeNode<Type>* head;
	DequeNode<Type>* rear;
	int size = 0;

};


vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
	vector<int> res;//answer
	deque<int> deq;//store the index of element
	int n = nums.size();

	if (n == 0) return res;//particular case of empty array

	//init the deque with first k elements
	for (int i = 0; i < k; i++)
	{
		if (deq.empty()) deq.push_back(i);//if deque is empty, push back
		else
		{
			int val = nums[i];
			while (!deq.empty() && nums[deq.back()] < val) {
				deq.pop_back();
			}
			deq.push_back(i);
		}
	}
	res.push_back(nums[deq.front()]);

	//slide the window and alter the deque
	for (int i = k; i < n; i++)
	{
		//index must be not smaller than i-k+1
		if (deq.front() < i - k + 1) deq.pop_front();
		if (deq.empty()) deq.push_back(i);
		else
		{
			int val = nums[i];
			while (!deq.empty() && nums[deq.back()] < val) {
				deq.pop_back();
			}
			deq.push_back(i);
		}
		res.push_back(nums[deq.front()]);//each time the largest value is the element of index in front
	}
	return res;
}