//Robot - Pick & Place

const int  lft_mtr1=5, lft_mtr2=6, rht_mtr1=7, rht_mtr2=8; //Motor Driver Initialization for Robot
const int up_motor=9, down_motor=10, close_motor=11, open_motor=12;   //Motor Driver Initialization for Arm

int forward_flag = 0, backward_flag = 0, right_flag = 0, left_flag = 0, stop_flag = 0;  //For Robot Movement
int up_flag = 0,down_flag = 0, hold_flag = 0;  //Robotic Arm Placement
int open_flag = 0,close_flag = 0; //Robotic Arm Picking and Holding
int cnt=0;

String Vehicle_status= "STOP",Data;

void setup()
{
  Serial.begin(9600); 
  pinMode(lft_mtr1,OUTPUT);
  pinMode(lft_mtr2,OUTPUT);   
  pinMode(rht_mtr1,OUTPUT);
  pinMode(rht_mtr2,OUTPUT);

  pinMode(up_motor,OUTPUT);
  pinMode(down_motor,OUTPUT);   
  pinMode(close_motor,OUTPUT);
  pinMode(open_motor,OUTPUT);
}

void loop() 
{  
  if(Serial.available())
  {
    delay(100);
    char c=Serial.read();

    digitalWrite(lft_mtr1,LOW);
    digitalWrite(lft_mtr2,LOW); 
    
    digitalWrite(rht_mtr1,LOW);
    digitalWrite(rht_mtr2,LOW);

    ///////////////////////////
    
    digitalWrite(up_motor,LOW);
    digitalWrite(down_motor,LOW); 
    
    digitalWrite(close_motor,LOW);
    digitalWrite(open_motor,LOW);

    if(c=='F')
    {
        digitalWrite(lft_mtr1,HIGH);
        digitalWrite(lft_mtr2,LOW);
      
        digitalWrite(rht_mtr1,HIGH);
        digitalWrite(rht_mtr2,LOW);

        Vehicle_status= "FORWARD";
    }

    if(c=='B')
    {
        digitalWrite(lft_mtr1,LOW);
        digitalWrite(lft_mtr2,HIGH);
      
        digitalWrite(rht_mtr1,LOW);
        digitalWrite(rht_mtr2,HIGH);

        Vehicle_status= "BACKWARD";
    }

    if(c=='R')
    {
        digitalWrite(lft_mtr1,HIGH);
        digitalWrite(lft_mtr2,LOW);
      
        digitalWrite(rht_mtr1,LOW);
        digitalWrite(rht_mtr2,HIGH);
        
        Vehicle_status= "RIGHT";
    }

    if(c=='L')
    {
        digitalWrite(lft_mtr1,LOW);
        digitalWrite(lft_mtr2,HIGH);
      
        digitalWrite(rht_mtr1,HIGH);
        digitalWrite(rht_mtr2,LOW);

        Vehicle_status= "LEFT";
    }

    if(c=='S')
    {
        digitalWrite(lft_mtr1,LOW);
        digitalWrite(lft_mtr2,LOW);
      
        digitalWrite(rht_mtr1,LOW);
        digitalWrite(rht_mtr2,LOW);

        Vehicle_status= "STOP";
    }
    
    if(c=='U')
    {
        digitalWrite(down_motor,LOW);
        digitalWrite(up_motor,HIGH);
      
        digitalWrite(close_motor,LOW);
        digitalWrite(open_motor,LOW);

        Vehicle_status= "UP";
    }

    if(c=='D')
    {
        digitalWrite(down_motor,HIGH);
        digitalWrite(up_motor,LOW);
      
        digitalWrite(close_motor,LOW);
        digitalWrite(open_motor,LOW);
  
        Vehicle_status= "DOWN";
    }

    if(c=='H')
    {
        digitalWrite(down_motor,LOW);
        digitalWrite(up_motor,LOW);
      
        digitalWrite(close_motor,LOW);
        digitalWrite(open_motor,LOW);

        Vehicle_status= "HOLD";
    }

    if(c=='O')
    {
        digitalWrite(down_motor,LOW);
        digitalWrite(up_motor,LOW);
      
        digitalWrite(close_motor,LOW);
        digitalWrite(open_motor,HIGH);

        Vehicle_status= "OPEN";
    }

    if(c=='C')
    {
        digitalWrite(down_motor,LOW);
        digitalWrite(up_motor,LOW);
      
        digitalWrite(close_motor,HIGH);
        digitalWrite(open_motor,LOW);

        Vehicle_status= "CLOSE";
    }
      
 Data = "*V" + Vehicle_status +  "+*cnt" + cnt ; 
 Serial.print(Data);
 Serial.println("");
 delay(1000);      
 }
}
