#include <iostream>
#include <queue>

using namespace std;

struct AscCmp {
    bool operator()(const pair<int, int>& p1,
                    const pair<int, int>& p2)
    {
        return p1.second < p2.second;
    }
};

struct DscCmp {
    bool operator()(const pair<int, int>& p1,
                    const pair<int, int>& p2)
    {
        return p1.second > p2.second;
    }
};

class Solution {
private:
    priority_queue<pair<int, int>, vector<pair<int, int> >,
                   DscCmp>
        minQ;
    priority_queue<pair<int, int>, vector<pair<int, int> >,
                   AscCmp>
        maxQ;

    void constructMinMaxQ(const vector<int>& amount)
    {
        for (int i = 0; i < amount.size(); ++i) {
            if (amount[i] == 0)
                continue;
            if (amount[i] > 0) {
                maxQ.emplace(i, amount[i]);
            }
            else {
                minQ.emplace(i, amount[i]);
            }
        }
    }

    void solveTransaction()
    {
        while (!minQ.empty() && !maxQ.empty()) {
            pair<int, int> maxCreditEntry = maxQ.top();
            maxQ.pop();

            pair<int, int> maxDebitEntry = minQ.top();
            minQ.pop();

            int transaction_val = maxCreditEntry.second
                                  + maxDebitEntry.second;

            int debtor = maxDebitEntry.first,
                creditor = maxCreditEntry.first,
                owed_amount = 0;

            if (transaction_val == 0) {
                owed_amount = maxCreditEntry.second;
            }
            else if (transaction_val < 0) {
                owed_amount = maxCreditEntry.second;
                minQ.emplace(maxDebitEntry.first,
                             transaction_val);
            }
            else {
                owed_amount = -(maxDebitEntry.second);
                maxQ.emplace(maxCreditEntry.first,
                             transaction_val);
            }
            cout << "Person " << debtor << " pays "
                 << owed_amount << " to Person " << creditor
                 << endl;
        }
    }

public:
    void minCashFlow(const vector<vector<int> >& graph)
    {
        int n = graph.size();
        vector<int> amount(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int diff = graph[j][i] - graph[i][j];
                amount[i] += diff;
            }
        }
        constructMinMaxQ(amount);
        solveTransaction();
    }
};
