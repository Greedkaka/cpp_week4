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
        else if(com.compare("add")){
            Entry ent;
            cout<<"key: ";
            cin>>ke;
            cout<<"type (int, double, string, array): ";
            cin>>ty;
            cout<<"value: ";
            cin>>val;
            if(ty.compare("int")){
                add(data, create(INT, ke, val));
            }
            // else if(ty.compare(double))
            //     add(data, DOUBLE, val);
            // else if(ty.compare(string))
            //     add(data, STRING, val);
            // else if(ty.compare(array))
            //     add(data, ARRAY, val);
        }
        else if(com.compare("get")){

        }
        else if(com.compare("del")){

        }

        else if(com.compare("exit")){
            destroy(data);
            break;
        }
    }


    return 0;
}