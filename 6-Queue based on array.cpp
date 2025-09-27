class Queue {
public:
    int *arr;
    int l, r, cap, sz;

    Queue() : l(0), r(-1), sz(0), cap(1), arr(nullptr) {
        arr = new int[1];
    }

    void handel(int newCap) {
        int *tmp = new int[newCap];
        for (int i = 0; i < sz; ++i) {
            tmp[i] = arr[l];
            l++, l %= cap;
        }
        delete[] arr;
        arr = tmp;
        cap = newCap;
        l = 0, r = sz;
    }

    void push(int val) {
        if (sz == cap) {
            handel(cap * 2 + 1);
            arr[r] = val;
            sz++;
            r %= cap;
        } else {
            ++r, r %= cap;
            arr[r] = val;
            sz++;
        }
    }

    void pop() {
        if (sz == 0)return;
        l++;
        l %= cap;
        sz--;
    }

    int front() {
        if (sz == 0)return -1;
        return arr[l];
    }

    int back() {
        if (sz == 0)return -1;
        return arr[r];
    }

    void print() {
        if (sz == 0)return;
        int k = l;
        for (int i = 0; i < sz; ++i) {
            cout << arr[k] << " ";
            k++, k %= cap;
        }
    }
};