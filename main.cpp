#include "database.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
    Database data;
    Entry* en;
    init(data);

    string com="", ke="", ty="", val3="";
    int val1;
    double val2;
    while(true){
        cout<<"command (list, add, get, del, exit): ";
        cin>>com;

        if(com.compare("list")==0){
            list(data);
        }
        else if(com.compare("add")==0){
            cout<<"key: ";
            cin>>ke;
            cout<<"type (int, double, string, array): ";
            cin>>ty;
            cout<<"value: ";
            if(ty.compare("int")==0){
                cin>>val1;
                add(data, create(INT, ke, &val1));
            }
            else if(ty.compare("double")==0){
                cin>>val2;
                add(data, create(DOUBLE, ke, &val2));
            }
            else if(ty.compare("string")==0){
                cin>>val3;
                add(data, create(STRING, ke, &val3));
            }
            // else if(ty.compare("array")==0){
            //     Array arr;
            //     cout<<"size: ";
            //     cin>>arr.size;
            //     item
            //     for(int i=0; i<arr.size; i++)
            //         a
            //     add(data, ARRAY, arr);
            // }
                
        }
        else if(com.compare("get")==0){
            cout<<"key: ";
            cin>>ke;
            en=get(data,ke);
            cout<<*(reinterpret_cast<int*>(en->value))<<endl;
        }
        else if(com.compare("del")==0){

        }

        else if(com.compare("exit")==0){
            destroy(data);
            break;
        }
    }


    return 0;
}