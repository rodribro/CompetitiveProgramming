#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    
    //map<char, int> pos;
    map<char, int> custos;
    string text;
    int len = text.length();
    for(int i = 0; i < len-1; i++) {

        // nao esta no mapa pos
        if((pos.find(text[i]) == pos.end())) {
            pos[text[i]] = i;

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
        //esta no mapa pos
        else {
            if(isalpha(text[i]))  {
                if ((tolower(pos[text[i]]) == tolower(pos[text[i-1]])) || (toupper(pos[text[i]]) == toupper(pos[text[i-1]]))) {
                    pos[text[i]] = i;
                }
                else {
                    //lower case
                    if(islower(text[i])) {
                        custos[0]++;
                    }

                    //upper case
                    if(isupper(text[i])) {
                        custos[1]+=2;
                    }
                }
                
            }
            if(isspace(text[i])) {
                if (pos[text[i]] == i-1) {
                    continue;
                }
                continue;
            }
            
        
        }



        cin >> c;
    }


}

/*
//lower case
if(islower(text[i])) {
    dict[0]++;
}

//upper case
if(isupper(text[i])) {
    dict[1]++;
}

//space
if(isspace(text[i])) {
    if()
}
*/