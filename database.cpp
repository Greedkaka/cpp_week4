#include "database.h"
#include <iostream>

using namespace std;

// 엔트리를 생성한다.
Entry *create(Type type, std::string key, void *value){
    Entry* ent=new Entry;
    ent->type=type;
    ent->key=key;
    ent->value=value;

    return ent;
}

// 데이터베이스를 초기화한다.
void init(Database &database){
    database.count=0;
    database.next=nullptr;
}

void list(Database &database){
    Database* Next=&database;
    for(int i=0; i<database.count; i++){
        cout<<Next->e->key<<": ";
        // if()
        cout<<*(reinterpret_cast<int*>(Next->e->value))<<endl;
        if(Next->next==0)
            break;
        Next=Next->next;
    }
    Next=database.next;
}

// 데이터베이스에 엔트리를 추가한다.
void add(Database &database, Entry *entry){
    Database* Next=new Database;
    Database* head=new Database;
    Next->next=database.next;
    head->next=database.next;
    // Next=&database;
    for(int i=0; i<database.count; i++){
        if(Next->next==0){
            database.next=Next;
            database=*head;
            Next->e=entry;
            break;
        }
        Next=Next->next;
        database=*database.next;
    }
    database.count++;
    database.e=Next->e;
    // Next=database.next;
}

// 데이터베이스에서 키에 해당하는 엔트리를 찾는다.
Entry *get(Database &database, std::string &key){
    Database* Next=&database;
    for(int i=0; i<database.count; i++){
        if(Next->e->key.compare(key)==0){
            return Next->e;
        }
        Next=Next->next;
    }
    Next=database.next;
}

// 데이터베이스에서 키에 해당하는 엔트리를 제거한다.
void remove(Database &database, std::string &key){
    Database* Next=&database;
    for(int i=0; i<database.count; i++){
        if(Next->next->e->key.compare(key)==0){
            Next->next=Next->next->next;
            // delete Next->next;
        }
        Next=Next->next;
    }
    database.count--;
}

// 데이터베이스를 해제한다.
void destroy(Database &database){

}