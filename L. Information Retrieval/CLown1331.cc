#include <bits/stdc++.h>
using namespace std;

const int sz = 1e5 + 10;
using ll = long long;

struct Query {
    string QueryString;
    string CandidateResult;
    int Relevancy;
    int QueryGroup;
    int Order;
};

vector <string> split(const string &s, char splitChar) {
    vector <string> splittedString;
    string hand = "";
    for (char c: s) {
        if (c == splitChar) {
            splittedString.push_back(hand);
            hand.clear();
            continue;
        }
        hand.push_back(c);
    }
    splittedString.push_back(hand);
    return splittedString;
}

unordered_map <string, unordered_set <string> > simmilarDictionay;
vector <pair <string, string> > simmilarPairs;
unordered_map <string, int> queryNumber;

vector <Query> Queries;

void makeLowerCaseString(vector <string> &strList) {
    for_each(strList.begin(), strList.end(), [](string &s) -> void {
        for (char &c: s) {
            c = tolower(c);
        }
    });
}

int calculateRelevancy(vector <string> &queryString, vector <string> &candidateResult) {
    makeLowerCaseString(queryString);
    makeLowerCaseString(candidateResult);
    int relevancy = 0;
    unordered_set <string> candidateSet;
    unordered_set <string> querySet;
    for (const string &s: queryString) {
        querySet.insert(s);
    }
    for (const string &s: candidateResult) {
        candidateSet.insert(s);
    }
    unordered_set <string> relevantSet;
    for (const string &s: queryString) {
        if (candidateSet.find(s) != candidateSet.end()) {
            relevantSet.insert(s);
        }
        if (simmilarDictionay.count(s)) {
            for (const string &t: simmilarDictionay[s]) {
                if (candidateSet.find(t) != candidateSet.end() && querySet.find(t) == querySet.end()) {
                    relevantSet.insert(s);
                }
            }
        }
    }
    for (const auto &it: simmilarPairs) {
        if (relevantSet.find(it.second) != relevantSet.end()) {
            relevantSet.erase(it.second);
            relevantSet.insert(it.first);
        }
    }
    return relevantSet.size();
}

int main() {

    string line;

    getline(cin, line);

    while (getline(cin, line) && (line.size() != 5 && line != "Query")) {
        auto simmilarWords = split(line, ' ');
        makeLowerCaseString(simmilarWords);
        simmilarPairs.push_back(make_pair(simmilarWords[0], simmilarWords[1]));
        simmilarDictionay[simmilarWords[0]].insert(simmilarWords[1]);
        simmilarDictionay[simmilarWords[1]].insert(simmilarWords[0]);
    }

    int number = 0;

    int order = 0;

    while (getline(cin, line) && (line.size() != 4 && line != "QUIT")) {
        auto query = split(line, '\t');
        auto queryString = split(query[0], ' ');
        auto candidateResult = split(query[1], ' ');
        if (queryNumber.count(query[0]) == 0) {
            queryNumber[query[0]] = ++number;
        }
        Queries.push_back({
            query[0],
            query[1],
            calculateRelevancy(queryString, candidateResult),
            queryNumber[query[0]],
            ++order
        });
    }

    sort(Queries.begin(), Queries.end(), [](const Query &a, const Query &b) -> bool {
        if (a.QueryGroup == b.QueryGroup) {
            if (a.Relevancy == b.Relevancy) {
                return a.Order < b.Order;
            }
            return a.Relevancy > b.Relevancy;
        }
        return a.QueryGroup < b.QueryGroup;
    });

    for (Query query: Queries) {
        cout << query.QueryString << "\t" << query.CandidateResult << "\n";
    }

    return 0;
}
