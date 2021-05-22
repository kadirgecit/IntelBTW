#ifndef _IO80211SKYWALK_H
#define _IO80211SKYWALK_H

#include <Availability.h>
#include <IOKit/network/IOSkywalkEthernetInterface.h>

// This is necessary, because even the latest Xcode does not support properly targeting 11.0.
#ifndef __IO80211_TARGET
#error "Please define __IO80211_TARGET to the requested version"
#endif

class IO80211SkywalkInterface : IOSkywalkEthernetInterface {
    OSDeclareAbstractStructors(IO80211SkywalkInterface)

public:

};

#endif /* _IO80211SKYWALK_H */
