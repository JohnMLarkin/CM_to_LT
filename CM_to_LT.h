/** Command Module interface for XBee communication with ground-based Local Tracker
 *
 *  @author John M. Larkin (jlarkin@whitworth.edu)
 *  @version 0.1
 *  @date 2019
 *  @copyright MIT License
 */

#ifndef CM_TO_LT_H
#define CM_TO_LT_H

#include <XBeeAPIParser.h>
#include <mbed.h>
#include <rtos.h>
#include <string> 
using namespace std;

class CM_to_LT
{
private:
  XBeeAPIParser _xbee;

public:

};

#endif
