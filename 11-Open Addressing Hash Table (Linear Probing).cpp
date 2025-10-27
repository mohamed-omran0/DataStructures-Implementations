class table {
    const int cap = 1049;
    pair<int, int> *arr;
    int *used, sz;

    int hash_fun(int x) {
        return ((x * 1861) + 4289) % cap;
    }


public:
    table() {
        arr = new pair<int, int>[cap];
        used = new int[cap];
        sz = 0;
        for (int i = 0; i < cap; ++i) {
            used[i] = 0;
        }
    }

    void insert(pair<int, int> x) {
        int k = hash_fun(x.first);
        int h_x = k;
        int del = -1;
        while (true) {
            if (used[k] == 1) {
                if (arr[k].first == x.first) {
                    arr[k].second = x.second;
                    return;
                }
                k++;
            } else if (used[k] == 2) {
                if (del == -1)del = k;
                k++;
            } else {
                if (del != -1) {
                   used[del] = 1;
                    arr[del] = x;
                    sz++;
                }
                arr[k] = x;
                used[k] = 1;
                sz++;
                return;
            }
            k %= cap;
            if (k == h_x)break;
        }
    }

    void erase(int x) {
        int k = hash_fun(x);
        int h_x = k;
        while (true) {
            if (used[k] == 1) {
                if (arr[k].first == x) {
                    used[k] = 2;
                    sz--;
                    return;
                }
                k++;
            } else if (used[k] == 2) {
                k++;
            } else {
                return;
            }
            k %= cap;
            if (k == h_x)break;
        }
    }

    int get(int x) {
        int k = hash_fun(x);
        int h_x = k;
        while (true) {
            if (used[k] == 1) {
                if (arr[k].first == x) {
                    return arr[k].second;
                }
                k++;
            } else if (used[k] == 2) {
                k++;
            } else {
                return -1;
            }

            k %= cap;
            if (k == h_x)break;
        }
        return -1;
    }

    bool exist(int x) {
        int k = hash_fun(x);
        int h_x = k;
        while (true) {
            if (used[k] == 1) {
                if (arr[k].first == x) {
                    return true;
                }
                k++;
            } else if (used[k] == 2) {
                k++;
            } else {
                return false;
            }
            k %= cap;
            if (k == h_x)break;
        }
        return false;
    }

    int size() {
        return sz;
    }
    int operator[](int x) {
        return get(x);
    }
    ~table() {
        delete[] arr;
        delete[] used;
    }
};
