class Queue {
public:
    struct node {
        node *nxt{};
        int val{};

        node(int v) : val(v), nxt(nullptr) {}
    };

    node *head = nullptr, *tail = nullptr;
    int sz = 0;

    void push(int val) {
        node *tmp = new node(val);
        if (tail == nullptr) {
            head = tail = tmp;
        } else {
            tail->nxt = tmp;
            tail = tmp;
        }
        tmp->nxt = nullptr;
        sz++;
    }

    void pop() {
        if (sz == 0)return;
        node *tmp = head->nxt;
        delete head;
        head = tmp;
        sz--;
    }

    int front() {
        if (sz == 0)return -1;
        return head->val;
    }

    int back() {
        if (sz == 0)return -1;
        return tail->val;
    }

    void print() {
        node *tmp = head;
        while (tmp != nullptr)cout << tmp->val << " ", tmp = tmp->nxt;
    }
};