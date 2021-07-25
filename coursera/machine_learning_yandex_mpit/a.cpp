#define _USE_MATH_DEFINES
#define forn(i, n) for(lli i=0; i<n; i++)
#define forn1(i, n) for(lli i=1; i<n; i++)
#define debug(x) cerr << "------" << x << endl;
#define All(x) x.begin(), x.end()
#define elif else if
#define lli long long int
#define _USE_MATH_DEFINES
#define _x first
#define _y second

#define _CRT_SECURE_NO_WARNINGS



//#include <bits/stdc++.h>

#include <stdlib.h>
#include <limits.h>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <cmath>
#include <numeric>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <bitset>
#include <stack>
#include <list>
#include <sstream>

#include <random>
#include <typeinfo>

using namespace std;

//Constant vars

const lli MOD = 1000000007, LIM = 4294967295;

//Vars

lli n, m, a, b, c, d, q, k, tr, summ, ans, minx, maxx, l, r, mid, l1, r1, mid1, res, mass1[1000000], mass2[1000000], mass[1000000];

string s, trs, str, ss;

//Structures

set<lli> g, bb, all;
set<lli> myset, myset1;
vector<lli> myvec, myvec1, toWrite, myvec2;
vector<pair<lli, lli>> mm, mm1;
vector<vector<lli>> mvv;
queue<lli> myq;
map<lli, lli> mymap, mymap1, mymap2;
map<lli, vector<lli>> mymapvec;
multiset<lli> mmset;
unordered_map<string, lli> smap;





int compare(const void * a, const void * b) {

	return -((*(lli*)a) - (*(lli*)b));

};

lli gcd(lli a, lli b) {

	while (b != 0) {

		lli t = b;
		b = a % b;
		a = t;

	}

	return a;

}

lli gcdex(lli a, lli b, lli & x, lli & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	lli x1, y1;
	lli d = gcdex(b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

lli NOK(lli n1, lli n2) {

	return n1 * n2 / gcd(n1, n2);

}

lli bin_pow(lli base, lli p) {
	if (p == 1) {
		return base % MOD;
	}
	if (p == 0) {
		return 1;
	}

	if (p % 2 == 0) {
		lli t = bin_pow(base, p / 2) % MOD;
		return t * t % MOD;
	}
	else {
		return bin_pow(base, p - 1) * base % MOD;
	}
}

lli inverse_element(lli x) {
	return bin_pow(x, MOD - 2);
}


lli divide(lli a, lli b) {
	return a * inverse_element(b) % MOD;
}

void doo(lli i) {

	toWrite.push_back(i + 1);
	swap(mass[i], mass[i + 1]);
	swap(mass[i], mass[i + 2]);

}


lli rec(string s, int c) {

	return 1;

}

void dl() {

	cout << "DEADLOCK";
	exit(0);

}

void ok() {

	cout << "OK";
	exit(0);

}

int main() {

	//freopen("input.txt", "r", stdin);
	//freopen("testlist.txt", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie();

	q = 1;
	cin >> q;

	while (q--) {

		cin >> s;

		forn(i, 10) {

			mass[i] = 0;

		}

		m = 0;

		forn(i, s.length()) {

			mass[s[i] - '0']++;
			m = max(m, mass[s[i] - '0']);

		}

		forn(i, 10) {

			if (mass[i] > m / 2) {

				forn(j, 10) {

					if (i != j && mass[j] > m / 2) {

						a = 0;
						b = 0;

						forn(k, s.length()) {

							if (a == 0 && s[k] - '0' == i) {

								a = 1;

							}

							if (a == 1 && s[k] - '0' == j) {

								a = 0;
								b += 2;

							}

						}

						m = max(m, b);
					}
				}
			}
		}

		cout << s.length() - m << endl;

	}

	return 0;
}
//
