/* secsys software by kaan turan (version 1.0) for node mcu 2688
 * software: secsys 1/2 for device number 1/2 (door)
 * 
 * info
 * > status: HIGH (signal on), LOW (signal off)
 * 
 */


//[]==========[settings start]==========[]
int time_speed = 50; //general refresh rate of system loop

int time_stage = 20; //alarm prestage stage time (in seconds) (sum up for total time before final alarm) - default: 20
int time_stage0 = 10; //default: 10
int time_stage1 = 5; //default: 5
int time_stage2 = 3; //default: 3

int final_time = 600; //time after final alarm goes on and disabled itself (in seconds) - default: 600

int cooldown = 180; //cooldown time after disabling the system (in seconds) - default: 180


//[]==========[pins start]==========[]
int button_armed = D8; //signal that enables the first stage
int button_unarm = D2; //signal that disables all alarm stages

int sound_alarm = D4; //sound signal device for user imput and feedback

int led_green = D5; //green led
int led_yellow = D6; //yellow led
int led_red = D7; //red led

int device_signal = D1; //signal that enables second secsys device


//[]==========[variables start]==========[]
boolean first_start = true; //only gets activates when software starts first time

int time_type = 0; //1/4 sec
int time_type0 = 0; //1/2 sec
int time_type1 = 0; //1 sec
int time_type2 = 0; //10 sec

boolean alarm_prestage = false; //if the alarm gets enabled for the first time
int alarm_counter = 0; //alarm prestage stage counter

boolean alarm_stage = false; //alarm stages from prestage
boolean alarm_stage0 = false;
boolean alarm_stage1 = false;
boolean alarm_stage2 = false;

boolean final_alarm = false; //alarm after no unarming has happend
int final_timer = 0; //timer for automatical final alarm disabilisazion

boolean system_unarmed = false; //if system gets unarmed
int time_cooldown = 0; //cooldown after unarming the system


//[]==========[setup]==========[]
void setup() {
  Serial.begin(500000);

  pinMode(button_armed, INPUT);
  pinMode(button_unarm, INPUT);

  pinMode(sound_alarm, OUTPUT);

  pinMode(led_green, OUTPUT);
  pinMode(led_yellow, OUTPUT);
  pinMode(led_red, OUTPUT);

  pinMode(device_signal, OUTPUT);
}


