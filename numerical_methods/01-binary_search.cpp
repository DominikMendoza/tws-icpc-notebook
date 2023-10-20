// a sorted array is stored as a[0], a[1], ..., a[n-1]
int l = -1, r = n;
while(r - l > 1) {
    int m = (l + r) / 2;
    if(k < a[m]) {
        r = m; // a[l] <= k < a[m] <= a[r]
    } else {
        l = m; // a[l] <= a[m] <= k < a[r]
    }
}

// f(i) is a boolean function such that f(0) <= ... <= f(n-1)
int l = -1, r = n;
while(r - l > 1) {
    int m = (l + r) / 2;
    if(f(m)) {
        r = m; // 0 = f(l) < f(m) = 1
    } else {
        l = m; // 0 = f(m) < f(r) = 1
    }
}