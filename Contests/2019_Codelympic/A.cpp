#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



/*
 * Complete the 'maxShared' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts WEIGHTED_INTEGER_GRAPH friends as parameter.
 */

/*
 * For the weighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] and <name>_to[i]. The weight of the edge is <name>_weight[i].
 *
 */

 const int MAX_WEIGHT = 105;

class UFDS {
private:
    int parent[200][200];

public:
    UFDS(int friends_nodes, int friends_edges) {
        for (int i = 1; i <= friends_nodes; i++) {
            for (int j = 1; j <= MAX_WEIGHT; j++) {
                this->parent[i][j] = -1;
            }
        }
    }

    void setInterest(int node_number, int interest_number) {
        this->parent[node_number][interest_number] = node_number;
    }

    int findParent(int node_number, int interest) {
        int par = this->parent[node_number][interest];
        if (par == node_number || par == -1) {
            return node_number;
        }
        int pred = this->findParent(par, interest);
        this->parent[node_number][interest] = pred;
        return pred;
    }

    void connect(int node_1, int node_2, int interest) {
        int parent_1 = this->findParent(node_1, interest);
        int parent_2 = this->findParent(node_2, interest);
        this->parent[parent_1][interest] = parent_2;
    }

    bool isConnected(int node_1, int node_2, int interest) {
        return this->findParent(node_1, interest) == this->findParent(node_2, interest);
    }

    int countConnection(int node_1, int node_2) {
        int connection = 0;
        for (int i = 1; i <= MAX_WEIGHT; i++) {
            if (this->isConnected(node_1, node_2, i)) {
                connection++;
            }
        }
        return connection;
    }
};

int maxShared(int friends_nodes, vector<int> friends_from, vector<int> friends_to, vector<int> friends_weight) {
    int friends_edges = friends_from.size();
    UFDS* ufds = new UFDS(friends_nodes, friends_edges);

    for (int i = 0; i < friends_edges; i++) {
        ufds->setInterest(friends_from[i], friends_weight[i]);
        ufds->setInterest(friends_to[i], friends_weight[i]);
    }

    for (int i = 0; i < friends_edges; i++) {
        ufds->connect(friends_from[i], friends_to[i], friends_weight[i]);
    }

    int ans = 0;
    int maxConnection = 0;
    for (int i = 1; i <= friends_nodes; i++) {
        for (int j = i + 1; j <= friends_nodes; j++) {
            int connection = ufds->countConnection(i, j);
            if (connection > maxConnection) {
                maxConnection = connection;
                ans = i * j;
            } else if (connection == maxConnection) {
                ans = max(ans, i * j);
            }
        }
    }
    return ans;
}

int main()
{
    string friends_nodes_edges_temp;
    getline(cin, friends_nodes_edges_temp);

    vector<string> friends_nodes_edges = split(rtrim(friends_nodes_edges_temp));

    int friends_nodes = stoi(friends_nodes_edges[0]);
    int friends_edges = stoi(friends_nodes_edges[1]);

    vector<int> friends_from(friends_edges);
    vector<int> friends_to(friends_edges);
    vector<int> friends_weight(friends_edges);

    for (int i = 0; i < friends_edges; i++) {
        string friends_from_to_weight_temp;
        getline(cin, friends_from_to_weight_temp);

        vector<string> friends_from_to_weight = split(rtrim(friends_from_to_weight_temp));

        int friends_from_temp = stoi(friends_from_to_weight[0]);
        int friends_to_temp = stoi(friends_from_to_weight[1]);
        int friends_weight_temp = stoi(friends_from_to_weight[2]);

        friends_from[i] = friends_from_temp;
        friends_to[i] = friends_to_temp;
        friends_weight[i] = friends_weight_temp;
    }

    int result = maxShared(friends_nodes, friends_from, friends_to, friends_weight);

    cout << result << "\n";

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}