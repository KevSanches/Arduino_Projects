int baseTBJ = 7;
int control = 0;
int PWMControl = 0;

void setup() {
	pinMode(baseTBJ, OUTPUT);
	Serial.begin(9600);
}

void departure(){
	int time = millis(); //Assign the "Time" variable with the millis function, which returns the time that has passed since the Arduino is turned on
	for (int x=0; x<512; x++){
		if ((millis()-time)>5){ //Every time that 29 miliseconds has passed:
			control = ((x*5)/1024);//Creates a control, so that the departure can be gradative
			PWMControl = ((control*255)/5); //Variable which will return the PWM value
			analogWrite(baseTBJ, PWMControl);
			time = millis();
		}
	}
	for (int x=512; x<1024; x++){
		if ((millis()-time)>19){ //Every time that 29 miliseconds has passed:
			control = ((x*5)/1024);//Creates a control, so that the departure can be gradative
			PWMControl = ((control*255)/5); //Variable which will return the PWM value
			analogWrite(baseTBJ, PWMControl);
			time = millis();
		}
	}
}

void stop(){
	int time = millis(); //Assign the "Time" variable with the millis function, which returns the time that has passed since the Arduino is turned on
	for (int x=1024; x>512; x--){
		if ((millis()-time)>19){ //Every time that 29 miliseconds has passed:
			control = ((x*5)/1024);//Creates a control, so that the departure can be gradative
			PWMControl = ((control*255)/5); //Variable which will return the PWM value
			analogWrite(baseTBJ, PWMControl);
			time = millis();
		}
	}
	for (int x=512; x>0; x--){
		if ((millis()-time)>5){ //Every time that 29 miliseconds has passed:
			control = ((x*5)/1024);//Creates a control, so that the departure can be gradative
			PWMControl = ((control*255)/5); //Variable which will return the PWM value
			analogWrite(baseTBJ, PWMControl);
			time = millis();
		}
	}
}

void loop(){ 
	if (Serial.read() == "Stop")
		stop();
	else{
		departure();
	}
}

	
	


