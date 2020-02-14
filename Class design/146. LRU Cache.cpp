/* 146 LRU缓存机制 */
/* 所有操作时间复杂度均为O(1) */

struct Data
{
	int value = -1;
	int front = -1;
	int next = -1;
};


/* LRU Cache*/
/* */
class LRUCache
{
public:
	LRUCache(int capacity):maxsize(capacity){
		data = new Data[maxvalue];
	}

	int get(int key)//获取key对应的value
	{
		if (data[key].value == -1) return -1;//未查找到
		else
		{
			if (size != 1)
			{
				if (data[key].front != -1) data[data[key].front].next = data[key].next;
				else {//队首特殊操作
					top = data[key].next;
					data[top].front = -1;
				}
				if (data[key].next != -1) data[data[key].next].front = data[key].front;
				else {//队尾特殊操作
					rear = data[key].front;
					data[rear].next = -1;
				}

				//插入到队尾
				data[rear].next = key;
				data[key].front = rear;
				data[key].next = -1;
				rear = key;
			}
			
			return data[key].value;
		}
	}

	void put(int key, int value)//key入队
	{
		if (data[key].value == -1)//key不在缓存中
		{
			data[key].value = value;
			size++;
			if (top == -1)
			{
				top = key;
				rear = key;
			}
			else
			{
				data[rear].next = key;
				data[key].front = rear;
				rear = key;
			}
		}
		else//key已在缓存中，需更改优先级
		{
			data[key].value = value;

			if (data[key].front != -1) data[data[key].front].next = data[key].next;
			else if (size != 1) top = data[key].next;
			if (data[key].next != -1) data[data[key].next].front = data[key].front;

			data[rear].next = key;
			data[key].front = rear;
			rear = key;
		}

		if (size > maxsize)
		{
			int i = data[top].next;
			data[top].value = -1;
			data[top].next = -1;
			top = i;
			data[top].front = -1;
			size--;
		}
	}

private:
	Data* data;
	int maxvalue = 100000;
	int maxsize;
	int top = -1;//队首
	int rear = -1;//队尾
	int size = 0;
};