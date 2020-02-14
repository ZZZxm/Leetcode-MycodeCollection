/****** 84. Largest Rectangle in Histogram *******/

/* ������ ʱ�临�Ӷ�O(N^2) */
/* ����ʱ�䣺2284ms ��ż���ᳬ��ʱ�����ƣ�*/
int largestRectangleArea(vector<int>& heights) 
{
	int ans = 0, cur;
	int n = heights.size(), min = INT_MAX;

	for (int i = 0; i < n; i++)
	{
		min = heights[i];
		for (int j = i; j < n; j++)
		{
			min = heights[j] < min ? heights[j] : min;
			cur = min * (j - i + 1);
			ans = cur > ans ? cur : ans;
		}
	}
	return ans;
}

/* ���η� O(NlogN) */
int getLargestArea(vector<int> heights, int i, int j)
{
	int min = INT_MAX;
	int mid;
	int ans = 0;
	//���������ʱ��������
	for (int k = i; k <= j; k++)
	{
		if (heights[k] <= min) {//ע��Ҫ<=�����������д���INT_MAX�����
			mid = k;
			min = heights[k];
		}
	}
	ans = (j - i + 1) * min;

	//����
	int cur = 0;
	if (i <= mid - 1) {
		cur = getLargestArea(heights, i, mid - 1);
		ans = cur > ans ? cur : ans;
	}//��������
	if (j >= mid + 1) {
		cur = getLargestArea(heights, mid + 1, j);
		ans = cur > ans ? cur : ans;
	}//������Ҳ�

	return ans;
}

int largestRectangleArea(vector<int>& heights)
{
	int n = heights.size();
	if (n == 0) return 0;
	else return getLargestArea(heights, 0, n - 1);
}

/* ���η��Ż�������Сֵ���Ż� */
/* �߶��� */
/* �ҳ���Сֵʱ�临�Ӷ�ΪO(log2N) */
class SegTreeNode
{
public:
	SegTreeNode(int start, int end)
	{
		this->start = start;
		this->end = end;
		left = NULL;
		right = NULL;
	}
	int start;
	int end;
	int min;//��Сֵ���±꣬��������Сֵ
	SegTreeNode* left, * right;
};

//�����߶���
SegTreeNode* buildSegTree(vector<int>& heights, int start, int end)
{
	SegTreeNode* root = new SegTreeNode(start, end);
	if (start > end) return NULL;
	if (start == end) {
		root->min = start;
		return root;
	}

	int mid = (start + end) / 2;
	root->left = buildSegTree(heights, start, mid);
	root->right = buildSegTree(heights, mid + 1, end);
	root->min = heights[root->left->min] < heights[root->right->min] ? root->left->min : root->right->min;

	return root;
}

//�ҳ���Сֵ������
int getMinIndex(vector<int>& heights, SegTreeNode* root, int start, int end)
{
	if (root == NULL || start > root->end || end < root->start) return -1;

	if (start <= root->start && end >= root->end) return root->min;

	int leftMin = getMinIndex(heights, root->left, start, end);
	int rightMin = getMinIndex(heights, root->right, start, end);
	if (leftMin == -1) return rightMin;
	if (rightMin == -1) return leftMin;
	return heights[leftMin] < heights[rightMin] ? leftMin : rightMin;
}

//�������������
int getMaxArea(vector<int>& heights, SegTreeNode* root, int start, int end)
{
	if (start > end) return -1;
	if (start == end) return heights[start];

	int minIndex = getMinIndex(heights, root, start, end);
	int leftMax = getMaxArea(heights, root, start, minIndex - 1);
	int rightMax = getMaxArea(heights, root, minIndex + 1, end);
	return max(max(leftMax, rightMax), heights[minIndex] * (end - start + 1));
}

int largestRectangleArea(vector<int>& heights)
{
	int n = heights.size();
	if (n == 0) return 0;

	SegTreeNode* root = buildSegTree(heights, 0, n - 1);
	return getMaxArea(heights, root, 0, n - 1);
}