#include<bits/stdc++.h>
using namespace std;
using lint = long long;
const lint mod = 1e9+7;
lint ipow(lint x, lint p){
	lint ret = 1, piv = x;
	while(p){
		if(p & 1) ret = ret * piv % mod;
		piv = piv * piv % mod;
		p >>= 1;
	}
	return ret;
}
vector<lint> berlekamp_massey(vector<lint> x){
	vector<lint> ls, cur;
	lint lf, ld;
	for(lint i=0; i<x.size(); i++){
		lint t = 0;
		for(lint j=0; j<cur.size(); j++){
			t = (t + 1ll * x[i-j-1] * cur[j]) % mod;
		}
		if((t - x[i]) % mod == 0) continue;
		if(cur.empty()){
			cur.resize(i+1);
			lf = i;
			ld = (t - x[i]) % mod;
			continue;
		}
		lint k = -(x[i] - t) * ipow(ld, mod - 2) % mod;
		vector<lint> c(i-lf-1);
		c.push_back(k);
		for(auto &j : ls) c.push_back(-j * k % mod);
		if(c.size() < cur.size()) c.resize(cur.size());
		for(lint j=0; j<cur.size(); j++){
			c[j] = (c[j] + cur[j]) % mod;
		}
		if(i-lf+(lint)ls.size()>=(lint)cur.size()){
			tie(ls, lf, ld) = make_tuple(cur, i, (t - x[i]) % mod);
		}
		cur = c;
	}
	for(auto &i : cur) i = (i % mod + mod) % mod;
	return cur;
}
lint get_nth(vector<lint> rec, vector<lint> dp, lint n){
	lint m = rec.size();
	vector<lint> s(m), t(m);
	s[0] = 1;
	if(m != 1) t[1] = 1;
	else t[0] = rec[0];
	auto mul = [&rec](vector<lint> v, vector<lint> w){
		lint m = v.size();
		vector<lint> t(2 * m);
		for(lint j=0; j<m; j++){
			for(lint k=0; k<m; k++){
				t[j+k] += 1ll * v[j] * w[k] % mod;
				if(t[j+k] >= mod) t[j+k] -= mod;
			}
		}
		for(lint j=2*m-1; j>=m; j--){
			for(lint k=1; k<=m; k++){
				t[j-k] += 1ll * t[j] * rec[k-1] % mod;
				if(t[j-k] >= mod) t[j-k] -= mod;
			}
		}
		t.resize(m);
		return t;
	};
	while(n){
		if(n & 1) s = mul(s, t);
		t = mul(t, t);
		n >>= 1;
	}
	lint ret = 0;
	for(lint i=0; i<m; i++) ret += 1ll * s[i] * dp[i] % mod;
	return ret % mod;
}
lint guess_nth_term(vector<lint> x, lint n){
	if(n < x.size()) return x[n];
	vector<lint> v = berlekamp_massey(x);
	if(v.empty()) return 0;
	return get_nth(v, x, n);
}
struct elem{lint x, y, v;}; // A_(x, y) <- v, 0-based. no duplicate please..
vector<lint> get_min_poly(lint n, vector<elem> M){
	// smallest poly P such that A^i = sum_{j < i} {A^j \times P_j}
	vector<lint> rnd1, rnd2;
	mt19937 rng(0x14004);
	auto randint = [&rng](lint lb, lint ub){
		return uniform_int_distribution<lint>(lb, ub)(rng);
	};
	for(lint i=0; i<n; i++){
		rnd1.push_back(randint(1, mod - 1));
		rnd2.push_back(randint(1, mod - 1));
	}
	vector<lint> gobs;
	for(lint i=0; i<2*n+2; i++){
		lint tmp = 0;
		for(lint j=0; j<n; j++){
			tmp += 1ll * rnd2[j] * rnd1[j] % mod;
			if(tmp >= mod) tmp -= mod;
		}
		gobs.push_back(tmp);
		vector<lint> nxt(n);
		for(auto &i : M){
			nxt[i.x] += 1ll * i.v * rnd1[i.y] % mod;
			if(nxt[i.x] >= mod) nxt[i.x] -= mod;
		}
		rnd1 = nxt;
	}
	auto sol = berlekamp_massey(gobs);
	reverse(sol.begin(), sol.end());
	return sol;
}
lint det(lint n, vector<elem> M){
	vector<lint> rnd;
	mt19937 rng(0x14004);
	auto randint = [&rng](lint lb, lint ub){
		return uniform_int_distribution<lint>(lb, ub)(rng);
	};
	for(lint i=0; i<n; i++) rnd.push_back(randint(1, mod - 1));
	for(auto &i : M){
		i.v = 1ll * i.v * rnd[i.y] % mod;
	}
	auto sol = get_min_poly(n, M)[0];
	if(n % 2 == 0) sol = mod - sol;
	for(auto &i : rnd) sol = 1ll * sol * ipow(i, mod - 2) % mod;
	return sol;
}

int main(void){
	vector<lint> v={1,272,589185,930336768,853401154,217676188,136558333,415722813,985269529,791527976,201836136,382110354,441223705,661537677,641601343,897033284,816519670,365311407,300643484,936803543,681929467,462484986,13900203,657627114,96637209,577140657,600647073,254604056,102389682,811580173,592550067,587171680,526467503,265885773,951722780,219627841,371508152,283501391,159234514,439380999,722868959,125599834,351398134,456317548,365496182,614778702,502680047,193063685,309004764,743901785,870955115,312807829,160375015,691844624,137034372,350330868,895680450,282610535,317897557,28600551,583305647,539409363,327406961,627805385,680183978,681299085,954964592,743524009,788048339,699454626,666369521,857206425,490463127,477198247,599963928,21247982,107843532,753662937,239039324,608530376,523383010,654448101,801430395,393034561,93313778,983052766,240336620,825539982,525118275,563899476,706271688,547405697,477082486,664058071,353207278,729486413,795704637,999271072,540749624,411451016,736422999,879369181,918733916,982303557,512499644,261033810,391766409,334092786,931794834,854181848,821090190,751839258,433126935,571194155,52438113,552977155,320805296,173355929,969659468,258854248,159509877,374487748,401382023,44060530,510164669,336596764,652050424,373872552,517226592,719871041,43959496,235333335,304962191,253114421,43638769,361871585,8060121,147014624,114846460,430864038,368951246,863795701,36066788,971606149};
	for(lint i:berlekamp_massey(v))cout<<i<<" ";
}
