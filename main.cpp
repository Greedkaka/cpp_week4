#include "database.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
    Database data;
    init(data);

    string com="", ke="", ty="", val="";
    while(true){
        cout<<"command (list, add, get, del, exit): ";
        cin>>com;

        if(com.compare("list")){

        }
        if(com.compare("add")){
            cout<<"type: (int, double, string, array): ";
            Entry ent;
            cin>>ent.type;
            add(data, ent)
        }
        if(com.compare("get")){

        }
        if(com.compare("del")){

        }

        if(com.compare("exit")){
            destroy(data);
            break;
        }
    }


    return 0;
}