#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
    map<char, int> wordOne;
    map<char, int> wordTwo;
    char sy;
    string strOne = "";
    string strTwo = "";
    bool newStr = false;
    cout << "Enter word in format : 'first word' 'second word'\n";
    while(sy != '\n') {
        cin.read(&sy, 1);
        if (sy == ' ') newStr = true;
        if (newStr) {
            if (sy != '\n' && sy != ' ') wordTwo.insert({sy, 1});
        }else if (sy != '\n' && sy != ' ') wordOne.insert({sy, 1});
    }
    if (wordOne == wordTwo){
        cout << "the words anagram\n";
    }else cout << "the words not anagram\n";
    return 0;
}