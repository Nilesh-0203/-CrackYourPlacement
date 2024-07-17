void printDups(string str)
{
    unordered_map<char, int> mp;
    for (int i = 0; i < str.length(); i++) {
        mp[str[i]]++;
    }
    for (auto it : mp) {
        if (it.second > 1){
            cout << it.first<<" "<< it.second<<endl;
        }
    }
}
