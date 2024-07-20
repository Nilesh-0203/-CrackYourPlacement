class TrieNode{
    public:
    char ch;
    TrieNode* children[26];
    bool isTerminal;
    TrieNode(char data){
        ch=data;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
    }
};
class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root=new TrieNode('\0');
    }
    void addUtil(TrieNode* root,string word){
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }
        int index=word[0]-'a';
        TrieNode* child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }
        addUtil(child,word.substr(1));
    }
    void addWord(string word) {
        addUtil(root,word);
    }
    bool searchUtil(TrieNode* root,string word){
        if(word.length()==0){
            return root->isTerminal;
        }
        TrieNode* child;
        if(word[0]=='.'){
            for(auto c: root->children)
                if(c && searchUtil(c,word.substr(1))){
                    return true;
                }
            return false;
        }else{
            int index=word[0]-'a';
            if(root->children[index]!=NULL){
                child=root->children[index];
            }
            else{
                return false;
            }
        }
        return searchUtil(child,word.substr(1));
    }
    bool search(string word) {
        return searchUtil(root,word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */