#ifndef PZEM004T_H
#define PZEM004T_H

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <SoftwareSerial.h>
#include <IPAddress.h>

struct PZEMCommand {
    uint8_t command;
    uint8_t addr[4];
    uint8_t data;
    uint8_t crc;
};

class PZEM004T
{
public:
    PZEM004T(uint8_t receivePin, uint8_t transmitPin);

    float voltage(const IPAddress &addr);
    float current(const IPAddress &addr);
    float power(const IPAddress &addr);
    float energy(const IPAddress &addr);

    bool setAddress(const IPAddress &newAddr);
    bool setPowerAlarm(const IPAddress &addr, uint8_t threshold);

private:
    SoftwareSerial serial;

    void send(const IPAddress &addr, uint8_t cmd, uint8_t data = 0);
    bool recieve(uint8_t *data, uint8_t resp);

    uint8_t crc(uint8_t *data, uint8_t sz);
};

#endif // PZEM004T_H