class heap {
    vector<int> CBT;
    int  sz{};
public:
    heap() : sz(-1) {}

    heap(const vector<int> &v) : sz(-1) {
        sz = v.size(), sz--;
        CBT = v;
        for (int i = (sz - 1) / 2; i >= 0; --i) {
            sift_down(i);
        }
    }


    void sift_down(int i) {
        int l, r;
        l = i * 2 + 1, r = i * 2 + 2;
        if (r <= sz) {
            if (CBT[l] > CBT[r])swap(l, r);
        }
        if (l <= sz && CBT[i] > CBT[l]) {
            swap(CBT[i], CBT[l]);
            sift_down(l);
        }
    }

    void sift_up(int i) {
        int p = (i - 1) / 2;
        if (p >= 0 && CBT[i] < CBT[p]) {
            swap(CBT[p], CBT[i]);
            sift_up(p);
        }
    }

    void push(int x) {
        CBT.push_back(x);
        sz++;
        sift_up(sz);
    }

    void pop() {
        if (CBT.empty())return;
        CBT[0] = CBT.back();
        CBT.pop_back();
        sz--;
        sift_down(0);
    }

    int size() {
        return sz + 1;
    }

    bool empty() {
        return sz == -1;
    }
    int top(){
        return CBT[0];
    }
};
