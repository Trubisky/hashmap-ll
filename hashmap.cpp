#include <iostream>
#include "hashmap.h"
#include <string>

using namespace std;

int main(){
    hashmap_ll<string, int> hashmap;
    cout << hashmap.insert("jack", 4) << endl;
    cout << hashmap.insert("jack", 4) << endl;
    cout << hashmap.insert("bob", 4) << endl;
    cout << hashmap.insert("bob", 4) << endl;
}