#include <stdio.h>

typedef struct {
    int SomeState;
} Connection;


void OpenConnection(Connection* db, char* filename) {
    db->SomeState = 1;
}

void ExecuteConnection(Connection* db, char* statement) {

}

void CloseConnection(Connection* db) {

}

int main() {

    Connection db;
    OpenConnection(&db, "");
    ExecuteConnection(&db, "");
    CloseConnection(&db);
}
