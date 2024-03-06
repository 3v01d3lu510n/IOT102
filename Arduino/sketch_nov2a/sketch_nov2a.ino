const int a=3, b=4, c=5, d=6, e=7, f=8, g=9;
int crossTime =5000;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i=0;i<13;i++){
    pinMode(i,OUTPUT);
    digitalWrite(i, LOW);
  }

}
void num_0(){
  digitalWrite(a, LOW);digitalWrite(b, LOW);
  digitalWrite(c, LOW);digitalWrite(d, LOW);
  digitalWrite(e, LOW);digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
}

void num_1(){
  digitalWrite(a, HIGH);digitalWrite(b, LOW);
  digitalWrite(c, LOW);digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void num_2(){
  digitalWrite(a, LOW);digitalWrite(b, LOW);
  digitalWrite(c, HIGH);digitalWrite(d, LOW);
  digitalWrite(e, LOW);digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
}

void num_3(){
  digitalWrite(a, LOW);digitalWrite(b, LOW);
  digitalWrite(c, LOW);digitalWrite(d, LOW);
  digitalWrite(e, HIGH);digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
}

void num_4(){
  digitalWrite(a, HIGH);digitalWrite(b, LOW);
  digitalWrite(c, LOW);digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void num_5(){
  digitalWrite(a, LOW);digitalWrite(b, HIGH);
  digitalWrite(c, LOW);digitalWrite(d, LOW);
  digitalWrite(e, HIGH);digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void num_6(){
  digitalWrite(a, LOW);digitalWrite(b, HIGH);
  digitalWrite(c, LOW);digitalWrite(d, LOW);
  digitalWrite(e, LOW);digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void num_7(){
  digitalWrite(a, LOW);digitalWrite(b, LOW);
  digitalWrite(c, LOW);digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void num_8(){
  digitalWrite(a, LOW);digitalWrite(b, LOW);
  digitalWrite(c, LOW);digitalWrite(d, LOW);
  digitalWrite(e, LOW);digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void seg_7(int x){
  switch(x){
    case 0:num_0();break;
    case 1:num_1();break;
    case 2:num_2();break;
    case 3:num_3();break;
    case 4:num_4();break;
    case 5:num_5();break;
    case 6:num_6();break;
    case 7:num_7();break;
    case 8:num_8();break;
  }
}
unsigned long change_time = millis();
int y=0;
void change_led(){
  while((millis()-change_time)>1000){
    change_time = millis();
    y++;
    if(y>0&&y<=8){
      digitalWrite(12, LOW);
      digitalWrite(10, HIGH);
    }
    if(y>8&&y<=13){
      digitalWrite(10, LOW);
      digitalWrite(11, HIGH);
    }
    if(y>13&&y<=23){
      digitalWrite(11, LOW);
      digitalWrite(12, HIGH);
    }
    if(y>23){
      y=0;
    }
    break;    
}
}
unsigned long last_time = millis();
int t=8;
int x=0;
int z=0;
void loop() {
  // put your main code here, to run repeatedly:
  while((millis()-last_time)>1000){
    last_time = millis();
    t--;
    
    if(t<0){
      t=3;
      x++;
    }
    if(t<0&&x==2){
      t=9;
      x++;
    }
    seg_7(t);
    if(x==3){
    x=0;
    t=9;
    }
    break;
  }
  change_led();
  
}