class table {
    const int sz=1049;
    list<pair<int, int>> *arr;

    int hash_fun(int x) {
        return ((x * 1861) + 4289) % sz;
    }


public:
    table() {
        arr = new list<pair<int, int>>[sz];
    }

    void insert(pair<int, int> x) {
        int h_x = hash_fun(x.first);
        for (auto &it: arr[h_x]) {
            if (it.first == x.first) {
                it.second = x.second;
                return;
            }
        }
        arr[h_x].push_back({x.first, x.second});
    }

    void erase(int x) {
        int h_x = hash_fun(x);
        for (auto it = arr[h_x].begin(); it != arr[h_x].end();) {
            if (it->first == x) {
                arr[h_x].erase(it);
                return;
            }
            it++;
        }
    }

    int get(int x) {
        int h_x = hash_fun(x);
        for (auto &it: arr[h_x]) {
            if (it.first == x)return it.second;
        }
        return -1;
    }
    ~table(){
        delete[]arr;
    }
};