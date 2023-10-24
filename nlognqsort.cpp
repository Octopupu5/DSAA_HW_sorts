#include <bits/stdc++.h>
using namespace std;

int getMedian(vector<int> &A, int start_pos, int sz) {

}

int median (vector<int> &A, int l, int r, int index) {
    if (index <= 0 || index > r - l + 1) return INT_MAX;
    int sz = r - l + 1, i;
    vector<int> medians;
    for (i = 0; i < sz / 5; ++i) {
        medians.push_back(getMedian(A, i * 5, 5));
    }
    if (sz / 5 * 5 != sz) {
        medians.push_back(getMedian(A, i * 5, sz % 5));
        ++i;
    }

    int medianAlongAll;
    if (sz <= 5) medianAlongAll = medians[0];
    else medianAlongAll = median(medians, 0, i - 1, i / 2);
    
    int medAlongAllPos = divide(A, l, r, medianAlongAll);
    if (medAlongAllPos - l == index - 1)
        return A[medAlongAllPos];
    if (medAlongAllPos - l > index - 1)
        return median(A, l, medAlongAllPos - 1, index);
    return median(A, medAlongAllPos + 1, r , index - medAlongAllPos + l - 1);
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
    quicksort(A, 0, n - 1);

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