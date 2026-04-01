
#include"TFT_eSPI.h"
#include<Arduino.h>
/*
TFT_eSPI tft = TFT_eSPI();

void setup(void) {
  tft.init();
  Serial.begin(115200);
  delay(3000);
  tft.fillScreen(TFT_BLACK);
  Serial.println("TFT Initialized");

}

void loop() {
  tft.setCursor(50, 150, 2);  
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(2);
  tft.println("Makerguides");
  Serial.println("Text Printed");
  delay(5000);
}
*/

#include "TFT_eSPI.h"

TFT_eSPI tft = TFT_eSPI();

void setup() {
  Serial.begin(115200);
  tft.begin();
  tft.setRotation(1);
}

void loop() {
  uint16_t cal[5];

  tft.fillScreen(TFT_BLACK);
  tft.setCursor(20, 0);
  tft.setTextFont(2);
  tft.setTextSize(1);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.print("Touch corners ... ");
  tft.calibrateTouch(cal, TFT_MAGENTA, TFT_BLACK, 15);
  tft.println("done.");

  Serial.printf("cal: {%d, %d, %d, %d, %d}\n",
                cal[0], cal[1], cal[2], cal[3], cal[4]);
  delay(10000);
}
/*
#include "TFT_eSPI.h"
#include "TFT_eWidget.h"

TFT_eSPI tft = TFT_eSPI();
uint16_t cal[5] = { 286, 3478, 196, 3536, 2 };

const int led1 = 25;
const int led2 = 32;

ButtonWidget btn1 = ButtonWidget(&tft);
ButtonWidget btn2 = ButtonWidget(&tft);
ButtonWidget* btns[] = { &btn1, &btn2 };

void btn1_pressed(void) {
  if (btn1.justPressed()) {
    bool state = !btn1.getState();
    btn1.drawSmoothButton(state, 2, TFT_WHITE, state ? "ON" : "OFF");
    digitalWrite(led1, state ? HIGH : LOW);
  }
}

void btn2_pressed(void) {
  if (btn2.justPressed()) {
    bool state = !btn2.getState();
    btn2.drawSmoothButton(state, 2, TFT_WHITE, state ? "ON" : "OFF");
    digitalWrite(led2, state ? HIGH : LOW);
  }
}

void initButtons() {
  uint16_t w = 100;
  uint16_t h = 50;
  uint16_t x = (tft.width() - w) / 2;
  uint16_t y = tft.height() / 2 - h - 10;

  btn1.initButtonUL(x, y, w, h, TFT_WHITE, TFT_BLACK, TFT_YELLOW, "LED1", 2);
  btn1.setPressAction(btn1_pressed);
  btn1.drawSmoothButton(false, 2, TFT_BLACK);

  y = tft.height() / 2 + 10;
  btn2.initButtonUL(x, y, w, h, TFT_WHITE, TFT_BLACK, TFT_GREEN, "LED2", 2);
  btn2.setPressAction(btn2_pressed);
  btn2.drawSmoothButton(false, 2, TFT_BLACK);
}

void handleButtons() {
  uint8_t nBtns = sizeof(btns) / sizeof(btns[0]);
  uint16_t x = 0, y = 0;
  bool touched = tft.getTouch(&x, &y);
  for (uint8_t b = 0; b < nBtns; b++) {
    if (touched) {
      if (btns[b]->contains(x, y)) {
        btns[b]->press(true);
        btns[b]->pressAction();
      }
    } else {
      btns[b]->press(false);
      btns[b]->releaseAction();
    }
  }
}

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  tft.begin();
  tft.setRotation(0);
  tft.fillScreen(TFT_BLACK);
  tft.setTouch(cal);
  
  initButtons();
}

void loop() {
  handleButtons();
  delay(50);
}
*/