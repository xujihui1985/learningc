#include <stdlib.h>
#include <stdio.h>

typedef struct RobotArmManager RobotArmManager;
typedef struct DisplayClient DisplayClient;


struct GasData {
    unsigned int value;
};

struct DisplayClient {
    struct GasData* itsGasData;
};

typedef void (*gasDataAcceptorPtr) (DisplayClient*, struct GasData*);

void DisplayClient_accept(DisplayClient* self, struct GasData* g) {
    printf("DisplayClient_accept called \n");
}

struct GasNotificationHandle {
    void* instancePtr;
    gasDataAcceptorPtr acceptorPtr;
};

struct GasNotificationHandle* GasNotificationHandle_Create() {
    struct GasNotificationHandle* res;

    res = (struct GasNotificationHandle*)malloc(sizeof(struct GasNotificationHandle));
    return res;
}


struct RobotArmManager {
    unsigned int currentStep;
    unsigned int nSteps;
    struct GasNotificationHandle *itsGasNH[100];
    int status;
};

void RobotArmManager_Add(RobotArmManager* const self, struct GasNotificationHandle* handle);

void RobotArmManager_subscribe(RobotArmManager* const self, void* instancePtr, gasDataAcceptorPtr aptr)
{
    struct GasNotificationHandle* h;
    h = GasNotificationHandle_Create();

    h->instancePtr = instancePtr;
    h->acceptorPtr = aptr;

    RobotArmManager_Add(self, h);
}

void RobotArmManager_notify(RobotArmManager* const self)
{
    struct GasNotificationHandle* h;
    int pos;
    for (pos = 0; pos < 100; ++pos) {
        if(self->itsGasNH[pos]) {
            h = self->itsGasNH[pos];
            h->acceptorPtr(NULL, NULL);
        }
    }
}


void RobotArmManager_Init(RobotArmManager* const self) 
{
    int pos;
    for (pos = 0; pos < 100; ++pos) {
        self->itsGasNH[pos] = NULL;
    }
}

void RobotArmManager_Add(RobotArmManager* const self, struct GasNotificationHandle* handle) 
{
    int pos;
    for (pos = 0; pos < 100; ++pos) {
        if (!self->itsGasNH[pos]){
            self->itsGasNH[pos] = handle;
            break;
        }
    }
}

RobotArmManager* RobotArmManager_Create() 
{
    RobotArmManager* self;

    self = (RobotArmManager *)malloc(sizeof(RobotArmManager));

    if (self != NULL)
        RobotArmManager_Init(self);
    return self;
}

int main()
{
    unsigned int cmd;
    RobotArmManager* manager;

    cmd = 0;

    cmd |= 1;

    printf("aaa %d\n", cmd);

    cmd |= (2 << 1);

    printf("aaa %d\n", cmd);

    manager = RobotArmManager_Create();
    RobotArmManager_subscribe(manager, NULL, &DisplayClient_accept);
    RobotArmManager_notify(manager);


}
