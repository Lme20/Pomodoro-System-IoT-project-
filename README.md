
![This is an image](https://github.com/Lme20/Pomodoro-System-IoT-project-/blob/f86371c9b4bdf22f5f9890022145c29f06fab050/assets/pomodoroLogo.png)

## Pomodoro tracking system - Tutorial

-------- TUTORIAL IN PROGRESS - NOT FINISHED YET --------

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

###### List of Materials

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

For this project I've stuck with Atom IDE, as it provides all the necessary plugins for this project. You should first start by installing Atom IDE if you haven't already. Concerning the USB connection, you will need to install the following driver for your computer to be able to detect it:

**[Install VCP Drivers](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers?tab=downloads)**

This is the only driver you will need for this project, assuming you are using a Mac. 

###### Flashing the firmware and required setup

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

![This is an image](https://github.com/Lme20/Pomodoro-System-IoT-project-/blob/192c416b52e20fab869704951836ff95480a2160/assets/sketch_pomodoro_bb.png)

All GPIO connections are made in pins 13, 15, 2, 4 and 21 whereas 15, 2, 4 are exclusively related to the RBG led light. The extension board allows for a well connected breadboard which makes the setup process easier to manage. Additionally, the push button is connected to GPIO 21 using a series of 2 10K Ω resistors. Finally, the buzzer is connected to GPIO 13 and makes use of 1 PNP 8550 transistor as well as 1K Ω resistor for the current circuit. Concerning the current RGB light, it is composed of 4 pins: the long pin (1) is the common port, that is, 3 LED 's positive or negative port. All pins except the common port are connected to GPIO 15, 2 and 4 respectively. Overall, I consider the current circuit to be fairly simple to develop, keep in mind that it is only possible with an extension board in its current state. 

Concerning the resistors, these are not set values and should be calculated on their own following your own setup, this step can be done by calculating the following formula: 

*Resistor = (Battery Voltage – LED voltage) / desired LED current.*

This process should also be done with the buzzer, to obtain the desired amount for the resistors and avoid any issues concerning the aforementioned components. I personally believe this phase of the project could be improved if I dedicate more time to the circuit itself, as I've encountered several issues even during the wiring process, including wrong color values for the RGB led light, and a buzzer that would simply not respond even after pressing the button. 

I do not consider this project usable for production, as it still has room for wiring improvements, a possible redo of the pins and an in-depth overview of electrical calculations, including schematics. This circuit should be considered a prototype and therefore only for a development setup. 

### Platform

My choice of platform is Node-Red, a flow-based development tool for visual programming used extensively for wiring together hardware devices, among other IoT aspects. Node-RED provides a web browser-based flow editor, which facilitates the visualisation process of wiring toghether data flows from a node to another far more easier, additionally, this platfrm is free to use and provides all the functionalities required for this project. This felt like an easy choice as Node-Red is naturally used for MQTT connectivity, additionally, this platform is by far the best option for projects of this size, even though with its limited scalability I do not consider this device to require increased scalability even for production. 

Initially, I figured that using an online service would provide all the required functionalities for this project, this took me to IFTTT, but early development without a visualizer and the lack of a messaging protocol made its use difficult to implement, furthermore, I noticed how using online platforms can be quite limiting, especially if those come with limited scalability and a paying option, considering that such platforms would make implementation difficult, as this project does not use any sensors, hence, the lack of obtaining any straightforward data. 

###### Installation of Node-Red

For Mac users, the installation can be done through the terminal, we'Il need this process to visualise connectivity with MQTT later on. **Make sure to have Node.js installed as a prerequisite of this phase**

Insert the following command into your terminal:
```
sudo npm install -g --unsafe-perm node-red
```
Once done, your terminal should show the following input: 
```
+ node-red@1.1.0
added 332 packages from 341 contributors in 18.494s
found 0 vulnerabilities
```
Now you can start Node-red by simply inserting *Node-red* to the terminal. This step should automatically give you access to data-flow visualiser at http://127.0.0.1:1880/  
*NOTE: this step will only allow you to run in local mode.*

If all steps above were done correctly, your terminal should look as follows:

<img src="https://github.com/Lme20/Pomodoro-System-IoT-project-/blob/3e51fac69722afed5ea5a8f8ae69b27344a430b3/assets/Node-red.png" width="550"> 

### The code

The code for this device is fairly straightforward, let's begin by presenting the libraries you will need: 
```
#include <EncButton.h> // https://github.com/GyverLibs/EncButton
#include <TimerMs.h> // https://github.com/GyverLibs/TimerMs
#include <HTTPClient.h> //included for the google sheets connection
#include <WiFiClient.h> //WiFi setup and client
#include <PubSubClient.h> //run MQTT

```
###### EncButton library 

This library is only used to controll the push button and manage any inputs from it, its use is pretty much restricted towards any methods used in the code that includes extracting functions from the EncButton library. 

###### TimerMs library 

This library allows for extracting necessary functions for the cases included in our code, these are exclusively used for our case switch statements and are declared in our Variable Declaration section of the code. This library serves as a  multifunctional software timer based on the millis() system timer seen in Arduino, and as you might have noticed, this project is heaviliy based on Arduino platforms. 

###### WiFiClient and HTTPClient library 

The WiFi and HTTPClient libraries are basically what allows us to connect our device to internent, without these there is no way we would be able to create an MQTT connection or be able to transmit data towards Google Sheets. Additionally, these might be required for furthered scalability in our project, mainly for transmitting data towards cloud or online services. These are important to connect to our specified internet IP address and port as defined in the client designated for this device. 

###### PubSubClient library 

This library is only for MQTT messaging and will be required when installing MQTT for this project. 

###### Core functionalities

[Find the complete code here for more insight](https://github.com/Lme20/Pomodoro-System-IoT-project-/blob/7a2e4175b3490c0cacd258cda2536c7f5dd66eed/pomodoro.ino)

Apart from the declaration of libraries which I specified above, the code comes divided into various sections. First we start with the setup, this section is quite obvious and includes setting up the pins of the device, network credentials, setting the MQTT connection, declaring methods and setting values for the timer and RGB led lights. I will omit most of it as I will present this part of the code later on in [Transmitting the data / connectivity](#transmitting-the-data--connectivity) section.

Here are the declared values for time intervals and blinking speed (RGB lights):
```
const int LED_SPEED_MS = 700; // led blinking speed

const uint32_t WORK_T_MS = 1500000; // work time 25 min
const uint32_t REST_T_MS = 300000; // rest time 5 min
const uint32_t LONG_REST_T_MS = 1200000; // long rest 20 min
```
And here I've included all the declared states for the case switches: 
```
int ledState = 0; // 0 - off, 1 - on, 2 - blinking

int state = 0; // 0 - pause, 1 - work, 2 - work end, 3 - rest, 4 - rest end
```

The project makes use of a case switch systems which allows us to switch into various states during a loop, this will facilitate the process of giving our components their functions based on the state they are in, this includes the various RGB light "states" such as blink and colors as well as if the buzzer is active or not, this also allows us to dedicate specific functions based on each case found in the code. In total, there are 5 cases: Pause, Work, Work end, Rest and Rest end. For the sake of simplicity I will only include 2 cases in the code below. 

```c++=
  // CASE 0 - PAUSE
  switch (state) {
    case 0: // pause
      if (initState) {
        setCurLed(LED_B_PIN); //B
        setLedState(2); //BLINK
        initState = false;

        client.publish(TOPIC, "PAUSE");
        Serial.println((String)TOPIC + " => PAUSE");
      }
      if (btn.release()) {
        beepClick();
        setState(1); // WORK
      }
      break;
    //-----------------------------------
    // CASE 1 - WORK
    case 1: // work
      if (initState) {
        initState = false;

        setCurLed(LED_R_PIN);
        setLedState(1); // ON

        client.publish(TOPIC, "WORK");
        Serial.println((String)TOPIC + " => WORK");

        mainTmr.setTime(WORK_T_MS);
        mainTmr.start();
      }
      if (mainTmr.tick()) setState(2);
      if (btn.release()) {
        beepClick();
        setState(0); //PAUSE
      }
      break;
  }
```

The case switches in the code above includes various sections which set the various states declared in the Variables sections for both the buzzer and RGB lights, these also include the data which will serve to publish input through the MQTT as well as the Topic. Our code works in a way where once you've pressed the push button, the device switches to a new case, when this occurs 3 things happen: An input from the device is published in Google sheet (time and states), the RGB lights switch to a specific color and the buzzer may stop. During all of these cases, a timer will be counting depending on which state you are in. 

Here is an overview of how each state works:

- 🔵 ⚪️ 🔵 ⚪️ [blinking blue] - PAUSE: Once pressing the button you will go to WORK mode. 
- 🔴 🔴 🔴 🔴 [red] - WORK: you have 25 minutes to work on your task. If you press the button you switch to PAUSE mode and the timer will reset.
- 🔴 ⚪️ 🔴 ⚪️ [blinking red] - NEED REST: current working period is finished, you need to take a rest. But you can still continue working until you press the button.
- 🟢 🟢 🟢 🟢 [green] - REST: you have 5 minutes for to rest. After 4 pomodoro periods you'll have a long rest of 20 min. If you click a button before rest is finished, you will go to WORK mode.
- 🟢 ⚪️ 🟢 ⚪️ [blinking green] - REST END: you have to go back to work, but it won't start until you press the button.

As for the buzzer, it functions with 3 states depending on which mode it is in: 
```
//BUZZER
void beepClick() {
  beep(1, 50, 0);
}

void beepEnd() {
  beep(2, 100, 0);
}

void beepLongRest() {
  beep(3, 300, 0);
}
```
Concerning the RGB lights, an If-statement is used to control each of its states:
```
  // led control
  if (ledTmr.tick()) {
    switch (ledState) {
      case 0:
        if (ledOn)ledSwitch(false);
        break;
      case 1:
        if (!ledOn) ledSwitch(true);;
        break;
      case 2:
        ledSwitch(!ledOn);
        break;
    }
  }
```
Lastly, a set of Void methods are used to control the RGB modes and states already mentioned, these are used in the case switches once for each of the 5 states. 

### Transmitting the data / connectivity

For this specific aspect of the project I've chosen to use WiFi as the wirless protocol, this deicison was mostly based on the fact that the device is meant to use the local network and shouldn't require long-range communication. Additionally, other technical aspects such as power consumption or low-latency were not of any concern, as the device depends on the computer it is connected to and does not transmit a high volume of data at all. WiFi connections is also backed by a variety of sources and tutorials which makes it fit for a beginner's project. 

In the code, the needed credentials for the local network are given, this includes the setup of the MQTT client and the Topic: 
```
//NETWORK CREDENTIALS - MQTT
const char *ssid_Router     = "*******"; // router name
const char *password_Router = "**********"; // router password

const char *ID = "Pomodoro_TIMER"; //Name of device
const char *TOPIC = "timer/pomodoro";  // Topic to subcribe to

char mqtt_server[] = "192.168......"; // IP address here 

WiFiClient TimerNET;
PubSubClient client(TimerNET); // Setup MQTT client
```
All of these are required if you are chosing a WiFi connection with MQTT, furthermore you will need to install Mosquitto to be able to setup an MQTT server, for this you will need to install through the terminal: 
```
brew install mosquitto
```
**NOTE: I highly recommend to make use of homebrew in order to be able to use the command above**

Now, you can test your MQTT server by entering the following command in a new window in yout terminal:
```
mosquitto_sub -d -t test
```
You can proceed by entering the following command in another window:
```
mosquitto_pub -d -t test -m "Hello world"
```
If your MQTT server is correctly set, you should be able to see the input "Hello World" in the window where you entered your first command. 

Do not forget to designate an **ID** and **TOPIC** in the code for your device and MQTT, this is required for any connection made through MQTT. 

Since MQTT will serve as our messaging protocol, we will make use of Node-red in order to publish MQTT messages directly to our Node-Red server, for this you will need to set up an MQTT node directly in our Node-Red window (mqtt://127.0.0.1:1883). From there you should double-click the node and insert "127.0.0.1" as your default server address. Before deploying anything in Node-Red you will need to do some modifications to your MQTT file.

As you've already installed MQTT (assuming you're using the latest version), the server itself will deploy in local mode, thus, we will need to edit the MQTT config file in order to change this, otherwise you won't be able to use your local network's IP address properly to connect to the MQTT server. 

The path to this file looks as follows: 
```
/usr/local/etc/mosquitto.conf
```

Make sure to open the *mosquitto.conf* file in a notepad, once done, you will need to edit the file by changing the **Listeners** section with the following:
```
listener 1883 0.0.0.0
```
Make sure there are not Hash symbols in the lines you edit. 

Now in the **Security** section of the file, you will need to change *allow_anonymous* from "false" to "true" and remove the hash symbol. This should allow you to start the MQTT server without local mode. 

If all these steps are done correctly, you will need to restart your MQTT server by using the *control + c* command and closing the window, in a new window you should insert the following: 

```
/usr/local/sbin/mosquitto -v -c /usr/local/etc/mosquitto/mosquitto.conf
```
Make sure the command contains the actual path to your mosquitto.conf file. If all these steps were done correcly, you will see the following in your terminal: 

<img src="https://github.com/Lme20/Pomodoro-System-IoT-project-/blob/a8aab21b51bd5b859db379a27b780ff3273508c3/assets/mosquitto.png" width="550"> 

*Notice how there is no local mode message shown.*

Once all these steps are done, you should be able to deploy your MQTT node in Node-Red with the IP address 127.0.0.1, make sure it is also set in port 1883 (default port). Finally, you can create a debug node in your Node-Red window to test connectivity and input, if all done correctly, the input should be shown in the debug window:

<img src="https://github.com/Lme20/Pomodoro-System-IoT-project-/blob/e71cfa8ee1400021b1b88058c10a91fc9f629ccd/assets/Debug_window.png" width="250"> 

To create the input simply connect your device (if not connected already) and push the push button in various modes, make sure it is connected to the WiFi and MQTT before doing so. 

By making use of MQTT and Node-red we will be able to send data whenever the push button is pressed, the objective is to capture the data free of time constraints as we aren't making use of sensors, thus, the data should be allowed to be sent so long it is created. The device is directly powered by the computer and does not require batteries so energy consumption is not a concern, in addition, the use of WiFi seemed obvious as the device does not require long-range connectivity or low-latency, furthermore, the use of MQTT as a transports protocol makes the creation of data from the device far easier as the device does not rely on sensors to obtain data but instead makes use of actuators. This was a challenge when making design choices as I wasn't sure how to create this "data",  MQTT provided the needed functions directly from the *PubSubClient* library which made the whole process straightforward. The data provided from the device is by itself lightweight and thus makes latency easy to manage, this made MQTT an even better option for this project. 

### Presenting the data

The project does not come with a dashboard per definition but I made use of Google sheets instead to present the data, most dashboards from various protocols require a defined set of "inputs" which are better adjusted to projects with sensors, I've instead decided to go for a spreadsheet as the data obtained does not require actual "measurements" and is only meant to provide insight to its user. I believe, however, that with some more exploring a dashboard could be implemented to make the data more intuitive. 

The data is meant to be preserved in the Google sheet as long as the user needs it to. A possible functionality could be added where the user has the chance to save the sheet beforee starting a new pass, however, as the project currently stands, the sheet only saves the data whether or not the user started a new pass, making no difference between passes that may be days old with new ones. 

First, there is a specific setup in Node-Red that must be done to obtain the data into Google sheets, after following the steps found in [Transmitting the data / connectivity](#transmitting-the-data--connectivity), you should now create a third node in the Node-Red window with the sequence node "Join", you might want to set the timout to 5 seconds after every message. Now we can proceed to Google sheets, in order to do so, you will need to create a Google forms containing 1 question "Mode" and make it a short answer, the form should look as follows: 

<img src="https://github.com/Lme20/Pomodoro-System-IoT-project-/blob/7800f2ac5ae54be0458d4c533b4974d3625b5cb2/assets/Google_forms.png" width="550"> 

Following this step you should now get a "pre-filled link" from the 3 dots in the forms, this will bring you to an overview of your forms, once done you will need to insert some "dummy" data into the formulaire and click "get link", this will give you a link needed for the next step. The link will look as follows:

```
https://docs.google.com/forms/d/e/1FAIpQLSdPg9tLqITqlvg8Gfgd9xisgHvTfyPVJbBirfySXSbCvh4Fnw/viewform?usp=pp_url&entry.1828283323=PAUSE
```
You can replace */viewform?usp=pp_url&* with */formResponse?* and proceed by changing
```
entry.1828283323=PAUSE
```
With the Topic of used in our Node-Red server/MQTT server: 
```
entry.1828283323={{payload.timer/pomodoro}}
```
Our now modified link should look like this:

```
https://docs.google.com/forms/d/e/1FAIpQLSdPg9tLqITqlvg8Gfgd9xisgHvTfyPVJbBirfySXSbCvh4Fnw/formResponse?entry.1828283323={{payload.timer/pomodoro}}
```
Now you can proceed by creating a new node in our Node-Red window with an "http request", make sure to attach this node to the "join" node and modify the URL section with the link above. Now you can press "Deploy" and observe how our Google forms is updated in real time. 

The final structure of our Node-Red server will look like this: 

<img src="https://github.com/Lme20/Pomodoro-System-IoT-project-/blob/d3326c1c74223de8304a00655827fbd485049a92/assets/Node-red_dataFlow.png" width="550"> 

We only need 1 Topic as the simplicity of our data does not require any specific category, this process also allows us to obtain a timestamp every time the Google forms is filled, which are the only 2 inputs we will need from the device. The data flow is fairly simple and leaves plenty of room for scalability and/or any improvements and new functionalities to this project. 

Now as a last step to this tutorial, you can create the Google sheet that I've mentioned by clicking on the Google sheet icon found in the "responses" section of our Google forms, I recommend creating a new sheet altogether. This will create the Google sheet we need to present the data: 

<img src="https://github.com/Lme20/Pomodoro-System-IoT-project-/blob/f2aea971c07b5dfe7b98587d1cbd36c7fc9bd38a/assets/Google_sheet_data.png" width="550"> 

I have done some changes to the sheet to better fit the aesthetic of this project, but you should see your sheet filled with a "timestamp" and "Mode" section with the data that was obtained from the steps above, if you have pressed the button to test and/or obtain any data to the Google forms. 

This choice of format for the database might be practical but becomes limitating if you require automatisation, furthermore, I believe the might be better services that provide all of the needs of this project in only one platform, but I believe that this is enough to give insight on how MQTT works and a basic understanding of how to connect a device to WiFi. The data itself can always be improved by adding new Topics that might fulfill the needs of the user, this could be done by creating a new topic in the code and a MQTT node in Node-Red with all the required data to publish. A good addition to this sheet might be the use of graphs to present the data in a more intuitive way. 

### Finalizing the design

This is the final setup for this project: 

<img src="https://github.com/Lme20/Pomodoro-System-IoT-project-/blob/2f238855c8fa6b0524ac0d4a2d2e98d5b6f237c1/assets/Full_setup.png" width="550"> 

My major constraint was actually time as I initially planned to use a Heltec ESP32 board instead, this did not go according to plan as I failed in soldering the pins correctly, rendering the Heltec board unusable for this project. The original idea was to an LCD screen to create a "countdown" for the timer, a nice addition which would've given some options for new data, this was possible at the time since the original Heltec board did come with a small display screen suited for this purpose. The failure in the soldering step took me back at least 2 weeks of planning, which made my schedule for this project already tight. Another issue which came in the development phase was the coding process itself and the specific structure I could use for this project, as I was unsure about which approach best suited my needs, this also needed defined requirements in order to have a better overview of which functionalities I required and how to apply them. 
Through testing and research I therefore found that using C++ and PlatformIO better suited my needs as there were far more projects with similar objectives as examples, as well as sources which I could use as a guide. Finally, the wiring process was by itself difficult, not due to the complexity of this project but rather due to inexperience in setting up an IoT device, as well as how to manage resistor values and what pins to use, I found this last phase quite challenging as a lot of the sources I found did not specify simple things such as how the resistors shouldn't "touch" or how to properly use a breadboard, additionally, I found that familiarising with the ESP32 board was crucial in order to create a functional circuit with the correct GPIO pins, without actually "frying" the board or the components themselves. 

I believe this project has a lot of potential and plenty of room for improvements, first, I'd suggest adding an LCD screen to visualise the timer as a useful addition to the device. Perhpas improving the MQTT connection and finding a better service instead of relying on Google sheets could help to automatise the process of obtaining data even further, this coupled with the use of a more intuitive way of presenting such data could make for a far better project. Lastly, I believe that reviewing the current design and all resistor values could vastly improve electrical flow in the device, perhaps making use of schematics and actually visualising the wiring for a better overview could ease this process. For these suggestions the use of wiring diagrams could be quie fitting. 
