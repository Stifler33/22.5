#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
string getFamily(string &operation){
    string input;
    for (int i = 0; i < operation.length(); i++){
        if (operation[i] >= 'a' && operation[i] <= 'z'){
            input += operation[i];
        }
    }
    return input;
}
string getNumber(string &operation){
    string input;
    for (int i = 0; i < operation.length(); i++){
        if (operation[i] >= '0' && operation[i] <= '9'){
            input += operation[i];
        }
    }
    return input;
}
int main() {
    //  number  family
    map<string, string> numberToFamily;
    //  family  number
    map<string, vector<string>> familyToNumber;
    vector<string> vecNumber;
    //init telephone book
    string operation;
    cout << "Enter operation\n";
    while(operation != "exit") {
        getline(cin, operation);
        if (operation == "exit") continue;
        //list book
        if (operation == "list"){
            cout << "family to number\n";
            for (auto outFN = familyToNumber.begin(); outFN != familyToNumber.end(); ++outFN){
                cout << outFN->first;
                for (int i = 0; i < outFN->second.size(); i++){
                    cout << outFN->second[i] << " ";
                }
                cout << endl;
            }
            cout << "number to family\n";
            for (auto outNF = numberToFamily.begin(); outNF != numberToFamily.end(); ++outNF){
                cout << outNF->first << " " << outNF->second << endl;
            }
        }
        // get number
        if (operation[0] >= 'a' && operation[0] <= 'z') {

            // get family or added number to book
        } else if (operation[0] >= '0' && operation[0] <= '9') {
           //added number book
           if (operation.back() >= 'a' && operation.back() <= 'z'){
               string number = getNumber(operation);
               string family = getFamily(operation);
               if (numberToFamily.count(number.c_str()) == 0) {
                   numberToFamily.insert(make_pair(number, family));
                   map<string, vector<string>>::iterator vecMapNumb = familyToNumber.begin();
                   if (familyToNumber.count(family.c_str()) == 0){
                       familyToNumber.insert(make_pair(family, vecNumber));
                        vecMapNumb->second.push_back(number);
                   }else {
                       familyToNumber[family].push_back(number);
                   }
               }
           }
            } else {

                }
            }
    return 0;
}
