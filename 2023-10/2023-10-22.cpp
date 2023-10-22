#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <math.h>
using namespace std;

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int sum=0,res=0;
        for(int i=satisfaction.size()-1;i>=0&&sum>=0;i--){
            sum+=satisfaction[i];
            if(sum>=0){
                res+=sum;
            }
        }
        return res;
    }
};

class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(tasks.begin(),tasks.end());
        sort(processorTime.begin(),processorTime.end());
        int res=0;
        int j=0;
        for(int i=tasks.size()-1;i>=0;i-=4){
            res=max(res,tasks[i]+processorTime[j]);
            j++;
        }
        return res;
    }
};


class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        vector<int> res;
        vector<string> s;
        int cnt=0;
        for (string word:words){
            if(word=="prev"){
                cnt++;
                if(s.size()<cnt){
                    res.push_back(-1);
                }else{
                    res.push_back(atoi(s[s.size()-cnt].c_str()));
                }
            }else{
                s.push_back(word);
                cnt=0;
            }
        }
        return res;
    }
};


class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        vector<int> s;
        s.push_back(0);
        for(int i=1;i<groups.size();i++){
            if(groups[i]!=groups[s[s.size()-1]]){
                s.push_back(i);
            }
        }
        vector<string> res=vector<string>(s.size());
        for (int i=0;i<s.size();i++){
            res[i]=words[s[i]];
        }
        return res;
    }
};


class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        unordered_map<string,vector<int>> m;
        m[words[0]]={0};
        int cnt=1;
        for(int i=1;i<words.size();i++){
            for(string v:getNext(words[i])){    
                if(m[v].size()>m[words[i]].size()&&groups[i]!=groups[m[v][m[v].size()-1]]){
                    m[words[i]]={};
                    for(int val:m[v]){
                        m[words[i]].push_back(val);
                    }
                }
            }
            m[words[i]].push_back(i);
            int temp=m[words[i]].size();
            cnt=max(cnt,temp);
        }
        vector<string> res;
        for(auto entry:m){
            if(entry.second.size()==cnt){
                for(int v:entry.second){
                    res.push_back(words[v]);
                }
                break;
            }
        }
        return res;
    }
    vector<string> getNext(string s) {
        vector<string> res;
        for(int i=0;i<s.size();i++){
            for (int j=0;j<26;j++){
                if(s[i]!=('a'+j)){
                    char t=s[i];
                    s[i]='a'+j;
                    res.push_back(s);
                    s[i]=t;
                }
            }
        }
        return res;
    }
};