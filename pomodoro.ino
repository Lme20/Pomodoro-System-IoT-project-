#include <EncButton.h> // https://github.com/GyverLibs/EncButton
#include <TimerMs.h> // https://github.com/GyverLibs/TimerMs
#include <HTTPClient.h> //included for the google sheets connection
#include <WiFiClient.h> //WiFi setup and client
#include <PubSubClient.h> //run MQTT

//---------------------------SETUP-------------------------------------
//PINS
const int LED_R_PIN = 15; // 15
const int LED_G_PIN = 2; //2
const int LED_B_PIN = 4; //4
const int BUZ_PIN = 13; //
const int BTN_PIN = 21; //

//NETWORK CREDENTIALS - MQTT
const char *ssid_Router     = "*****"; //Enter the router name
const char *password_Router = "******"; //Enter the router password

const char *ID = "Pomodoro_TIMER"; //Name of device
const char *TOPIC = "timer/pomodoro";  // Topic to subcribe to

char mqtt_server[] = "192.168....."; //127.0.0.1

WiFiClient TimerNET;
PubSubClient client(TimerNET); // Setup MQTT client

//RECONNECT TO CLIENT
void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect(ID)) {
      Serial.println("connected");
      Serial.print("Publishing to: ");
      Serial.println(TOPIC);
      Serial.println('\n');

    } else {
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

//EXTRA
#define R_channel 0
#define G_channel 1
#define B_channel 2
#define pwm_Frequency 5000 // pwm frequency
#define pwm_resolution 8 // 8 bit resolution

const int LED_SPEED_MS = 700; // led blinking speed

const uint32_t WORK_T_MS = 1500000; // work time 25 min
const uint32_t REST_T_MS = 300000; // rest time 5 min
const uint32_t LONG_REST_T_MS = 1200000; // long rest 20 min
//---------------------------------------------------------------------

////VARIABLE DECLARATION
int curLed = LED_R_PIN;
int ledState = 0; // 0 - off, 1 - on, 2 - blinking
bool ledOn = false;

int pomodoros = 0;
int state = 0; // 0 - pause, 1 - work, 2 - work end, 3 - rest, 4 - rest end
int initState = true;

EncButton<EB_TICK, BTN_PIN> btn(INPUT);

TimerMs ledTmr(LED_SPEED_MS, 1, 0);
TimerMs mainTmr(WORK_T_MS, 0, 1);

//---------------------------------------------------------------------
////SETUP FUNCTION START
//---------------------------------------------------------------------
void setup() {

  //START WiFi connection
  Serial.begin(115200); //serial communication with serial monitor
  delay(2000);
  Serial.println("Setup start");
  WiFi.hostname(ID);
  WiFi.begin(ssid_Router, password_Router);
  client.setServer(mqtt_server, 1883);
  reconnect();
  Serial.println(String("Connecting to ")+ssid_Router);
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected, IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println("Setup End");

  //---------------------------------------------------------------------

  //PIN SETUP
  pinMode(LED_R_PIN, OUTPUT);
  pinMode(LED_G_PIN, OUTPUT);
  pinMode(LED_B_PIN, OUTPUT);
  pinMode(BUZ_PIN, OUTPUT);
  pinMode(BTN_PIN, INPUT);

  //---------------------------------------------------------------------
}

void loop() {

    //Button update
    btn.tick();

  //---------------------------------------------------------------------
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
    //---------------------------------------------------------------------
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
    //---------------------------------------------------------------------
    // CASE 2 - WORK END
    case 2: // work end
      if (initState) {
        initState = false;

        setCurLed(LED_R_PIN);
        setLedState(2); //BLINK

        client.publish(TOPIC, "WORK END");
        Serial.println((String)TOPIC + " => WORK END");

        pomodoros = pomodoros+1;
        if (pomodoros >= 4) {
          // LONG REST
          pomodoros = 0;
          mainTmr.setTime(LONG_REST_T_MS);
          beepLongRest();

          client.publish(TOPIC, "LONG BREAK");
          Serial.println((String)TOPIC + " => LONG BREAK");

        } else {
          mainTmr.setTime(REST_T_MS);
          beepEnd();
        }
      }
      if (btn.release()) {
        beepClick();
        setState(3); //REST
      }
      break;
    //---------------------------------------------------------------------
    // CASE 3 - REST
    case 3: // rest
      if (initState) {
        initState = false;

        setCurLed(LED_G_PIN);
        setLedState(1); //ON

        client.publish(TOPIC, "BREAK");
        Serial.println((String)TOPIC + " => BREAK");

        mainTmr.start();
      }
      if (mainTmr.tick()) setState(4);
      if (btn.release()) {
        beepClick();
        setState(1);
      }
      break;
    //---------------------------------------------------------------------
    // CASE 4 - REST END
    case 4: // rest end
      if (initState) {
        initState = false;

        setCurLed(LED_G_PIN);
        setLedState(2);
        beepEnd();

        client.publish(TOPIC, "BREAK END");
        Serial.println((String)TOPIC + " => BREAK END");

      }
      if (btn.release()) {
        beepClick();
        setState(1);
      }
      break;
  }

  //---------------------------------------------------------------------
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
  //---------------------------------------------------------------------

}

void setState(int val) {
  if (val == state) return;
  if (state >= 5) val = 0;
  state = val;
  initState = true;
}

void ledSwitch(bool on) {
  if (on) {
    digitalWrite(curLed, HIGH);
  } else {
    digitalWrite(curLed, LOW);
  }
  ledOn = on;
}

void setCurLed(int val) {
  if (val == curLed) return;
  ledSwitch(false);
  curLed = val;
}

void setLedState(int val) {
  if (val == ledState) return;
  ledState = val;

}

//---------------------------------------------------------------------
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
//---------------------------------------------------------------------

void beep(int n, int durSig, int durPause) {
  if (n>1 && durPause == 0 ) {
    durPause = durSig;
  }
  for (int i=0;i<n;i++) {
    digitalWrite(BUZ_PIN, HIGH);
    delay(durSig);
    digitalWrite(BUZ_PIN, LOW);
    delay(durPause);
  }
}
//---------------------------------------------------------------------


//---------------------------------------------------------------------
//// LOOP FUNCTION START
//---------------------------------------------------------------------
