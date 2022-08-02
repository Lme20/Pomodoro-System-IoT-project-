## Pomodoro tracking system - Tutorial

Louis Mercier - lm223ei

If you've ever struggled with productivity, missed a deadline, or ended up distracted too many times, then this project might be for you. There are countless techniques claiming to boost productivity and while many may work to varying degrees, there's no denying that Pomodoro takes the first spot. 

Pomodoro, meaning "Tomato" in Italian, is a very simple and consize technique based purely on how you distribute your time. The technique consists of time intervals, where you may only work for 25 minutes followed by a 5 minutes pause, totalling 30 minutes, this routine is then repeated and a new set is followed. This project is purely aimed at creating a device that allows you to follow this technique, with as little distractions as possible, without having to use a a Pomodoro timer online. Now, you may ask, why use a device when I can simply use a timer on my phone? Well, we know that phones are a distraction, besides, this device allows you to track all your passes, getting a better overview of how productive you've been. 

This project may take between 15 to 30 hours, depending on the complexity you're aiming and any addons you might want for this project (assuming you're not copypasting the entirety of the code). Additionaly, the coding phase may take up only 40% of the project, with the rest being left to the setup of your device and any issues that may come. Consider that this project may not be straightforward, as it depends entirely on your ESP board and the components you are using.

### Objective

I've chosen to build this specific device as I consider it beguinner friendly, fairly simple to develop and quite useful for anyone. I decided against any device that used sensors and instead aimed for a project in which I knew I would use even after this course was completed and would remain useful to me even long after. I could have aimed for a project that used basic sensors and displayed the data, however, I found the idea of developing something fairly different and still remain simple quite appealing. As such, I consider this device to still fulfill the basic requirements of this course while providing an alternative for anyone interested in a project that does not use sensors. 

The aim of this device is to track productivity using the pomodoro technique, in a way, this device functions as a timer free of distractions, while providing a set of data for its user. The data shall be displayed in a Google sheets document where the user will be able to obtain all the time intervals that have been completed, along the current date and time of such intervals. 

While fairly simple, I believe this device can provide insight on the productivity of its user, giving way to how long the user has been working as well as all the pauses activated during such intervals. If used correctly, this device culd suit anyone who's aiming at improving productivity and reduce any forms of distraction. 

### Material

For this project I've chosen a Freenove ESP32 board, with a GPIO extension board added to it. I've chosen this specific device as it provides all the perks of a generic ESP32 board with the addition of free resources provided by Freenove, additionally, as it comes with an extension board built-in, this specific board makes any kind of setup far easier and less troublesome, with no soldering required and no confusing setup compared to other boards (see pycom expansion boards), I considering this board to be highly beguinner friendly, with a range of tutorials and projects already provided by Freenove for free. As a side note, this board is compatible to the firmware provided by the course, as well as the firmware used in ESP32 boards by Espressif. 

Explain all material that is needed. All sensors, where you bought them and their specifications. Please also provide pictures of what you have bought and what you are using.

- [ ] List of material
- [ ] What the different things (sensors, wires, controllers) do - short specifications
- [ ] Where you bought them and how much they cost


&gt; Example:
&gt;| IoT Thing | For this         |
&gt;| --------- | ---------------- |
&gt;| Perhaps   | a table          |
&gt;| is a      | jolly good idea? |
&gt;
&gt;In this project I have chosen to work with the Pycom LoPy4 device as seen in Fig. 1, it&#39;s a neat little device programmed by MicroPython and has several bands of connectivity. The device has many digital and analog input and outputs and is well suited for an IoT project.
&gt;
&gt;![LoPy!](https://pycom.io/wp-content/uploads/2018/08/lopySide-1.png =360x)
&gt;Fig. 1. LoPy4 with headers. Pycom.io


### Computer setup

How is the device programmed. Which IDE are you using. Describe all steps from flashing the firmware, installing plugins in your favorite editor. How flashing is done on MicroPython. The aim is that a beginner should be able to understand.

- [ ] Chosen IDE
- [ ] How the code is uploaded
- [ ] Steps that you needed to do for your computer. Installation of Node.js, extra drivers, etc.

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
