class Stack {
    int sz, cap;
    int *arr;
public:
    Stack() : sz(0), arr(nullptr), cap(0) {}
    Stack(const Stack &st): sz(0), arr(nullptr), cap(0) {
        copy(st);
    }
public:
    void copy(const Stack &st) {
      clear();
        cap=sz=st.sz;
        arr=new int [cap];
        for (int i = 0; i < sz; ++i) {
            arr[i]=st[i];
        }
    }
    void handel(int newCap) {
        int *tmp = new int[newCap];
        for (int i = 0; i < sz; ++i) {
            tmp[i] = arr[i];
        }
        cap = newCap;
        swap(arr, tmp);
        tmp = nullptr;
    }

    void push(int v) {
        if (cap == sz) {
            handel(sz * 2 + 1);
        }
        arr[sz++] = v;
    }

    int top() {
        if (sz == 0)return -1;
        return arr[sz - 1];
    }

    int size() {
        return sz;
    }

    void pop() {
        if (sz == 0)return;
        sz--;
        arr[sz] = 0;
    }

    void print() {
        for (int i = sz - 1; i >= 0; --i) {
            cout << arr[i] << " ";
        }
    }

    void clear() {
        sz = cap = 0;
        delete[] arr;
        arr = nullptr;
    }
    int& operator[](int i) const {
        return arr[i];
    }
    void operator=(const Stack &st) {
        copy(st);
    }
};