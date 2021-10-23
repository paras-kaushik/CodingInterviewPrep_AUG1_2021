#include<iostream>
typedef unsigned long long ull;
using namespace std;
int* getLps(string pattern){
    ull len=pattern.length();
    int* lps=new int[len]();
    
    lps[0]=0;
    int j=0;
    int i=1;
    // lps[k]-> Length of longest prefix which is also a suffix between 0 to k
    while(i<len){
        if(pattern[i]==pattern[j]){
            lps[i]=j+1;// added one as we are storing length and we will get pointer to the character JUST after the matched lps
            i++;
            j++;
        }else{
            if(j==0){
                lps[i]=0;// pattern doesnt match
                i++;
            }
            j=lps[j-1];//try previous one
        }
    }
    return lps;
}
bool kmpSearch(string text,string pattern){
    ull lenText=text.length();
    ull lenPatt=pattern.length();
    int * lps=getLps(pattern);
    for(int i=0;i<lenPatt;i++){
        cout<<lps[i]<<" ";
    }
    cout<<endl;
    int i=0;
    int j=0;
    while(i<lenText && j<lenPatt){
        if(text[i]==pattern[j]){
            i++;
            j++;
        }else{
            if(j==0){
                i++;//move on - pattern doesnt match
            }else{
                j=lps[j-1];// instead of starting from the begining in the pattern
            }
        }
    }
    
    if(j==lenPatt)return true;
    
    return false;
}
int main(){
    string str="abcxabcdabcdabcy";
    string subString="abcdabcy";
    cout<<kmpSearch(str, subString)<<endl;
    return 0;
    
}
