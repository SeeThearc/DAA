#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
#define d 256
void search(string& pat,string& text,int q){
    int m=pat.length();
    int n=text.length();
    int i,j;
    int p=0,t=0;
    int h=1;
    for(i=0;i<m-1;i++){
        h=(h * d) % q;
    }
    for(i=0;i<m;i++){
        p=(p*d+pat[i])%q;
        t=(t*d+text[i])%q;
    }
    for(i=0;i<=n-m;i++){
        if(p==t){
            for(j=0;j<m;j++){
                if(pat[j]!=text[i+j]){
                    break;
                }
            }
            if(j==m){
                cout<<"pattern found at index: "<<i<<endl;
            }
        }
        if(i<n-m){
            t=(d*(t-text[i]*h)+text[i+m])%q;
        }
        if(t<0){
            t=t+q;
        }
    }
}
int main(){
    string text,pattern;
    cin>>text;
    cin>>pattern;
    search(pattern,text,101);
}