#ifndef itlwm_interface_hpp
#define itlwm_interface_hpp

#include <IOKit/network/IOEthernetInterface.h>

#define ETHERNET_MTU            1500

class itlwm_interface : public IOEthernetInterface {
    OSDeclareDefaultStructors( itlwm_interface )

public:
    virtual bool init( IONetworkController * controller ) override;

protected:

    virtual void free() override;

    virtual bool setMaxTransferUnit(UInt32 mtu) override;
};

#endif /* itlwm_interface_hpp */
