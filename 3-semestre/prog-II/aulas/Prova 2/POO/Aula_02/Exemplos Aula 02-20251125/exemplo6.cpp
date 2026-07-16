#include<string>
#include<iostream>


using namespace std;


int main(){
    string s("Hello World");
    for(auto &c : s){
        c = toupper(c);
    }
    cout << s << endl;
}