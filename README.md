
![This is an image](https://github.com/Lme20/Pomodoro-System-IoT-project-/blob/f86371c9b4bdf22f5f9890022145c29f06fab050/assets/pomodoroLogo.png)

## Pomodoro tracking system - Tutorial

Louis Mercier - lm223ei

If you've ever struggled with productivity, missed a deadline, or ended up distracted too many times, then this project might be for you. There are countless techniques claiming to boost productivity and while many may work to varying degrees, there's no denying that Pomodoro takes the first spot. 

Pomodoro, meaning "Tomato" in Italian, is a very simple and consize technique based purely on how you distribute your time. The technique consists of time intervals, where you may only work for 25 minutes followed by a 5 minutes pause, totalling 30 minutes, this routine is then repeated and a new set is followed. This project is purely aimed at creating a device that allows you to follow this technique, with as little distractions as possible, without having to use a a Pomodoro timer online. Now, you may ask, why use a device when I can simply use a timer on my phone? Well, we know that phones are a distraction, besides, this device allows you to track all your sets, getting a better overview of how productive you've been. 

This project may take between 15 to 30 hours, depending on the complexity you're aiming and any addons you might want for this project (assuming you're not copypasting the entirety of the code). Additionaly, the coding phase may take up only 40% of the project, with the rest being left to the setup of your device and any issues that may come. Consider that this project may not be straightforward, as it depends entirely on your ESP board and the components you are using.

### Objective

I've chosen to build this specific device as I consider it beguinner friendly, fairly simple to develop and quite useful for anyone. I decided against any device that used sensors and instead aimed for a project in which I knew I would use even after this course was completed and would remain useful to me even long after. I could have aimed for a project that used basic sensors and displayed the data, however, I found the idea of developing something fairly different and still remain simple quite appealing. As such, I consider this device to still fulfill the basic requirements of this course while providing an alternative for anyone interested in a project that does not use sensors. 

The aim of this device is to track productivity using the pomodoro technique, in a way, this device functions as a timer free of distractions, while providing a set of data for its user. The data shall be displayed in a Google sheets document where the user will be able to obtain all the time intervals that have been completed, along the current date and time of such intervals. 

While fairly simple, I believe this device can provide insight on the productivity of its user, giving way to how long the user has been working as well as all the pauses activated during such intervals. If used correctly, this device culd suit anyone who's aiming at improving productivity and reduce any forms of distraction. 

### Material

For this project I've chosen a Freenove ESP32 board, with a GPIO extension board added to it. I've chosen this specific device as it provides all the perks of a generic ESP32 board with the addition of free resources provided by Freenove, additionally, as it comes with an extension board built-in, this specific board makes any kind of setup far easier and less troublesome, with no soldering required and no confusing setup compared to other boards (see pycom expansion boards), I considering this board to be highly beguinner friendly, with a range of tutorials and projects already provided by Freenove for free. As a side note, this board is compatible to the firmware provided by the course, as well as the firmware used in ESP32 boards by Espressif. 

Overall, this is the complete list of materials that you will need: 

- [ ] 1 - Freenove ESP32 board 
- [ ] 15 - M-M jump wires
- [ ] 1 - RGB led light
- [ ] 1 - Push button
- [ ] 1 - PNP transistor 8550
- [ ] 3 - 220 Ω resistors*
- [ ] 2 - 10K Ω resistors*
- [ ] 1 - 1K Ω resistor*
- [ ] 1 - Active buzzer
- [ ] 1 - Breadboard

* *Make sure to calculate the resistor values you need before using them as these may differ depending on your circuit.*

