# Motor-Butterfly

# Servoized Butterfly

By [@skhsmrn](https://github.com/skhsmrn), as an idea for my grad cap, but now an idea for room decor haha...

## Idea

I wanted to make a large, simple butterfly that I could hang on my wall. Normally, it sits idle and flaps its wings slowly. But when it hears something loud, like a crashout after losing project progress, it reacts by flapping its wings faster.

The butterfly uses two servos, with each servo controlling one wing. A microphone module detects loud noises and tells the ESP32 when to increase the wing-flapping speed.

## Features

* Wall-mounted butterfly design
* Idle wing-flapping animation
* Faster flapping when loud noise is detected
* Two-servo wing control
* ESP32-based electronics
* 3D-printed base and wing attachments
* Paper or construction paper wings
* Simple mechanical design using servo couplers

## Hardware Used

* ESP32
* 2 positional servo motors
* MAX9814 microphone
* 3D-printed base
* 3D-printed wing attachments
* Construction paper or cardstock for wings
* Male and Female wires
* Hot glue
* 9V Battery Pack
* Soldering Iron

## Electrical

The ESP32 connects two servos and MAX9814. The Max9814 postive and negative connect to the ESP32. The servos postive and negative connect to the 9V Battery Pack. The microphone listens for nearby sound. When the detected sound level becomes loud, the ESP32 switches into a faster flapping mode. After the sound level drops again, the butterfly returns to its slower idle motion.

## CAD

* A base sized ~0.5 in x 3.5 in
* Chamfers and fillets for easier printing
* Servo outlet and plug clearances
* Wing attachment length around ~2.75 in
* Rounded edges to avoid sharp corners
* A coupler to connect the servo horn to the wing attachment

The parts are intended to print on a Bambu Lab X1.

<img width="838" height="733" alt="Cad" src="https://github.com/user-attachments/assets/aaefb64f-bbb3-4dfc-97a2-dbf7dee36a8d" />

# Code 

Basic behavior:

1. Start with wings in the upward position/initalizing/origin.
2. Slowly flap wings while idle.
3. Continuously read microphone levels.
4. If a loud sound is detected, increase flap speed.
5. Return to idle speed when the sound level goes back down.

<img width="536" height="567" alt="code" src="https://github.com/user-attachments/assets/b0403f26-478e-4a5d-8825-906c46461b9e" />

# BOM

Part / Model                                                          | Unit Price | Total Price |
------------------------------------                                  | ---------: | ----------: |
MAX9814 Microphone Amplifier Module                                   | $12.99 CAD |  $12.99 CAD |
ESP32                                                                 | $12.99 CAD |  $12.99 CAD |
Studica 75002 Multi-Mode Smart Servo (Could find cheaper alternative) | $28.99 USD |  $57.98 USD |
