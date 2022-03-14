//com7

/*
 * reciving information: digitalRead(recive_message) == HIGH/LOW
 */

//settings
int message_time = 150; //1000: 1 sec, should be the same as in secsyspart1 (+50)
int alarm_activasion = 3800; //100 = 1sek (should be the same as in secsyspart1 +10) 38 sec default || 3800 def.
int alarm_repeat = 600; //one rep one sec (600 = 10 min) 600 = default




//variablen
int counter = 0;
int recive_message = D8;
int led = D7;
int sound = D3;

int led_status = 0;
boolean alarm_active = false;
int alarm_status = 0;

int alarm_counter = 0;

boolean firststart = true;
boolean test = false;

void setup() {
  Serial.begin(500000);

  pinMode(led, OUTPUT);
  pinMode(sound, OUTPUT);
  
  pinMode(recive_message, INPUT);
}

void loop() {
  if (firststart == true) {
    for (int i = 0; i < 5; i++) {
      delay(50);
      digitalWrite(led, HIGH);
      delay(50);
      digitalWrite(led, LOW);
    }
    
    firststart = false;
  }
  
  //led on message recive 
  if (alarm_active == true) {
    digitalWrite(led, HIGH);
    if (alarm_status <= 0) {
      alarm_status++;
      delay(message_time);
    }
  } else {
    digitalWrite(led, LOW);
  }

  if (alarm_status >= 2) {
    alarm_active = false;
    alarm_status = 0;
    alarm_counter = 0;
  }
  
  //reciving part
  if (digitalRead(recive_message) == HIGH) {
    alarm_active = true;
    alarm_status++;
    Serial.println("signal recived");
  } else if (digitalRead(recive_message) == LOW) {
    if (alarm_status == 0) {
      Serial.println("no signal");
    } else {
      Serial.println("awaiting signal");
      Serial.println(alarm_counter);
      Serial.println("----------");
    }
  }
  
  //counter
  if (counter >= 1000) {
    counter = 0;
  }
  
  if (counter == 0) {
    digitalWrite(led, HIGH);
  } else if (counter == 500) {
    digitalWrite(led, LOW);
  }
  
  if (alarm_status == 0) {
    Serial.println(counter);
  }
  counter++;

  //alarm counter
  if (alarm_active == true && alarm_active) {
    alarm_counter++;
    
    if (alarm_counter >= alarm_activasion) {

      Serial.println("main alarm is now active");
      
      for (int i = 0; i < alarm_repeat; i++) {
        
        delay(250);
        digitalWrite(led, LOW);
        delay(250);
        digitalWrite(led, HIGH);
        digitalWrite(sound, HIGH);
        Serial.println("ping");
        delay(250);
        digitalWrite(led, LOW);
        delay(250);
        digitalWrite(led, HIGH);
        digitalWrite(sound, LOW);
        Serial.println("pong");
      }
    }
  }
  
  //loop delay
  delay(10);
}
