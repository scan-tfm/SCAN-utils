/*
 *  Copyright (C) 2016 Daniel Cárdenes
 *  
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see http://www.gnu.org/licenses/.
 *
 *  Version: 1.0
 *  Design and Implementation:  Daniel Cárdenes
 */ 

#include <EEPROM.h>

//This Program writes default values to EEPROM

#define TXID_ADDRESS          0
#define TXNUM_ADDRESS         2
#define HIG_POWER_ADDRESS     3
#define MED_POWER_ADDRESS     4
#define LOW_POWER_ADDRESS     5
#define START_REG_ADDRESS     6

void setup() {

  Serial.begin(115200);
  
  //default values
  unsigned int txid=0;
  byte txnum=0;
  byte hig_power=14;
  byte med_power=7;
  byte low_power=0;
  
  
  unsigned int address=TXID_ADDRESS;
  EEPROM.put(address,txid);

  address=TXNUM_ADDRESS;
  EEPROM.write(address,txnum);

  address=HIG_POWER_ADDRESS;
  EEPROM.write(address,hig_power);

  address=MED_POWER_ADDRESS;
  EEPROM.write(address,med_power);

  address=LOW_POWER_ADDRESS;
  EEPROM.write(address,low_power);

  delay(10000);
  //Read EEPROM and send to consol to check validity
  unsigned int tempInt;
  byte tempByte;
  
  address=TXID_ADDRESS;
  EEPROM.get(address, tempInt);
  Serial.print("TXID: ");
  Serial.println(tempInt);

  address=TXNUM_ADDRESS;
  tempByte=EEPROM.read(address);
  Serial.print("TXNUM: ");
  Serial.println(tempByte);

  address=HIG_POWER_ADDRESS;
  tempByte=EEPROM.read(address);
  Serial.print("High Power Value: ");
  Serial.println(tempByte);

  address=MED_POWER_ADDRESS;
  tempByte=EEPROM.read(address);
  Serial.print("Medium Power Value: ");
  Serial.println(tempByte);

  address=LOW_POWER_ADDRESS;
  tempByte=EEPROM.read(address);
  Serial.print("Low Power Value: ");
  Serial.println(tempByte);
  

}

void loop() {
 
}
