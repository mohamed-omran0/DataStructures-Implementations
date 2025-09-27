struct node {
    int val{};
    node *l{}, *r{},*p{};

    node(int v) : val(v), l(nullptr), r(nullptr),p(nullptr) {}
};
class BST {
public:
    node *root{};

    pair<bool,node*> search(int &t, node *tmp) {
        if (!tmp)return {false, nullptr};
        if (tmp->val == t)return {true,tmp};
        if (t < tmp->val)return search(t, tmp->l);
        else return search(t, tmp->r);
    }

    void insert(int target, node *tmp) {
        if (root == nullptr) {
            root = new node(target);
            return;
        }
        if (tmp->val < target) {
            if (tmp->r)insert(target, tmp->r);
            else tmp->r = new node(target), tmp->r->p = tmp;
        } else {
            if (tmp->l)insert(target, tmp->l);
            else tmp->l = new node(target), tmp->l->p = tmp;
        }
    }

    node* sucessor(int target) {
        node *tmp = search(target, root).second;
        if (!tmp)return nullptr;
        if (tmp->r) {
            tmp = tmp->r;
            while (tmp->l)tmp = tmp->l;
            return tmp;
        } else {
            while (tmp->p) {
                tmp = tmp->p;
                if (tmp->val > target)return tmp;
            }
            return nullptr;
        }
    }

    void delete_node(int target) {
        node *tmp = search(target, root).second;
        if (!tmp->l && !tmp->r) {
            if (tmp == root) {
                root = nullptr;
            } else {
                if (tmp->p->l == tmp) {
                    tmp->p->l = nullptr;
                } else {
                    tmp->p->r = nullptr;
                }
            }
            delete tmp;
        } else if (!tmp->l||!tmp->r) {
          node*child=(tmp->l)?tmp->l:tmp->r;
          if(tmp==root){
              root=child;
              child->p= nullptr;
          }
          else {
              if (tmp->p->l == tmp)tmp->p->l = child;
              else tmp->p->r = child;
              child->p = tmp->p;
          }
          delete tmp;
        } else {
            node *suc = sucessor(target);
            tmp->val = suc->val;
            if (suc->r) {
                if (suc->p->l == suc) {
                    suc->p->l = suc->r;
                } else {
                    suc->p->r = suc->r;
                }
                suc->r->p=suc->p;
            }
            else {
                if (suc->p->l == suc) {
                    suc->p->l = nullptr;
                } else {
                    suc->p->r = nullptr;
                }
            }
            delete suc;

        }
    }

    void PRE_ORDER(node *tmp) {
        if (!tmp)return;
        cout << tmp->val << " ";
        PRE_ORDER(tmp->l);
        PRE_ORDER(tmp->r);
    }


};
