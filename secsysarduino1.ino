/*
 * LIGHT Alarm-System
 * 
 * 0. Normal state: Green LED blinks in 10 second intervall
 * 1. Button gets pressed (by the door for example)
 * 2. Alarm-System will get armed (Yellow LED + Sound (Will get faster))
 * 3. The user gets 20 seconds to press the button to disable
 * 4. After 10 seconds the alarm-sound will get faster
 * 5. After 5 seconfs the alarm-sound will get even more faster + red light starts to blink
 * 6. situation 1: alarm start (red light will go on + alarm system will go on + sound off)
 * 7. situation 2: alarm will go off (happy sound plays + green light)
 * 
 * -> deactivates after 30min automatically
 */


/*====[SETTINGS]========================================================================================*/

int main_time = 50; //100 is default (5 half the time), everything changed on this number will make all other time settings logically obsolete. Smaller means faster, higher slower.

int cooldown = 1000; //time for cooldown after alarm gets triggered (300 = 3min | 60 = 1min | 1 = 1sec)
int activealarmtime = 12000; //when alarm goes on, when does it end? (6.000 = 10min | 600 = 1min)
int disablesound = D4; //D4 = active, something else = inactive
boolean disablestartsound = true; //disabeling the first warning stage sound

/*====[SETTINGS]========================================================================================*/


int button_armed = D8;
int button_unarm = D2;

int sound_alarm = disablesound;

int led_green = D5;
int led_yellow = D6;
int led_red = D7;

int signal_device2 = D1; //signal sender

int time_tenthsecond = 0;
int time_halfsecond = 0;
int time_second = 0;
int time_fiveseconds = 0;
int time_tenseconds = 0;
int time_minute = 0;

int active_timer = 0;
int alarm_active_timer = 0;

boolean phase_0 = false;
boolean phase_1 = false;
boolean phase_2 = false;

int temp_switcher = 0;
int temp_switcher2 = 0;
int temp_switcher3 = 0;

boolean first_start = true;

boolean system_active = false; //false = default
boolean alarm = false;

boolean main_alarm = false;

boolean signal_block = false;

void setup() {
  Serial.begin(500000);

  pinMode(button_armed, INPUT);
  pinMode(button_unarm, INPUT);
  
  pinMode(sound_alarm, OUTPUT);

  pinMode(signal_device2, OUTPUT);
  
  pinMode(led_green, OUTPUT);
  pinMode(led_yellow, OUTPUT);
  pinMode(led_red, OUTPUT);
}

