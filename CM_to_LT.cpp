#include <mbed.h>
#include <rtos.h>
#include <CM_to_LT.h>

CM_to_LT::CM_to_LT(PinName tx, PinName rx) : _xbee(tx, rx) {
}

int CM_to_LT::broadcastTelemetry(float lat, float lng, float alt, float gndSpeed, float vertVel, int heading) {
  const char numBytes = 25;  // ID byte + 5*(4-byte floats) + (4-byte int)
  char payload[numBytes];
  payload[0] = 0xB0;
  *(float*)(payload+1) = lat;
  *(float*)(payload+5) = lng;
  *(float*)(payload+9) = alt;
  *(float*)(payload+13) = gndSpeed;
  *(float*)(payload+17) = vertVel;
  *(int*)(payload+21) = heading;
  return _xbee.txBroadcast(payload,numBytes);;
}

int CM_to_LT::broadcastHello() {
  char payload[] = "Hello";
  int status = _xbee.txBroadcast(payload,5);
  return 0;
}
