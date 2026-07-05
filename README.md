# Motor-Butterfly

# Servoized Butterfly

By [@skhsmrn](https://github.com/skhsmrn), as an idea for my grad cap, but now an idea for room decor haha...

## Idea

I wanted to make a large, simple butterfly that I could hang on my wall. Normally, it sits idle and flaps its wings slowly. But when it hears something loud, like a crashout after losing project progress, it reacts by flapping its wings faster.

The butterfly uses two servos, with each servo controlling one wing. A microphone module detects loud noises and tells the ESP32 when to increase the wing-flapping speed.

## Features

* Wall-mountable butterfly design
* Idle wing-flapping animations
* Faster flapping when loud noise is detected
* Two-servo wing control
* ESP32-based electronics
* 3D-printed base and wing attachments
* Construction paper wings

## Electrical

The ESP32 connects two servos and MAX9814. The Max9814 postive and negative connect to the ESP32. The servos postive and negative connect to the 9V Battery Pack. The microphone listens for nearby sound. When the detected sound level becomes loud, the ESP32 switches into a faster flapping mode. After the sound level drops again, the butterfly returns to its slower idle motion.

## CAD

* A base sized ~0.5 in x 3.5 in
* Chamfers and fillets for easier printing
* Servo outlet and clearances
* Wing attachment length around ~2.75 in
* Rounded edges to avoid sharp corners
* A coupler to connect the servo horn to the wing attachment

The parts are intended to be printed on a Bambu Lab X1.

<img width="838" height="733" alt="Cad" src="https://github.com/user-attachments/assets/aaefb64f-bbb3-4dfc-97a2-dbf7dee36a8d" />

# Code 

Basic behavior:

1. Start with wings in the upward position/initalizing/origin.
2. Slowly flap wings while idle.
3. Continuously read microphone levels.
4. If a loud sound is detected, increase flap speed.
5. Return to idle speed when the sound level goes back down.

Right now, the code only has time-based animations, need to do more testing with the servos and microphone before doing any more changes.

<img width="536" height="567" alt="code" src="https://github.com/user-attachments/assets/b0403f26-478e-4a5d-8825-906c46461b9e" />

# BOM

| Part / Model                                                            |  Unit Price | Total Price | Link                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| ----------------------------------------------------------------------- | ----------: | ----------: | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| MAX9814 Microphone Amplifier Module                                     |  ~$4.39 CAD |   $4.39 CAD | [Amazon](https://www.amazon.ca/Adjustable-Microphone-Amplifier-Auditory-Applications/dp/B0GX6KX5JL/ref=asc_df_B0GX6KX5JL?mcid=06d96855775331d99b9f4ff22c769be5&tag=googleshopc0c-20&linkCode=df0&hvadid=706724917158&hvpos=&hvnetw=g&hvrand=4477985885645849661&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9000861&hvtargid=pla-2486324422228&psc=1&hvocijid=4477985885645849661-B0GX6KX5JL-&hvexpln=0&gad_source=1)                                                                                                                                                                          |
| ESP32                                                                   | ~$12.99 CAD |  $12.99 CAD | [Amazon](https://www.amazon.ca/ESP-WROOM-32-NodeMCU-Bluetooth-Development-Microcontroller/dp/B0DX8M8FXD/ref=sr_1_5?crid=37RTAHL8G3HDC&dib=eyJ2IjoiMSJ9.QVcRPpcTCAkYPodSx7FppajuRJgrvEqFyqImJMAjfvtzOIYEkHp6xYbbeLoNPwp43xKTYyfteuBnhU4ZMxWpCMaV7VBzkDMW_vsJKlFHRBbuQHMq-FlAJYgT8wsygn1l_nmt9yTgKM4vnJmge8SweEISxHIYP8pxQqd3dCKUdjs9BZIBfW6iAeqOXbKfDek4CQXOLkrMdDonLz44x8nJIf5nP9W_aieVO6jKbgON81_ALW1MIDhOwFpbZMUoQpE0rakyGWkv2gsRCrLXVCIo9zaD1SvY0iztRZR2MAI3A4A.TM40eXrjGeBmUQOFcacN6U2D-gpMsAGi85zflMGro20&dib_tag=se&keywords=esp32%2Bwroom&qid=1783226619&sprefix=esp32%2Bwroom%2Caps%2C117&sr=8-5&th=1) |
| Studica 75002 Multi-Mode Smart Servo *(Could find cheaper alternative)* | ~$28.99 USD |  $57.98 USD | [Studica](https://www.studica.ca/en/multi-mode-smart-servo)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    |

