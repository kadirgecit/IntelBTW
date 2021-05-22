#ifndef ItlDriverController_h
#define ItlDriverController_h

class ItlDriverController {

public:

    virtual void clearScanningFlags() = 0;

    virtual IOReturn setMulticastList(IOEthernetAddress *addr, int count) = 0;
};

#endif /* ItlDriverController_h */
