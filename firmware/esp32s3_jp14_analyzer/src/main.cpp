// Onkyo RC-764M ESP32-S3 JP1.4 Analyzer v3
// Passive service/program interface investigation
//
// Design assumptions:
// - JP1.4 may be a factory programming/test interface.
// - Do not drive lines.
// - Do not enable internal pullups/pulldowns.
// - Capture only.
//
// Confirmed:
// Pin 1 = VCC
// Pin 2 = GND
// Pins 3-6 = unknown

#include <Arduino.h>
#include <string.h>

#define JP14_COUNT 4
#define BUFFER_SIZE 2048

const uint8_t JP14_PINS[JP14_COUNT] = {4,5,6,7};
const char* JP14_NAMES[JP14_COUNT] = {
 "JP1.4 Pin 3","JP1.4 Pin 4","JP1.4 Pin 5","JP1.4 Pin 6"
};

struct Event {
 uint8_t pin;
 uint8_t level;
 uint32_t timestamp;
};

Event events[BUFFER_SIZE];
uint16_t eventIndex=0;
int lastState[JP14_COUNT];
uint32_t edges[JP14_COUNT];

void addEvent(uint8_t p,uint8_t s){
 events[eventIndex]={p,s,micros()};
 eventIndex=(eventIndex+1)%BUFFER_SIZE;
}

void clearEvents(){
 memset(events,0,sizeof(events));
 eventIndex=0;
 Serial.println("CLEARED");
}

void dumpEvents(){
 Serial.println("JP1.4 CAPTURE");
 for(int i=0;i<BUFFER_SIZE;i++){
  if(events[i].timestamp){
   Serial.print("P");
   Serial.print(events[i].pin+3);
   Serial.print(" ");
   Serial.print(events[i].level?"HIGH":"LOW");
   Serial.print(" ");
   Serial.println(events[i].timestamp);
  }
 }
}

void setup(){
 Serial.begin(115200);
 delay(500);
 Serial.println("JP1.4 PASSIVE ANALYZER");
 Serial.println("INPUT ONLY - NO PULLS - NO OUTPUTS");
 Serial.println("d=dump c=clear");

 for(int i=0;i<JP14_COUNT;i++){
  pinMode(JP14_PINS[i],INPUT);
  lastState[i]=digitalRead(JP14_PINS[i]);
  edges[i]=0;
 }
}

void loop(){
 if(Serial.available()){
  char c=Serial.read();
  if(c=='d') dumpEvents();
  if(c=='c') clearEvents();
 }

 for(int i=0;i<JP14_COUNT;i++){
  int s=digitalRead(JP14_PINS[i]);
  if(s!=lastState[i]){
   edges[i]++;
   addEvent(i,s);
   Serial.print(JP14_NAMES[i]);
   Serial.print(" ");
   Serial.print(s?"HIGH":"LOW");
   Serial.print(" count=");
   Serial.println(edges[i]);
   lastState[i]=s;
  }
 }
}
