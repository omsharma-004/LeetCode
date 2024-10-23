class RecentCounter {
public:
    RecentCounter() {
    }
    vector<int> records;
    int ping(int t) {
        records.push_back(t);        
        while (records.front() < t - 3000) {
            records.erase(records.begin());
        }
        return records.size();
    }
};
