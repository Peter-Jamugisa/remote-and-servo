#include <IRremote.h>
#include <Servo.h>
#define STEP 4 // degrees to rotate the servo
Servo myservo;
int RECV_PIN = 7, SERVO_PIN = 8;
int x, y=90,z=90;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup ()
{
myservo.attach (8);
Serial.begin (9600);
irrecv.enableIRIn (); // Start the receiver
irrecv.blink13(true);
}
void loop ()
{
if (irrecv.decode (& results))
{
Serial.println(results.value ,HEX);
delay (50);
irrecv.resume ();
x=results.value ;// Receive the next value
Serial.println(x);
if(x==2064)
{
y=y-STEP;
myservo.write(y);
if(y <=0) y=0; // Lower bound of the servo motor
}
if(x==1040)
{
y=y+STEP;
myservo.write(y);
if(y >=180) y=180; // Upper bound of the servo motor
}
}// end if , receiver
}// end loop