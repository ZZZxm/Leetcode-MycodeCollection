class ProductOfNumbers {
public:
    ProductOfNumbers() {
        size = 0;
        data = new int[40001];
        b = 0;
    }

    void add(int num) {
        b = 0;
        data[size] = num;
        size++;
    }

    int getProduct(int k) {
        int res = 1;
        if (b == 1) return product[k];
        product[1] = data[size - 1];
        for (int i = 2; i <= size; i++) product[i] = product[i - 1] * data[size - i];
        b = 1;
        return product[k];
    }

private:
    int* data;
    int size;
    bool b;
    int product[40001];
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */