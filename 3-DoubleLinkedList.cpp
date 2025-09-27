class DLL {
public:
    struct node {
        int val;
        node *nxt, *prv;

        node(int v) : val(v), nxt(nullptr), prv(nullptr) {}

        node() : val(0), nxt(nullptr), prv(nullptr) {}
    };

    node *head = nullptr;
    node *tail = nullptr;
    int sz = 0;

    void push_front(int val) {
        node *tmp = new node(val);
        if (sz == 0) {
            head = tail = tmp;
            tmp->nxt = nullptr;
            tmp->prv = nullptr;
        } else {
            tmp->nxt = head;
            tmp->prv = nullptr;
            head->prv = tmp;
            head = tmp;
        }
        sz++;
    }

    void push_back(int val) {
        if (sz == 0)push_front(val);
        else {
            node *tmp = new node(val);
            tmp->prv = tail;
            tmp->nxt = nullptr;
            tail->nxt = tmp;
            tail = tmp;
            sz++;
        }
    }

    void insert(int v, node *cur) {
        if (sz == 0) {
            push_front(v);
        } else if (sz == 1 || cur == tail) {
            push_back(v);
        } else {
            node *tmp = new node(v);
            tmp->nxt = cur->nxt;
            tmp->prv = cur;
            cur->nxt->prv = tmp;
            cur->nxt = tmp;
            sz++;
        }
    }

    void pop_back() {
        if (sz == 0)return;
        if (sz == 1) {
            delete tail;
            tail = head = nullptr;
            sz--;
        } else {
            node *tmp = tail->prv;
            delete tail;
            tail = tmp;
            tail->nxt = nullptr;
            sz--;
        }
    }

    void pop_front() {
        if (sz <= 1)pop_back();
        else {
            node *tmp = head->nxt;
            delete head;
            head = tmp;
            head->prv = nullptr;
            sz--;
        }
    }

    void erase(node *cur) {
        if (cur == head)pop_front();
        else if (cur == tail)pop_back();
        else {
            cur->nxt->prv = cur->prv;
            cur->prv->nxt = cur->nxt;
            delete cur;
            sz--;
        }
    }

    void reverse() {
        node *cur = head, *next;
        while (cur != nullptr) {
            next = cur->nxt;
            swap(cur->nxt, cur->prv);
            cur = next;
        }
        swap(head, tail);
    }

    void print() {
        node *cur = head;
        while (cur != nullptr) {
            cout << cur->val << " ";
            cur = cur->nxt;
        }
    }
    //------------------------------------

  

};