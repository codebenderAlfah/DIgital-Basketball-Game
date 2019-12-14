#include<SoftwareSerial.h>
#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

Servo dorja; 

//SoftwareSerial BTserial(10,11);
 
int knob = 7; 
int awaj = 8;
int alo = 10;        
int button = 3;
int ir1 = 4;
int ir2 = 5;
int ir3 = 6; 
int val1 = 0;
int val2 = 0;
int val3 = 0;
int score = 0;
int highscore=0;
int buttonState = 0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
lcd.backlight(); 
  //BTserial.begin(9600);
  dorja.attach(knob);   
  
  pinMode(button,INPUT);
    
  pinMode(ir1,INPUT);  
//  pinMode(ir2,INPUT);  
//  pinMode(ir3,INPUT);  
  
  pinMode(awaj, OUTPUT);
  pinMode(alo, OUTPUT); 
  
  dorjaSet(); 
  lcd.print("Welcome!!!");
}

void dorjaSet() {
  dorja.write(0);   
  delay(100);
 // dorja.detach();
}

void loop() {
  digitalWrite(alo, LOW);
  if(score>highscore)
  highscore = score;
  lcd.setCursor(0,0);
  lcd.print("High Score:");
  lcd.setCursor(11,0);
  lcd.print(highscore);
  
  buttonState = digitalRead(button);
  val1 = digitalRead(ir1);
  val2 = digitalRead(ir2);
  val3 = digitalRead(ir3); 
   
  if (buttonState == HIGH)
  
 {  
    dorja.attach(knob);
    delay(1);
    dorja.write(103);  
    delay(3000);       
    dorja.write(0);    
    delay(1000);
    dorja.detach();     
    score=0;
    lcd.setCursor(12,1);
    lcd.clear();
  }

    Serial.println("checking start");
    Serial.println("Kacher ta");
    Serial.println(val1);
    Serial.println("Majher ta");
    Serial.println(val2);
    Serial.println("Durer ta");
    Serial.println(val3);
    Serial.println("checking done");

    if (val1 == LOW) 
  {
    digitalWrite(awaj, HIGH);
    digitalWrite(alo, HIGH);
    delay(500);
    //BTserial.print(score);
    digitalWrite(awaj, LOW);
    score = score + 10;
    Serial.println("Kacher ta");
    Serial.println(score);
    lcd.setCursor(0,0);
    lcd.print("High Score:");
    lcd.setCursor(11,0);
    lcd.print(highscore);
        lcd.setCursor(0,1);
    lcd.print("Your Score:");
    lcd.setCursor(12,1);
    lcd.print(score);
    
  }
  
  else if(val2 == LOW)
  {
    digitalWrite(awaj, HIGH);
    digitalWrite(alo, HIGH);
    delay(500);
    //BTserial.print(score);
    digitalWrite(awaj, LOW);
    score = score + 20;
    Serial.println("Majher ta");
    Serial.println(score);
        lcd.setCursor(0,0);
    lcd.print("High Score:");
    lcd.setCursor(11,0);
    lcd.print(highscore);
        lcd.setCursor(0,1);
    lcd.print("Your Score:");
    lcd.setCursor(12,1);
    lcd.print(score);
   // digitalWrite(awaj, HIGH);
    //BTserial.print(score);
    //delay(500);
    //digitalWrite(awaj, LOW);
  }
  
   else if(val3 == LOW)
  {
    digitalWrite(awaj, HIGH);
    digitalWrite(alo, HIGH);
    delay(500);
    //BTserial.print(score);
    digitalWrite(awaj, LOW);
    score = score + 30;
    Serial.println("Durer ta");
    Serial.println(score);
        lcd.setCursor(0,0);
    lcd.print("High Score:");
    lcd.setCursor(11,0);
    lcd.print(highscore);
        lcd.setCursor(0,1);
    lcd.print("Your Score:");
    lcd.setCursor(12,1);
    lcd.print(score);
    //digitalWrite(awaj, HIGH);
    //BTserial.print(score);
    //digitalWrite(awaj, LOW);
  }
  else
  {
    score = score + 0;
    Serial.println(score);
        lcd.setCursor(0,0);
    lcd.print("High Score:");
    lcd.setCursor(11,0);
    lcd.print(highscore);
        lcd.setCursor(0,1);
    lcd.print("Your Score:");
    lcd.setCursor(12,1);
    lcd.print(score);
    //BTserial.print(score);
//    delay(50);
  }
}
