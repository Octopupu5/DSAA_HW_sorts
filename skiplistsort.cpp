#include <bits/stdc++.h>
using namespace std;

struct node {
    int x;
    node *next;
    node *down;
    node (int xx = 0) : x(xx), next(nullptr), down(nullptr) {}
};

node *find (node *& skiplist, int key) {
    node *l = skiplist;
    node *r = l->next;
    while (l->down != nullptr) {
        l = l->down;
        r = r->down;
        while (l->next->x < key)
            l = l->next;
        r = l->next;
    }
    if (r->x == key) return r;
    else return nullptr;
}

node *insert (node * res, int key) {
    while (res->next != nullptr && res->next->x < key)
        res = res->next;
    
}

int main (int argc, char **argv) {
    if (argc > 2 || (argc == 2 && (string(argv[1]) != "print"))) {
        printf("Wrong input!\n");
        exit(-1);
    }

    /* Input process */
    int n;
    cin >> n;

    vector<int> A(n);
    for (auto & el : A)
        cin >> el;
    
    

    if (argc == 2) {
        cout << "Sorted array :\n";
        for (int i = 0; i < n; ++i)
            cout << A[i] << ' ';
        cout << '\n';
    }

    return 0;
}