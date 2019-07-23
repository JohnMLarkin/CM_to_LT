#include <mbed.h>
#include <rtos.h>
#include <CM_to_LT.h>

CM_to_LT::CM_to_LT(PinName tx, PinName rx) : _xbee(tx, rx) {
}

int CM_to_LT::broadcastTelemetry(time_t t, float lat, float lng, float alt, float gndSpeed, float vertVel, int heading) {
  const char numBytes = 29;  // ID byte + time byte + 5*(4-byte floats) + (4-byte int)
  char payload[numBytes];
  payload[0] = 0xB0;
  *(time_t*)(payload+1) = t;
  *(float*)(payload+5) = lat;
  *(float*)(payload+9) = lng;
  *(float*)(payload+13) = alt;
  *(float*)(payload+17) = gndSpeed;
  *(float*)(payload+21) = vertVel;
  *(int*)(payload+25) = heading;
  return _xbee.txBroadcast(payload,numBytes);;
}
