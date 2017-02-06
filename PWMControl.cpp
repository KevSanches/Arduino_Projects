int baseTBJ = 9;
char command;
int z = 0;

void setup() {
  pinMode(baseTBJ, OUTPUT);
  Serial.begin(9600);
}

int departure(){
  int y = 21;
  for (int x=0; x<256; x++){
    int tempo = millis(); //Assign the "Time" variable with the millis function, which returns the time that has passed since the Arduino is turned on
    while ((millis()-tempo)<y){} //Every time that xx miliseconds has passed:
      Serial.println(x);
      Serial.println(y);
      analogWrite(baseTBJ, x);
      y++;
      z = x;
  }
  return z;
}

void stopper(){
  int y = 100;
  for (int x=255; x>0; x--){
    int tempo = millis(); //Assign the "Time" variable with the millis function, which returns the time that has passed since the Arduino is turned on
    while ((millis()-tempo)<y){} //Every time that xx miliseconds has passed:
      Serial.println(x);
      analogWrite(baseTBJ, x);
      y++;
  }
}

void loop(){ 
  if (Serial.available()){
    command = Serial.read();
    if (command == 'd'){
      int x = departure();
      analogWrite(baseTBJ, x);
    }
    Serial.println("------------------------------------------------------------------------------------------");
    if (command == 's'){
      stopper();
    }
  }
}