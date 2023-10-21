//You are given two numbers n and k. Find the largest power of k x such that n! is divisible by kx.
//Example:
//For n = 6, 6! = 720 = 24 · 31 · 51 :
//If k = 2, the largest power of k = x = 4
//If k = 3, the largest power of k = x = 1
//If k = 4, the largest power of k = x = 2
int fact_pow (int n, int k) {
    int res = 0;
    while (n) {
        n /= k;
        res += n;
    }
    return res;
}

//For general values we will canonically decompose the number k. 
//After that, we use the algorithm described above for each ki, this value will be ai. Finally, the answer for k
//will be min(ai/pi) among i = 1, 2, 3, ..., m