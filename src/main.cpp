#include <Arduino.h>
#include <Servo.h>

Servo myservo;

const int servoPin = D4; 

void setup() {
  Serial.begin(9600);
  myservo.attach(servoPin, 544, 2400);
  Serial.println("Servo SG90 180 degres initialisé");
  delay(1000);
}

void loop() {
  

  Serial.println("Test de la plage de mouvement (rapide) :");
  for (int pos = 0; pos <= 180; pos += 45) {
    myservo.write(pos);
    Serial.print("Position : ");
    Serial.print(pos);
    Serial.print(" degres");
    Serial.print("\t Pulse Width : ");
    Serial.print(myservo.readMicroseconds());
    Serial.print(" us");
    Serial.println();
    delay(200);
  }
  delay(1000);
  
  Serial.println("Test de la plage de mouvement inversé (rapide) :");
  for (int pos = 180; pos >= 0; pos -= 45) {
    myservo.write(pos);
    Serial.print("Position : ");
    Serial.print(pos);
    Serial.print(" degres");
    Serial.print("\t Pulse Width : ");
    Serial.print(myservo.readMicroseconds());
    Serial.print(" us");
    Serial.println();
    delay(200);
  }
  delay(1000);


  Serial.println("Test de la plage de mouvement (précis) :");
  for (int pos = 0; pos <= 180; pos += 1) {
    myservo.write(pos);
    Serial.print("Position : ");
    Serial.print(pos);
    Serial.print(" degres");
    Serial.print("\t Pulse Width : ");
    Serial.print(myservo.readMicroseconds());
    Serial.print(" us");
    Serial.println();
    delay(10);
  }
  delay(1000);
  
  Serial.println("Test de la plage de mouvement inversé (rapide) :");
  for (int pos = 180; pos >= 0; pos -= 1) {
    myservo.write(pos);
    Serial.print("Position : ");
    Serial.print(pos);
    Serial.print(" degres");
    Serial.print("\t Pulse Width : ");
    Serial.print(myservo.readMicroseconds());
    Serial.print(" us");
    Serial.println();
    delay(10);
  }
  delay(1000);


  Serial.println("Test de la vitesse de rotation :");
  for (int speed = 1; speed <= 25; speed++) {
    Serial.print("Vitesse : ");
    Serial.print(speed);
    Serial.println(" degres/ms");
    myservo.write(0);
    for (int pos = 0; pos <= 180; pos++) {
      myservo.write(pos);
      delay(speed);
    }
    delay(1000);
  }

  Serial.println("Test de la vitesse de rotation (inversé) :");
  for (int speed = 25; speed <= 1; speed--) {
    Serial.print("Vitesse : ");
    Serial.print(speed);
    Serial.println(" degres/ms");
    myservo.write(180);
    for (int pos = 180; pos >= 0; pos--) {
      myservo.write(pos);
      delay(speed);
    }
    delay(500);
  }
  
Serial.println("Test de la réactivité :");
for (int i = 0; i < 5; i++) {
  Serial.print("Envoi de la commande 0 à la position ");
  Serial.println(myservo.read());
  myservo.write(0);
  delay(500);
  Serial.print("Envoi de la commande 180 à la position ");
  Serial.println(myservo.read());
  myservo.write(180);
  delay(500);
}
Serial.println("Fin du test de réactivité");
delay(500);

  
}
