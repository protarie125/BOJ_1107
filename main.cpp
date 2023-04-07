#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;

auto mn = int{ 987'654'321 };

void calc(int n, const vb& brk, const string& num) {
	for (auto i = 0; i < 10; ++i) {
		if (!brk[i]) {
			const auto& now = num + to_string(i);

			auto ct = static_cast<int>(abs(n - stoi(now)) + now.length());
			mn = min(mn, ct);

			if (now.length() < 6) {
				calc(n, brk, now);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	cin >> n;

	int m;
	cin >> m;

	auto brk = vb(10, false);
	for (auto i = 0; i < m; ++i) {
		int x;
		cin >> x;

		brk[x] = true;
	}

	mn = abs(n - 100);

	if (m < 10) {
		calc(n, brk, "");
	}

	cout << mn;

	return 0;
}