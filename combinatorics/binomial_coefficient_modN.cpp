//First we precompute all factorials modulo m up to maxn with following algorithm:
factorial[0] = 1;
for (int i = 1; i <= MAXN; i++) {
    factorial[i] = factorial[i - 1] * i % m;
}

//And afterwards we can compute the binomial coefficient in O(log m) time
long long binomial_coefficient(int n, int k) {
    return factorial[n] * inverse(factorial[k] * factorial[n - k] % m) % m;
    //inverse function -> algebra's section
}