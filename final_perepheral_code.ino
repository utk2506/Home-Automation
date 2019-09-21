//---------ELECTRONOOBS----------//
//--------BT app control---------//



int light=7;
int fan=6;
int tv = 5;

char Received='0';
int light_state =0;
int fan_state = 0;
int tv_state = 0;


void setup(){
  
  Serial.begin(9600);
  pinMode(fan,OUTPUT);
  pinMode(light,OUTPUT);
  pinMode(tv,OUTPUT);
  
}

void loop(){
 
 if(Serial.available()>0)
 { 
    Received = Serial.read();
    
 }
////////////////LIGHT/////////////////////
if (light_state == 0 && Received == '7')
  {
    digitalWrite(light,HIGH);
    light_state=1;
    Received=0;  
    Serial.println("Light On");
  }
if (light_state ==1 && Received == '7')
  {
    digitalWrite(light,LOW);
    light_state=0;
    Received=0;
    Serial.println("Light off");
  }

  if(Received == '1'){
    digitalWrite(light,HIGH);
    delay(1000); 
    Serial.println("Light On");
  }

  if (Received == '2')
  {
    digitalWrite(light,LOW);
    delay(1000);
    Serial.println("Light off");
  }
///////////////////////////////////////////



////////////////FaN/////////////////////
if (fan_state == 0 && Received == '8')
  {
    digitalWrite(fan,HIGH);
    fan_state=1;
    Received=0;  
    Serial.println("Fan On");
  }
if (fan_state ==1 && Received == '8')
  {
    digitalWrite(fan,LOW);
    fan_state=0;
    Received=0;
    Serial.println("fan off");
  }

  if(Received == '3'){
    digitalWrite(fan,HIGH);
    delay(1000); 
    Serial.println("Fan On");
  }

  if (Received == '4')
  {
    digitalWrite(fan,LOW);
    delay(1000);
    Serial.println("Fan off");
  }
///////////////////////////////////////////




////////////////tv/////////////////////
if (tv_state == 0 && Received == '9')
  {
    digitalWrite(tv,HIGH);
    tv_state=1;
    Received=0;  
    Serial.println("tv On");
  }
if (tv_state ==1 && Received == '9')
  {
    digitalWrite(tv,LOW);
    tv_state=0;
    Received=0;
    Serial.println("tv off");
  }
  if(Received == '5'){
    digitalWrite(tv,HIGH);
    delay(1000); 
    Serial.println("TV On");
  }

  if (Received == '6')
  {
    digitalWrite(tv,LOW);
    delay(1000);
    Serial.println("TV off");
  }
///////////////////////////////////////////


 
}
