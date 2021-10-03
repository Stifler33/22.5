#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
string family(string &operation){
    string input;
    for (int i = 0; i < operation.length(); i++){
        if (operation[i] >= 'a' && operation[i] <= 'z'){
            input += operation[i];
        }
    }
    return input;
}
int telNumber(string &operation){
    int input;
    for (int i = 0; i < operation.length(); i++){
        if (operation[i] >= '0' && operation[i] <= '9'){
            input += stoi(operation);
        }
    }
    return input;
}
int main() {
    map<string, int> telephone;
    telephone.insert(make_pair<string, int>("ivanov", 331525));
    telephone.insert(make_pair<string, int>("pavlov", 551241));
    telephone.insert(make_pair<string, int>("sidorov", 361655));
    string operation;
    cout << "Enter operation\n";
    while(operation != "exit") {
        getline(cin, operation);
        if (operation == "exit") continue;
        if (operation[0] >= 'a' && operation[0] <= 'z') {
            cout << telephone[operation] << endl;
        } else if (operation[0] >= '0' && operation[0] <= '9') {
            if (operation.back() >= 'a' && operation.back() <= 'z') {
                telephone.insert(pair<string, int>(family(operation), stoi(operation)));
            } else {
                for (map<string, int>::iterator numb = telephone.begin(); numb != telephone.end(); ++numb) {
                    if (stoi(operation) == numb->second) {
                        cout << numb->first << endl;
                    }
                }
            }
        }
    }
    return 0;
}
