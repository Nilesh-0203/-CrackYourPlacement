bool check(int i,string &text, string &pattern){
	for(int j=0;j<pattern.length();j++){
		if(pattern[j]==text[i]){
			i++;
		}
		else{
			return false;
		}
	}
	return true;
}

vector<int> stringMatch(string text, string pattern) {
	// Write your code here.
	vector<int>ans;
	int n=text.length();
	int m=pattern.length();
	for(int i=0;i<=n-m;i++){
		if(text[i]==pattern[0]){
			if(check(i,text,pattern)){
				ans.push_back(i+1);
			}
		}
	}
	return ans;
}
