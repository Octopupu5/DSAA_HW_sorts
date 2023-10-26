#include <bits/stdc++.h>
using namespace std;

int getMedian(vector<int> &A, int pos, int sz) {
    switch (sz) {
        case 1: {
            return A[pos];
        }
        case 2: {
            if (A[pos] > A[pos + 1]) swap(A[pos], A[pos + 1]);
            return A[pos];
        }
        case 3: {
            if (A[pos] > A[pos + 1]) swap(A[pos], A[pos + 1]);
            if (A[pos + 1] > A[pos + 2]) swap(A[pos + 1], A[pos + 2]);
            if (A[pos] > A[pos + 1]) swap(A[pos], A[pos + 1]);
            return A[pos + 1];
        }
        case 4: {
            if (A[pos] > A[pos + 1]) swap(A[pos], A[pos + 1]);
            if (A[pos + 2] > A[pos + 3]) swap(A[pos + 2], A[pos + 3]);
            if (A[pos] > A[pos + 2]) swap(A[pos], A[pos + 2]);
            if (A[pos + 1] > A[pos + 3]) swap(A[pos + 1], A[pos + 3]);
            if (A[pos + 1] > A[pos + 2]) swap(A[pos + 1], A[pos + 2]);
            return A[pos + 1];
        }
        default: {
            if (A[pos] > A[pos + 1]) swap(A[pos], A[pos + 1]);
            if (A[pos + 2] > A[pos + 3]) swap(A[pos + 2], A[pos + 3]);
            if (A[pos] > A[pos + 2]) swap(A[pos], A[pos + 2]);
            if (A[pos + 2] > A[pos + 4])
                if (A[pos + 4] > A[pos + 3])
                    swap(A[pos + 3], A[pos + 4]);
            else {
                if (A[pos] > A[pos + 4]) {
                    swap(A[pos + 3], A[pos + 4]);
                    swap(A[pos + 3], A[pos + 2]);
                }
                else {
                    swap(A[pos], A[pos + 4]);
                    swap(A[pos + 4], A[pos + 3]);
                    swap(A[pos + 3], A[pos + 2]);
                }
            }
            if (A[pos + 3] > A[pos + 1]) {
                if (A[pos + 4] > A[pos + 1]) {
                    swap(A[pos], A[pos + 4]);
                    swap(A[pos + 2], A[pos + 3]);
                    swap(A[pos], A[pos + 1]);
                }
                else {
                    swap(A[pos], A[pos + 4]);
                    swap(A[pos + 2], A[pos + 3]);
                }
            }
            else {
                if (A[pos + 2] > A[pos + 1]) {
                    swap(A[pos], A[pos + 4]);
                    swap(A[pos + 3], A[pos + 1]);
                    swap(A[pos + 2], A[pos + 3]);
                }
                else {
                    swap(A[pos], A[pos + 4]);
                    swap(A[pos + 3], A[pos + 1]);
                }
            }
            return A[pos + 2];
        }
    }
}

int divide (vector<int> &A, int l, int r, int pivot) {
    int pivot_index = find(A.begin() + l, A.begin() + r, pivot) - A.begin();
    swap(A[pivot_index], A[l]);
    
    int i = l, j = r;
    while (i < pivot_index && j > pivot_index) {
        while (A[i] <= pivot) ++i;
        while (A[j] > pivot) --j;
        if (i < pivot_index && j > pivot_index)
            swap(A[i++], A[j--]);
    }
    return pivot_index;
}

int median (vector<int> &A, int l, int r, int index) {
    if (index <= 0 || index > r - l + 1) return INT_MAX;
    int sz = r - l + 1;
    vector<int> medians;
    for (int i = 0; i < sz / 5; ++i)
        medians.push_back(getMedian(A, i * 5, 5));
    if (sz / 5 * 5 != sz)
        medians.push_back(getMedian(A, medians.size() * 5, sz % 5));

    int medianAmongAll;
    if (sz <= 5) medianAmongAll = medians[0];
    else medianAmongAll = median(medians, 0, medians.size() - 1, medians.size() / 2);
    
    int medAmongAllPos = divide(A, l, r, medianAmongAll);
    if (medAmongAllPos - l == index - 1)
        return A[medAmongAllPos];
    if (medAmongAllPos - l > index - 1)
        return median(A, l, medAmongAllPos - 1, index);
    return median(A, medAmongAllPos + 1, r, index - medAmongAllPos + l - 1);
}

void quicksort (vector<int> &A, int l, int r) {
    if (l >= r) return;

    int median_index = (r - l + 1) / 2;
    int pivot = median(A, l, r, median_index);
    int pivot_index = divide(A, l, r, pivot);

    quicksort(A, l, pivot_index - 1);
    quicksort(A, pivot_index + 1, r);
}

int main (int argc, char **argv) {
    if (argc > 2 || (argc == 2 && (string(argv[1]) != "print"))) {
        printf("Wrong input!\n");
        exit(-1);
    }

    /* Input process */
    // int n;
    // cin >> n;

    // mt19937 gen(time(nullptr));

    // vector<int> A(n);
    // for (auto & el : A) {
    //     el = gen();
    // }

    // struct timespec start, end;
    // clock_gettime(CLOCK_MONOTONIC, &start);
    // ios_base::sync_with_stdio(false);

    // /* Sort process */
    // quicksort(A, 0, n - 1);

    // /* Getting the time of sorting */
    // clock_gettime(CLOCK_MONOTONIC, &end);
    // double time_taken;
    // time_taken = (end.tv_sec - start.tv_sec) * 1e9;
    // time_taken = (time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-9;
    // cout << time_taken << setprecision(9) << '\n';

    // /* Print sorted array */
    // if (argc == 2) {
    //     cout << "Sorted array :\n";
    //     for (int i = 0; i < n; ++i)
    //         cout << A[i] << ' ';
    //     cout << '\n';
    // }

    vector<int> p({1, 2, 3, 4, 5});
    vector<int> perm(p);
    do {
        vector<int> x(p);
        getMedian(x, 0, 5);
        for (auto & el : p)
            cout << el << ' ';
        cout << '\n';
        for (auto & el : x)
            cout << el << ' ';
        cout << '\n';
        cout << '\n';
    } while (next_permutation(p.begin(), p.end()));

    return 0;
}