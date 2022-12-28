//TC: 

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
         unordered_set<string> s(wordList.begin(), wordList.end());
        vector<string>used;
        int lv=0;
        queue<vector<string>>q;
        q.push({beginWord});
        s.erase(beginWord);
        used.push_back(beginWord);
        vector<vector<string>>ans;
        
        while(!q.empty()){
            vector<string>v=q.front();q.pop();
            
            if(v.size()>lv){lv++;
                for(auto it:used){
                    s.erase(it);
                }
                used.clear();
            }
            string word=v.back();
            if(word==endWord){
                if(ans.size()==0){ans.push_back(v);}
                else if(ans[0].size()==v.size()){ans.push_back(v);}
            }
            
            for(int i=0;i<word.size();i++){
                char ori=word[i];
                for(char j='a';j<='z';j++){
                    word[i]=j;
                    if(s.count(word)){
                        v.push_back(word);
                        q.push(v);
                        used.push_back(word);
                        v.pop_back();
                    }
                }
                word[i]=ori;
            }
        }
        return ans;
    }
};