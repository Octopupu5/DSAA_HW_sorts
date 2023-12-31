#include <bits/stdc++.h>
using namespace std;

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

    /* Sorting process */
    for (int i = 0; i < n; ++i) {
        int saved = A[i];
        for (int j = i - 1; j >= 0 && A[j] > saved; --j)
            swap(A[j], A[j + 1]);
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