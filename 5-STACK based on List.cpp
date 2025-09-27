class Stack {
public:
    struct node {
        node *nxt;
        int val;
        node(int v = 0) : nxt(nullptr), val(v) {}
    };
    int sz=0;
    node*head= nullptr;
    void push(int v) {
        node *tmp = new node(v);
        tmp->nxt = head;
        head = tmp;
        sz++;
    }
    void pop() {
        node *tmp = head;
        head = head->nxt;
        delete tmp;
        sz--;
    }
    bool empty() {
        return sz == 0;
    }
    int top() {
        if(empty())return -1;
        return head->val;
    }

};