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
int main() {
    map<int, string> telephone;
    //init telephone book
    telephone.insert(make_pair<int, string>(748596, "pavlov"));
    telephone.insert(make_pair<int, string>(331525, "ivanov"));
    telephone.insert(make_pair<int, string>(551241, "pavlov"));
    telephone.insert(make_pair<int, string>(361655, "sidorov"));

    string operation;
    cout << "Enter operation\n";
    while(operation != "exit") {
        getline(cin, operation);
        if (operation == "exit") continue;

        if (operation[0] >= 'a' && operation[0] <= 'z') {
            for (map<int, string>::iterator searchFamily = telephone.begin(); searchFamily != telephone.end(); ++searchFamily){
                if (searchFamily->second == operation) cout << searchFamily->first << " ";
            }
            cout << endl;
        } else if (operation[0] >= '0' && operation[0] <= '9') {
            if (operation.back() >= 'a' && operation.back() <= 'z') {
                telephone.insert(pair<int, string>(stoi(operation), family(operation)));
            } else {
                for (map<int, string>::iterator numb = telephone.begin(); numb != telephone.end(); ++numb) {
                    if (stoi(operation) == numb->first) {
                        cout << numb->second << endl;
                    }
                }
            }
        }
    }
    return 0;
}
