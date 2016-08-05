//Appel à la librairie PS3
#include <SPI.h>
#include <PS3BT.h>                                                    //Include the necessary libraries.
USB Usb;
BTD Btd(&Usb);
PS3BT PS3(&Btd);
//Définition de pin relais
#define RELAY_1 22
#define RELAY_2 23
#define RELAY_3 24
#define RELAY_4 25
#define RELAY_5 26
#define RELAY_6 27
#define RELAY_7 28
#define RELAY_8 29
#define RELAY_9 30
#define RELAY_10 31
#define RELAY_11 32
#define RELAY_12 33
#define RELAY_13 34
#define RELAY_14 35
#define RELAY_15 36
#define RELAY_16 37


bool PS3Connected,PS3NavigationConnected;

void setup() {
   Serial.begin(115200);

   #if !defined(__MIPSEL__)
  while (!Serial);
#endif
  
   if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while (1); //halt
  }
  Serial.print(F("\r\nPS3 Bluetooth Library Started"));

  // on initialise les sorties et on éteind les Relais connectées
    pinMode(RELAY_1, OUTPUT);      
    pinMode(RELAY_2, OUTPUT);  
    pinMode(RELAY_3, OUTPUT);  
    pinMode(RELAY_4, OUTPUT);    
    pinMode(RELAY_5, OUTPUT);
    digitalWrite(RELAY_5, HIGH);  
    pinMode(RELAY_6, OUTPUT); 
    digitalWrite(RELAY_6, HIGH); 
    pinMode(RELAY_7, OUTPUT);  
    digitalWrite(RELAY_7, HIGH);
    pinMode(RELAY_8, OUTPUT);  
    digitalWrite(RELAY_8, HIGH);
    pinMode(RELAY_9, OUTPUT);  
    
    pinMode(RELAY_10, OUTPUT);  
    
    pinMode(RELAY_11, OUTPUT);  
    
    pinMode(RELAY_12, OUTPUT);  
    
    pinMode(RELAY_13, OUTPUT);  
    digitalWrite(RELAY_13, HIGH);
    pinMode(RELAY_14, OUTPUT);  
    digitalWrite(RELAY_14, HIGH);
    pinMode(RELAY_15, OUTPUT);  
    digitalWrite(RELAY_15, HIGH);
    pinMode(RELAY_16, OUTPUT);  
    digitalWrite(RELAY_16, HIGH);
    
    }

void loop()
{
  Usb.Task();


       //Déconnection de la manette
       if (PS3.getButtonClick(PS)) {
        Serial.print(F("\r\nPS"));
        PS3.disconnect();
    }
    else {
        //Contrôle Boutton croix,carré,rond,triangle
        if (PS3.getButtonPress(TRIANGLE)) { 
        Serial.print(PS3.getButtonPress(TRIANGLE));
        digitalWrite(RELAY_12,LOW);     // ON Relai 12
        } else {                   
        digitalWrite(RELAY_12,HIGH);    // Relai Off
        }  
        
        if (PS3.getButtonPress(CIRCLE)) { 
        Serial.print(PS3.getButtonPress(CIRCLE));
        digitalWrite(RELAY_11,LOW);     // ON Relai 11
        } else {                   
        digitalWrite(RELAY_11,HIGH);    // Relai Off
        }  
        
       if (PS3.getButtonPress(CROSS)) { 
        Serial.print(PS3.getButtonPress(CROSS));
        digitalWrite(RELAY_9,LOW);     // ON Relai 9
        } else {                   
        digitalWrite(RELAY_9,HIGH);    // Relai Off
        }  
        
        if (PS3.getButtonPress(SQUARE)) { 
        Serial.print(PS3.getButtonPress(SQUARE));
        digitalWrite(RELAY_10,LOW);     // ON Relai 10
        } else {                   
        digitalWrite(RELAY_10,HIGH);    // Relai Off
        }  
        }
      //contrôle fleche haut/bas/droite/gauche
      if (PS3.getButtonPress(UP)) { 
        Serial.print(PS3.getButtonPress(UP));
        digitalWrite(RELAY_1,LOW);     // ON Relai 1
        } else {                   
        digitalWrite(RELAY_1,HIGH);    // Relai Off
        }
      if (PS3.getButtonPress(RIGHT)) {
        digitalWrite(RELAY_4,LOW);     // ON Relai 4
        } else {                    
        digitalWrite(RELAY_4,HIGH);    // Relai Off
        }
      
      if (PS3.getButtonPress(DOWN)) {
        digitalWrite(RELAY_2,LOW);     // ON Relai 2
        } else {                    
        digitalWrite(RELAY_2,HIGH);    // Relai Off
        }
      
      if (PS3.getButtonPress(LEFT)) {
        digitalWrite(RELAY_3,LOW);     // ON Relai 3
        } else {                    
        digitalWrite(RELAY_3,HIGH);    // Relai Off
        }
        
        //Contrôle joystick GAUCHE
        if (PS3.PS3Connected) {
        if (PS3.getAnalogHat(LeftHatY)) {
        Serial.print(PS3.getAnalogHat(LeftHatY));
        digitalWrite(RELAY_5, HIGH);  // ON Relai 5
        } else { 
        digitalWrite(RELAY_5, LOW);   // Relai Off
        }
        
        if (PS3.getAnalogHat(LeftHatX)) {
        Serial.print(PS3.getAnalogHat(LeftHatX));
        digitalWrite(RELAY_6, HIGH);   // ON Relai 6
        } else { 
        digitalWrite(RELAY_6, LOW);   // Relai Off
        }
        //Contrôle joystick DROITE
        if (PS3.getAnalogHat(RightHatY)) {
        Serial.print(PS3.getAnalogHat(RightHatY));
        digitalWrite(RELAY_7, HIGH);   // ON Relai 7
        } else { 
        digitalWrite(RELAY_7, LOW);    // Relai Off
        }
        
        if (PS3.getAnalogHat(RightHatX)) {
        Serial.print(PS3.getAnalogHat(RightHatX));
        digitalWrite(RELAY_8, HIGH);   // ON Relai 8
        } else { 
        digitalWrite(RELAY_8, LOW);   // Relai Off
        }
        }
       //Contrôle L1/R1 L2/R2  
       if (PS3.PS3Connected) {
          
       if (PS3.getButtonPress(L1)) { 
        Serial.print(PS3.getButtonPress(L1));
        digitalWrite(RELAY_13,LOW);     // ON Relai 13
        } else {                   
        digitalWrite(RELAY_13,HIGH);    // Relai Off
        } 

       if (PS3.getButtonPress(R1)) { 
        Serial.print(PS3.getButtonPress(R1));
        digitalWrite(RELAY_14,LOW);     // ON Relai 14
        } else {                   
        digitalWrite(RELAY_14,HIGH);    // Relai Off  
      }

      if (PS3.getAnalogButton(L2)) { 
        Serial.print(PS3.getAnalogButton(L2));
        digitalWrite(RELAY_15,LOW);     // ON Relai 15
        } else {                   
        digitalWrite(RELAY_15,HIGH);    // Relai Off
      } 
      
      if (PS3.getAnalogButton(R2)) { 
        Serial.print(PS3.getAnalogButton(R2));
        digitalWrite(RELAY_16,LOW);     // ON Relai 16
        } else {                   
        digitalWrite(RELAY_16,HIGH);    // Relai Off
      } 
        }
        }
     
        
        
        
        
       




