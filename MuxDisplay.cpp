//Author: KevSanches
//Email: kevinsanches@gmail.com
//The circuit to this code can be found in my circuits.io account, Kevin Sanches, or in the following link: https://circuits.io/circuits/2885051-timer-w-display-mux


long tempo=0;
int dezminu=0, dezsegun=0, unminu=0, unsegun=0, minu=0, segun=0, test=0, dezminust=0, unminust=0, dezsegunst=0, unsegunst=0;


int dezminuTBJ = 13;
int unminuTBJ = 12;
int dezsegunTBJ = 11;
int unsegunTBJ = 10;

int SHCP = 8;

int STCP = 7;

int DS = 6;

int MR = 5;

byte simbCC[][7] =  {	{0,1,1,1,1,1,1},   // 0  -->   g,f,e,d,c,b,a - Catodo Comum
				 	{0,0,0,0,1,1,0},   // 1
				 	{1,0,1,1,0,1,1},   // 2
				 	{1,0,0,1,1,1,1},   // 3
				 	{1,1,0,0,1,1,0},   // 4
					{1,1,0,1,1,0,1},   // 5
					{1,1,1,1,1,0,1},   // 6
				  	{0,0,0,0,1,1,1},   // 7
					{1,1,1,1,1,1,1},   // 8
					{1,1,0,1,1,1,1} 	}; // 9

byte simbAC[][7] =  { 	{1,0,0,0,0,0,0},   // 0  -->   g,f,e,d,c,b,a - Anodo Comum
					{1,1,1,1,0,0,1},   // 1
					{0,1,0,0,1,0,0},   // 2
					{0,1,1,0,0,0,0},   // 3
					{0,0,1,1,0,0,1},   // 4
					{0,0,1,0,0,1,0},   // 5
					{0,0,0,0,0,1,0},   // 6
					{1,1,1,1,0,0,0},   // 7
					{0,0,0,0,0,0,0},   // 8
					{0,0,1,0,0,0,0} 	}; // 9
 
void setup(){
	Serial.begin(9600);
  	pinMode(MR, OUTPUT);
  	digitalWrite(MR, HIGH);
	pinMode(DS, OUTPUT);
	pinMode(STCP, OUTPUT);
	pinMode(SHCP, OUTPUT);
	pinMode(dezminuTBJ, OUTPUT);
	pinMode(unminuTBJ, OUTPUT);
	pinMode(dezsegunTBJ, OUTPUT);
	pinMode(unsegunTBJ, OUTPUT);
	program();  // Calls the functions "Program";
	tempo = millis();
}

void loop(){
	control();
	if (Serial.available()>0){    // Lets you decide if you're going to pause it, continue it or reprogram;
		switch(Serial.read()){
			case 'P':
				dezminust = dezminu;
				unminust = unminu;
				dezsegunst = dezsegun;
				unsegunst = unsegun;
			 	pausa();
				break;
			case 'R':			 
				program();
		} 
	} 
}	

void sendDS(int n){
    digitalWrite(6, HIGH);
	clock(8);
	for(int i=0; i<7; i++){
		digitalWrite(6, simbAC[n][i]);
		clock(8);
	}
	clock(7);
}

void dsp(int TBJpin){
    if (TBJpin==13)
    	digitalWrite(10, LOW);
    else 
		digitalWrite(TBJpin+1, LOW);
	digitalWrite(TBJpin, HIGH);
}

void clock(byte pin){
  digitalWrite(pin, LOW);
  digitalWrite(pin, HIGH);
}

void control(void){
	sendDS(dezminu);
	dsp(13);
	POV();
	sendDS(unminu);
	dsp(12);
	POV();
	sendDS(dezsegun);
	dsp(11);
	POV();
	sendDS(unsegun);
	dsp(10);
	POV();    
	atualiza();
}	
	
void pausa(void){
	while (test==0){
		pausestate();
		if (Serial.read()=='C') //Leaves the "Pause" loop;
			test=1;
	}
}  
	
void program(void){
	digitalWrite(10, LOW);
	Serial.print("Type the minutes:");
    while (Serial.available() == 0);
	dezminu = Serial.read()-'0';    // Stores all the data read on the serial port in the dezminu variable, because the Serial.read command already reads the value when it is called. So, it will break the loop once the variable isn't reading -1;
    while (Serial.available() == 0);
	unminu = Serial.read()-'0'; 
	Serial.print("Type the seconds:");
    while (Serial.available() == 0);
	dezsegun = Serial.read()-'0';
	while ((dezsegun)>6){
		Serial.print("Please, don't type a number above 6");
        while (Serial.available() == 0);
		dezsegun = Serial.read()-'0';
	}
    while (Serial.available() == 0);
	unsegun = Serial.read()-'0';
}			

void atualiza(void){
	if ((millis()-tempo) > 1000) {
	tempo = millis();
      Serial.print(dezminu);Serial.print(unminu);Serial.print(':');Serial.print(dezsegun);Serial.println(unsegun);
	  if (--unsegun < 0) {
        if (dezsegun==0)
          unsegun=0;
		unsegun = 9;
		dezsegun--;
        if (dezsegun < 0) {
          if (unminu==0)
            dezsegun = 0;
          dezsegun = 5;
		  if (--unminu < 0){
            if(dezminu == 0)
              unminu = 0;
              else {
		  	    unminu = 9;
				dezminu--;
              }
               if (dezminu < 0)
                 dezminu = 0;
		 }
	   }
	 }
   }
}

void POV(void){
	delay(3);
	//delay(25);
}

void pausestate(void){
	sendDS(dezminust);
	dsp(dezminuTBJ);
	delay(1);
	sendDS(unminust);
	dsp(unminuTBJ);
	delay(1);
	sendDS(dezsegunst);
	dsp(dezsegunTBJ);
	delay(1);
	sendDS(unsegunst);
	dsp(unsegunTBJ);
	delay(1);
}
