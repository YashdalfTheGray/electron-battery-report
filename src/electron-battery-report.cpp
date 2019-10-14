/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "application.h"
#line 1 "/Users/yash/playground/electron-battery-report/src/electron-battery-report.ino"
/*
 * Project electron-battery-report
 * Description: a project that reports battery stats for the electron
 * Author:Yash Kulshrestha
 * Date: 10/13/2019
 */

void setup();
void loop();
double getBatteryPercent(double vCell);
#line 8 "/Users/yash/playground/electron-battery-report/src/electron-battery-report.ino"
FuelGauge fuel;
double vCell = 0;
double percent = 0;

void setup()
{
  Particle.variable("vCell", vCell);
  Particle.variable("percent", percent);
}

void loop()
{
  vCell = fuel.getVCell();
  percent = fuel.getSoC();
  delay(1000);
}

double getBatteryPercent(double vCell)
{
  return ((2.427 * vCell) - 8.981) * 100;
}
