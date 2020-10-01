//---------ELECTRONOOBS----------//
//--------BT app control---------//
//--------BLUETOOTH CONTROL HOME AUTOMATION-------//


int light=7; //connect relay input pin 1 of arduino pin 7
int fan=6;.  //connect relay input pin 2 of arduino pin 6
int tv = 5;. //connect relay input pin 3 of arduino pin 5

char Received='0';
int light_state =0;     
int fan_state = 0;
int tv_state = 0;   //initially state all appliance in off mode


void setup(){
  
  Serial.begin(9600);
  pinMode(fan,OUTPUT);
  pinMode(light,OUTPUT);
  pinMode(tv,OUTPUT);   //define which pin are output or input
  
}

void loop(){
 
 if(Serial.available()>0)
 { 
    Received = Serial.read();
    
 }
////////////////LIGHT/////////////////////
if (light_state == 0 && Received == '7')  //if Light state is 0 and value receive 7 then Light on mode
  {
    digitalWrite(light,HIGH);  //on mode
    light_state=1;
    Received=0;  
    Serial.println("Light On");
  }
if (light_state ==1 && Received == '7')  //if Light state is 1 and value receive 7 then Light off mode
  {
    digitalWrite(light,LOW);  //off mode
    light_state=0;
    Received=0;
    Serial.println("Light off");
  }

  if(Received == '1'){  //if value received 1 then Light off mode
    digitalWrite(light,HIGH);  //on mode
    delay(1000); 
    Serial.println("Light On");
  }

  if (Received == '2')  //if value received 2 then Light off mode
  {
    digitalWrite(light,LOW);  //off mode
    delay(1000);
    Serial.println("Light off");
  }
///////////////////////////////////////////



////////////////FaN/////////////////////
if (fan_state == 0 && Received == '8')  //if fan state is 0 and value receive 8 then tv off mode
  {
    digitalWrite(fan,HIGH);  //on mode
    fan_state=1;
    Received=0;  
    Serial.println("Fan On");
  }
if (fan_state ==1 && Received == '8')  //if fan state is 1 and value receive 8 then fan off mode
  {
    digitalWrite(fan,LOW);  //off mode
    fan_state=0;
    Received=0;
    Serial.println("fan off");
  }

  if(Received == '3'){  //if value received 3 then Fan on mode
    digitalWrite(fan,HIGH);  //on mode
    delay(1000); 
    Serial.println("Fan On");
  }

  if (Received == '4') //if value received 4 then Fan off mode
  {
    digitalWrite(fan,LOW);  //off mode
    delay(1000);
    Serial.println("Fan off");
  }
///////////////////////////////////////////




////////////////tv/////////////////////
if (tv_state == 0 && Received == '9')  //if tv state is 0 and value receive 9 then tv on mode
  {
    digitalWrite(tv,HIGH);  //on mode
    Received=0;  
    Serial.println("tv On");
  }
if (tv_state ==1 && Received == '9')  //if tv state is 1 and value receive 5 then tv off mode
  {
    digitalWrite(tv,LOW); //off mode
    tv_state=0;
    Received=0;
    Serial.println("tv off");
  }
  if(Received == '5'){ //if value receive 5 then TV on mode
    digitalWrite(tv,HIGH);  //on mode
    delay(1000); 
    Serial.println("TV On");
  }

  if (Received == '6')  //if value received 6 then TV off mode
  {
    digitalWrite(tv,LOW);  //off mode
    delay(1000);
    Serial.println("TV off");
  }
///////////////////////////////////////////


 
}
