void update(vector<int>& fenwickTree, int index, int delta) {
    index++;
    int n = fenwickTree.size();
    while (index < n) {
        fenwickTree[index] += delta;
        index += index & -index;
    }
}

int query(const vector<int>& fenwickTree, int index) {
    index++;
    int sum = 0;
    while (index > 0) {
        sum += fenwickTree[index];
        index -= index & -index;
    }
    return sum;
}

int main() {
    int n; cin >> n;

    vector<int> arr(n, 0); // Arreglo original
    vector<int> fenwickTree(n + 1, 0); // Arbol BIT

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        update(fenwickTree, i, arr[i]);
    }
    return 0;
}
