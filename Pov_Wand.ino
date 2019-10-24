/*
 * ECE 341: Junior Design Accelerted Project 1
 * 
 * Persistance Of Vision Waving Wand
 * 
 * Author: Tristan Luther
 * Date: 10/11/2019
 * Purpose: Firmware for the Persistance of 
 * Vision Wand using the ADLX Accelerometer
 * 
 */
#include <avr/pgmspace.h> //Uses Arduino flash memory
#include "text_ref.h"

int magThresh = 20;
int prevX = 0;
int prevY = 0;
bool dir = NULL; //if dir = 1, moving left. if dir = 0, moving right.
int timeLCorner = 0; //Used to measure the time from one corner
int timeRCorner = 0; //Used to measure time to other corner

byte led_pin_min = 4;
byte led_pin_max = 13;

String displayText = "beavers"; //All lowercse, spaces allowed, no puncutation

byte textLen = displayText.length();
int delayMod = 0;
int delayTime = 2.75;
int charBreak = 2.1;

/***************Functions***************************/
void determineDir(){
  // Get raw accelerometer data for x/y axis
  int rawX = analogRead(A0);
  int rawY = analogRead(A1);

  //Determine if the enviroment has changed
  int diff = (rawX + rawY)-(prevX + prevY);

  //New Previous Values
  prevX = rawX;
  prevY = rawY;

  //Diffenece Maganitude
  diff = sqrt(pow(diff, 2));

  //The movement difference pass the threshold
  if(diff > magThresh){
    //Detected a Left Swing
    if((rawX + rawY) > 760){
      dir = 1;
      timeLCorner = millis();
    }
    //Detected a Right Swing
    else if((rawX + rawY) < 730){
      dir = 0;
      timeRCorner = millis();
    }
  }
  //Check the time it took to complete rotation to adjust delay
  if((timeRCorner - timeLCorner) > 300 && (timeRCorner - timeLCorner) < 1000){
    delayMod = (timeRCorner - timeLCorner);
    delayTime = (delayMod / (textLen * 30));
    charBreak = (delayTime * 2);
  }
}

void printLED(uint8_t col){
  int curr_col;
  curr_col = col;
  if(curr_col >= 64){
    digitalWrite(5, HIGH);
    curr_col-=64;
  }
  else{
    digitalWrite(5, LOW);
  }
  if(curr_col >= 32){
    digitalWrite(6, HIGH);
    curr_col-=32;
  }
  else{
    digitalWrite(6, LOW);
  }
  if (curr_col >= 16){
    digitalWrite(7, HIGH); 
    curr_col-=16;
  } 
  else{
    digitalWrite(7, LOW);
  }
  if (curr_col >= 8){
    digitalWrite(8, HIGH); 
    curr_col-=8;
  }  
  else{
    digitalWrite(8, LOW);
  }
  if (curr_col >= 4){
    digitalWrite(9, HIGH);
    curr_col-=4;
  }  
  else{
    digitalWrite(9, LOW);
  }
  if (curr_col >= 2){
    digitalWrite(10, HIGH);
    curr_col-=2;
  }  
  else{
    digitalWrite(10, LOW);
  }
  if (curr_col >= 1){
    digitalWrite(11, HIGH); 
    curr_col-=1;
  }  
  else{
    digitalWrite(11, LOW);
  }
  determineDir();
}

