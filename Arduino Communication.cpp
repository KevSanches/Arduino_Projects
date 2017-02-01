// SENDER	

void setup() {
  Serial.begin(9600);
}

void loop() {
  char command = 'X'; 
  //IF object reaches place:
  Serial.write(command);
}

//RECEIVER

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
  	char command = Serial.read();	
  	if(command == "X") {
    	//Pick up object
  	}
  }
  //if picked up object:
  Serial.write('Y');
}
