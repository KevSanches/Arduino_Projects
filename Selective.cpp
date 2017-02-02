#include <Servo.h>

#define SERVA 3
#define SERVB 5     //Define os pinos aos quais os servos estão conectados
#define SERVC 6
#define SERVD 9
#define SERVE 10

int irPin = 0;
float ir = 0;
char SERVATUAL;     //Container para segurar qual o servo selecionado via serial
int POSATUAL;     //Container para segurar o valor da posição do servo
char RCV[3];      //Array de 3 posições para segurar o valor da posição recebido via serial

Servo servoA;
Servo servoB;
Servo servoC;     //Criação dos servos
Servo servoD;
Servo servoE;

void setup(){
	Serial.begin(9600);
	pinMode(irPin, INPUT);
	servoA.attach(SERVA);
    servoB.attach(SERVB);
    servoC.attach(SERVC);     //Vinculando os servos aos pinos correspondentes
    servoD.attach(SERVD);
    servoE.attach(SERVE);
}

void Select(){
	while((ir = analogRead(irPin))>=1000){} //Values to null
	if (999>=ir>=830){   //Values to black object
		SERVATUAL = Serial.read();      
		routine(70,30,50,90,40);
		routine(170,30,50,90,40);
		routine(170,100,50,90,40);
		routine(170,100,50,90,100);
		routine(70,30,50,90,100);
		routine(70,80,30,50,100);
		routine(0,80,30,50,100);
		servoE.write(40);	
	}
	if (ir<830){ //Values to white object
		SERVATUAL = Serial.read();
		routine(70,30,50,90,40);
		routine(170,30,50,90,40);
		routine(170,100,50,90,40);
		routine(170,100,50,90,100);
		routine(70,30,50,90,100);
		routine(70,80,30,50,100);
		routine(70,80,30,50,40);  
	}
}

void routine(int valA,int valB,int valC,int valD,int valE){     // Send moviments to servo
    servoE.write(valE);                      
    delay(600);
    servoD.write(valD);                  // Os três servos de baixo são movidos devagar
    delay(600);
    servoC.write(valC);
    delay(600);
    servoB.write(valB);
    delay(60);
    servoA.write(valA);
    delay(600);
}

