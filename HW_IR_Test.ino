/*
  Hockey Warrior - IR Test
  Tests the IR Sensors & prints the results
 */
 
 #include "config.h"

int IRFL_FRONT_Off;
int IRFL_FRONT_On;
int IRFL_SIDE_Off;
int IRFL_SIDE_On;

int IRFR_FRONT_Off;
int IRFR_FRONT_On;
int IRFR_SIDE_Off;
int IRFR_SIDE_On;

int IRBL_BACK_Off;
int IRBL_BACK_On;
int IRBL_SIDE_Off;
int IRBL_SIDE_On;

int IRBR_BACK_Off;
int IRBR_BACK_On;
int IRBR_SIDE_Off;
int IRBR_SIDE_On;

void setup() {
	// Set IR pins as outputs
  pinMode(IRFL_IR_LED_PIN, OUTPUT);
  pinMode(IRFR_IR_LED_PIN, OUTPUT);
  pinMode(IRBL_IR_LED_PIN, OUTPUT);
  pinMode(IRBR_IR_LED_PIN, OUTPUT);

  Serial.begin(9600);      // open the serial port at 9600 bps:

  DEBUG_PRINT("Starting...");
}

void loop() {
	// Read each sensor in a loop
  digitalWrite(IRFL_IR_LED_PIN, HIGH);
  delay(LED_READ_DELAY_TIME);
  IRFL_FRONT_On = analogRead(IRFL_FRONT_PHOTOTRANSISTOR_PIN);
  IRFL_SIDE_On = analogRead(IRFL_SIDE_PHOTOTRANSISTOR_PIN);
  digitalWrite(IRFL_IR_LED_PIN, LOW);

  digitalWrite(IRFR_IR_LED_PIN, HIGH);
  delay(LED_READ_DELAY_TIME);
  IRFR_FRONT_On = analogRead(IRFR_FRONT_PHOTOTRANSISTOR_PIN);
  IRFR_SIDE_On = analogRead(IRFR_SIDE_PHOTOTRANSISTOR_PIN);
  digitalWrite(IRFR_IR_LED_PIN, LOW);

  digitalWrite(IRBL_IR_LED_PIN, HIGH);
  delay(LED_READ_DELAY_TIME);
  IRBL_BACK_On = analogRead(IRBL_BACK_PHOTOTRANSISTOR_PIN);
  IRBL_SIDE_On = analogRead(IRBL_SIDE_PHOTOTRANSISTOR_PIN);
  digitalWrite(IRBL_IR_LED_PIN, LOW);

  digitalWrite(IRBR_IR_LED_PIN, HIGH);
  delay(LED_READ_DELAY_TIME);
  IRBR_BACK_On = analogRead(IRBR_BACK_PHOTOTRANSISTOR_PIN);
  IRBR_SIDE_On = analogRead(IRBR_SIDE_PHOTOTRANSISTOR_PIN);
  digitalWrite(IRBR_IR_LED_PIN, LOW);  
    
  IRFL_FRONT_Off = analogRead(IRFL_FRONT_PHOTOTRANSISTOR_PIN);
  IRFL_SIDE_Off = analogRead(IRFL_SIDE_PHOTOTRANSISTOR_PIN);
  IRFR_FRONT_Off = analogRead(IRFR_FRONT_PHOTOTRANSISTOR_PIN);
  IRFR_SIDE_Off = analogRead(IRFR_SIDE_PHOTOTRANSISTOR_PIN);
  
  IRBL_BACK_Off = analogRead(IRBL_BACK_PHOTOTRANSISTOR_PIN);
  IRBL_SIDE_Off = analogRead(IRBL_SIDE_PHOTOTRANSISTOR_PIN);
  IRBR_BACK_Off = analogRead(IRBR_BACK_PHOTOTRANSISTOR_PIN);
  IRBR_SIDE_Off = analogRead(IRBR_SIDE_PHOTOTRANSISTOR_PIN);
  
  PLOT("IRFL_FRONT_Off", IRFL_FRONT_Off);
  PLOT("IRFL_FRONT_On", IRFL_FRONT_On);
  PLOT("IRFL_SIDE_Off", IRFL_SIDE_Off);
  PLOT("IRFL_SIDE_On", IRFL_SIDE_On);
  
  PLOT("IRFR_FRONT_Off", IRFR_FRONT_Off);
  PLOT("IRFR_FRONT_On", IRFR_FRONT_On);
  PLOT("IRFR_SIDE_Off", IRFR_SIDE_Off);
  PLOT("IRFR_SIDE_On", IRFR_SIDE_On);
  
  PLOT("IRBL_BACK_Off", IRBL_BACK_Off);
  PLOT("IRBL_BACK_On", IRBL_BACK_On);
  PLOT("IRBL_SIDE_Off", IRBL_SIDE_Off);
  PLOT("IRBL_SIDE_On", IRBL_SIDE_On);
  
  PLOT("IRBR_BACK_Off", IRBR_BACK_Off);
  PLOT("IRBR_BACK_On", IRBR_BACK_On);
  PLOT("IRBR_SIDE_Off", IRBR_SIDE_Off);
  PLOT("IRBR_SIDE_On", IRBR_SIDE_On);
}
