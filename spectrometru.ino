#include <Servo.h>

#define READINGS 100
#define OFFSET 1500
#define GRAPH_H 10
#define RES 100

Servo s;
int value;
int times = 3; // used for getting color average
int LIGHT_AVERAGE = 0; // 1 - RED, 2 - GREEN
int readings[READINGS];
int baseline[READINGS];

double LIGHT_AVERAGES[3]; // used to calculate the average of a color
double RED_AVERAGE = 0; // average red color
double GREEN_AVERAGE = 0; // average red color

const char ROSU[] = {'R', 'O', 'S', 'U', '\0'};
const char VERDE[] = {'V', 'E', 'R', 'D', 'E', '\0'};

int ON = 1;
double average = 0;

void printReadings()
{
  for (int g = GRAPH_H; g > 0; --g)
  {
    for (int i = 0; i < READINGS; ++i)
    {
      if (readings[i] > RES * g)
        Serial.print("#");
    }
    Serial.println();
  }
}

void resetBaseline() {
  for (int i = 0; i < READINGS; ++i)
  {
    s.writeMicroseconds(OFFSET + i);
    delay(15);
    baseline[i] = analogRead(0);
  }
}

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(10);
  pinMode(A0, INPUT_PULLUP);
  s.attach(9);
  resetBaseline();
}

void calculateAverage() {
  average = 0;
  for (int i = 0; i < 100; ++i) {
    average = average + readings[i];
  }
  average = average / 100;  
}

void showColor()
{
  Serial.println("\n---\n");
  if (average > GREEN_AVERAGE)
  {
    double diff1 = RED_AVERAGE - average;
    double diff2 = average - GREEN_AVERAGE;
    if (diff1 < diff2)
      Serial.println(ROSU);
    else
      Serial.println(VERDE);
  }
  
}

void loop() {
  if (Serial.available())
  {
    value = 0;
    value = Serial.readStringUntil("\n").toInt();
    if (value == 1)
    {
      Serial.println("Reset baseline");
      resetBaseline();
    }
    else if (value == 2)
    {
      Serial.println("Stop");
      ON = 0;
    }
    else if (value == 3)
    {
      Serial.println("Start");
      resetBaseline();
      ON = 1;
    }
    else if (value == 4)
    {
      Serial.println("Get RED Average");
      ON = 1;
      LIGHT_AVERAGE = 1;
    }
    else if (value == 5)
    {
      Serial.println("Get GREEN Average");
      ON = 1;
      LIGHT_AVERAGE = 2;
    }
  }
  else if (Serial.available())
  {
    value = Serial.readStringUntil("\n").toInt();
    Serial.println(value);
    s.writeMicroseconds(value);
  }
  if (ON == 1) { 

  
    for (int i = 0; i < READINGS; ++i)
    {
      s.writeMicroseconds(OFFSET + i);
      delay(15);
      readings[i] = baseline[i] - analogRead(0);
      Serial.println(readings[i]);
  //    Serial.print(" ");
    }
    
    calculateAverage();
    if (LIGHT_AVERAGE == 0) {
      //Serial.println(average);
    }
    else if (LIGHT_AVERAGE == 1)
    {
      times = times - 1;
      LIGHT_AVERAGES[times] = average;
      if (times == 0) {
        times = 3;
        LIGHT_AVERAGE = 0;
        RED_AVERAGE = (LIGHT_AVERAGES[0] + LIGHT_AVERAGES[1] + LIGHT_AVERAGES[2]) / 3;
        Serial.print("Intensitatea medie a luminii rosii este: ");
        Serial.println(RED_AVERAGE);
      }
    }
    else if (LIGHT_AVERAGE == 2)
    {
      times = times - 1;
      LIGHT_AVERAGES[times] = average;
      if (times == 0) {
        times = 3;
        LIGHT_AVERAGE = 0;
        GREEN_AVERAGE = (LIGHT_AVERAGES[0] + LIGHT_AVERAGES[1] + LIGHT_AVERAGES[2]) / 3;
        Serial.print("Intensitatea medie a luminii verzi este: ");
        Serial.println(GREEN_AVERAGE);
      }
    }

    
 //   Serial.print("Intensitatea medie a luminii rosii este: ");
 //   Serial.println(RED_AVERAGE);
 //   Serial.print("Intensitatea medie a luminii verzi este: ");
 //   Serial.println(GREEN_AVERAGE);
    if ((times == 3) && (RED_AVERAGE > 0) && (GREEN_AVERAGE)) {
 //     showColor();
    }
  
  
    //  printReadings();
  
    //  Serial.println(analogRead(0));
    //  s.write(map(analogRead(0),300,1023,0,180));
  }
}
