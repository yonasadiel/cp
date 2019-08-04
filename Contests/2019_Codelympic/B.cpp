#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'predictAnswer' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY stockData
 *  2. INTEGER_ARRAY queries
 */

void precompute(vector<int>* stockData, vector<int>* result, int dir) {
    stack<int> st;
    int start = (dir == 1 ? 0 : (stockData->size() - 1));
    int end = (dir == 1 ? stockData->size() : -1);
    for (int i = start; i != end; i += dir) {
        if (st.empty()) {
            st.push(i);
        } else {
            while (!st.empty() && stockData->at(st.top()) > stockData->at(i)) {
                result->at(st.top()) = i;
                st.pop();
            }
            st.push(i);
        }
    }
    while (!st.empty()) {
        result->at(st.top()) = -1;
        st.pop();
    }
}

vector<int> predictAnswer(vector<int> stockData, vector<int> queries) {
    vector<int> lowerRight(stockData.size() + 5);
    vector<int> lowerLeft(stockData.size() + 5);
    precompute(&stockData, &lowerRight, 1);
    precompute(&stockData, &lowerLeft, -1);

    for (int i : lowerRight) cout << i << " "; cout << endl;
    for (int i : lowerLeft) cout << i << " "; cout << endl;

    vector<int> ans;
    for (int q : queries) {
        q--; // adjustment to zero-based index
        if (lowerRight[q] == -1 && lowerLeft[q] == -1) {
            ans.push_back(-1);
        } else if (lowerRight[q] == -1) {
            ans.push_back(lowerLeft[q] + 1);
        } else if (lowerLeft[q] == -1) {
            ans.push_back(lowerRight[q] + 1);
        } else {
            int distToLeft = q - lowerLeft[q];
            int distToRight = lowerRight[q] - q;
            if (distToLeft <= distToRight) {
                ans.push_back(lowerLeft[q] + 1);
            } else {
                ans.push_back(lowerRight[q] + 1);
            }
        }
    }
    return ans;
}

int main()
{

    string stockData_count_temp;
    getline(cin, stockData_count_temp);

    int stockData_count = stoi(ltrim(rtrim(stockData_count_temp)));

    vector<int> stockData(stockData_count);

    for (int i = 0; i < stockData_count; i++) {
        string stockData_item_temp;
        getline(cin, stockData_item_temp);

        int stockData_item = stoi(ltrim(rtrim(stockData_item_temp)));

        stockData[i] = stockData_item;
    }

    string queries_count_temp;
    getline(cin, queries_count_temp);

    int queries_count = stoi(ltrim(rtrim(queries_count_temp)));

    vector<int> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        string queries_item_temp;
        getline(cin, queries_item_temp);

        int queries_item = stoi(ltrim(rtrim(queries_item_temp)));

        queries[i] = queries_item;
    }

    vector<int> result = predictAnswer(stockData, queries);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
