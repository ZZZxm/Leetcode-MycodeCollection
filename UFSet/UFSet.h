// 并查集模板

#include <iostream>
#include <vector>

using namespace std;

class UnionFindSet
{
    public:
        UnionFindSet(int num)
        {
            this->num = num;
            this->parents = new int[num + 1];
            this->rank = new int[num + 1];

            for (int i = 0; i < num; i++)
            {
                this->parents[i] = i;
                this->rank[i] = 1;
            }
        }

        ~UnionFindSet()
        {
            delete this->parents;
        }

        int Find(int x);
        void Union(int x, int y);

    private:
        int num;

        int* parents;        
        int* rank;
};

int UnionFindSet::Find(int x)
{
    if (this->parents[x] == x)
    {
        return x;
    }
    else
    {
        this->parents[x] = Find(this->parents[x]);
        return Find(this->parents[x]);
    }
}

void UnionFindSet::Union(int x, int y)
{
    int findx = Find(x);
    int findy = Find(y);

    if (findx == findy)
    {
        return;
    }

    if (this->rank[findx] > this->rank[findy])
    {
        this->parents[findy] = findx;
    }
    else if (this->rank[findx] < this->rank[findy])
    {
        this->parents[findx] = findy;
    }
    else
    {
        this->parents[findy] = findx;
        this->rank[findx]++;
    }
}