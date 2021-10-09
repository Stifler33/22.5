#include <iostream>
#include <map>
#include <string>
using namespace std;
bool chekAnagram(string &strOne, string &strTwo){
    map<string, string> words;
    words.insert(pair(strOne, strTwo));
    int sumCharOne = 0;
    int sumCharTwo = 0;
    if (words.begin()->second.length() == words.begin()->first.length()){
        for (int i = 0;i < words.begin()->second.length(); i++){
            sumCharOne += int(words.begin()->first[i]);
            sumCharTwo += int(words.begin()->second[i]);
        }
    }else return false;
    return sumCharOne == sumCharTwo;
}
int main(){
    string strOne = "";
    string strTwo = "";
    cout << "Enter first word\n";
    cin >> strOne;
    cout << "Enter second word\n";
    cin >> strTwo;
    if (chekAnagram(strOne, strTwo)){
        cout << "the words anagram\n";
    }else cout << "the words not anagram\n";
    return 0;
}