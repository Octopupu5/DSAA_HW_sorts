#include <bits/stdc++.h>
#include <chrono>
using namespace std;

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
    
    auto start = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);

    /* Sorting process */
    for (int i = 0; i < n; ++i) {
        int saved = A[i];
        for (int j = i - 1; j >= 0 && A[j] > saved; --j)
            swap(A[j], A[j + 1]);
    }

    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
 
    time_taken *= 1e-9;
 
    cout << "Time taken by program is : " << fixed << time_taken << setprecision(9);
    cout << " sec" << endl;

    if (argc == 2) {
        cout << "Sorted array :\n";
        for (int i = 0; i < n; ++i)
            cout << A[i] << ' ';
        cout << '\n';
    }

    return 0;
}