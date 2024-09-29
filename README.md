# Ergonomic-Posture-and-Sitting-Time-Monitoring-Device
Introducing a low-cost, wearable and chair-mounted ergonomic solution that monitors posture and sitting time, helping you maintain better sitting habits and encouraging regular breaks for a healthier workday.
#Elevator pitch
Introducing a low-cost, wearable and chair-mounted ergonomic solution that monitors posture and sitting time, helping you maintain better sitting habits and encouraging regular breaks for a healthier workday.
#Tagline
Sit smarter, live healthier—monitor your posture and sitting habits effortlessly.
#About the project

#Inspiration
The inspiration for this project came from the realization that many people, including myself, spend long hours sitting at a desk, often with poor posture and little movement. This prolonged sitting can lead to serious health issues such as back pain, poor circulation, and fatigue. We wanted to create a simple and affordable device that could help individuals maintain better posture and encourage them to take regular breaks, ultimately leading to a healthier lifestyle.

##What it does
The device monitors both posture and sitting time:
- Posture Monitoring: A wearable tilt sensor detects the user's posture. If the user slouches or deviates from a healthy sitting position, the solution provides feedback to correct it. (For demonstration purposes, the threshold is temporarily reduced to a few seconds to quickly observe the behavior.) 
- Sitting Time Monitoring: An ultrasonic sensor attached to the chair monitors how long the user has been sitting. After 30 minutes of continuous sitting, the device alerts the user to take a break, stand, or move around. (For demonstration purposes, this threshold is temporarily reduced to 5 seconds to observe the behavior quickly.)

## How we built it
We built the project using a combination of sensors:
- A Tilt Ball Switch was used in the wearable component to detect posture by measuring the angle of the user's body.
- An Ultrasonic Sensor was mounted on the chair to track the time the user spends seated.
- We programmed an Arduino Uno R3 microcontroller using the Arduino IDE with C language. The sensors (tilt sensor, ultrasonic sensor, and RGB LED) were connected to a breadboard and wired to the Arduino using jumper cables. Power was supplied via USB from a laptop, resulting in a compact setup that was easy to attach to both the user and the chair.

## Challenges we ran into
One of the main challenges we faced was ensuring accurate posture detection. The tilt sensor had to be positioned correctly to differentiate between various postures while being comfortable for the user to wear. Another challenge was calibrating the ultrasonic sensor to accurately measure seated time without false positives when the user briefly stands up or shifts position.

## Accomplishments that we're proud of
We are proud of successfully building a working prototype that can track both posture and sitting time, providing real-time feedback to improve sitting habits. The simplicity and affordability of the design are key achievements, as we wanted this solution to be accessible to a wide range of long duration sitting users.

## What we learned
Throughout the project, we learned a lot about sensor integration and human-computer interaction. We gained experience in designing wearable technology that balances functionality and comfort, as well as the importance of proper calibration and testing to ensure accurate results.

## What's next for Untitled
Next, we plan to refine the design by making the device smaller and more comfortable for long-term wear. We also aim to integrate additional features, such as tracking more complex movements or posture adjustments, and developing a companion app to log data and provide more detailed feedback. Ultimately, we want to create a comprehensive ergonomic solution that helps users build lasting healthy habits while working at a desk.
