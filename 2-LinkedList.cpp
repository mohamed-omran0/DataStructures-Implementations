class LinkedList {
public:
    struct node {
        node *nxt;
        int val;

        node() : nxt(nullptr), val(0) {}

        node(int v) : nxt(nullptr), val(v) {};
    };

//    ~LinkedList() {
//        clear();
//    }


    node *head{}, *tail{};
    int sz = 0;
public:
    void push_front(int val) {
        node *tmp = new node(val);
        if (head != nullptr) {
            tmp->nxt = head;
            head = tmp;
        } else {
            head = tail = tmp;
            tmp->nxt = nullptr;
        }
        sz++;
    }

    void push_back(int val) {
        node *tmp = new node(val);
        if (tail != nullptr) {
            tail->nxt = tmp;
            tail = tmp;
        } else {
            head = tail = tmp;
            tmp->nxt = nullptr;
        }
        sz++;
    }

    void insert(node *cur, int val) {  //current node that we need to insert node after it
        node *tmp = new node(val);
        if (head == nullptr) {
            push_front(val);
        } else if (cur == tail) {
            push_back(val);
        } else {
            tmp->nxt = cur->nxt;
            cur->nxt = tmp;
            sz++;
        }
    }

    void pop_front() {
        if (head == nullptr)return;
        if (head == tail) {
            delete head;
            head = tail = nullptr;
            sz--;
        } else {
            node *tmp = head;
            head = head->nxt;
            delete tmp;
            tmp = nullptr;
            sz--;
        }
    }

    void pop_back() {
        if (tail == nullptr)return;
        if (head == tail)pop_front();
        else {
            node *tmp = head;
            while (tmp->nxt != tail) {
                tmp = tmp->nxt;
            }
            delete tail;
            tail = tmp;
            tail->nxt = nullptr;
            sz--;
        }
    }

    void clear() {
        while (sz > 0) {
            pop_front();
        }
    }

    bool empty() {
        return sz == 0;
    }

    int front() { //TODO exception handling
        if (head == nullptr) throw runtime_error("List is empty");
        return head->val;
    }

    int back() {//TODO exception handling
        if (head == nullptr) throw runtime_error("List is empty");
        return tail->val;
    }

    int size() {
        return sz;
    }

    void print() {
        node *tmp = head;
        while (tmp) {
            cout << tmp->val << " ";
            tmp = tmp->nxt;
        }
        cout << "\n";
    }

    void reverse() {
        node *cur = head;
        node *prv = nullptr;
        node *next = nullptr;
        while (cur) {
            next = cur->nxt;
            cur->nxt = prv;
            prv = cur;
            cur = next;
        }
        swap(head, tail);
    }

    void erase(int n) {
        if (sz < n)return;
        else if (sz == n)pop_back();
        else if (n == 1)pop_front();
        else {
            node *tmp = head, *prv;
            n--;
            while (n--) {
                prv = tmp;
                tmp = tmp->nxt;
            }
            prv->nxt = tmp->nxt;
            delete tmp;
            tmp = nullptr;
            sz--;
        }
    }

    //-------------------------------------------------------------------
    
};
