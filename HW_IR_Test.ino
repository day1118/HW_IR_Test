/*
  Hockey Warrior - IR Test
  Tests the IR Sensors & prints the results
 */
 
 #include "config.h"

int IRFL_FRONT_Off;
int IRFL_FRONT_On;
int IRFL_SIDE_Off;
int IRFL_SIDE_On;
int IRFL_FRONT_Diff;
int IRFL_SIDE_Diff;

int IRFR_FRONT_Off;
int IRFR_FRONT_On;
int IRFR_SIDE_Off;
int IRFR_SIDE_On;
int IRFR_FRONT_Diff;
int IRFR_SIDE_Diff;

int IRBL_BACK_Off;
int IRBL_BACK_On;
int IRBL_SIDE_Off;
int IRBL_SIDE_On;
int IRBL_BACK_Diff;
int IRBL_SIDE_Diff;

int IRBR_BACK_Off;
int IRBR_BACK_On;
int IRBR_SIDE_Off;
int IRBR_SIDE_On;
int IRBR_BACK_Diff;
int IRBR_SIDE_Diff;

int averageCount = 30;

void setup() {
	// Set IR pins as outputs
  pinMode(IRFL_IR_LED_PIN, OUTPUT);
  pinMode(IRFR_IR_LED_PIN, OUTPUT);
  pinMode(IRBL_IR_LED_PIN, OUTPUT);
  pinMode(IRBR_IR_LED_PIN, OUTPUT);

  Serial.begin(115200);      // open the serial port at 9600 bps:

  DEBUG_PRINT("Starting...");
}

void loop() {
	// Read each sensor in a loop
  digitalWrite(IRFL_IR_LED_PIN, HIGH);
  delay(LED_READ_DELAY_TIME);
  IRFL_FRONT_On = readSensor(IRFL_FRONT_PHOTOTRANSISTOR_PIN, averageCount);
  IRFL_SIDE_On = readSensor(IRFL_SIDE_PHOTOTRANSISTOR_PIN, averageCount);
  digitalWrite(IRFL_IR_LED_PIN, LOW);

  digitalWrite(IRFR_IR_LED_PIN, HIGH);
  delay(LED_READ_DELAY_TIME);
  IRFR_FRONT_On = readSensor(IRFR_FRONT_PHOTOTRANSISTOR_PIN, averageCount);
  IRFR_SIDE_On = readSensor(IRFR_SIDE_PHOTOTRANSISTOR_PIN, averageCount);
  digitalWrite(IRFR_IR_LED_PIN, LOW);

  digitalWrite(IRBL_IR_LED_PIN, HIGH);
  delay(LED_READ_DELAY_TIME);
  IRBL_BACK_On = readSensor(IRBL_BACK_PHOTOTRANSISTOR_PIN, averageCount);
  IRBL_SIDE_On = readSensor(IRBL_SIDE_PHOTOTRANSISTOR_PIN, averageCount);
  digitalWrite(IRBL_IR_LED_PIN, LOW);

  digitalWrite(IRBR_IR_LED_PIN, HIGH);
  delay(LED_READ_DELAY_TIME);
  IRBR_BACK_On = readSensor(IRBR_BACK_PHOTOTRANSISTOR_PIN, averageCount);
  IRBR_SIDE_On = readSensor(IRBR_SIDE_PHOTOTRANSISTOR_PIN, averageCount);
  digitalWrite(IRBR_IR_LED_PIN, LOW);  
    
  IRFL_FRONT_Off = readSensor(IRFL_FRONT_PHOTOTRANSISTOR_PIN, averageCount);
  IRFL_SIDE_Off = readSensor(IRFL_SIDE_PHOTOTRANSISTOR_PIN, averageCount);
  IRFR_FRONT_Off = readSensor(IRFR_FRONT_PHOTOTRANSISTOR_PIN, averageCount);
  IRFR_SIDE_Off = readSensor(IRFR_SIDE_PHOTOTRANSISTOR_PIN, averageCount);
  
  IRBL_BACK_Off = readSensor(IRBL_BACK_PHOTOTRANSISTOR_PIN, averageCount);
  IRBL_SIDE_Off = readSensor(IRBL_SIDE_PHOTOTRANSISTOR_PIN, averageCount);
  IRBR_BACK_Off = readSensor(IRBR_BACK_PHOTOTRANSISTOR_PIN, averageCount);
  IRBR_SIDE_Off = readSensor(IRBR_SIDE_PHOTOTRANSISTOR_PIN, averageCount);
  
  IRFL_FRONT_Diff = IRFL_FRONT_On - IRFL_FRONT_Off;
  IRFL_SIDE_Diff = IRFL_SIDE_On - IRFL_SIDE_Off;
  IRFR_FRONT_Diff = IRFR_FRONT_On - IRFR_FRONT_Off;
  IRFR_SIDE_Diff = IRFR_SIDE_On - IRFR_SIDE_Off;
  IRBL_BACK_Diff = IRBL_BACK_On - IRBL_BACK_Off;
  IRBL_SIDE_Diff = IRBL_SIDE_On - IRBL_SIDE_Off;
  IRBR_BACK_Diff = IRBR_BACK_On - IRBR_BACK_Off;
  IRBR_SIDE_Diff = IRBR_SIDE_On - IRBR_SIDE_Off;
  
  PLOT("IRFL_FRONT_Off", IRFL_FRONT_Off);
  PLOT("IRFL_FRONT_On", IRFL_FRONT_On);
  PLOT("IRFL_SIDE_Off", IRFL_SIDE_Off);
  PLOT("IRFL_SIDE_On", IRFL_SIDE_On);
  PLOT("IRFL_FRONT_Diff", IRFL_FRONT_Diff);
  PLOT("IRFL_SIDE_Diff", IRFL_SIDE_Diff);
  
  PLOT("IRFR_FRONT_Off", IRFR_FRONT_Off);
  PLOT("IRFR_FRONT_On", IRFR_FRONT_On);
  PLOT("IRFR_SIDE_Off", IRFR_SIDE_Off);
  PLOT("IRFR_SIDE_On", IRFR_SIDE_On);
  PLOT("IRFR_FRONT_Diff", IRFR_FRONT_Diff);
  PLOT("IRFR_SIDE_Diff", IRFR_SIDE_Diff);
  
  PLOT("IRBL_BACK_Off", IRBL_BACK_Off);
  PLOT("IRBL_BACK_On", IRBL_BACK_On);
  PLOT("IRBL_SIDE_Off", IRBL_SIDE_Off);
  PLOT("IRBL_SIDE_On", IRBL_SIDE_On);
  PLOT("IRBL_BACK_Diff", IRBL_BACK_Diff);
  PLOT("IRBL_SIDE_Diff", IRBL_SIDE_Diff);
  
  PLOT("IRBR_BACK_Off", IRBR_BACK_Off);
  PLOT("IRBR_BACK_On", IRBR_BACK_On);
  PLOT("IRBR_SIDE_Off", IRBR_SIDE_Off);
  PLOT("IRBR_SIDE_On", IRBR_SIDE_On);
  PLOT("IRBR_BACK_Diff", IRBR_BACK_Diff);
  PLOT("IRBR_SIDE_Diff", IRBR_SIDE_Diff);
}


int readSensor(int pin, int averageCount)
{
  int value = 0;
  int i = 0;
  for(i = 0; i < averageCount; i++)
      value += analogRead(pin);
  return value/averageCount;
}
