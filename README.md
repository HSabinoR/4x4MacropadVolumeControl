# 4x4 Macropad with Volume Control
![20240526_190812](https://github.com/HSabinoR/4x4MacropadVolumeControl/assets/153095110/03e00508-714e-4bec-bbf8-cf4997fa3ee3)
A macropad with a 4x4 key switch matrix and 5 slide potentiometer used for volume control. I copied the general design of the MisteRdeck stream deck and turned it in to a 4x4 key switch matrix and added space for an extra slide potentiometer. Aswell as changing the design, i used QMK firmware instead of making my own arduino sketch.


## Software Requirements: 
- QMK [Firmware](https://msys.qmk.fm/) and [Toolbox](https://github.com/qmk/qmk_toolbox/releases/tag/beta)
- [Midi-Mixer](https://www.midi-mixer.com/)
- Some type of code editor(any will do)

## Hardware/Machine Requirements
No need to have these things personanlly. As long as you have access to them, it's fine.
- 3D printer
- Soldering iron
- Multimeter

- M3 heat set threaded inserts
- M3x10mm Bolt head screws(I used countersunk head screws as thats all i had on hand)

## Electronic Components:
- 1x Arduino Pro Micro (I went with the one that has a USB C port)
- 16x [key switches](https://www.aliexpress.com/item/1005004388563696.html?spm=a2g0o.order_list.order_list_main.35.30dc1802Wi4ATW)
- 16x [1N4148 Diodes](https://www.aliexpress.com/item/1005006094377496.html?spm=a2g0o.order_list.order_list_main.23.30dc1802Wi4ATW)
- 5x Slide (Linear) Potentiomters (make sure that they are linear and not a logarithmic potentiometer, I got [these](https://www.aliexpress.com/item/1005005032811114.html?spm=a2g0o.order_list.order_list_main.17.30dc1802Wi4ATW))
- A bunch of wires
- USB C/Micro Cable(depending on which Arduino Pro Micro)
- A button to connect between the reset pin and gnd(you can also just use some tweezers)

## Wiring Diagrams
![image](https://github.com/HSabinoR/4x4MacropadVolumeControl/assets/153095110/809dfe69-12cb-47d0-8268-27a372502751)

Slide Potentiometers (You will have to be careful with which way round you have the VCC and Gnd on the potentiometer. I ended up having gnd towards the top pins)

![image](https://github.com/HSabinoR/4x4MacropadVolumeControl/assets/153095110/de2e4b4e-a9d4-4112-870d-b75683920ab5)

Key switch matrix (Make sure that the ```"diode_direction"``` in the [info.json](QMK%20Firmware/info.json) file is set to ```"ROW2COL"``` if you follow my wiring diagram)

![MacroPad](https://github.com/HSabinoR/4x4MacropadVolumeControl/assets/153095110/c1c767a0-2804-49f3-8ffa-a9eae703166e)

Arduino Pro Micro Pinout Diagram

## Things to keep in mind
- You will most likely have to change the pins in this section around:
```json
"matrix_pins": {
    "cols": ["D0", "D4", "C6", "D7"],
    "rows": ["B2", "B5", "B4", "E6"]
},
```
as the pins labelled in the diagrams weren't the exact pins I used.
- You will probably have to cut away at the [base section](STL%20Files/Base.stl) as the Arduino pro micro didn't fit in the hold i designed for it. In fact, you don't need it at all as the hotglue that i used around the USB C port was enough to keep it in place.
- I suggest you use heatshrink tubing, if you have any, to be extra sure that the exposed wires don't touch each other. I didn't use any cause i didn't have any on hand.
- You don't have to spraypaint the case like I did, i just wanted to.
- You can either buy some keycaps or 3D print some. There are plenty of stl files online.

## QMK Guide
If you've downloaded QMK [Firmware](https://msys.qmk.fm/) correctly, this guide should work.
1.  Open **QMK MSYS**
2.  Run ```qmk setup``` assumming this is the first time you've run **QMK MSYS** (In most situations you will want to answer ```y``` to all of the prompts)
3.  Once ```qmk setup``` is done, run ```cd qmk_firmware/``` to move to the main folder of anything to do with QMK
4.  Run ```qmk new-keyboard -kb keyboardname -u GitHubName -n YourName -l ortho_4x4 -t promicro```. You can replace ```keyboardname```, ```GithubName``` and ```YourName``` with what you want.
5.  Now locate the folder that the previous command created and replace each file in the folder with the ones in the [QMK Firmware](QMK%20Firmware) folder. You can (Make sure to change the pins to the correct ones)
6.  Now you can run ```qmk compile -kb keyboardname -km HexFileName``` to create a hex file.

7.  Open QMK [toolbox](https://github.com/qmk/qmk_toolbox/releases/tag/beta)
8.  Select the hex file, connect the pro micro to the pc, press the reset button two times and press flash.
   ![image](https://github.com/HSabinoR/4x4MacropadVolumeControl/assets/153095110/2b5e64d2-9273-42da-b3da-ee4fd45d40f6)

 If it looks something like this, you've done it correctly.

## Midi-Mixer Guide
1. Create a new profile, go to the controls tab and add 5 faders.

![image](https://github.com/HSabinoR/4x4MacropadVolumeControl/assets/153095110/4b812d09-32a9-4a28-b339-890fe58a09bd)

2. For each fader, press the learn control button while moving the respective slide potentiometer up and down.

![image](https://github.com/HSabinoR/4x4MacropadVolumeControl/assets/153095110/5896ddfe-4b6f-4a4e-a2df-d42532a67b11)

3. In the groups tab, create 5 groups and assign 1 fader to each

![image](https://github.com/HSabinoR/4x4MacropadVolumeControl/assets/153095110/8b93c9b3-dbaf-4087-9bf4-98751b24e540)

4. Go to the assignments tab and assign each group to an application/device

![image](https://github.com/HSabinoR/4x4MacropadVolumeControl/assets/153095110/d4f0b983-a098-4b1a-b3af-708bef627e8b)
