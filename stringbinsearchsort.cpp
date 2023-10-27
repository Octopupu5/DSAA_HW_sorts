#include <bits/stdc++.h>
using namespace std;

int main (int argc, char **argv) {
    if (argc > 2 || (argc == 2 && (string(argv[1]) != "print"))) {
        printf("Wrong input!\n");
        exit(-1);
    }

    /* Input process */
    mt19937 gen(time(nullptr));
    int n;
    cin >> n;
    int m;
    cin >> m;

    vector<string> A(n);
    for (auto & el : A) {
        el.resize(m);
        for (int i = 0; i < m; ++i)
            el[i] = 'a' + gen() % 26;
    }
    
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    ios_base::sync_with_stdio(false);

    /* Sort process */
    for (int i = 1; i < n; ++i) {
        int l = 0, r = i - 1;
        int right_most = i - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (A[i] < A[m]) {
                r = m - 1;
                right_most = min(right_most, m);
            }
            else
                l = m + 1;
        }
        for (int j = i; j >= l + 1; --j)
            swap(A[j], A[j - 1]);
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
            cout << A[i] << '\n';
    }

    return 0;
}