int baseTBJ = 7;
int command = 0;

void setup() {
	pinMode(baseTBJ, OUTPUT);
	Serial.begin(9600);
}

void departure(){
	for (int x=200; x<256; x++){
		int time = millis(); //Assign the "Time" variable with the millis function, which returns the time that has passed since the Arduino is turned on
		if ((millis()-time)>20){ //Every time that 5 miliseconds has passed:
			analogWrite(baseTBJ, x);
		}
	}
}

void stop(){
	for (int x=255; x>200; x--){
		int time = millis(); //Assign the "Time" variable with the millis function, which returns the time that has passed since the Arduino is turned on
		if ((millis()-time)>20){ //Every time that 29 miliseconds has passed:
			analogWrite(baseTBJ, x);
		}
	}
}

void loop(){ 
	if (Serial.available()){
		command = Serial.read();
		if (command == 1){
			departure();
		}
		else{
			stop();
		}
	}
}
	
	


