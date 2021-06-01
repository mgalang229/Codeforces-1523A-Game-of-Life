#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, m;
		string s;
		cin >> n >> m >> s;
		// create 'index' vector to store the mark the valid indices
		vector<int> index;
		for (int i = 0; i < min(n, m); i++) {
			for (int j = 0; j < n; j++) {
				if (j == 0) {
					// check if the first element is equal to '0' and the next element is '1'
					if (s[j] == '0' && s[j + 1] == '1') {
						// store this index
						index.emplace_back(j);
					}
				} else if (j == n - 1) {
					// check if the last element is equal to '0' and the previous element is '1'
					if (s[j] == '0' && s[j - 1] == '1') {
						// store this index
						index.emplace_back(j);
					}
				} else {
					// check if the current element is equal to '0' and ONLY ONE of its neighbors is equal to '1'
					if (s[j] == '0' && (s[j + 1] - '0' + s[j - 1] - '0') == 1) {
						// store this index
						index.emplace_back(j);
					}
				}
			}
			for (auto id : index) {
				// change the value of all the marked and valid indices to '1'
				s[id] = '1';
			}
		}		
		cout << s << '\n';
	}
	return 0;
}
