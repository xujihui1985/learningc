#include <stdio.h>
#include <string.h>

// the difference between class and struct in c++ is class member by default is private 
// while struct is public by default
class Connection {

    int SomeState;

public:

    Connection() {
        this->SomeState = 0;
        printf("Connection Constructor\n");
    }

    void Open(char const* filename) {
        this->SomeState = 1;
    }

    void Execute(char const* statement) const {
        printf("execute sql statement\n");
    }

    void Close() {
        this->SomeState = 0;
    }

    ~Connection() {
        Close();
        printf("Connection disctructor\n");
    }
};


void PrepareSchema(Connection const &db) {
    db.Execute("");
}

int main() {

    Connection db;
    db.Open("some address");
    db.Execute("some statement");

    PrepareSchema(db);
    //db.Close();
}
