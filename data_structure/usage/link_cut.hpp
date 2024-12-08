struct Node {
    typedef Node* NP;
    NP l, r, p;
    bool rev;
    int v, mx, lz;
    static const int INF = 1e9;
    Node() : l(NULL), r(NULL), p(NULL), rev(false), v(-INF), mx(-INF), lz(-INF) {}
    void Propagate() {
        if (rev) {
            swap(l, r);
            if (l) l->rev ^= true;
            if (r) r->rev ^= true;
            rev = false;
        }
        if (l) l->lz = min(l->lz, lz);
        if (r) r->lz = min(r->lz, lz);
        v = min(v, lz);
        mx = min(mx, lz);
        lz = -INF;
    }
    int GetMax() { return max(mx, lz); }
    int GetVert() { return max(v, lz); }
    void Update() {
        assert(lz == -INF);
        mx = v;
        if (l) mx = max(mx, l->GetMax());
        if (r) mx = max(mx, r->mx);
    }
    int Pos() {
        if (p && p->l == this) return -1;
        if (p && p->r == this) return 1;
        return 0;
    }
    void Prepare() {
        if (Pos()) p->Prepare();
        Propagate();
    }
    void Rotate() {
        NP q = p, c;
        if (Pos() == 1) {
            c = l;
            l = p;
            p->r = c;
        } else {
            c = r;
            r = p;
            p->l = c;
        }
        if (c) c->p = p;
        p = p->p;
        q->p = this;
        if (p && p->l == q) p->l = this;
        if (p && p->r == q) p->r = this;
        q->Update();
    }
    void Splay() {
        Prepare();
        while (Pos()) {
            int a = Pos(), b = p->Pos();
            if (b && a == b) p->Rotate();
            if (b && a != b) Rotate();
            Rotate();
        }
        Update();
    }
    void Expose() {
        for (NP x = this; x; x = x->p) x->Splay();
        for (NP x = this; x->p; x = x->p) {
            x->p->r = x;
            x->p->Update();
        }
        Splay();
    }
    void Evert() {
        Expose();
        if (l) {
            l->rev ^= true;
            l = NULL;
            Update();
        }
    }
    void Link(NP x) {
        Evert();
        p = x;
    }
    void Set(int q) {
        Expose();
        r = NULL;
        lz = max(lz, q);
    }
    void Cut() {
        Expose();
        assert(l);
        l->p = NULL;
        l = NULL;
        Update();
    }
    int Get() {
        Expose();
        r = NULL;
        Update();
        return GetMax();
    }
};
Node* LCA(Node* a, Node* b) {
    a->Expose();
    b->Expose();
    if (!a->p) return NULL;
    Node* d = a;
    while (a->p != b) {
        if (a->Pos() == 0) d = a->p;
        a = a->p;
    }
    if (a == b->l) return d;
    else return b;
}