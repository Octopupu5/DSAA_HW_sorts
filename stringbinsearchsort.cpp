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

    vector<string> A(n);
    for (auto & el : A)
        cin >> el;
    
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

    if (argc == 2) {
        cout << "Sorted array :\n";
        for (int i = 0; i < n; ++i)
            cout << A[i] << '\n';
    }

    return 0;
}