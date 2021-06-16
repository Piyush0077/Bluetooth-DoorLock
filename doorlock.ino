//This creates a bridge between Server and the Client via
Bluetooth
#include "BluetoothSerial.h"
#if !defined(CONFIG_BT_ENABLED) ||
!defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make
menuconfig` to and enable it
#endif
int ledpin = 2;
BluetoothSerial SerialBT;
void setup()
{
  Serial.begin(115200);
  pinMode(ledpin,OUTPUT);
  SerialBT.begin("Enter Pass Key when Connected");
  Serial.println("The device started, now you can pair it withbluetooth!");
  Serial.println("Enter Pass Key");
}
int i = 0;
int v = 1;
void loop()
{
 if (SerialBT.available())
 {
  char x = SerialBT.read();
  Serial.println(x);
  if (x == 'P')
  {
    if (i == 0)
    {
      digitalWrite(ledpin, HIGH);
      SerialBT.println("Correct Password");
      SerialBT.println("Visitor No.:");
      SerialBT.println(v);
      SerialBT.println("Kindly Enter the same to lock it again");
      i =1;
      v++;
      }
      else if (i ==1)
     {
       digitalWrite(ledpin, LOW);
       Seria;BT.println("Thank You!");
       i = 0;
     }
   }
  }
  delay(20);
}
