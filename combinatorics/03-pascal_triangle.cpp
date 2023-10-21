
//Algorithm for Pascal’s triangle with some maxn:

const int maxn = 6;//triangle limit
int P[maxn + 1][maxn + 1];
P[0][0] = 1;

for (int n = 1; n <= maxn; ++n) {
    P[n][0] = P[n][n] = 1;
    for (int k = 1; k < n; ++k){
        P[n][k] = P[n - 1][k - 1] + P[n - 1][k];
        //cout << C[n][k] << " ";
    }
}