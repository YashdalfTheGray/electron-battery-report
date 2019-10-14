/*
 * Project electron-battery-report
 * Description: a project that reports battery stats for the electron
 * Author:Yash Kulshrestha
 * Date: 10/13/2019
 */

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
