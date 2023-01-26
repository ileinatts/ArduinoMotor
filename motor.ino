// Define the analog pin, the TMP36's Vout pin is connected to
#define sensorPin A0
#define LED_PIN 8
const int buzzer = 7; //buzzer to arduino pin 9
int motorPin = 3;


void setup() {
  // Begin serial communication at 9600 baud rate
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output
  pinMode(LED_PIN, OUTPUT);
  
  digitalWrite(LED_PIN, LOW);
  Serial.begin(9600);
}

void loop() {
  // Get the voltage reading from the TMP36
  int reading = analogRead(sensorPin);

  // Convert that reading into voltage
  // Replace 5.0 with 3.3, if you are using a 3.3V Arduino
  float voltage = reading * (5.0 / 1024.0);

  // Convert the voltage into the temperature in Celsius
  float temperatureC = (voltage - 0.5) * 100;
  
  if(temperatureC > 30){
    digitalWrite(motorPin, HIGH);
  }
  if (temperatureC > 50){
    digitalWrite(LED_PIN, HIGH);
    tone(buzzer, 1000); // Send 1KHz sound signal...
    delay(1000);        // ...for 1 sec
    digitalWrite(LED_PIN, LOW);
    noTone(buzzer);     // Stop sound...
    delay(1000);        // ...for 1sec
    
    }
 
  
  
  // Print the temperature in Celsius
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.print("\xC2\xB0"); // shows degree symbol
  Serial.print("C  |  ");
  
  // Print the temperature in Fahrenheit
  //float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
  //Serial.print(temperatureF);
  //Serial.print("\xC2\xB0"); // shows degree symbol
  //Serial.println("F");

  delay(1000); // wait a second between readings
}