void loop() { //digitalRead, digitalWrite
  if (first_start == true) { //only at first software start
    for (int i = 0; i < 5; i++) {
      digitalWrite(led_green, HIGH);
      digitalWrite(sound_alarm, HIGH);
      delay(100);
      digitalWrite(led_green, LOW);
      digitalWrite(led_yellow, HIGH);
      digitalWrite(sound_alarm, LOW);
      delay(100);
      digitalWrite(led_yellow, LOW);
      digitalWrite(led_red, HIGH);
      delay(100);
      digitalWrite(led_red, LOW);
    }
    for (int i = 0; i < 1; i++) {
      digitalWrite(led_green, HIGH);
      digitalWrite(led_yellow, HIGH);
      digitalWrite(led_red, HIGH);
      digitalWrite(sound_alarm, HIGH);
      delay(500);
      digitalWrite(led_green, LOW);
      digitalWrite(led_yellow, LOW);
      digitalWrite(led_red, LOW);
      digitalWrite(sound_alarm, LOW);
      delay(500);
    }
    for (int i = 0; i < 2; i++) {
      digitalWrite(led_green, HIGH);
      digitalWrite(led_yellow, HIGH);
      digitalWrite(led_red, HIGH);
      digitalWrite(sound_alarm, HIGH);
      delay(300);
      digitalWrite(led_green, LOW);
      digitalWrite(led_yellow, LOW);
      digitalWrite(led_red, LOW);
      digitalWrite(sound_alarm, LOW);
      delay(300);
    }
    for (int i = 0; i < 3; i++) {
      digitalWrite(led_green, HIGH);
      digitalWrite(led_yellow, HIGH);
      digitalWrite(led_red, HIGH);
      digitalWrite(sound_alarm, HIGH);
      delay(200);
      digitalWrite(led_green, LOW);
      digitalWrite(led_yellow, LOW);
      digitalWrite(led_red, LOW);
      digitalWrite(sound_alarm, LOW);
      delay(200);
    }
    for (int i = 0; i < 5; i++) {
      digitalWrite(led_green, HIGH);
      digitalWrite(led_yellow, HIGH);
      digitalWrite(led_red, HIGH);
      digitalWrite(sound_alarm, HIGH);
      delay(100);
      digitalWrite(led_green, LOW);
      digitalWrite(led_yellow, LOW);
      digitalWrite(led_red, LOW);
      digitalWrite(sound_alarm, LOW);
      delay(100);
    }
    for (int i = 0; i < 6; i++) {
      digitalWrite(led_green, HIGH);
      digitalWrite(led_yellow, HIGH);
      digitalWrite(led_red, HIGH);
      digitalWrite(sound_alarm, HIGH);
      delay(50);
      digitalWrite(led_green, LOW);
      digitalWrite(led_yellow, LOW);
      digitalWrite(led_red, LOW);
      digitalWrite(sound_alarm, LOW);
      delay(50);
    }
    for (int i = 0; i < 7; i++) {
      digitalWrite(led_green, HIGH);
      digitalWrite(led_yellow, HIGH);
      digitalWrite(led_red, HIGH);
      digitalWrite(sound_alarm, HIGH);
      delay(30);
      digitalWrite(led_green, LOW);
      digitalWrite(led_yellow, LOW);
      digitalWrite(led_red, LOW);
      digitalWrite(sound_alarm, LOW);
      delay(30);
    }
    Serial.println("system is now active and ready");
    first_start = false;
  }

  if (temp_switcher3 >= 5) {
    for (int i = 0; i < 30; i++) {
      digitalWrite(led_red, HIGH);
      delay(50);
      digitalWrite(led_red, LOW);
      delay(50);
    }
    digitalWrite(sound_alarm, HIGH);
    delay(50);
    digitalWrite(sound_alarm, LOW);
    digitalWrite(led_green, HIGH);
    delay(500);
    digitalWrite(led_green, LOW);
    time_tenthsecond = 0;
    time_halfsecond = 0;
    time_second = 0;
    time_fiveseconds = 0;
    time_tenseconds = 0;
    time_minute = 0;

    active_timer = 0;
    alarm_active_timer = 0;

    phase_0 = false;
    phase_1 = false;
    phase_2 = false;

    temp_switcher = 0;
    temp_switcher2 = 0;
    temp_switcher3 = 0;

    first_start = true;

    system_active = false;
    alarm = false;

    main_alarm = false;
  }
  
  if ((digitalRead(button_unarm) == HIGH) || (main_alarm == true && digitalRead(button_armed) == HIGH)) {
    system_active = false;
    alarm = false;
    main_alarm = false;

    if (signal_block == true) {
      signal_block = false;
      digitalWrite(signal_device2, HIGH);
      delay(500);
      digitalWrite(signal_device2, LOW);
    }
      
    time_tenthsecond = 0;
    time_halfsecond = 0;
    time_second = 0;
    time_fiveseconds = 0;
    time_tenseconds = 0;
    time_minute = 0;
    active_timer = 0;
    alarm_active_timer = 0;
    phase_0 = false;
    phase_1 = false;
    phase_2 = false;
    temp_switcher = 0;

    digitalWrite(led_green, LOW);
    digitalWrite(led_yellow, LOW);
    digitalWrite(led_red, LOW);
    digitalWrite(sound_alarm, LOW);

    
    for (int i = 0; i < 5; i++) {
      digitalWrite(led_green, HIGH);
      digitalWrite(led_yellow, HIGH);
      digitalWrite(led_red, HIGH);
      digitalWrite(sound_alarm, HIGH);
      delay(50);
      digitalWrite(led_green, LOW);
      digitalWrite(led_yellow, LOW);
      digitalWrite(led_red, LOW);
      digitalWrite(sound_alarm, LOW);
      delay(50);
    }
    for (int i2 = 0; i2 < cooldown; i2++) { //after disabling the system, the system will be shut down
      digitalWrite(led_green, HIGH);
      delay(250);
      digitalWrite(led_green, LOW);
      delay(250);
      digitalWrite(led_green, HIGH);
      delay(250);
      digitalWrite(led_green, LOW);
      delay(250);
    }
    digitalWrite(led_red, HIGH);
    digitalWrite(sound_alarm, HIGH);
    delay(2000);
    digitalWrite(sound_alarm, LOW);
    digitalWrite(led_red, LOW);
    temp_switcher2 = 0;
  }
  
  //[]====================[]------------------------------------------------------------
  //every tenth second
  //[]====================[]------------------------------------------------------------
  if (system_active == false) {
    phase_0 = false;
    phase_1 = false;
    phase_2 = false;
  }
  
  if (phase_2 == true) {
    digitalWrite(sound_alarm, HIGH);
  } else {
    digitalWrite(sound_alarm, LOW);
  }
  
  if (phase_2 == false) { //light stands still after enabling the alarm at second 20-30
    digitalWrite(led_yellow, LOW);
  }
  
  if (digitalRead(button_armed) == HIGH) { //action if alarm gets enabled
    Serial.println("system amored now");
    system_active = true;
  }
  
  if (system_active == true) {
      if (signal_block == false) {
        signal_block = true;
        Serial.println("signal <-------------------------");
        digitalWrite(signal_device2, HIGH);
        delay(500);
        digitalWrite(signal_device2, LOW);
      }
    
      active_timer++;

      if (active_timer <= 200) { //0-10 seconds (alarm being active) //default: 100
        phase_0 = true;
      } else if (active_timer <= 400 && active_timer >= 200) { //after 10-20 seconds (alarm being active) //default: 200 100
        phase_0 = false;
        phase_1 = true;
      } else if (active_timer <= 500 && active_timer >= 400) { //after 20-30 seconds (alarm being active) //default: 300 200
        phase_2 = true;
      } else if (active_timer >= 500) { //over 30 seconds == main alarm starts //default: 300
        system_active = false;
        alarm = true;
      }
  }
  
  if (phase_1 == true) {
      if (temp_switcher == 0) {
        digitalWrite(led_yellow, HIGH);
        temp_switcher = 1;
      } else {
        temp_switcher = 0;
      }
  }


  
  //[]====================[]------------------------------------------------------------
  //every half second
  //[]====================[]------------------------------------------------------------
  if (time_tenthsecond >= 5) {
    Serial.println("update 0.5 sec");
    time_tenthsecond = 0;
    time_halfsecond++;


    digitalWrite(led_green, LOW); //that if after 5 seconds, the green light goes on for half a second
    if (phase_0 == true) {
      digitalWrite(sound_alarm, LOW);
    } else if (phase_1 == true) {
      digitalWrite(sound_alarm, HIGH);
    }
    
    if (phase_0 == true) {
      digitalWrite(led_yellow, HIGH);
    }
  }

  if (alarm == true) {
    digitalWrite(led_red, HIGH);
  }



  //[]====================[]------------------------------------------------------------
  //every second
  //[]====================[]------------------------------------------------------------
  if (time_halfsecond >= 2) {
    Serial.println("update 1 sec");
    time_halfsecond = 0;
    time_second++;
    time_fiveseconds++;
    time_tenseconds++;


    if (phase_0 == true && disablestartsound == false) {
      digitalWrite(sound_alarm, HIGH);
    }
  }



  //[]====================[]------------------------------------------------------------
  //every five seconds
  //[]====================[]------------------------------------------------------------
  if (time_fiveseconds >= 5) {
    Serial.println("update 5 sec");
    time_fiveseconds = 0;

 
  }



  //[]====================[]------------------------------------------------------------
  //every ten seconds
  //[]====================[]------------------------------------------------------------
  if (time_tenseconds >= 10) {
    Serial.println("update 10 sec");
    time_tenseconds = 0;


    if (system_active == false && alarm == false) { //if alarm is off light blinks every 10 seconds
      Serial.println("green light -> blink");
      digitalWrite(led_green, HIGH);
    }
  }
  


  //[]====================[]------------------------------------------------------------
  //every minute
  //[]====================[]------------------------------------------------------------
  if (time_second >= 60) {
    Serial.println("update 1 min");
    time_second = 0;
    time_minute++;

    temp_switcher3 = 0;
  }



  //[]====================[]------------------------------------------------------------
  //every five minutes
  //[]====================[]------------------------------------------------------------
  if (time_minute >= 10) {
    Serial.println("update 10 min");
    time_minute = 0;
  }



  //auto stop after 10 minutes (alarm)
  if (alarm == true) {
    Serial.println("alarm now active");
    
    alarm_active_timer++;
    main_alarm = true;
  }
  if (alarm_active_timer >= activealarmtime) { //after 10 minutes active alarm goes offline (system reset)
    Serial.println("system got a factory reset");
    
    time_tenthsecond = 0;
    time_halfsecond = 0;
    time_second = 0;
    time_fiveseconds = 0;
    time_tenseconds = 0;
    time_minute = 0;
    active_timer = 0;
    alarm_active_timer = 0;
    phase_0 = false;
    phase_1 = false;
    phase_2 = false;
    temp_switcher = 0;
    first_start = true;
    system_active = false;
    alarm = false;
    main_alarm = false;
    temp_switcher2 = 0;
  }

  if (main_alarm == true) { //everything that happens when main alarm gets enabled
    Serial.println("master alarm triggered...");
  }


  
  time_tenthsecond++; //every loop, the counter goes up by one (1 sec equals timeCounter = 10)
  delay(main_time); //1000 = 1 sec (In this instance, every second the loop goes 10 times) - default: 100
}


  
