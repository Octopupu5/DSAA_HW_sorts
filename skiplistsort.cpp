#include <bits/stdc++.h>
using namespace std;

struct node {
    int x;
    node *next;
    node *down;
    node (int xx = 0, node *nextx = nullptr, node *downx = nullptr) : x(xx), next(nextx), down(downx) {}
};

void insert (node *& skiplist, int key, int &sl_h) {
    int height = 1;
    while (rand() % 2 != 0 && height < sl_h - 1) ++height;
    // if (height == sl_h) {
    //     sl_h = height + 1;
    //     node *right_bound = new node(INT_MAX, nullptr, skiplist->next->down);
    //     skiplist = new node(INT_MIN, right_bound, skiplist);
    //     cout << sl_h << '\n';
    // }
    
    int h = sl_h;
    node *l = skiplist;
    node *r = l->next;
    node *upper = nullptr;
    while (l->down != nullptr) {
        --h;
        l = l->down;
        r = r->down;
        while (l->next->x < key)
            l = l->next;
        r = l->next;
        if (height >= h) {
            node *insert_node = new node(key, r);
            l->next = insert_node;
            if (upper != nullptr)
                upper->down = insert_node;
            upper = insert_node;
        }
    }
}

int main (int argc, char **argv) {
    if (argc > 2 || (argc == 2 && (string(argv[1]) != "print"))) {
        printf("Wrong input!\n");
        exit(-1);
    }

    /* Input process */
    int n;
    cin >> n;

    mt19937 gen(time(nullptr));

    vector<int> A(n);
    for (auto & el : A) {
        el = gen() % 5000 - 2500;
    }

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    ios_base::sync_with_stdio(false);
    
    node *down_left = nullptr;
    node *down_right = nullptr;
    node *skiplist = nullptr;
    int h = 18;
    for (int i = 0; i < h; ++i) {
        node *right_bound = new node(INT_MAX, nullptr, down_right);
        skiplist = new node(INT_MIN, right_bound, down_left);
        down_left = skiplist;
        down_right = right_bound;
    }

    for (int i = 0; i < n; ++i) {
        insert(skiplist, A[i], h);
    }

    /* Getting the time of sorting */
    clock_gettime(CLOCK_MONOTONIC, &end);
    double time_taken;
    time_taken = (end.tv_sec - start.tv_sec) * 1e9;
    time_taken = (time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-9;
    cout << time_taken << setprecision(9) << '\n';

    /* Print sorted array */
    if (argc == 2) {
        cout << "Sorted array :\n";
        node *start_seq = skiplist;
        while (start_seq->down != nullptr)
            start_seq = start_seq->down;
        start_seq = start_seq->next;
        for (int i = 0; i < n; ++i) {
            cout << start_seq->x << ' ';
            start_seq = start_seq->next;
        }
        cout << '\n';
    }

    node *start_seq = skiplist;
    while (start_seq != nullptr) {
        node *curr = start_seq;
        start_seq = start_seq->down;
        while (curr != nullptr) {
            node *next_node = curr->next;
            delete curr;
            curr = next_node;
        }
    }

    return 0;
}