#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &A, int l, int r) {
    if (l == r)
        return;
    int m = l + (r - l) / 2, p1 = l, p2 = m + 1;
    merge(A, l, m);
    merge(A, m + 1, r);
    vector<int> temporary;
    while (p1 <= m && p2 <= r) {
        if (A[p1] <= A[p2]) {
            temporary.push_back(A[p1]);
            ++p1;
        }
        else {
            temporary.push_back(A[p2]);
            ++p2;
        }
    }
    while (p1 <= m) {
        temporary.push_back(A[p1]);
        ++p1;
    }
    while (p2 <= r) {
        temporary.push_back(A[p2]);
        ++p2;
    }
    for (int i = 0; i < r - l + 1; ++i) {
        A[i + l] = temporary[i];
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
    
    /* Sort process (recursive merge) */
    merge(A, 0, n - 1);

    if (argc == 2) {
        cout << "Sorted array :\n";
        for (int i = 0; i < n; ++i)
            cout << A[i] << ' ';
        cout << '\n';
    }
    
    return 0;
}