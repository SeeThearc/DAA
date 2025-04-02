#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
vector<int> computelps(string& pat){
    int j=0;
    int i=1;
    vector<int> lps(pat.length());
    lps[0]=0;
    while(i<pat.length()){
        if(pat[i]==pat[j]){
            j++;
            lps[i]=j;
            i++;
        }
        else{
            if(j!=0){
                j=lps[j-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }
    return lps;
}
vector<int> search(string& text,string& pat){
    vector<int>lps=computelps(pat);
    int i=0,j=0;
    vector<int>res;
    while(i<text.length()){
        if(text[i]==pat[j]){
            i++;
            j++;
        }
        if(j==pat.length()){
            res.push_back(i-j);
            j=lps[j-1];
        }
        else if(i<text.length() && pat[j]!=text[i]){
            if(j!=0){
                j=lps[j-1];
            }
            else{
                i++;
            }
        }
    }
    return res;
}
int main(){
    string pat,text;
    cin>>text;
    cin>>pat;
    vector<int>result = search(text,pat);
    for(int index : result){
        cout<<"pattern found at: "<<index<<endl;
    }
}