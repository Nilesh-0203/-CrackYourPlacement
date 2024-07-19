bool isPossible(long long a[], long long b[], int n, long long k) {
        // Your code goes here
    sort(a, a + n);
    sort(b, b + n, greater<int>());

    // Checking condition on each index.
    for (int i = 0; i < n; i++)
        if (a[i] + b[i] < k)
            return false;

    return true;
    }
