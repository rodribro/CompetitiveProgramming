#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    string text;
    int len = text.length();
    map<int,int> custos;

    for(int i = 0; i < len; i++) {
        if(i == 0) {
            if(isalpha(text[i])) {
                //lower case
                if(islower(text[i])) {
                    custos[0]++;
                }

                //upper case
                if(isupper(text[i])) {
                    custos[1]+=2;
                }
            }

            //space
            if(isspace(text[i])) {
                custos[2]++;
            }
        }

        else {

            if(isalpha(text[i])) {
                
                if(isupper(text[i-1]) && islower(text[i])) {
                    if(tolower(text[i-1]) == tolower(text[i])) {
                        continue;
                    }
                }

                if(isupper(text[i-1]) && islower(text[i])) {
                    if(tolower(text[i-1]) == tolower(text[i])) {
                        continue;
                    }
                }
                
            }
            
        }
    }

}