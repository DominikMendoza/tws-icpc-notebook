const int MAXN = 100005; 
const int SQRTN = 320;  

vector<int> arr(MAXN);       
vector<int> blockSum(SQRTN); 

int blockSize; 

void init(int n) {
    blockSize = sqrt(n); 
    for (int i = 0; i < n; i++) {
        blockSum[i / blockSize] += arr[i];
    }
}

void update(int index, int value) {
    blockSum[index / blockSize] += value - arr[index];
    arr[index] = value;
}

int query(int l, int r) {
    int sum = 0;
    while (l % blockSize != 0 && l <= r) {
        sum += arr[l];
        l++;
    }
    while (l + blockSize <= r) {
        sum += blockSum[l / blockSize];
        l += blockSize;
    }
    while (l <= r) {
        sum += arr[l];
        l++;
    }
    return sum;
}
