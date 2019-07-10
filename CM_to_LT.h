/** Command Module interface for XBee communication with ground-based Local Tracker
 *
 *  @author John M. Larkin (jlarkin@whitworth.edu)
 *  @version 0.1
 *  @date 2019
 *  @copyright MIT License
 */

#ifndef CM_TO_LT_H
#define CM_TO_LT_H

#include <XBee900APIParser.h>
#include <mbed.h>
#include <rtos.h>
#include <string> 
using namespace std;

class CM_to_LT
{
private:
  XBee900APIParser _xbee;

public:
  CM_to_LT(PinName tx, PinName rx);
  int broadcastTelemetry(float lat, float lng, float alt, float gndSpeed, float vertVel, int heading);
  int broadcastHello();
};

#endif
