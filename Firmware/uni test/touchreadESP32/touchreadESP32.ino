
/*static const uint8_t T0 = 4;
static const uint8_t T1 = 0;
static const uint8_t T2 = 2;
static const uint8_t T3 = 15;
static const uint8_t T4 = 13;
static const uint8_t T5 = 12;
static const uint8_t T6 = 14;
static const uint8_t T7 = 27;
static const uint8_t T8 = 33;
static const uint8_t T9 = 32;*/
int up = 100;
int left = 100;
int right = 100;
int down = 100;
int space = 100;
int clickk = 100;

void setup()
{
Serial.begin(115200);
Serial.println("ESP32 Touch Test");
}
 
void loop()
{
up = touchRead(T8);
left = touchRead(T9);
down=touchRead(T7);
right=touchRead(T6);
space=touchRead(T5);
clickk=touchRead(T4);
Serial.print("UP : ");
Serial.print(up); // get value using T0
Serial.print("LEFT : ");
Serial.print(left); // get value using T0
Serial.print("RIGHT : ");
Serial.print(right); // get value using T0
Serial.print("DOWN : ");
Serial.println(down); // get value using T0
Serial.print("space : ");
Serial.println(space); // get value using T0
Serial.print("click : ");
Serial.println(clickk); // get value using T0
/*if (touch_value < 50)
{
digitalWrite (LED_PIN, HIGH);
}
else
{
digitalWrite (LED_PIN, LOW);
}*/
delay(10);
}
