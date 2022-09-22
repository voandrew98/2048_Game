#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string>
#include "functions.h"
using namespace std;

bool impossible(vector<vector<int>> m) {
    int c = 0;
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[i].size(); j++) {
            if (m[i][j] > 0 && m[i][j] != 2048) {
                c+=m[i][j];
            }
        }
    }
    if (c == 2 || c ==4  || c == 8 || c ==16 || c == 32 || c == 64 || c == 128 || c == 256 || c == 512 || c == 1024 || c== 2048) {
        return false;
    } else {
        return true;
    }
}

bool isAnswer(vector<vector<int>> m, string moveList) {
    for (char c : moveList) {
        if (c == '1') {
            moveUp(m);
        } else if (c == '2') {
            moveRight(m);
        } else if (c == '3') {
            moveDown(m);
        } else {
            moveLeft(m);
        }
    }
    
    int count = 0;
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[i].size(); j++) {
            if (m[i][j] > 0 && m[i][j] != 2048) {
                count++;
            }
        }
    }
    if (count == 1) {
        return true;
    } else {
        return false;
    }
}

int main(){
    ifstream input("input31.txt");
    ofstream output("output.txt");
    vector<vector<int>> v;
    

    int GetVectorSize;
    input >> GetVectorSize;

    int matrixNum;

    for(int i=0;i<GetVectorSize;i++){ // i is row
        vector<int>temp;
        for(int j=0;j<GetVectorSize;j++){ // j is column
            input >> matrixNum;
            temp.push_back(matrixNum);
        }
        v.push_back(temp);
    }
    
    for(int i=0;i<GetVectorSize;i++){
        for(int j=0;j<GetVectorSize;j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    
    if (isAnswer(v, "")) {
        output << 0;
        return 0;
    }
    
    if (impossible(v)) {
        output << "Imposible";
        cout << "Impossible";
        return 0;
    }
    
    vector<string> moves {"1", "2", "3", "4"};
    queue<string> moveList;
    moveList.push("1");
    moveList.push("2");
    moveList.push("3");
    moveList.push("4");
    while (moveList.size() > 0) {
        string currMovesToTest = moveList.front();
        
        if (currMovesToTest.length() > 12) {
            output << "Impossible";
            return 0;
        }
        
        moveList.pop();
        
        if (!isAnswer(v, currMovesToTest)) {
            moveList.push(currMovesToTest + "1");
            moveList.push(currMovesToTest + "2");
            moveList.push(currMovesToTest + "3");
            moveList.push(currMovesToTest + "4");
        } else {
            output << currMovesToTest;
            cout << currMovesToTest;
            return 0;
        }
    }
    return 0;
}