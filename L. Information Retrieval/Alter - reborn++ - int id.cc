#include <bits/stdc++.h>
#include <sstream>

using namespace std;

map < string, string > synonym;
map < string, int > id;

inline int get_id(const string &s) {
	auto it = id.find(s);
	if(it != id.end()) return it->second;

	int sz = id.size();
	id[s] = sz;
	
	auto it2 = synonym.find(s);
	if(it2 != synonym.end()) {
		id[it2->second] = sz;
	}

	return sz;
}

inline void to_low(string &s) {
	for(char &c : s) if(isalpha(c)) c = tolower(c);
}

vector<int> process_line(const string &line) {
	vector<int> ret;

	stringstream ss(line);
	string s;
	while(ss >> s) {
		ret.push_back(get_id(s));
	}

	sort(ret.begin(), ret.end());
	ret.erase(unique(ret.begin(), ret.end()), ret.end());

	return ret;
}

const int SIMILAR_WORD_LINE = 120;
const int QUERY_ANS_LINE = 6500;
const int QUERY_LEN = 200;
const int ANS_LEN = 800;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string str;
	assert(cin >> str);
	assert(str == "Similar");

	bool query_word = false;
	int similar_cnt = 0;
	
	while(cin >> str) {
		if(str == "Query") {
			query_word = true;
			break;
		}

		string syn;
		assert(cin >> syn);
		
		to_low(str);
		to_low(syn);
		synonym[str] = syn;
		synonym[syn] = str;

		get_id(str);
		get_id(syn);

		++similar_cnt;
	}
	assert(query_word);
	assert(similar_cnt <= SIMILAR_WORD_LINE);

	assert(getline(cin, str));	// blank line
	assert(str.empty());
	
	bool quit_word = false;
	int qa_cnt = 0;
	vector< vector<int> > lhs, rhs;
	vector< string > qu, re;

	while(getline(cin, str)) {
		if(str == "QUIT") {
			quit_word = true;
			break;
		}

		assert(count(str.begin(), str.end(), '\t') == 1);
		int pos = str.find('\t');
		assert(pos > 0);
		assert(pos + 1 < (int) str.size());

		string t_qu = str.substr(0, pos);
		string t_re = str.substr(pos + 1);

		assert((int) t_qu.size() <= QUERY_LEN);
		assert((int) t_re.size() <= ANS_LEN);
		
		qu.push_back(t_qu);
		re.push_back(t_re);

		to_low(t_qu);
		to_low(t_re);

		lhs.push_back(process_line(t_qu));
		rhs.push_back(process_line(t_re));

		++qa_cnt;
	}
	assert(quit_word);
	assert(qa_cnt <= QUERY_ANS_LINE);

	assert(qu.size() == re.size());
	assert(qu.size() == lhs.size());
	assert(re.size() == rhs.size());

	// for(auto &qq : lhs) {
	// 	cerr << "Query:\n";
	// 	for(auto &ss : qq) cerr << ss << " | ";
	// 	cerr << "\n";
	// }
	// for(auto &qq : rhs) {
	// 	cerr << "Response:\n";
	// 	for(auto &ss : qq) cerr << ss << " | ";
	// 	cerr << "\n";
	// }
	
	for(int i=0; i<(int) qu.size(); ) {
		int fr = i, to = i;
		while(to < (int) qu.size() and qu[to] == qu[fr]) ++to;
		--to;

		vector< pair<int, int> > vec;
		
		for(int j=fr; j<=to; ++j) {
			int cnt = 0;
			for(int lp=0, rp=0; lp<(int) lhs[i].size() and rp<(int) rhs[j].size(); ) {
				if(lhs[i][lp] == rhs[j][rp]) {
					++cnt;
					++lp;
					++rp;
				}
				else if(lhs[i][lp] < rhs[j][rp]) {
					++lp;
				}
				else {
					++rp;
				}
			}

			vec.push_back(make_pair(-cnt, j));
		}

		sort(vec.begin(), vec.end());
		for(auto &qq : vec) {
			cout << qu[i] << "\t" << re[qq.second] << "\n";
		}

		i = to + 1;
	}

	assert(!(cin >> str));

	return 0;
}
