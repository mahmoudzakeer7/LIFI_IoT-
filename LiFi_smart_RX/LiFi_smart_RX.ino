#include <LiquidCrystal.h>

// Pin definitions
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;  // LCD pins
const int sig = 9;  // Signal input pin
const int led = 8;
const int lamp = A2;
// speed for motor 1 and 2
int sp1 = 150;
int sp2 = 150;
// motor 1
const int in1 = 13;
const int in2 = 10;
const int enA = A0;

//motor 2
const int in3 = 7;
const int in4 = 6;
const int enB = A1;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(sig, INPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(enA,OUTPUT);
  pinMode(enB,OUTPUT);
  pinMode(lamp,OUTPUT);
  pinMode(led,OUTPUT);


  // Welcome Message
  lcd.setCursor(0, 0);
  lcd.print("   WELCOME TO    ");
  lcd.setCursor(0, 1);
  lcd.print(" LiFi RECEIVER   ");
  delay(1000);
  lcd.clear();
}
  
void displayMessage(char receivedChar) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Received: ");
  lcd.print(receivedChar);
  switch (receivedChar){
   case '1':
   lcd.setCursor(0,1);
   lcd.print("turn on Motor 1");
   Serial.println("turn on motor 1");
   digitalWrite(in1,HIGH);
   digitalWrite(in2,LOW);
   analogWrite(enA,sp1);
   break; 
   case '2':
   lcd.setCursor(0,1);
   lcd.print("turn oFF Motor1");
   Serial.println("turn OFF motor 1");
   digitalWrite(in1,LOW);
   digitalWrite(in2,LOW);
   break;
   case '3':
   lcd.setCursor(0,1);
   lcd.print("turn on Motor2");
   Serial.println("turn On motor 2");
   digitalWrite(in3,HIGH);
   digitalWrite(in4,LOW);
   analogWrite(enB,sp2);
   break;
   case '4':
   lcd.setCursor(0,1);
   lcd.print("turn oFF Motor2");
   Serial.println("turn OFF motor 2");
   digitalWrite(in3,LOW);
   digitalWrite(in4,LOW);
   break;
   case '5':
   lcd.setCursor(0,1);
   lcd.print("turn on lamp");
   Serial.println("turn On lamp");
   digitalWrite(lamp,HIGH);
   break;
   case '6':
   lcd.setCursor(0,1);
   lcd.print("turn oFF lamp");
   Serial.println("turn OFF lamp");
   digitalWrite(lamp,LOW);
   break;
   case '7':
   lcd.setCursor(0,1);
   lcd.print("turn on led");
   Serial.println("turn on led");
   digitalWrite(led,HIGH);
   break;
   case '8':
   lcd.setCursor(0,1);
   lcd.print("turn oFF led");
   Serial.println("turn oFF led");
   digitalWrite(led,LOW);
   break;
   case 'D':
   lcd.setCursor(0,1);
   lcd.print("inc speed motor1");
   Serial.println("increase speed motor 1");
   sp1+=50;
   break;
   case 'C':
   lcd.setCursor(0,1);
   lcd.print("dec speed motor1");
   Serial.println("decrease speed motor 1");
   sp1-=50;
   break;
   case 'B':
   lcd.setCursor(0,1);
   lcd.print("inc speed motor2");
   Serial.println("increase speed motor 2");
   sp2+=50;
   break;
   case 'A':
   lcd.setCursor(0,1);
   lcd.print("dec speed motor2");
   Serial.println("decrease speed motor 2");
   sp2-=50;
   break;
   default:
   lcd.clear();
   lcd.print("Wrong in num!");
   Serial.println("you have enterd wrong number don't exist in options");
  } 
}

void loop() {
  unsigned long duration = pulseIn(sig, HIGH);
  Serial.print("Pulse Duration: ");
  Serial.println(duration);
  Serial.print("speed motor 1: ");
  Serial.println(sp1);
  Serial.print("speed motor 2: ");
  Serial.println(sp2);
  delay(700);
  // Interpret the pulse duration based on actual measurements
  if (duration > 9950 && duration < 9970) displayMessage('1');
  else if (duration > 19000 && duration < 20050) displayMessage('2');
  else if (duration > 29000 && duration < 30050) displayMessage('3');
  else if (duration > 39000 && duration < 40050) displayMessage('4');
  else if (duration > 49000 && duration < 50050) displayMessage('5');
  else if (duration > 59000 && duration < 60050) displayMessage('6');
  else if (duration > 69000 && duration < 70050) displayMessage('7');
  else if (duration > 79000 && duration < 80050) displayMessage('8');
  else if (duration > 89000 && duration < 90050) displayMessage('9');
  else if (duration > 99000 && duration < 100050) displayMessage('*');
  else if (duration > 109000 && duration < 110050) displayMessage('0');
  else if (duration > 119000 && duration < 120050) displayMessage('#');
  else if (duration > 129000 && duration < 130050) displayMessage('A');
  else if (duration > 139000  && duration < 147000) displayMessage('B');
  else if (duration > 149000 && duration < 150050) displayMessage('C');
  else if (duration > 159000 && duration < 160050) displayMessage('D');
  else {
    lcd.setCursor(0, 0);
    lcd.print("Waiting for Signal");
    lcd.setCursor(0,1);
    lcd.print("----------------");
  }

delay(100);  // Avoid rapid updates
}
