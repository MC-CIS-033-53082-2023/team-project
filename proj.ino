#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <Wire.h>
#include <NewPing.h>

#define SOUND_PIN 2
#define TRIGGER_PIN 3
#define ECHO_PIN 4
#define SERVO 9
#define RED_PIN 6
#define GREEN_PIN 7
#define BLUE_PIN 8
#define SWITCH_PIN A3
#define REPEAT 5
#define TOGGLE_PIN 12

float duration, distance;
float max_distance;
float parsed_range = 50;
int range;
bool system_on = false;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, parsed_range);

Servo servo1;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
    Serial.begin(9600);
    pinMode(RED_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);
    pinMode(BLUE_PIN, OUTPUT);
    pinMode(SWITCH_PIN, INPUT);
    pinMode(SOUND_PIN, OUTPUT);
    analogWrite(RED_PIN, 255);
    analogWrite(GREEN_PIN, 255);
    analogWrite(BLUE_PIN, 255);
    lcd.init();
    lcd.backlight();
    lcd.begin(16, 2);
    servo1.attach(SERVO);
}

void warning_blink()
{
    // Red
    analogWrite(RED_PIN, 0);     // Full intensity
    analogWrite(GREEN_PIN, 255); // No intensity (off)
    analogWrite(BLUE_PIN, 255);  // No intensity (off)
    analogWrite(SOUND_PIN, 0);
    delay(150);

    // Blue
    analogWrite(RED_PIN, 255);   // No intensity (off)
    analogWrite(GREEN_PIN, 255); // No intensity (off)
    analogWrite(BLUE_PIN, 0);    // Full intensity
    analogWrite(SOUND_PIN, 1023);
    delay(150);
}

void display_message(int distance, int range)
{
    lcd.setCursor(0, 0);
    lcd.print("Distance: ");
    lcd.print(distance);
    lcd.print("cm");
    lcd.setCursor(0, 1);
    lcd.print("Range: ");
    lcd.print(range);
    lcd.print("cm");
}

void loop()
{
    system_on = !digitalRead(TOGGLE_PIN);
    if (system_on)
    {
        run_radar();
    }
    else
    {
        analogWrite(SOUND_PIN, 1023);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("System off");
        delay(10);
    }
}

void run_radar()
{
    analogWrite(SOUND_PIN, 1023);
    range = analogRead(SWITCH_PIN);
    parsed_range = map(range, 0, 1000, 20, 40);
    Serial.println(range);
    lcd.setCursor(0, 0);
    lcd.print("Range: ");
    lcd.print(parsed_range);
    lcd.print("cm");
    int i = 0;
    for (i; i < 180; i++)
    {
        system_on = !digitalRead(TOGGLE_PIN);
        if (system_on == false)
        {
            break;
            analogWrite(SOUND_PIN, 1023);
        }
        servo1.write(i);
        sonar_detect();
        range = analogRead(SWITCH_PIN);
        parsed_range = map(range, 0, 1000, 20, 40);
        lcd.setCursor(0, 0);
        lcd.print("Range: ");
        lcd.print(parsed_range);
        lcd.print("cm");
        if (distance < parsed_range && distance > 0)
        {

            warning_blink();
        }
        else
        {
            analogWrite(RED_PIN, 255);
            analogWrite(GREEN_PIN, 255);
            analogWrite(BLUE_PIN, 255);
            analogWrite(SOUND_PIN, 1023);
        }
    }
    for (i; i > 0; i--)
    {
        system_on = !digitalRead(TOGGLE_PIN);
        if (system_on == false)
        {
            break;
        }
        servo1.write(i);
        sonar_detect();
        range = analogRead(SWITCH_PIN);
        parsed_range = map(range, 0, 1000, 20, 40);
        lcd.setCursor(0, 0);
        lcd.print("Range: ");
        lcd.print(parsed_range);
        lcd.print("cm");
        if (distance < parsed_range && distance > 0)
        {
            warning_blink();
        }
        else
        {
            analogWrite(RED_PIN, 255);
            analogWrite(GREEN_PIN, 255);
            analogWrite(BLUE_PIN, 255);
            analogWrite(SOUND_PIN, 1023);
        }
    }
}

void sonar_detect()
{
    duration = sonar.ping_median(REPEAT);
    distance = (duration / 2) * 0.0343;
    if (distance >= parsed_range || distance <= 0)
    {
        lcd.setCursor(0, 1);
        lcd.print("Distance: ");
        lcd.print("Safe.     ");
    }
    else
    {
        lcd.setCursor(0, 1);
        lcd.print("Distance: ");
        lcd.print(distance);
        lcd.print("!!!!");
    }
}