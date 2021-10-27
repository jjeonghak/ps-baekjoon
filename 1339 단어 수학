#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int n;
int maxResult;
int checkBaseIndex[10];
int baseIndex[10];
vector<string>  userInputSave;
vector<char>    userUsedAlpha;

void usedIndexAlpha(){
    char    index;
    string  userInput;
    int     userInputIndex;
    int     checkIndex[26];
    
    memset(checkIndex, 0, sizeof(checkIndex));
    for (int i=0;i<userInputSave.size();i++){
        userInput = userInputSave[i];
        for (int j=0;userInput[j]!='\0';j++){
            userInputIndex = userInput[j] - 'A';
            if (checkIndex[userInputIndex] == 0){
                checkIndex[userInputIndex] = 1;
                userUsedAlpha.push_back(userInput[j]);
            }
        }
    }
}

int atoiBase(string str){
    int sum;
    
    sum = 0;
    for (int i=0;str[i]!='\0';i++){
        for (int j=0;j<userUsedAlpha.size();j++){
            if (str[i] == userUsedAlpha[j]){
                sum *= 10;
                sum += baseIndex[j];
                break;
            }
        }
    }
    return sum;
}

int calculateMax(){
    int sum;
    
    sum = 0;
    for (int i=0;i<userInputSave.size();i++)
        sum += atoiBase(userInputSave[i]);
    return sum;
}

void makeAtoiBaseAndCalculateMax(int cntIndex, int minIndex){
    if (cntIndex == userUsedAlpha.size()){
        maxResult = max(maxResult, calculateMax());
        return;
    }
    for (int i=9;i>minIndex;i--){
        if (checkBaseIndex[i] == 0){
            checkBaseIndex[i] = 1;
            baseIndex[cntIndex] = i;
            makeAtoiBaseAndCalculateMax(cntIndex + 1, minIndex);
            checkBaseIndex[i] = 0;
        }
    }
    return;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    cin.ignore();
    for (int i=0;i<n;i++){
        string userInput;
        getline(cin, userInput);
        userInputSave.push_back(userInput);
    }
    usedIndexAlpha();
    makeAtoiBaseAndCalculateMax(0, 9 - userUsedAlpha.size());
    cout << maxResult;
    return 0;
}
