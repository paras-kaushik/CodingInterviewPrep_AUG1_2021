#include<iostream>
#include<string>
using namespace std;
int main(){
    string s="12";
    int x=3;
    s+=(to_string(x));// CONVERTING INT TO STRING IN C++
    cout<<s<<endl;
    
    x=stoi(s);//stoull for string to unsigned long long
    cout<<x+1<<endl;// CONVERTING STRING TO INT
    
    cout<<s.front()<<" "<<s.back()<<endl;
    s.clear();
    cout<<s<<"ok cleared"<<endl;
    
    return 0;
}
