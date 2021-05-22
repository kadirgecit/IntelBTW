#include "itlwm_interface.hpp"

#define super IOEthernetInterface
OSDefineMetaClassAndStructors( itlwm_interface, IOEthernetInterface )

bool itlwm_interface::init(IONetworkController *controller)
{
    if (!super::init(controller))
        return false;
    setMaxTransferUnit(1482);
    return true;
}

bool itlwm_interface::setMaxTransferUnit(UInt32 mtu) {
    IOLog("itlwm setting MTU to %d\n", mtu);
    if (mtu > ETHERNET_MTU) {
        return false;
    }
    super::setMaxTransferUnit(mtu);
    return true;
}

void itlwm_interface::free()
{
    super::free();
}
