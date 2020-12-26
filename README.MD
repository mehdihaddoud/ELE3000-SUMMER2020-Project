# ELE3000 SUMMER 2020 : Personal Project in Electrical Engineering 

## Project description

This project consists of a module that uses voice recognition to unlock a lock. When the user says specific words in front of the module while having a specific application opened, the module opens a lock. The module saves the time and the word used to open the lock in chronological order. The user can display this information on an LCD screen. When the user taps on the button of the module, the screen displays the information about the next opening chronologically and it displays the first unlocking when it reaches the end of the list of saved unlocking.


## How to use the module

The module uses the voice recognition of Google on Android devices. The module uses the HC-05 device to communicate with the Android device. You will need to pair your Android device with the HC-05.
You will also need to download an application that can use the embedded voice recognition on your Android device and sends the string of the recognized word through serial communication. The application AMR_Voice is suggested.
Once the pairing is done, open the application and say one of these words near the module to open the door :

1 - Allumer

2 - Ouvrir

3 - Partir

For further information, check the report included in the repositery.

## Videos

Presentation : https://youtu.be/OXaXUwaeh4I

Demonstration : https://youtu.be/OuUEIST_3XM

## References

The code for LCD1602 Display with I2C module

- https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library

The DS3231 library :

- https://github.com/rodan/ds3231

Setting Up Bluetooth HC-05 With Arduino

- https://www.instructables.com/Setting-Up-Bluetooth-HC-05-With-Arduino/
