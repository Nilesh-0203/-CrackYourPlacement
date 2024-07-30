class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st;
        for(string word:wordList){
            st.insert(word);
        }
        if(st.find(endWord)==st.end()){
            return 0;
        }
        int len=beginWord.size();
        int level=0;
        queue<string>q;
        q.push(beginWord);
        while(!q.empty()){
            level++;
            int n=q.size();
            for(int i=0;i<n;i++){
                string front=q.front();
                q.pop();
                for(int j=0;j<len;j++){
                    char org=front[j];
                    for(char ch='a';ch<='z';ch++){
                        front[j]=ch;
                        if(front==endWord){
                            return level+1;
                        }
                        if(st.find(front)==st.end()){
                            continue;
                        }
                        st.erase(front);
                        q.push(front);
                    }
                    front[j]=org;
                }
            }
        }
        return 0;
    }
};