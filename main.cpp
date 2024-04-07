#include "database.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
    Database data;
    init(data);

    string com="", ke="", ty="", val3="";
    int val1=0,k=123;
    double val2=0;

    while(true){
        cout<<"command (list, add, get, del, exit): ";
        cin>>com;
        // create(INT,"k",&k);
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
                getline(cin,val3);
                add(data, create(STRING, ke, &val3));
            }
            else if(ty.compare("array")==0){
                add(data, create(ARRAY, ke, cre_Arr(0)));
            }
                
        }
        else if(com.compare("get")==0){
            cout<<"key: ";
            cin>>ke;
            Entry* m_e=get(data,ke);
            // cout<<*(reinterpret_cast<int*>(m_e->value))<<endl;
            if(m_e->type==INT && m_e!=nullptr)
               cout<<ke<<": "<<*((int*)(m_e->value))<<endl;
            else if(m_e->type==DOUBLE && m_e!=nullptr)
               cout<<ke<<": "<<*((double*)(m_e->value))<<endl;
            else if(m_e->type==STRING && m_e!=nullptr)
               cout<<ke<<": "<<*((string*)(m_e->value))<<endl;
            else if(m_e->type==ARRAY && m_e!=nullptr){
               cout<<ke<<": ";
               get_Arr((Array*)m_e->value);
               cout<<endl;
            }
        }
        else if(com.compare("del")==0){
            cout<<"key: ";
            cin>>ke;
            remove(data,ke);
        }

        if(com.compare("exit")==0){
            destroy(data);
            break;
        }
    }

    return 0;
}