All material was bought in Amazon and come in the Freenove Ultimate starter Kit, with additional components if you are willing to scale up your project. The total cost is *499.00 kr* without shipping included. 
Link here: [Freenove Ultimate starter kit](https://www.amazon.se/Freenove-Ultimate-ESP32-WROVER-Included-Compatible/dp/B08FM2NCST/ref=asc_df_B08FM2NCST/?tag=shpngadsglede-21&linkCode=df0&hvadid=476555136704&hvpos=&hvnetw=g&hvrand=16805966142249198589&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9062383&hvtargid=pla-1072775098961&psc=1)

**Image of all components:**
![This is an image](https://github.com/Lme20/Pomodoro-System-IoT-project-/blob/c303aae921dd7d84778a07a3f3913afaae76e745/assets/Part%20list.png)

### Computer setup

For this project I've stuck with Atom IDE, as it provides all the necessary plugins for this project. You should first start by installing Atom IDE if you haven't already. 

#### Flashing the firmware and required setup

First of all, you will need to flash the required firmware to your ESP32 board, for this you will need to access this **[website](https://nabucasa.github.io/esp-web-flasher/)** and download the specified **[firmware](https://github.com/H-Ryan/Heltec/blob/main/PyCom%20MicroPython/Heltec%20PyCom%20MicroPython.zip?raw=trueS)** in your computer, do this by first connecting your ESP32 board to your computer (use the USB cable provided in the kit), make sure your computer detects the board by following **[these steps](https://hackmd.io/@lnu-iot/By5ZUqvOq#Mac-OS)**. 

Once you've flashed the firmware to your ESP32 board, continue by installing Atom IDE. Once done, you should now install PlatformIO to your IDE, you can install it following this **[link](https://platformio.org/install/ide?install=atom)**. Start by opening the Atom Package Manager, from there you should search for the official **platformio-ide** package, proceed by installing it. 

Now you can start by creating a project from PlatformIO once all the steps above are completed. This will give you the required structure for this project. PlatformIO gives you the facility of detecting all possible devices connected to your computer directly from the IDE, however, depending on the board and the OS you are using, you might need to configure the port manually. For this you need to go to your *platform.ini* file, from there, make sure the .ini file is set with the port of your device, in my case, as I am using MacOS, my port will likely look different from yours. 

the *platform.ini* file should look moreless like this: 

```
[env:esp-wrover-kit]
platform = espressif32
board = esp-wrover-kit
framework = arduino
build_flags = -DBOARD_HAS_PSRAM -mfix-esp32-psram-cache-issue
upload_port = /dev/cu.wchusbserial1410
lib_deps = 
	alexgyver/EncButton@^1.12
	gyverlibs/TimerMs@^1.1.1
	makuna/NeoPixelBus@^2.7.0
	knolleary/PubSubClient@^2.8
board_build.partitions = huge_app.csv
```
**NOTE:** *make sure the board and upload port are correct, depending on your board and the USB port you are using.*

 The *lib_deps* section should be empty, as you have not installed any libraries yet. If you have not installed any platform yet, do so by going to the *platforms* section of PlatformIO and from there download Espressif 32. If you are using the Freenove ESP32 board recommended for this project, you will need to search for the *esp-wrover-kit* board and from there you can download it. 

**Once installed, you should have it as shown below in the platforms section:**
![This is an image](https://github.com/Lme20/Pomodoro-System-IoT-project-/blob/e1006429af41bd588cc85cbe7b64677765c2b84f/assets/board-PlatformIO.png)
 
You can start by uploading dummy code just to make sure the PIO upload works as it should, additionally, this process should be done with your device connected at all times, so the port can be visible in the IDE and during the upload process as well. 

### Putting everything together

How is all the electronics connected? Describe all the wiring, good if you can show a circuit diagram. Be specific on how to connect everything, and what to think of in terms of resistors, current and voltage. Is this only for a development setup or could it be used in production?

- [ ] Circuit diagram (can be hand drawn)
- [ ] *Electrical calculations

### Platform

Describe your choice of platform. If you have tried different platforms it can be good to provide a comparison.

Is your platform based on a local installation or a cloud? Do you plan to use a paid subscription or a free? Describe the different alternatives on going forward if you want to scale your idea.

- [ ] Describe platform in terms of functionality
- [ ] *Explain and elaborate what made you choose this platform 

### The code

Import core functions of your code here, and don&#39;t forget to explain what you have done! Do not put too much code here, focus on the core functionalities. Have you done a specific function that does a calculation, or are you using clever function for sending data on two networks? Or, are you checking if the value is reasonable etc. Explain what you have done, including the setup of the network, wireless, libraries and all that is needed to understand.


```python=
import this as that

def my_cool_function():
    print(&#39;not much here&#39;)

s.send(package)

# Explain your code!
```



### Transmitting the data / connectivity

https://blog.particle.io/particle-pomodoro-an-internet-connected-pomodoro-timer/

How is the data transmitted to the internet or local server? Describe the package format. All the different steps that are needed in getting the data to your end-point. Explain both the code and choice of wireless protocols.


- [ ] How often is the data sent? 
- [ ] Which wireless protocols did you use (WiFi, LoRa, etc ...)?
- [ ] Which transport protocols were used (MQTT, webhook, etc ...)
- [ ] *Elaborate on the design choices regarding data transmission and wireless protocols. That is how your choices affect the device range and battery consumption.


### Presenting the data

Describe the presentation part. How is the dashboard built? How long is the data preserved in the database?

- [ ] Provide visual examples on how the dashboard looks. Pictures needed.
- [ ] How often is data saved in the database.
- [ ] *Explain your choice of database.
- [ ] *Automation/triggers of the data.


### Finalizing the design

Show the final results of your project. Give your final thoughts on how you think the project went. What could have been done in an other way, or even better? Pictures are nice!

- [ ] Show final results of the project
- [ ] Pictures
- [ ] *Video presentation
