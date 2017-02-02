int irPin = 0;
float ir = 0;

void setup(){
	Serial.begin(9600);
	pinMode(irPin, INPUT);
}

void Select(){
	while((ir = analogRead(irPin))>=1000){} //Values to null
	if (999>=ir>=830){   //Values to black object
		Serial.println('J');
	}
	if (ir<830){ //Values to white object
		Serial.println('K');
	}
}
