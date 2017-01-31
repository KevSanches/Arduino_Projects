int baseTBJ = 7;
int PWMPin = 9;
int control = 0;
int PWMControl = 0;

void setup() {
	pinMode(baseTBJ, OUTPUT);
	pinMode(PWMPin, OUTPUT);
	digitalWrite(baseTBJ, HIGH);
	analogWrite(PWMPin, 0);
}

void departure(){
	int time = millis();
	for (int x=0; x<1024; x++){
		if ((millis()-time)>29){
			control = ((x*5)/1024);
			PWMControl = ((control*255)/5);
			analogWrite(PWMPin, PWMControl);
			time = millis();
		}
	}
}

void stop(){
	int time = millis();
	for (int x=1024; x>0; x--){
		if ((millis()-time)>29){
			control = ((x*5)/1024);
			PWMControl = ((control*255)/5);
			analogWrite(PWMPin, PWMControl);
			time = millis();
		}
	}
}

void loop(){ 
	Serial.begin(9600);
	if (Serial.read() == "Stop")
		stop();
}

	
	


