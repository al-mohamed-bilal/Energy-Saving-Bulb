 /*
 * This Arduino code uses HS-SR501 motion sensor and a relay
 * and switches an alarm or a device using relay when motion is detected
 * the device can be an alarm or light or any other device

 */

const int SENSOR_PIN = 2;// the Arduino pin connected to output (middle) wire of sensor
const int RELAY_PIN = 4;// the Arduino pin which is connected to control relay

void setup() {
  Serial.begin(9600);// setup Serial Monitor to display information
  Serial.println("HC-SR501 sensor with relay");
  pinMode(SENSOR_PIN, INPUT);// Define SENSOR_PIN as Input from sensor
  pinMode(RELAY_PIN, OUTPUT);// Define RELAY_PIN as OUTPUT for relay
}

void loop() {
  
  int motion =digitalRead(SENSOR_PIN);// read the sensor pin and stores it in "motion" variable
 
  // if motion is detected
  if(motion){
    Serial.println("Motion detected");
    digitalWrite(RELAY_PIN, LOW);// Turn the relay ON
  }else{
     Serial.println("===nothing moves");
     digitalWrite(RELAY_PIN,HIGH);// Turn the relay OFF
  }
  delay(500);
