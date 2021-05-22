#ifndef ItlDriverInfo_h
#define ItlDriverInfo_h

class ItlDriverInfo {

public:

    virtual const char *getFirmwareVersion() = 0;

    virtual int16_t getBSSNoise() = 0;

    virtual bool is5GBandSupport() = 0;

    virtual int getTxNSS() = 0;

    virtual const char *getFirmwareName() = 0;

    virtual UInt32 supportedFeatures() = 0;

    virtual const char *getFirmwareCountryCode() = 0;

    virtual uint32_t getTxQueueSize() = 0;
};

#endif /* ItlDriverInfo_h */