void displayLetter(char ch, bool dir){
  Serial.println(ch);
  //If we found an A
  if(ch == 'a'){
    determineDir();
    if(dir){
      for(int k = 0; k < 6; k++){
        printLED(a[k]);
        delay(delayTime);
      }
    }
    else{
      for(int k = 5; k >= 0; k++){
        printLED(a[k]);
        delay(delayTime);
      }
    }
  }
  //If we found a B
  if(ch == 'b'){
    determineDir();
    if(dir){
      for(int k = 0; k < 6; k++){
        printLED(b[k]);
        delay(delayTime);
      }
    }
    else{
      for(int k = 5; k >= 0; k++){
        printLED(b[k]);
        delay(delayTime);
      }
    }
  }
  //If we found a C
  if(ch == 'c'){
    determineDir();
    if(dir){
      for(int k = 0; k < 6; k++){
        printLED(c[k]);
        delay(delayTime);
      }
    }
    else{
      for(int k = 5; k >= 0; k++){
        printLED(c[k]);
        delay(delayTime);
      }
    }
  }
  //If we found a D
  if(ch == 'd'){
    determineDir();
    if(dir){
      for(int k = 0; k < 6; k++){
        printLED(d[k]);
        delay(delayTime);
      }
    }
    else{
      for(int k = 5; k >= 0; k++){
        printLED(d[k]);
        delay(delayTime);
      }
    }
  }
  //If we found a E
  if(ch == 'e'){
    determineDir();
    if(dir){
      for(int k = 0; k < 6; k++){
        printLED(e[k]);
        delay(delayTime);
      }
    }
    else{
      for(int k = 5; k >= 0; k++){
        printLED(e[k]);
        delay(delayTime);
      }
    }
  }
  //If we found a F
  if(ch == 'f'){
    determineDir();
    if(dir){
      for(int k = 0; k < 6; k++){
        printLED(f[k]);
        delay(delayTime);
      }
    }
    else{
      for(int k = 5; k >= 0; k++){
        printLED(f[k]);
        delay(delayTime);
      }
    }
  }
  //If we found a G
  if(ch == 'g'){
    determineDir();
    if(dir){
      for(int k = 0; k < 6; k++){
        printLED(g[k]);
        delay(delayTime);
      }
    }
    else{
      for(int k = 5; k >= 0; k++){
        printLED(g[k]);
        delay(delayTime);
      }
    }
  }
  //If we found a H
  if(ch == 'h'){
    determineDir();
    if(dir){
      for(int k = 0; k < 6; k++){
        printLED(h[k]);
        delay(delayTime);
      }
    }
    else{
      for(int k = 5; k >= 0; k++){
        printLED(h[k]);
        delay(delayTime);
      }
    }
  }
  //If we found a I
  if(ch == 'i'){
    determineDir();
    if(dir){
      for(int k = 0; k < 6; k++){
        printLED(i[k]);
        delay(delayTime);
      }
    }
    else{
      for(int k = 5; k >= 0; k++){
        printLED(i[k]);
        delay(delayTime);
      }
    }
  }
  //If we found a J
  if(ch == 'j'){
    determineDir();
    if(dir){
      for(int k = 0; k < 6; k++){
        printLED(j[k]);
        delay(delayTime);
      }
    }
    else{
      for(int k = 5; k >= 0; k++){
        printLED(j[k]);
        delay(delayTime);
      }
    }
  }
  //If we found a K
  if(ch == 'k'){
    determineDir();
    if(dir){
      for(int k = 0; k < 6; k++){
        printLED(k2[k]);
        delay(delayTime);
      }
    }
    else{
      for(int k = 5; k >= 0; k++){
        printLED(k2[k]);
        delay(delayTime);
      }
    }
  }
  //If we found a L
  if(ch == 'l'){
    determineDir();
    if(dir){
      for(int k = 0; k < 6; k++){
        printLED(l[k]);
        delay(delayTime);
      }
    }
    else{
      for(int k = 5; k >= 0; k++){
        printLED(l[k]);
        delay(delayTime);
      }
    }
  }
  //If we found a M
  if(ch == 'm'){
    determineDir();
    if(dir){
      for(int k = 0; k < 6; k++){
        printLED(m[k]);
        delay(delayTime);
      }
    }
    else{
      for(int k = 5; k >= 0; k++){
        printLED(m[k]);
        delay(delayTime);
      }
    }
  }
  //If we found a N
  if(ch == 'n'){
    determineDir();
    if(dir){
      for(int k = 0; k < 6; k++){
        printLED(n[k]);
        delay(delayTime);
      }
    }
    else{
      for(int k = 5; k >= 0; k++){
        printLED(n[k]);
        delay(delayTime);
      }
    }
  }
  //If we found a O
  if(ch == 'o'){
    determineDir();
    if(dir){
      for(int k = 0; k < 6; k++){
        printLED(o[k]);
        delay(delayTime);
      }
    }
    else{
      for(int k = 5; k >= 0; k++){
        printLED(o[k]);
        delay(delayTime);
      }
    }
  }
  //If we found a P
  if(ch == 'p'){
    determineDir();
    if(dir){
      for(int k = 0; k < 6; k++){
        printLED(p[k]);
        delay(delayTime);
      }
    }
    else{
      for(int k = 5; k >= 0; k++){
        printLED(p[k]);
        delay(delayTime);
      }
    }
  }
  //If we found a Q
  if(ch == 'q'){
    determineDir();
    if(dir){
      for(int k = 0; k < 6; k++){
        printLED(q[k]);
        delay(delayTime);
      }
    }
    else{
      for(int k = 5; k >= 0; k++){
        printLED(q[k]);
        delay(delayTime);
      }
    }
  }
  //If we found a R
  if(ch == 'r'){
    determineDir();
    if(dir){
      for(int k = 0; k < 6; k++){
        printLED(r[k]);
        delay(delayTime);
      }
    }
    else{
      for(int k = 5; k >= 0; k++){
        printLED(r[k]);
        delay(delayTime);
      }
    }
  }
  //If we found a S
  if(ch == 's'){
    determineDir();
    if(dir){
      for(int k = 0; k < 6; k++){
        printLED(s[k]);
        delay(delayTime);
      }
    }
    else{
      for(int k = 5; k >= 0; k++){
        printLED(s[k]);
        delay(delayTime);
      }
    }
  }
  //If we found a T
  if(ch == 't'){
    determineDir();
    if(dir){
      for(int k = 0; k < 6; k++){
        printLED(t[k]);
        delay(delayTime);
      }
    }
    else{
      for(int k = 5; k >= 0; k++){
        printLED(t[k]);
        delay(delayTime);
      }
    }
  }
  //If we found a U
  if(ch == 'u'){
    determineDir();
    if(dir){
      for(int k = 0; k < 6; k++){
        printLED(u[k]);
        delay(delayTime);
      }
    }
    else{
      for(int k = 5; k >= 0; k++){
        printLED(u[k]);
        delay(delayTime);
      }
    }
  }
  //If we found a V
  if(ch == 'v'){
    determineDir();
    if(dir){
      for(int k = 0; k < 6; k++){
        printLED(v[k]);
        delay(delayTime);
      }
    }
    else{
      for(int k = 5; k >= 0; k++){
        printLED(v[k]);
        delay(delayTime);
      }
    }
  }
  //If we found a W
  if(ch == 'w'){
    determineDir();
    if(dir){
      for(int k = 0; k < 6; k++){
        printLED(w[k]);
        delay(delayTime);
      }
    }
    else{
      for(int k = 5; k >= 0; k++){
        printLED(w[k]);
        delay(delayTime);
      }
    }
  }
  //If we found a X
  if(ch == 'x'){
    determineDir();
    if(dir){
      for(int k = 0; k < 6; k++){
        printLED(x[k]);
        delay(delayTime);
      }
    }
    else{
      for(int k = 5; k >= 0; k++){
        printLED(x[k]);
        delay(delayTime);
      }
    }
  }
  //If we found a Y
  if(ch == 'y'){
    determineDir();
    if(dir){
      for(int k = 0; k < 6; k++){
        printLED(y[k]);
        delay(delayTime);
      }
    }
    else{
      for(int k = 5; k >= 0; k++){
        printLED(y[k]);
        delay(delayTime);
      }
    }
  }
  //If we found a Z
  if(ch == 'z'){
    determineDir();
    if(dir){
      for(int k = 0; k < 6; k++){
        printLED(z[k]);
        delay(delayTime);
      }
    }
    else{
      for(int k = 5; k >= 0; k++){
        printLED(z[k]);
        delay(delayTime);
      }
    }
  }
  //If we found a Space
  if(ch == ' '){
    determineDir();
    if(dir){
      for(int k = 0; k < 6; k++){
        printLED(sp[k]);
        delay(delayTime);
      }
    }
    else{
      for(int k = 5; k >= 0; k++){
        printLED(sp[k]);
        delay(delayTime);
      }
    }
  }
  //If we found a !
  if(ch == '!'){
    determineDir();
    if(dir){
      for(int k = 0; k < 6; k++){
        printLED(ex[k]);
        delay(delayTime);
      }
    }
    else{
      for(int k = 5; k >= 0; k++){
        printLED(ex[k]);
        delay(delayTime);
      }
    }
  }
  delay(charBreak);
}

/****************Set-up****************************/
void setup() {
  //Initalize the Serial Mointor (9600 baud)
  Serial.begin(9600);

  //Initalize the LED outputs (D2 - D12)
  for(byte i = led_pin_min; i < led_pin_max; i++){
    pinMode(i, OUTPUT);
  }
}

/*****************Loop***************/
void loop() {
  //Loop through each char in the word
  for(int j = 0; j < textLen; j++){
      determineDir();
      displayLetter(displayText[j], dir);
  }
  delay(20);
}
