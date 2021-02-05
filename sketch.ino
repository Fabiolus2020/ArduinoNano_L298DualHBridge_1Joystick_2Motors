/*
 * Fabiolus
 * 2020/07/04
 * the_fabiolous@hotmail.com
   This is a dual axis joystick skitch for Arduino.
   The position of joystick is read and displayed on serial monitor
*/
//Joystick Pins
int x_key = A1;
int y_key = A0;
int x_pos;
int y_pos;


//Motor Pins
//int EN_A = 10;      //disable pin since we dont use PWM
int IN1 = 4;       //control pin for first motor
int IN2 = 5;       //control pin for first motor
int IN3 = 6;        //control pin for second motor
int IN4 = 7;        //control pin for second motor
//int EN_B = 3;      //disable pin since we dont use PWM


void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
 // pinMode(EN_A, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
 // pinMode(EN_B, OUTPUT);

  //Initializng the joystick pins as input
  pinMode (x_key, INPUT) ;
  pinMode (y_key, INPUT) ;

}

void loop() {


  x_pos = analogRead (x_key) ;  //Reading the horizontal movement value
  y_pos = analogRead (y_key) ;  //Reading the vertical movement value

  if (x_pos < 460) {    //Rotating direction FORWARD BOTH MOTORS

    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);

  }

  else if (x_pos > 525) {  //Rotating direction BACKWARD BOTH MOTORS
  
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    

  }


 else if (y_pos > 525) {    //Rotating direction FORWARD and BACKWARD BOTH MOTORS PUSHING JOYSTICK RIGHT

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
 
  }

  else if (y_pos < 460) {    //Rotating direction FORWARD and BACKWARD BOTH MOTORS PUSHING JOYSTICK RIGHT

    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);

  }

else 
{
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);

}


  //  Serial.print("X: ");
  //  Serial.print(x_pos); //print x

  //  Serial.print(" Y: ");
  //  Serial.println(y_pos);// print y

}
