#include <bits/stdc++.h>
using namespace std;

void quicksort (vector<int> &A, int l, int r) {
    if (l >= r) return;
    
    int pivot_index = l;
    for (int i = l + 1; i <= r; ++i)
        if (A[i] <= A[l]) ++pivot_index;
    swap(A[pivot_index], A[l]);
    
    int i = l, j = r;
    while (i < pivot_index && j > pivot_index) {
        while (A[i] <= A[pivot_index]) ++i;
        while (A[j] > A[pivot_index]) --j;
        if (i < pivot_index && j > pivot_index)
            swap(A[i++], A[j--]);
    }

    quicksort(A, l, pivot_index - 1);
    quicksort(A, pivot_index + 1, r);
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
    quicksort(A, 0, n - 1);

    if (argc == 2) {
        cout << "Sorted array :\n";
        for (int i = 0; i < n; ++i)
            cout << A[i] << ' ';
        cout << '\n';
    }

    return 0;
}