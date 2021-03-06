
#ifndef ItlHalService_hpp
#define ItlHalService_hpp

#include <libkern/c++/OSObject.h>
#include <IOKit/IOLib.h>
#include <IOKit/IOService.h>
#include <IOKit/IOCommandGate.h>
#include <IOKit/IOWorkLoop.h>
#include <IOKit/pci/IOPCIDevice.h>
#include <IOKit/network/IOEthernetController.h>
#include <IOKit/network/IOEthernetInterface.h>

#include "ItlDriverInfo.hpp"
#include "ItlDriverController.hpp"

#include <net80211/ieee80211_var.h>

class ItlHalService : public OSObject {
    OSDeclareAbstractStructors(ItlHalService)

public:

    virtual bool attach(IOPCIDevice *device) = 0;

    virtual void detach(IOPCIDevice *device) = 0;

    virtual IOReturn enable(IONetworkInterface *interface) = 0;

    virtual IOReturn disable(IONetworkInterface *interface) = 0;

    virtual struct ieee80211com *get80211Controller() = 0;

    virtual ItlDriverInfo *getDriverInfo() = 0;

    virtual ItlDriverController *getDriverController() = 0;

    virtual void free() override;

public:
    virtual bool initWithController(IOEthernetController *controller, IOWorkLoop *workloop, IOCommandGate *commandGate);

protected:

    int tsleep_nsec(void *ident, int priority, const char *wmesg, int timo);

    void wakeupOn(void* ident);

    IOEthernetController *getController();

    IOCommandGate *getMainCommandGate();

    IOWorkLoop *getMainWorkLoop();

private:
    IOEthernetController *controller;
    IOCommandGate *mainCommandGate;
    IOWorkLoop *mainWorkLoop;

    lck_grp_t *inner_gp;
    lck_grp_attr_t *inner_gp_attr;
    lck_attr_t *inner_attr;
    lck_mtx_t *inner_lock;
};

#endif /* ItlHalService_hpp */
