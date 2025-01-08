# Obstacle Avoidance Robot with Ultrasonic Sensor and Motor Control

---

## **Overview**
This project demonstrates an autonomous obstacle-avoidance robot that uses an ultrasonic sensor to measure distances and adjust motor actions. It controls four DC motors for movement and a servo motor for ultrasonic sensor positioning. The robot continuously checks for obstacles in its path and takes corrective actions to avoid collisions.

---

## **Features**
1. **Obstacle Detection**:
   - Uses an ultrasonic sensor to measure distances in front, left, and right of the robot.

2. **Motor Control**:
   - Controls four DC motors using the Adafruit Motor Shield library for forward, backward, and turning actions.

3. **Servo Motor Control**:
   - Rotates the ultrasonic sensor to scan for obstacles on the left and right.

4. **Decision-Making**:
   - Compares distances and adjusts movement to avoid obstacles, prioritizing paths with more clearance.

---

## **Components Required**
1. **Microcontroller**:
   - Arduino board (e.g., Uno, Mega, etc.).
2. **Motor Driver Shield**:
   - Adafruit Motor Shield (or compatible motor driver).
3. **Ultrasonic Sensor**:
   - HC-SR04 (or similar).
4. **Servo Motor**:
   - Standard servo motor (e.g., SG90 or MG995).
5. **DC Motors**:
   - 4 DC motors for robot wheels.
6. **Chassis**:
   - A 4-wheel robot chassis.
7. **Battery Pack**:
   - To power the motors and Arduino.
8. **Connecting Wires**:
   - Jumper wires for connections.

---

## **Circuit Diagram**
### **Connections**:

#### **Ultrasonic Sensor**:
- **Trig Pin** → Analog Pin `A0`
- **Echo Pin** → Analog Pin `A1`
- **VCC** → 5V
- **GND** → GND

#### **Servo Motor**:
- **Signal Pin** → PWM Pin (e.g., `D9` or any compatible PWM pin).
- **VCC** → 5V
- **GND** → GND

#### **DC Motors**:
- Connected to motor terminals on the Adafruit Motor Shield:
  - **M1** → Motor 1
  - **M2** → Motor 2
  - **M3** → Motor 3
  - **M4** → Motor 4

---

## **Setup**
1. **Install Libraries**:
   - Install the following libraries in the Arduino IDE:
     - `AFMotor` for the Adafruit Motor Shield.
     - `Servo` for servo motor control.

2. **Code Upload**:
   - Connect the Arduino board to your computer.
   - Upload the provided code to the board using the Arduino IDE.

3. **Power Connections**:
   - Ensure the motors are powered by an external power source to avoid overloading the Arduino.

4. **Chassis Setup**:
   - Mount the motors, ultrasonic sensor, and servo motor on the robot chassis.

---

## **How It Works**
1. **Ultrasonic Sensor**:
   - The sensor emits ultrasonic pulses and measures the time taken for the echo to return.
   - Distance is calculated using the formula:
     \[
     \text{Distance} = \frac{\text{Duration} \times \text{Speed of Sound}}{2}
     \]

2. **Main Loop**:
   - Continuously measures the distance in front (`distance_F`).
   - If the distance is greater than the threshold (`set`), the robot moves forward.
   - If an obstacle is detected, it stops and scans left (`distance_L`) and right (`distance_R`) to decide the next move.

3. **Decision-Making**:
   - Compares left and right distances:
     - Turns towards the side with more clearance.
     - If distances are equal, performs a backward maneuver followed by a left turn.

4. **Motor Control**:
   - Controls motor actions using the Adafruit Motor Shield library:
     - `FORWARD` for forward movement.
     - `BACKWARD` for reverse.
     - `RELEASE` to stop the motors.

---

## **Code Highlights**
1. **Ultrasonic Measurement**:
   - `pulseIn()` function is used to measure the duration of the ultrasonic pulse.
   - Converts duration to distance.

2. **Obstacle Avoidance**:
   - The `compare()` function determines the next movement based on the left and right distances.

3. **Motor Control**:
   - `AF_DCMotor` objects control each motor.
   - Speed is set using `setSpeed()` and direction with `run()`.

4. **Servo Motor Scanning**:
   - The servo motor rotates the ultrasonic sensor to scan the left and right directions.

---

## **Expected Behavior**
1. When no obstacles are detected within the set range:
   - The robot moves forward.

2. When an obstacle is detected:
   - The robot stops.
   - The servo motor rotates to scan the left and right sides.
   - Based on the comparison, the robot turns or moves backward and resumes forward motion.

3. The system continuously updates, ensuring real-time obstacle avoidance.

---

## **Troubleshooting**
1. **Robot Doesn't Move**:
   - Check motor connections to the motor shield.
   - Ensure the motor power supply is adequate.

2. **Incorrect Distance Measurements**:
   - Verify ultrasonic sensor alignment.
   - Check sensor wiring and ensure no obstructions near the sensor.

3. **Servo Motor Not Rotating**:
   - Check servo motor connections.
   - Verify the PWM pin assignment in the code.

4. **Erratic Behavior**:
   - Ensure proper power distribution.
   - Test individual components to isolate issues.

---

## **Improvements**
1. **Enhanced Decision-Making**:
   - Implement algorithms to handle more complex environments.

2. **Speed Control**:
   - Adjust motor speeds based on proximity to obstacles.

3. **Multi-Sensor Setup**:
   - Add additional sensors for better environmental awareness.

4. **Path Planning**:
   - Incorporate mapping and pathfinding for autonomous navigation.

---

## **Acknowledgments**
This project utilizes:
- **Adafruit Motor Shield** for motor control.
- **Servo Library** for servo motor handling.
- **HC-SR04 Ultrasonic Sensor** for reliable distance measurement.
