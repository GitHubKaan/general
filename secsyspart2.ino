/* secsys software by kaan turan (version 1.0) for node mcu 2688
 * software: secsys 2/2 for device number 2/2 (backend)
 * 
 * info
 * > status: HIGH (signal on), LOW (signal off)
 * 
 */


//[]==========[settings start]==========[]
int tuning = 100; //time management tuning (1000 = 1 sec) - default: 100
int cooldown = 1; //time for cooldown between signals (5 = 1/2 sec) - default: 1
int infotime = 100; //time for console info messages (10 = 1 sec) - default: 100
int alarmtime = 370; //time before alarm get enabled (10 = 1 sec) - default: should be as long as in secsyspart1 (minus apr. 10 because of delay (=370))
int alarmactivetime = 100; //how many times the alarm should give a feedback after being active - default: 100

//[]==========[pins start]==========[]
int reciver = D7; //signals from secsys device one
int sound = D1; //signal to sound device
int led = D5; //led

int time_info = 0; //console time counter

boolean triggered = false; //when alarm gets triggered

int time_cooldown = 0; //cooldown between signals

boolean alarm_active = false; //if alarm is activ now

boolean first_start = true; //just on first start

boolean temp = false;

int timer = 0; //counter for alarm time enabeling

boolean resetter = false;


//[]==========[setup]==========[]
void setup() {
  Serial.begin(500000);
  
  pinMode(led, OUTPUT);
  pinMode(sound, OUTPUT);
  pinMode(reciver, INPUT);
}


//[]==========[loop]==========[]
void loop() {
  //will only be enabled at first start
  if (first_start == true) {
    for (int i = 0; i < 30; i++) {
      Serial.println();
    }
    for (int i = 0; i < 2; i++) {
      digitalWrite(led, HIGH); digitalWrite(sound, HIGH); delay(30); digitalWrite(led, LOW); digitalWrite(sound, LOW); delay(30);
    }
    
    Serial.println("system now online");
    
    first_start = false;
  }

  //disabeling alarm
  if (alarm_active == true && digitalRead(reciver) == HIGH) {
    alarm_active = false;
    temp = true;
    timer = 0;
    
    digitalWrite(led, LOW);
    
    Serial.println("alarm disabled");
  } else if (alarm_active == true) {
    if (timer >= alarmtime) {
      for (int i = 0; i < alarmactivetime; i++) {
        digitalWrite(sound, HIGH);
        digitalWrite(led, HIGH);
        delay(500);
        digitalWrite(sound, LOW);
        digitalWrite(led, LOW);
        delay(500);
      }
      
      //reset after alarm
      time_info = 0;
      triggered = false;
      time_cooldown = 0;
      alarm_active = false;
      first_start = true;
      temp = false;
      timer = 0;
    
      resetter = true;

      Serial.println("alarm now disabled");
    }
  }

  if (resetter == false) {
    //timer
    if (alarm_active == true) {
      timer++;
    }
  
    if (temp == false) {
      //when reciver gets a signal
      if (digitalRead(reciver) == HIGH && triggered == false) {
        triggered = true;
        alarm_active = true;
    
        digitalWrite(led, HIGH);
    
        Serial.println("trigger");
      }
      if (triggered == true) { //counter for cooldown time between signals
        time_cooldown++;

        if (time_cooldown >= cooldown) { //cooldown time
          triggered = false;
      
          Serial.println("input free for new signal");
        }
      }
    }
    temp = false;
  
    //general console info
    if (alarm_active == false) {
      digitalWrite(led, LOW);
    }
    if (time_info >= infotime) {
      time_info = 0;

      if (alarm_active == false) {
        digitalWrite(led, HIGH);
      
        Serial.println("system currently inactive");
      }
    }
  }
  resetter = false;

  time_info++;
  delay(tuning);
}
