int btn_pin = 2;//UNO: pin2, 3:Interupt
int counter =0;
void colour_set(){
  
  pinMode(btn_pin, INPUT);
}
int counter = 0;
void int_counter(){
  if(counter>=256)counter=0;
  counter++;
  Serial.print(counter);
}


void setup() {
  // put your setup code here, to run once:
  
  pinMode(btn_pin, INTPUT);
  attachInterrput(digitalPinToInterrput(btn_pin), int_counter, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:

  if(digitalRead(btn_pin)){
    counter++;
    Serial.print(counter);
    delay(500);
  }

}