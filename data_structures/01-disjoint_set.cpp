#define MAXN 100
int pd[MAXN];
int rk[MAXN];

void makeSet(int n) {
  for (int i = 0; i < n; i++) {
    pd[i] = i;
    rk[i] = 0;
  }
}

int findSet(int u) {
  if (u == pd[u])
    return u;
  return pd[u] = findSet(pd[u]);
}

void unionSets(int u, int v) {
  u = findSet(u);
  v = findSet(v);
  if (u == v)
    return;
  if (rk[u] < rk[v])
    swap(u, v);
  pd[v] = u;
  if (rk[u] == rk[v])
    rk[u]++;
}