//[]==========[loop]==========[]
void loop() {
  //blinking on first software start
  if (first_start == true) {
    for (int i = 0; i < 5; i++) {
      digitalWrite(led_green, HIGH); digitalWrite(sound_alarm, HIGH); delay(50); digitalWrite(led_yellow, HIGH); digitalWrite(led_green, LOW); digitalWrite(sound_alarm, LOW); delay(50); digitalWrite(led_red, HIGH); digitalWrite(led_yellow, LOW); delay(50); digitalWrite(led_red, LOW);
    }
    digitalWrite(sound_alarm, HIGH); digitalWrite(led_green, HIGH); digitalWrite(led_yellow, HIGH);  digitalWrite(led_red, HIGH); delay(300); digitalWrite(sound_alarm, LOW); digitalWrite(led_green, LOW); digitalWrite(led_yellow, LOW);  digitalWrite(led_red, LOW);
    
    first_start = false;

    for (int i = 0; i < 30; i++) {
      Serial.println("");
    }
    Serial.println("secsys software has been enabled");
  }

  //unarm button settings
  if (digitalRead(button_unarm) == LOW && system_unarmed == false) {
    if (final_alarm == false && (alarm_prestage == true || final_alarm == true)) {
      digitalWrite(device_signal, HIGH); delay(500); digitalWrite(device_signal, LOW);
    }
     
    system_unarmed = true;
    
    for (int i = 0; i < 2; i++) {
      digitalWrite(sound_alarm, HIGH); digitalWrite(led_green, HIGH); digitalWrite(led_yellow, LOW);  digitalWrite(led_red, LOW); delay(50); digitalWrite(sound_alarm, LOW); digitalWrite(led_green, LOW); delay(50);
    }
    
    time_type = 0;
    time_type0 = 0;
    time_type1 = 0;
    time_type2 = 0;

    alarm_prestage = false;
    alarm_counter = 0;

    alarm_stage = false;
    alarm_stage0 = false;
    alarm_stage1 = false;
    alarm_stage2 = false;

    final_alarm = false;
    final_timer = 0;

    time_cooldown = 0;
    
    digitalWrite(led_green, HIGH);
    
    Serial.println("secsys unarmed now");
  }
  if (time_cooldown >= cooldown && system_unarmed == true) { //after the cooldown is over
    digitalWrite(led_green, LOW); digitalWrite(led_red, HIGH); digitalWrite(sound_alarm, HIGH); delay(500); digitalWrite(led_red, LOW); digitalWrite(sound_alarm, LOW);

    time_cooldown = 0;
    system_unarmed = false;
  }
  
  //final alarm settings
  if (final_alarm == true) {
    digitalWrite(led_red, HIGH); digitalWrite(led_yellow, LOW); digitalWrite(led_green, LOW); digitalWrite(sound_alarm, LOW);
    
    alarm_prestage = false;
    alarm_counter = 0;

    if (final_timer >= final_time) {
      first_start = true;

      time_type = 0;
      time_type0 = 0;
      time_type1 = 0;
      time_type2 = 0;

      alarm_prestage = false;
      alarm_counter = 0;

      alarm_stage = false;
      alarm_stage0 = false;
      alarm_stage1 = false;
      alarm_stage2 = false;

      final_alarm = false;
      final_timer = 0;

      time_cooldown = 0;
      
      Serial.println("secsys final alarm is now disabled");
    }
  }
  
  //alarm_prestage activator (checker)
  if (digitalRead(button_armed) == HIGH && system_unarmed == false) {
    if (alarm_prestage == false && final_alarm == false) {
      digitalWrite(device_signal, HIGH); delay(500); digitalWrite(device_signal, LOW);
      
      alarm_prestage = true;
      
      Serial.println("prestage alarm got enabled");
    }
  }
  
  //alarm_prestage yellow led blinking stages
  if (alarm_prestage == true && alarm_stage2 == false) { //general alarm prestage led and sound settings
    digitalWrite(led_yellow, LOW); digitalWrite(sound_alarm, LOW);
  }
  if (alarm_stage2 == true) { //last alarm prestage led and sound settings
    digitalWrite(led_yellow, HIGH); digitalWrite(sound_alarm, HIGH);
  }
  
  if (alarm_counter <= time_stage && alarm_prestage == true) {
    alarm_stage = true;
  } else if (alarm_counter > time_stage && alarm_counter <= time_stage + time_stage0) {
    alarm_stage = false;
    alarm_stage0 = true;
  } else if (alarm_counter > time_stage + time_stage0 && alarm_counter <= time_stage + time_stage0 + time_stage1) {
    alarm_stage0 = false;
    alarm_stage1 = true;
  } else if (alarm_counter > time_stage + time_stage0 + time_stage1 && alarm_counter <= time_stage + time_stage0 + time_stage1 + time_stage2) {
    alarm_stage1 = false;
    alarm_stage2 = true;
  } else if (alarm_counter > time_stage + time_stage0 + time_stage1 + time_stage2) {
    alarm_stage2 = false;

    final_alarm = true;
  
    Serial.println("final alarm enabled no unarming happened");
  }


  //[]==========[1/4 sec]==========[]
  if (time_type == 5) {
    time_type = 0; //reset time_speed (time_speed: 5 = 1/4 sec)
    time_type0++;
    //--- /\ --- time settings --- /\ ---

    //default green light blink turn off (after every 10 seconds the light gets emediatly disabled 1/4 second afterwards (light goes on for 1/4 of a second))
    if (alarm_prestage == false && system_unarmed == false) {
      digitalWrite(led_green, LOW);
    }

    //second alarm stage from alarm prestage
    if (alarm_stage1 == true) {
      digitalWrite(led_yellow, HIGH); digitalWrite(sound_alarm, HIGH);
    }
  }
  
  
  //[]==========[1/2 sec]==========[]
  if (time_type0 == 2) {
    time_type0 = 0; //reset time_type0 (time_type0: 2 = 1/2 sec)
    time_type1++;
    //--- /\ --- time settings --- /\ ---
    
    //second alarm stage from alarm prestage
    if (alarm_stage0 == true) {
      digitalWrite(led_yellow, HIGH); digitalWrite(sound_alarm, HIGH);
    }
  }

  
  //[]==========[1 sec]==========[]
  if (time_type1 == 2) {
    time_type1 = 0; //reset time_type1 (time_type1: 2 = 1 sec)
    time_type2++;
    //--- /\ --- time settings --- /\ ---

    //counter for alarm stages goes up every second
    if (alarm_prestage == true) {
      alarm_counter++;
    }

    //first alarm stage from alarm prestage
    if (alarm_stage == true) {
      digitalWrite(led_yellow, HIGH);
    }

    //final alarm counter
    if (final_alarm == true) {
      final_timer++;
    }

    //cooldown counter for unarming
    if (system_unarmed == true) {
      time_cooldown++;
    }
  }

  
   //[]==========[30 sec]==========[]
  if (time_type2 == 30) {
    time_type2 = 0; //reset time_type2 (time_type2: 30 = 30 sec)
    //--- /\ --- time settings --- /\ ---

    //default green light blink (enabling every 10 seconds)
    if (alarm_prestage == false && final_alarm == false) {
      digitalWrite(led_green, HIGH);
    }
  }
  
  
  
  time_type++;
  delay(time_speed);
}
