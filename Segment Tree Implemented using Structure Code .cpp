struct SegmentTree {
	int n;
	vector <ll> tree, lazy;
	SegmentTree(int n) :
		n(n), tree(4 * n), lazy(4 * n) {}
	void update(int i, int st, int en, int l, int r, int val) {
		if(lazy[i]) {
			tree[i] += lazy[i];
			if(st != en) {
				lazy[2 * i] += lazy[i];
				lazy[2 * i + 1] += lazy[i];
			}
			lazy[i] = 0;
		}
		if(en < l || st > r) return;
		if(l <= st && en <= r) {
			tree[i] += val;
			if(st != en) {
				lazy[2 * i] += val;
				lazy[2 * i + 1] += val;
			}
			return;
		}
		int mid = (st + en) / 2;
		update(2 * i, st, mid, l, r, val);
		update(2 * i + 1, mid + 1, en, l, r, val);
		tree[i] = min(tree[2 * i], tree[2 * i + 1]);
	}
	ll query(int i, int st, int en, int l, int r) {
		if(lazy[i]) {
			tree[i] += lazy[i];
			if(st != en) {
				lazy[2 * i] += lazy[i];
				lazy[2 * i + 1] += lazy[i];
			}
			lazy[i] = 0;
		}
		if(en < l || st > r) return 1e18;
		if(l <= st && en <= r) return tree[i];
		int mid = (st + en) / 2;
		return min(query(2 * i, st, mid, l, r), query(2 * i + 1, mid + 1, en, l, r));
	}
};