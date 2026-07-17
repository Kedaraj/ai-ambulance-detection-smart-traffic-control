/*
  ESP32-CAM Framework for TinyML Ambulance Detection

  IMPORTANT:
  This sketch is a framework only.
  Replace the TODO section with your Edge Impulse or TensorFlow Lite
  inference code.

  Sends:
    'A' -> Ambulance detected
    'N' -> No ambulance

  UART:
    TX (GPIO1) -> Arduino Mega RX1 (Pin 19)
    RX (GPIO3) -> Arduino Mega TX1 (Pin 18)
*/

#include "esp_camera.h"

// AI Thinker ESP32-CAM Pins
#define PWDN_GPIO_NUM     32
#define RESET_GPIO_NUM    -1
#define XCLK_GPIO_NUM      0
#define SIOD_GPIO_NUM     26
#define SIOC_GPIO_NUM     27
#define Y9_GPIO_NUM       35
#define Y8_GPIO_NUM       34
#define Y7_GPIO_NUM       39
#define Y6_GPIO_NUM       36
#define Y5_GPIO_NUM       21
#define Y4_GPIO_NUM       19
#define Y3_GPIO_NUM       18
#define Y2_GPIO_NUM        5
#define VSYNC_GPIO_NUM    25
#define HREF_GPIO_NUM     23
#define PCLK_GPIO_NUM     22

bool initCamera() {
  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sscb_sda = SIOD_GPIO_NUM;
  config.pin_sscb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  config.pixel_format = PIXFORMAT_RGB565;
  config.frame_size = FRAMESIZE_QQVGA;
  config.jpeg_quality = 12;
  config.fb_count = 1;

  return esp_camera_init(&config) == ESP_OK;
}

void setup() {
  Serial.begin(115200);      // USB debug
  Serial1.begin(115200);     // To Arduino Mega

  if (!initCamera()) {
    Serial.println("Camera init failed");
    while (true) delay(1000);
  }

  Serial.println("ESP32-CAM Ready");
}

void loop() {

  camera_fb_t *fb = esp_camera_fb_get();

  if (!fb) {
    Serial.println("Capture failed");
    delay(100);
    return;
  }

  // =====================================================
  // TODO:
  // Run your Edge Impulse / TensorFlow Lite model here.
  //
  // Example:
  // bool ambulanceDetected = run_inference(fb->buf, fb->len);
  // =====================================================

  bool ambulanceDetected = false; // Placeholder

  if (ambulanceDetected) {
    Serial1.write('A');
    Serial.println("Ambulance");
  } else {
    Serial1.write('N');
    Serial.println("Normal");
  }

  esp_camera_fb_return(fb);

  delay(200);
}
