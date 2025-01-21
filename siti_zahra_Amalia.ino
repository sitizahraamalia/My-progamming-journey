/*********
  Rui Santos
  Complete project details at https://randomnerdtutorials.com  
*********/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSerif9pt7b.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define RED 19
#define YELLOW 18
#define GREEN 5
#define BUZZER 17

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println("SSD1306 allocation failed");
    for (;;);
  }
  delay(2000);
}

void loop() {
  // Menyalakan LED hijau dan menampilkan pesan "Terisi"
  digitalWrite(GREEN, HIGH);
  display.clearDisplay();
  display.setTextSize(3);             
  display.setTextColor(WHITE);        
  display.setCursor(0, 20);             
  display.println("Terisi");
  display.display();
  delay(3000);
  
  digitalWrite(GREEN, LOW);
  delay(2000);

  // Menyalakan LED merah dan buzzer
  digitalWrite(RED, HIGH);
  digitalWrite(BUZZER, HIGH);
  
  // Membuat suara "tit tit tit tit" dengan interval
  for (int i = 0; i < 4; i++) {  // Mengulang 4 kali
    tone(BUZZER, 1000);  // Nada 1000 Hz
    delay(300);          // Durasi suara
    noTone(BUZZER);      // Hentikan suara
    delay(300);          // Interval antar suara
  }
  
  display.clearDisplay();
  display.setTextSize(3);             
  display.setTextColor(WHITE);        
  display.setCursor(0, 20);             
  display.println("Habis!");
  display.display();
  delay(2000);
  
  // Mematikan LED merah dan buzzer
  digitalWrite(RED, LOW);
  digitalWrite(BUZZER, LOW);
  
  delay(3000);
}
