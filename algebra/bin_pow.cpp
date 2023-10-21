
//recursive
long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}

//normal
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}


//with modulo
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

//multimplication of big numbers
long long modularMultiply(long long a, long long b, long long mod) {
    long long result = 0; // Initialize result
    
    // Convert a to its positive modulo if it's negative
    a %= mod;
    if (a < 0) a += mod;

    // Traverse through all bits of b
    while (b > 0) {
        // If current bit of b is set, add a to the result
        if (b & 1)
            result = (result + a) % mod;
        
        // Move to the next bit of b and double a
        a = (2 * a) % mod;
        b >>= 1;
    }

    return result % mod;
}