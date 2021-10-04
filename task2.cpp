#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
    map<string, int> patient;
    cout << "Enter name new patient or next or exit\n";
    string action;
    while (action != "exit"){
        cin >> action;
        // if exit
        if (action != "exit"){
            // if enter name
            if (action != "next"){
                bool repeatName = false;
                for (map<string, int>::iterator curName = patient.begin(); curName != patient.end(); ++curName){
                    if (curName->first == action){
                        curName->second++;
                        repeatName = true;
                    }
                }
                if (!repeatName) patient.insert({action, 1});
            }
            // if next
            else if (action == "next"){

            }
        }else if (action == "exit") break;
    }
    return 0;
}
