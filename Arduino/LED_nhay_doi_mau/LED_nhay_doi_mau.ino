/*
PWM : pulse width modulati;
PIN ~ : PWM
analogWrite(PWM_PIN, value): value :0-255
*/
int red_pin =9, green_pin = 10, blue_pin =11;
int btn_pin = 2;
int counter =0;
void colour_set(int r_colour, int g_colour, int b_colour){
  analogWrite(red_pin, r_colour);
  analogWrite(green_pin, g_colour);
  analogWrite(blue_pin, b_colour);
  pinMode(int_pin, INPUT);
  pinMode(bnt_pin, INPUT);
}
int counter = 0;
void int_counter(){
  if(counter>=256)counter=0;
  counter++;
  Serial.print(counter);
}


void setup() {
  // put your setup code here, to run once:
  pinMode(red_pin, OUTPUT);analogWrite(red_pin, 0);
  pinMode(green_pin, OUTPUT);analogWrite(green_pin, 0);
  pinMode(blue_pin, OUTPUT);analogWrite(blue_pin, 0);
  colour_set(255,197,0);
  pinMode(int_pin, INTPUT);
  attachInterrput(digitalPinToInterrput(btn_pin), int_counter, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
  int c1 = random(0,counter);
  int c2 = random(0,counter);
  int c3 = random(0,counter);
  colour_set(c1,c2,c3);
  delay(1000);

  if(digitalRead(btn_pin)){
    counter++;
    Serial.print(counter);
    delay(500);
  }

}
