/*
 * Project electron-battery-report
 * Description: a project that reports battery stats for the electron
 * Author:Yash Kulshrestha
 * Date: 10/13/2019
 */

FuelGauge fuel;
double vCell = 0;
double percent = 0;
int canPublishLowBatteryWarning = 1;

void setup()
{
  Particle.variable("vCell", vCell);
  Particle.variable("percent", percent);
}

void loop()
{
  vCell = fuel.getVCell();
  percent = fuel.getSoC();

  if (percent < 10.0 && canPublishLowBatteryWarning)
  {
    Particle.publish("/electron/battery-warning", "10%", 86400, PRIVATE);
    canPublishLowBatteryWarning = 0;
  }

  if (percent > 50.0)
  {
    canPublishLowBatteryWarning = 1;
  }
}
