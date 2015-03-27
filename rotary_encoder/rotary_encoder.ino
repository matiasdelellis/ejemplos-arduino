/*
 * Ejemplo encoder rotativo.
 *        ┌───────┐
 * Pines: │B  C  A│
 *        │   ©   │
 *        │SW0 SW1│
 *        └───────┘
 * Conexiones:
 *  Pin C to GND
 *  Pin B to digital pin 2
 *  Pin A to digital pin 3
 *
 *  Pin SWO to GND
 *  Pin SW1 to digital pin 4
 */

int encoderPinA = 2;
int encoderPinB = 3;
int encoderSwitchPin = 4;

volatile int lastEncoded = 0;
volatile long encoderValue = 0;

long lastencoderValue = 0;

int lastMSB = 0;
int lastLSB = 0;

void
setup (void)
{
  Serial.begin (9600);

  pinMode(encoderPinA, INPUT); 
  digitalWrite(encoderPinA, HIGH);

  pinMode(encoderPinB, INPUT); 
  digitalWrite(encoderPinB, HIGH);

  pinMode(encoderSwitchPin, INPUT);
  digitalWrite(encoderSwitchPin, HIGH);

  /*
   * Agrega un manejador de interrupciones, para int.0 e int.1
   * Estas se corresponden a los pines a los pines digitales 2
   * y 3 utilizando un arduino UNO. Asi se configura que cuando
   * estos pines cambien de valor se ejecute la funcion
   * updateEncoder.
   * Mas info:
   *  http://arduino.cc/en/pmwiki.php?n=Reference/AttachInterrupt
   */
  attachInterrupt(0, updateEncoder, CHANGE);
  attachInterrupt(1, updateEncoder, CHANGE);
}

void
loop (void)
{
  int valor;

  if (digitalRead(encoderSwitchPin) == LOW)
  {
    encoderValue = 0;
  }
  else
  {
    valor = (encoderValue/4);
  } 

  Serial.println (valor);

  delay (100); 
}

void
updateEncoder (void)
{
  int MSB = digitalRead(encoderPinA);
  int LSB = digitalRead(encoderPinB);

  int encoded = (MSB << 1) | LSB;
  int sum  = (lastEncoded << 2) | encoded;

  if (sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) encoderValue ++;
  if (sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) encoderValue --;

  lastEncoded = encoded;
}

