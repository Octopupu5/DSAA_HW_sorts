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
        string saved = A[i];
        for (int j = i - 1; j >= 0 && A[j] > saved; --j)
            swap(A[j], A[j + 1]);
    }

    if (argc == 2) {
        cout << "Sorted array :\n";
        for (int i = 0; i < n; ++i)
            cout << A[i] << '\n';
    }

    return 0;
}