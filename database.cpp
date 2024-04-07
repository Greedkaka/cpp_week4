#include "database.h"
#include <iostream>

// 데이터베이스를 초기화한다.
void init(Database &database){
    database.count=0;
    // database.head->e->key=""; 오류남
    // database.head->e->value=nullptr;
    database.head->next=0;
}

Array* cre_Arr(int count){
    Array* arr=new Array;
    string typ;
    cout<<"type (int, double, string, array): ";
    cin>>typ;
    cout<<"size: ";
    cin>>arr->size;

    if(typ.compare("int")==0){
        arr->type=INT;
        int arri[arr->size];
        arr->items=&arri[0];
        for(int i=0; i<arr->size; i++){
            cout<<"item["<<i<<"]: ";
            cin>>arri[i];
        } 
    }
    else if(typ.compare("double")==0){
        arr->type=DOUBLE;
        double arri[arr->size];
        arr->items=&arri[0];
        for(int i=0; i<arr->size; i++){
            cout<<"item["<<i<<"]: ";
            cin>>arri[i];
        } 
    }
    else if(typ.compare("string")==0){
        arr->type=STRING;
        string arri[arr->size];
        arr->items=&arri[0];
        for(int i=0; i<arr->size; i++){
            cout<<"item["<<i<<"]: ";
            getline(cin,arri[i]);
        } 
    }
    else if(typ.compare("array")==0){
        arr->type=ARRAY;
        Array arri[arr->size];
        arr->items=&arri[0];
        for(int i=0; i<arr->size; i++){
            cout<<"item["<<i<<"]: ";
            arri[i]=*cre_Arr(count++);
        } 
    }           
    return arr;
}

void get_Arr(Array* arr){
    cout<<"[";
    if(arr->type==INT){
        for (int i = 0; i < arr->size; i++){
            cout<<*(int*)arr->items+i;
            if(i<arr->size-1)
                cout<<", ";
        }
    }
    if(arr->type==DOUBLE){
        for (int i = 0; i < arr->size; i++){
            cout<<*(double*)arr->items+i;
            if(i<arr->size-1)
                cout<<", ";
        }
    }
    if(arr->type==STRING){
        for (int i = 0; i < arr->size; i++){
            cout<<*(string*)(arr->items+i);
            if(i<arr->size-1)
                cout<<", ";
        }
    }
    if(arr->type==ARRAY){
        for (int i = 0; i < arr->size; i++){
            get_Arr((Array*)arr->items+i);
            if(i<arr->size-1)
                cout<<", ";
        }
    }
    cout<<"]";
}

// 엔트리를 생성한다.
Entry *create(Type type, std::string key, void *value){
    Entry* ent=new Entry;
    ent->type=type;
    ent->key=key;
    ent->value=new void*;
    ent->value=value;

    return ent;
}

void list(Database &database){
    Node* currNode=database.head;
    for(int i=0; i<database.count; i++){
        currNode=currNode->next;
        cout<<currNode->e->key;
        if(currNode->e->type==INT)
            cout<<": "<<*(int*)(currNode->e->value)<<endl;
        if(currNode->e->type==DOUBLE)
            cout<<": "<<*(double*)(currNode->e->value)<<endl;
        if(currNode->e->type==STRING)
            cout<<": "<<*(string*)(currNode->e->value)<<endl;
        if(currNode->e->type==ARRAY){
            cout<<": ";
            get_Arr((Array*)currNode->e->value);
            cout<<endl;
        }
    }
}

// 데이터베이스에 엔트리를 추가한다.
void add(Database &database, Entry *entry){
    Node* currNode=database.head;
    Node* newNode=new Node(entry);
    for(int i=0; i<=database.count; i++){
        // if((currNode->e->key).compare(entry->key)==0){
        //     currNode->e=entry;
        //     break;
        // }
        if(i==database.count){
            currNode->next=newNode;
            database.count++;
            break;
        }
        currNode=currNode->next;
    }        
}

// 데이터베이스에서 키에 해당하는 엔트리를 찾는다.
Entry *get(Database &database, std::string &k){
    Node* currNode=database.head;
    for(int i=0; i<database.count; i++){
        currNode=currNode->next;
        if((currNode->e->key).compare(k)==0)
            return (currNode->e);
    }
    return nullptr;
}

// 데이터베이스에서 키에 해당하는 엔트리를 제거한다.
void remove(Database &database, std::string &key){
    Node* currNode=database.head;
    Node* prevNode=database.head;
    for(int i=0; i<database.count; i++){
        currNode=currNode->next;
        if((currNode->e->key).compare(key)==0){
            prevNode->next=currNode->next;
            delete(currNode->e);
            break;
        }
        prevNode=prevNode->next;
    }
    database.count--;
}

// 데이터베이스를 해제한다.
void destroy(Database &database){
    Node* currNode=database.head;
    currNode=currNode->next;
    Node* delNode;
    for (int i = 0; i < database.count; i++)
    {
        delNode=currNode;
        currNode=currNode->next;
        delete(delNode->e);
        // delete(delNode);
    }
    
    delete(database.head);
}