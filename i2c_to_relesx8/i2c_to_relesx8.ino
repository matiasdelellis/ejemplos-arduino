/*
 * Ejemplo utilizacion I2C to LCD adaptor
 * para controlar 8 reles utilizando solo
 *
 * De derecha a izquierda:
 *  1  VSS <-> GND
 *  2  VDD <-> VCC
 *  3  V0  <-> POTENCIOMETRO
 *  4  RS  <-> P0
 *  5  RW  <-> P1
 *  6  E   <-> P2
 *  7  D0  <-> ?
 *  8  D1  <-> ?
 *  9  D2  <-> ?
 *  10 D3  <-> ?
 *  11 D4  <-> P4
 *  12 D5  <-> P5
 *  13 D6  <-> P4
 *  14 D7  <-> P7
 *  15 A   <-> JUMPER A VCC
 *  16 K   <-> GND <-> NPN <-> P3
 */

#include <Wire.h>

void
setup()
{
  Wire.begin();
}

void
loop()
{
  Serial.println("Scanning...");
 
  Wire.beginTransmission(0x27);
  Wire.write(0x01);
  Wire.endTransmission();
 
  delay(5000);
}

