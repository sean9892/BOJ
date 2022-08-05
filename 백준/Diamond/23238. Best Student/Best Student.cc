#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
using ll = long long;
using pii = pair<int, int>;
#define fi first
#define se second

vector<int> v, w;
int L[100010];
int R[100010];
int res[100010];
vector<int> ID[100010];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, Q;
  cin >> N >> Q;
  v.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> v[i];
  }
  w = v;
  sort(all(w));
  w.erase(unique(all(w)), w.end());
  for (int i = 0; i < N; i++) {
    v[i] = lower_bound(all(w), v[i]) - w.begin();
  }
  const int BK = (1 << 8);
  const int BN = (N - 1) / BK + 1;
  for (int i = 0; i < Q; i++) {
    cin >> L[i] >> R[i];
    L[i]--;
    R[i]--;
    ID[L[i] / BK].push_back(i);
  }
  for (int i = 0; i < BN; i++) {
    sort(all(ID[i]), [&](int x, int y) { return R[x] < R[y]; });
    int st = (i + 1) * BK - 1;
    int pre = st;
    vector<int> cnt(N);
    pii pmx(cnt[0], 0);
    for (int j : ID[i]) {
      int l = L[j], r = R[j];
      // non-first block recording (R[j] monotonicity)
      for (int x = pre + 1; x <= r; x++) {
        cnt[v[x]]++;
        pmx = max(pmx, pii(cnt[v[x]], v[x]));
      }
      pre = max(st, r);
      pii mx = pmx;
      // first block naive process
      for (int x = l; x <= min(r, st); x++) {
        cnt[v[x]]++;
        mx = max(mx, pii(cnt[v[x]], v[x]));
      }
      res[j] = mx.se;
      // first block rollback
      for (int x = l; x <= min(r, st); x++) {
        cnt[v[x]]--;
      }
    }
  }
  for (int i = 0; i < Q; i++) {
    cout << w[res[i]] << "\n";
  }
}