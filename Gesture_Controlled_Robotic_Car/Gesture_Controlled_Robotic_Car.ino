#include <SoftwareSerial.h>

SoftwareSerial BT(10, 11); 
String readvoice;

void setup() {
 BT.begin(115200);
 Serial.begin(115200);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}
void loop() {
  while (BT.available()){  
  delay(10); 
  char c = BT.read(); 
  readvoice += c; 
  }  
  if (readvoice.length() > 0) {
    Serial.println(readvoice); 

  if(readvoice == "*forward#") 
  {
    digitalWrite(5,HIGH);
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    delay(100);
  } 
  
  else if(readvoice == "*back#") 
  {
    digitalWrite(5, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4,HIGH);
    delay(100);
  }
  
  else if (readvoice == "*right#")
  {
    digitalWrite (5,HIGH);
    digitalWrite (4,LOW);
    digitalWrite (3,LOW);
    digitalWrite (2,LOW);
    delay (100);
    
  }
  
 else if ( readvoice == "*left#")
 {
   digitalWrite (5, LOW);
   digitalWrite (2, HIGH);
   digitalWrite (3, LOW);
   digitalWrite (4, LOW);
   delay (100);
 }
 
 else if (readvoice == "*stop#")
 {
   digitalWrite (5, LOW);
   digitalWrite (4, LOW);
   digitalWrite (3, LOW);
   digitalWrite (2, LOW);
   delay (100);
 }
 else if (readvoice == "*dooropen#")
 {
  delay(100);
  digitalWrite (6, HIGH);
  digitalWrite (7,LOW);
 }
 else if (readvoice == "*doorclose#")
 {
  delay(100);
  digitalWrite (6, LOW);
  digitalWrite (7, HIGH);
 } 
readvoice="";}} 
