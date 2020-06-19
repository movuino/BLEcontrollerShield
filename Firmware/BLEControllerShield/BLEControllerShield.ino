/**
 * This example turns the ESP32 into a Bluetooth LE keyboard that writes the words, presses Enter, presses a media key and then Ctrl+Alt+Delete
 */
#include <BleKeyboard.h>

BleKeyboard bleKeyboard;

/*be careful the release of key is manual => a line has been commented in the library*/

int up = 100;
int left = 100;
int right = 100;
int down = 100;
int space = 100;
int clickk = 100;
bool lastUP = false;
bool lastDOWN = false;
bool lastRIGHT = false;
bool lastLEFT = false;
bool lastSPACE = false;
bool lastCLICKK = false;

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  bleKeyboard.begin();
}

int upBuffer=0; 
int downBuffer=0;
int rightBuffer=0; 
int leftBuffer=0;
int count=0;
int touchThreshold=35;


void loop() {
  if(bleKeyboard.isConnected()) {
      //Serial.print("connected");   
      upBuffer += touchRead(T8);
      downBuffer += touchRead(T7);
      leftBuffer += touchRead(T9);
      rightBuffer+=touchRead(T6);
      count++;
      if(count==3) {
        up = upBuffer/4;
        down = downBuffer/4;
        left = leftBuffer/4;
        right = rightBuffer/4;
       // Serial.print(sum);
        //Serial.print(" ");
        Serial.print(up);
        Serial.print(" ");
        Serial.print(down);
        Serial.print(" ");
         Serial.print(left);
        Serial.print(" ");
        Serial.println(right);
        upBuffer=0;
        downBuffer=0;
        leftBuffer=0;
        rightBuffer=0;
        count=0;
        }
      /*delay(5);
      left = touchRead(T9);
      down=touchRead(T7);
     
      space=touchRead(T5);
      clickk=touchRead(T4);
      Serial.println(up);
      /*Serial.print(" ");
      Serial.print(down);
      Serial.print(" ");
      Serial.print(left);
      Serial.print(" ");
      Serial.println(right);*/
      /*UP*/
      if(up<touchThreshold) {
       // Serial.println(up);
        if(!lastUP){
            bleKeyboard.press(KEY_UP_ARROW); 
            Serial.println("up"); 
            lastUP=true;
            }
        }
        else {
            if(lastUP) {
              bleKeyboard.release(KEY_UP_ARROW); 
              Serial.println("release up"); 
              }
            lastUP=false;
       }
        /*down*/
      if(down<touchThreshold) {
        //Serial.println(down);
        if(!lastDOWN){
            bleKeyboard.press(KEY_DOWN_ARROW); 
            Serial.println("down"); 
            lastDOWN=true;
            }
        }
        else {
            if(lastDOWN) {
              bleKeyboard.release(KEY_DOWN_ARROW); 
              Serial.println("release DOWN"); 
              }
            lastDOWN=false;
       }
       
        /*LEFT*/
      if(left<touchThreshold) {
        if(!lastLEFT){
            bleKeyboard.press(KEY_LEFT_ARROW); 
            Serial.println("LEFT"); 
            lastLEFT=true;
            }
        }
        else {
            if(lastLEFT) {
              bleKeyboard.release(KEY_LEFT_ARROW); 
              Serial.println("release LEFT"); 
              }
            lastLEFT=false;
       }
        /*RIGHT*/
      if(right<touchThreshold) {
        //Serial.println(down);
        if(!lastRIGHT){
            bleKeyboard.press(KEY_RIGHT_ARROW); 
            Serial.println("RIGHT"); 
            lastRIGHT=true;
            }
        }
        else {
            if(lastRIGHT) {
              bleKeyboard.release(KEY_RIGHT_ARROW); 
              Serial.println("release RIGHT"); 
              }
            lastRIGHT=false;
       }
    /*DOWN*/
  /*  if(down<=40) {
      // Serial.println(up);
        if(!lastDOWN){
          bleKeyboard.write(KEY_DOWN_ARROW); 
          Serial.println("down"); 
          lastDOWN=true;
          }
      }
      else if(down>40){
        if(lastDOWN) {
        bleKeyboard.release(KEY_DOWN_ARROW); 
        Serial.println("release down"); 
        }
        lastDOWN=false;
      }
   /*LEFT*/
 /*   if(left<=40) {
      // Serial.println(up);
        if(!lastLEFT){
          bleKeyboard.write(KEY_LEFT_ARROW); 
          Serial.println("left"); 
          lastLEFT=true;
          }
      }
      else if(left>40){
        if(lastLEFT) {
        bleKeyboard.release(KEY_LEFT_ARROW); 
        Serial.println("release left"); 
        }
        lastLEFT=false;
      }
      /*RIGHT*/
   /* if(right<=40) {
      // Serial.println(up);
        if(!lastRIGHT){
          bleKeyboard.write(KEY_RIGHT_ARROW); 
          Serial.println("right"); 
          lastRIGHT=true;
          }
      }
      else if(right>40){
        if(lastRIGHT) {
        bleKeyboard.release(KEY_RIGHT_ARROW); 
        Serial.println("release right"); 
        }
        lastRIGHT=false;
      }
  /*  if(down<50) bleKeyboard.write(KEY_DOWN_ARROW);
    if(left<50) bleKeyboard.write(KEY_LEFT_ARROW);
    if(right<50) bleKeyboard.write(KEY_RIGHT_ARROW);
   //iqqf(space<50) bleKeyboard.print("a");
    //if(clickk<50) bleKeyboard.print("d");
    /*Serial.println("Sending 'Hello world'...");
    bleKeyboard.print("Hello world");

    delay(1000);

    Serial.println("Sending Enter key...");
    bleKeyboard.wrqite(KEY_RETURN);

    delay(1000);

    Serial.println("Sending Play/Pause media key...");
    bleKeyboard.write(KEY_MEDIA_PLAY_PAUSE);

    delay(1000);

    Serial.println("Sending Ctrl+Alt+Delete...");
    bleKeyboard.press(KEY_LEFT_CTRL);
    bleKeyboard.press(KEY_LEFT_ALT);
    bleKeyboard.press(KEY_DELETE);*/
    //delay(100);
    //bleKeyboard.releaseAll();
    delay(5);
  }
  else {
  lastUP = false;
  Serial.println("Waiting 5 seconds...");
  delay(5000);
  }
}
