// Onkyo RC-764M ESP32-S3 JP1.4 Analyzer v4
// Passive service/program interface investigation
//
// No line driving. No pull resistors.
// JP1.4 is treated as a sensitive factory interface.
//
// Pin 1 = VCC
// Pin 2 = GND
// Pins 3-6 = monitored lines

#include <Arduino.h>
#include <string.h>

#define JP14_COUNT 4
#define BUFFER_SIZE 4096

const uint8_t JP14_PINS[JP14_COUNT] = {4,5,6,7};
const char* JP14_NAMES[JP14_COUNT] = {
 "JP1.4 Pin 3","JP1.4 Pin 4","JP1.4 Pin 5","JP1.4 Pin 6"
};

struct Event {
 uint8_t pin;
 uint8_t level;
 uint32_t timestamp;
 uint32_t delta;
};

Event events[BUFFER_SIZE];
uint16_t eventIndex=0;
int lastState[JP14_COUNT];
uint32_t edges[JP14_COUNT];
uint32_t lastTime[JP14_COUNT];

void addEvent(uint8_t p,uint8_t s,uint32_t d){
 events[eventIndex]={p,s,micros(),d};
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
   Serial.print(" dt=");
   Serial.println(events[i].delta);
  }
 }
}

void report(){
 Serial.println("--- JP1.4 ANALYSIS ---");
 for(int i=0;i<JP14_COUNT;i++){
  Serial.print(JP14_NAMES[i]);
  Serial.print(" edges=");
  Serial.println(edges[i]);
 }
}

void setup(){
 Serial.begin(115200);
 delay(500);

 Serial.println("JP1.4 PASSIVE ANALYZER v4");
 Serial.println("INPUT ONLY - NO PULLS - NO OUTPUTS");
 Serial.println("d=dump c=clear r=report");

 for(int i=0;i<JP14_COUNT;i++){
  pinMode(JP14_PINS[i],INPUT);
  lastState[i]=digitalRead(JP14_PINS[i]);
  edges[i]=0;
  lastTime[i]=micros();
 }
}

void loop(){
 if(Serial.available()){
  char c=Serial.read();
  if(c=='d') dumpEvents();
  if(c=='c') clearEvents();
  if(c=='r') report();
 }

 for(int i=0;i<JP14_COUNT;i++){
  int s=digitalRead(JP14_PINS[i]);
  if(s!=lastState[i]){
   uint32_t now=micros();
   uint32_t delta=now-lastTime[i];
   edges[i]++;
   addEvent(i,s,delta);
   lastTime[i]=now;
   lastState[i]=s;
  }
 }
}
