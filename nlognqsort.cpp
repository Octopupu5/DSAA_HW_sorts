#include <bits/stdc++.h>
using namespace std;

int getMedian (vector<int> &A, int pos, int sz) {
    switch (sz) {
        case 1: {
            return A[pos];
        }
        case 2: {
            if (A[pos] > A[pos + 1]) swap(A[pos], A[pos + 1]);
            return A[pos + 1];
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
            return A[pos + 2];
        }
        default: {
            if (A[pos + 1] > A[pos]) swap(A[pos], A[pos + 1]);
            if (A[pos + 3] > A[pos + 2]) swap(A[pos + 2], A[pos + 3]);
            if (A[pos + 2] > A[pos]) {
                swap(A[pos], A[pos + 2]);
                swap(A[pos + 1], A[pos + 3]);
            }
            if (A[pos + 2] > A[pos + 4]) {
                if (A[pos + 4] > A[pos + 3])
                    swap(A[pos + 3], A[pos + 4]);
            }
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
	int pivot_index;
    for (pivot_index = l; pivot_index < r; ++pivot_index)
        if (A[pivot_index] == pivot)
            break;
    swap(A[pivot_index], A[r]);
    
    pivot_index = l;
    for (int i = l; i < r; ++i)
        if (A[i] <= pivot)
            swap(A[i], A[pivot_index++]);
    
    swap(A[pivot_index], A[r]);
    
    return pivot_index;
}

int findMedian (vector<int> &A, int l, int r, int index) {
	int sz = r - l + 1;
    int median_among_medians;
    vector<int> medians((sz + 4) / 5);

	for (int i = 0; i < sz / 5; i++)
		medians[i] = getMedian(A, l + i * 5, 5);
	if (sz / 5 * 5 != sz)
		medians[sz / 5] = getMedian(A, l + sz / 5 * 5, sz % 5);
    
    int count_medians = medians.size();
    if (count_medians == 1)
        median_among_medians = medians[0];
    else
        median_among_medians = findMedian(medians, 0, count_medians - 1, count_medians / 2);
    
    int pivot_among_medians = divide(A, l, r, median_among_medians);
	if (pivot_among_medians == l + index - 1)
		return A[pivot_among_medians];
	if (pivot_among_medians > l + index - 1)
		return findMedian(A, l, pivot_among_medians - 1, index);
	
    return findMedian(A, pivot_among_medians + 1, r, index - pivot_among_medians + l - 1);
}

void quicksort (vector<int> &A, int l, int r) { 
	if (l >= r) return;  
	int pivot_index = divide(A, l, r, findMedian(A, l, r, (r - l + 1) / 2)); 
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
        el = gen() % 5000;
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