#include <Servo.h>
Servo myservo;

const int buttonPin = 2;
int buttonState = 0;
int oneClick = 0;
int modeServo = 0;

void setup() {
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
  myservo.attach(9);
  Serial.println("Start Project");
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    if (oneClick < 10 ) {
      oneClick ++;
    }
    //    oneClick ++;
    if (oneClick == 1) {
      modeServo ++;
      if (modeServo > 2) {
        modeServo = 0;
      }
      Serial.print("mode servo : ");Serial.println(modeServo);      
    }
  }
  else if (buttonState == LOW) {
    //    Serial.println("LOW");
    oneClick = 0;
  }

  if (modeServo == 0) {
    myservo.write(0);
  }

  if (modeServo == 1) {
    myservo.write(90);
  }

  if (modeServo == 2) {
    myservo.write(180);
  }


delay(10);


}
