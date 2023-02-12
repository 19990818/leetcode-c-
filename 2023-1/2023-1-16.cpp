#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> arr1=split(sentence1),arr2=split(sentence2);
        if(arr1.size()<arr2.size()){swap(arr1,arr2);}
      
        int diff=arr1.size()-arr2.size();
        for(int i=0;i<arr1.size();i++){
            auto reconduct=[&]{
                vector <string> res;
                for(int j=0;j<i;j++){
                    res.push_back(arr1[j]);
                }
                for(int j=i+diff;j<arr1.size();++j){
                    res.push_back(arr1[j]);
                }
                return res;
            };
            auto equal=[&]{
                auto temp=reconduct();
                if(temp.size()!=arr2.size()){
                    return false;
                }
                for(int i=0;i<temp.size();++i){
                    if(temp[i]!=arr2[i]){
                        return false;
                    }
                }
                return true;
            };
            if(equal()){
                return true;
            }
        }
        return false;
    }
    vector<string> split(string a){
        string temp="";
        a+=" ";
        vector<string> res;
        for(auto c:a){
            if(c==' '){
                res.push_back(temp);
                temp="";
            }else{
                temp+=c;
            }
        }
        return res;
    }
    auto print(vector<string> &arr){
        for(auto a:arr){
            cout<<a<<endl;
        }
    }
};
