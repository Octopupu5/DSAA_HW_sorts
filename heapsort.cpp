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

    mt19937 gen(time(nullptr));

    vector<int> A(n);
    for (auto & el : A) {
        el = gen();
    }

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    ios_base::sync_with_stdio(false);

    /* Sort process */
    for (int i = n / 2 - 1; i >= 0; --i)
        heap(A, i, n);

    for (int i = n - 1; i > 0; --i) {
        swap(A[0], A[i]);
        heap(A, 0, i);
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
        for (int i = 0; i < n; ++i)
            cout << A[i] << ' ';
        cout << '\n';
    }

    return 0;
}