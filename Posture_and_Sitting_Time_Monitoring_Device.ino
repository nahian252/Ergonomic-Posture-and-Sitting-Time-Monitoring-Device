// Pin Definitions
const int tiltSwitchPin = 2; // Tilt Ball Switch
const int trigPin = 9;       // Ultrasonic Sensor Trigger
const int echoPin = 10;      // Ultrasonic Sensor Echo
const int rgbRedPin = 3;     // RGB LED Red
const int rgbGreenPin = 5;   // RGB LED Green
const int rgbBluePin = 6;    // RGB LED Blue

// Variables to track state for ultrasonic sensor
bool isSeated = false;
unsigned long sitStartTime = 0;
const int sitThreshold = 5000; // we set it 5 seconds (seated duration threshold) for testing quickly. It will change to 30minutes in real life
const int distanceThreshold = 500; // 500 cm (5 meters)

// Debounce settings for tilt sensor
int lastTiltState = HIGH;     // Stores the last stable state of the tilt sensor
unsigned long lastDebounceTime = 0; // The last time the tilt sensor was toggled
const unsigned long debounceDelay = 50; // Debounce time in milliseconds

// Timing variables for ultrasonic measurement
unsigned long ultrasonicDelay = 0;
const unsigned long ultrasonicInterval = 100; // Interval for ultrasonic measurement

void setup() {
  // Pin configurations
  pinMode(tiltSwitchPin, INPUT);
  digitalWrite(tiltSwitchPin, HIGH);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(rgbRedPin, OUTPUT);
  pinMode(rgbGreenPin, OUTPUT);
  pinMode(rgbBluePin, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  // Check posture (tilt sensor) with debouncing
  checkPosture();

  // Check seating (ultrasonic sensor) every ultrasonicInterval milliseconds
  if (millis() - ultrasonicDelay >= ultrasonicInterval) {
    ultrasonicDelay = millis(); // Reset the delay timer
    int distance = measureDistance();
    checkSeating(distance);
  }

}

// Function to measure distance using the ultrasonic sensor
int measureDistance() {
  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure echo time
  long duration = pulseIn(echoPin, HIGH);
  
  // Calculate distance (in cm)
  int distance = duration * 0.034 / 2;
  
  return distance;
}

// Function to check posture based on tilt sensor state with debouncing
void checkPosture() {
  int currentTiltState = digitalRead(tiltSwitchPin);

  // Debouncing the tilt sensor input
  if (currentTiltState == lastTiltState) {
    lastDebounceTime = millis();  // Reset debounce timer
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    lastTiltState = currentTiltState; // Update the last stable state

    // Only change if the tilt sensor state has stabilized
    if (lastTiltState == HIGH) {
      // Bad posture detected (tilted)
      digitalWrite(rgbRedPin, HIGH);
      digitalWrite(rgbGreenPin, LOW);
      digitalWrite(rgbBluePin, LOW);
      Serial.println("Tilt detected. Red LED ON.");
    } else {
      // Good posture (no tilt)
      digitalWrite(rgbRedPin, LOW);
      digitalWrite(rgbGreenPin, HIGH);
      digitalWrite(rgbBluePin, LOW);
      Serial.println("No tilt detected. Green LED ON.");
    }
  }
}

// Function to check if the person has been seated for more than 5 seconds
void checkSeating(int distance) {
  if (distance <= distanceThreshold) {
    if (!isSeated) {
      // Person just sat down, start timing
      sitStartTime = millis();
      isSeated = true;
    } else {
      // Person has been seated, check how long
      unsigned long seatedDuration = millis() - sitStartTime;
      if (seatedDuration >= sitThreshold) {
        // Person has been seated for more than 5 seconds
        alertLongSitting();
      }
    }
  } else {
    // Person is not sitting, reset state
    isSeated = false;
    // Turn off blue LED when leaving
    digitalWrite(rgbBluePin, LOW);
  }
}

// Function to alert for long sitting time (Blue light)
void alertLongSitting() {
  // Blue LED for long sitting alert
  digitalWrite(rgbRedPin, LOW);
  digitalWrite(rgbGreenPin, LOW);
  digitalWrite(rgbBluePin, HIGH);
  
  Serial.println("Person has been sitting for a long time. It's time to take a walk.");
}
