class ProductOfNumbers {
public:
    vector<int> arr, mul;
    ProductOfNumbers() {}
    void add(int num) {
        arr.push_back(num);
        if(mul.empty() && num) mul.push_back(num);
        else if(!num) mul.clear();
        else mul.push_back(mul.back() * num);
    }
    int getProduct(int k) {
        if (k > mul.size()) return 0;
        return k == mul.size() ? mul.back() : mul.back() / mul[mul.size() - k - 1];
    }
};