// C++ code 

// Define pin connections
const int tempSensorPin = A0;   // Analog pin A0 for the temperature sensor (TMP36 or similar)
const int ledPin = 13;          // Built-in LED pin on most Arduino boards
const float thresholdTemp = 30.0; // Temperature threshold (in Celsius)

void setup() {
  // Initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);
  // Begin serial communication for monitoring
  Serial.begin(9600);
}

void loop() {
  // Read the analog value from the temperature sensor
  int sensorValue = analogRead(tempSensorPin);

  // Convert the analog value to a temperature in Celsius
  float voltage = sensorValue * (5.0 / 1024.0);
  float temperature = (voltage - 0.5) * 100.0;  // For TMP36, the formula is (Vout - 500mV) * 100

  // Print temperature to the serial monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");

  // Check if the temperature exceeds the threshold
  if (temperature > thresholdTemp) {
    Serial.println("Temperature is high! Turning LED on.");
    
    // Turn on the LED
    digitalWrite(ledPin, HIGH);
  } else {
    Serial.println("Temperature is normal. LED off.");
    
    // Turn off the LED
    digitalWrite(ledPin, LOW);
  }

  // Add a small delay to avoid flooding the serial monitor
  delay(1000);
}

