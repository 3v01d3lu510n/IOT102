// C++ code
//
/*#define led1 5*/
const int led1 = 1;
//------------------
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for( int i=1;i<9;i++){
    pinMode(i,OUTPUT);
    digitalWrite(i,LOW);
  }

}

void dk_led(char c){
  switch(c){
    case 1:
    digitalWrite(1,HIGH);
    break;
    
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    char c = Serial.read();
    Serial.println(c);
    if(c=='1'){
      digitalWrite(3,HIGH);
    }
    if(c=='C'){
      digitalWrite(3,LOW);
    }
  }

}

