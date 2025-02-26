//bluetooth
char val1;
//autodrive
#include<Servo.h>
Servo moter;
const int triga=5;
const int echoa=4;
//remote
#include<IRremote.h>
IRrecv remote(11);
decode_results results;

void setup() {
  //linefllow
  //bluetooth
  pinMode(12,INPUT);
  pinMode(13,INPUT);
  //remote
Serial.begin(9600);
remote.enableIRIn();
//autodrive
  moter.attach(3);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(triga,OUTPUT);
  pinMode(echoa,INPUT);
}

void loop() {
  //remote
  if(remote.decode(&results)){
    Serial.println(results.value,DEC);
    remote.resume();
  }
  delay(100);
  long val=results.value;
  if(val==752){
    //froward
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(7,LOW);
    digitalWrite(9,HIGH);
  }
  if(val==2672){
    //stop
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
  }
  if(val==3280){
    //turn_right
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,HIGH);
  }
  if(val==720){
    //turn_left
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
  }
  if(val==2800){
    //reverse
    digitalWrite(6,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(9,LOW);

  }
  if(val==16){
    //autodrive
  

   }
//bluetooth
  
  if(val==2064){




    

  }if(val==1040){
//linefollw-----
    
  }


  if(Serial.available()){
    Serial.println(val1);
    val1=Serial.read();

  if(val1=='S'){
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  }
  if(val1=='L'){
  digitalWrite(7,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
   }
  if(val1=='R'){
  digitalWrite(7,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,HIGH);
  }
  if(val1=='B'){
  digitalWrite(9,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(8,HIGH);
   }
   if(val1=='F'){
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(9,HIGH);
  digitalWrite(8,LOW);
        }
        if(val1=='G'){
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(9,LOW);
        }
        if(val1=='J'){
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
        }
        if(val1=='H'){
  digitalWrite(7,LOW);
  digitalWrite(9,LOW);
  digitalWrite(6,LOW);
  digitalWrite(8,HIGH);
        }
        if(val1=='I'){
  digitalWrite(9,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
        }
}
}



