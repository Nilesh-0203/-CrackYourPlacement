class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> v(n);
        unordered_set<int> elementsInA, elementsInB;
        for (int i = 0; i < n; i++) {
            elementsInA.insert(A[i]);
            elementsInB.insert(B[i]);

            int Count = 0;
            for (int element : elementsInA) {
                if (elementsInB.count(element)) {
                    Count++;
                }
            }
            v[i] = Count;
        }
        return v;
    }
};