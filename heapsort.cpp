#include <bits/stdc++.h>
using namespace std;

void heap (vector<int> &A, int root, int size) {
    int left_child = 2 * root + 1, right_child = 2 * root + 2;
    int maximum_index = root;
    
    if (left_child < size && A[left_child] > A[maximum_index])
        maximum_index = left_child;
    if (right_child < size && A[right_child] > A[maximum_index])
        maximum_index = right_child;
    
    if (maximum_index != root) {
        swap(A[root], A[maximum_index]);
        heap(A, maximum_index, size);
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

    vector<int> A(n);
    for (auto & el : A)
        cin >> el;

    /* Sort process */
    for (int i = n / 2 - 1; i >= 0; --i)
        heap(A, i, n);

    for (int i = n - 1; i > 0; --i) {
        swap(A[0], A[i]);
        heap(A, 0, i);
    }

    if (argc == 2) {
        cout << "Sorted array :\n";
        for (int i = 0; i < n; ++i)
            cout << A[i] << ' ';
        cout << '\n';
    }

    return 0;
}