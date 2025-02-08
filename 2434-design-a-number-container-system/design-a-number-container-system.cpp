class NumberContainers {
public:
    map<int, set<int>> mpp;
    map<int, int> mp;
    NumberContainers() {}
    void change(int index, int number) {
        if (mp[index]) {
            int val = mp[index];
            mpp[val].erase(index);
            mp[index] = number;
        } else {
            mp[index] = number;
        }
        mpp[number].insert(index);
    }
    int find(int number) {
        if (mpp[number].empty())
            return -1;
        return *(mpp[number].begin());
    }
};
