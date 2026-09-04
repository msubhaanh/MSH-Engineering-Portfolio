const int buzzer = 6;
int tmppin = 0;
int bpin = 8;
int rpin = 13;
int reedswitch = 10;
int isdooropenLED = 9;
int reading ;

void setup()
{
  pinMode(tmppin, INPUT);
  pinMode(rpin,OUTPUT);
  pinMode(bpin,OUTPUT);
  Serial.begin(9600);

  pinMode(2, INPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(reedswitch, INPUT);
  pinMode(isdooropenLED, OUTPUT);
}

void turnOff(){
  digitalWrite(rpin,LOW);
  digitalWrite(bpin,LOW);
}

void loop()
{
  int sensor = analogRead(tmppin);
  int temp = map(sensor,20,358,-40,125);

  if (temp <= 18){
    turnOff();
    digitalWrite(bpin,HIGH);
    tone(buzzer, 1000);
  }
  else if (temp >=24){
    turnOff();
    digitalWrite(rpin,HIGH);
    tone(buzzer, 1000);
  }
  else if (temp >=18 && temp <= 24)
  {
    digitalWrite(rpin, LOW);
    digitalWrite(bpin,LOW);
    noTone(buzzer);
    delay(1000);
  }

  {
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);

    int read=digitalRead(2);

    if(read == HIGH)
    {
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      digitalWrite(5,HIGH);
      delay(20000);
    }

    delay(0);
  }

  {
    reading = digitalRead (reedswitch);

    if (reading ==1) {
      digitalWrite (isdooropenLED, HIGH);
      delay(1000);
      digitalWrite (isdooropenLED, LOW);
      delay (1000);
    }
  }
}
