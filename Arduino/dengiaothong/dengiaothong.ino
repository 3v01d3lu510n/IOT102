const int a=3, b=4, c=5, d=6, e=7, f=8, g=9;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i=0;i<10;i++){
    pinMode(i,OUTPUT);
    digitalWrite(i, LOW);
  }
  for(int i=10;i<13;i++){
    pinMode(i,OUTPUT);
    digitalWrite(i, HIGH);
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
unsigned long last_time = millis();
int t=9;
void count_down_1(){
if((millis()-last_time)>1000){
    int t=9;
    last_time = millis();
    t--;
    if(t<0)t=8;
    seg_7(t);
    digitalWrite(10, LOW);
  }
}

void count_down_2(){
if((millis()-last_time)>1000){
    int t=3;
    last_time = millis();
    t--;
    if(t<0)t=3;
    seg_7(t);
    digitalWrite(11, LOW);
  }
}

void count_down_3(){
if((millis()-last_time)>1000){
    int t=9;
    last_time = millis();
    t--;
    if(t<0)t=8;
    seg_7(t);
    digitalWrite(12, LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  count_down_1();
  count_down_2();
  count_down_3();
}