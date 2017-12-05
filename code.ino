/*
Relay IN1 connected to PinOut 10 Arduino
Relay IN2 connected to PintOur 11 Arduino
Relay IN3 connected to PintOur 12 Arduino
Relay IN4 connected to PintOur 12 Arduino

--> you can connected to relay modul 4 channel
Serial data sending from Arduino Bluetooth Relay 4CH.apk

data '1'-'4' to on is Relay CH 1-4
data 'A'-'D to off is RElay CH 1-4

data '9' to on ALL CH 1-4
data 'I'to off ALL CH 1-4

*/

int relay1 = 10;
int relay2 = 11;
int relay3 = 12;
int relay4 = 13;

char val;

void setup() {

	pinMode(relay1, OUTPUT);
	pinMode(relay2, OUTPUT);
	pinMode(relay3, OUTPUT);
	pinMode(relay4, OUTPUT);

	digitalWrite(relay1,HIGH);
     digitalWrite(relay2,HIGH);
     digitalWrite(relay3,HIGH);
     digitalWrite(relay4,HIGH);

	Serial.begin(9600);
}

void loop() {
	//check data serial from bluetooth Android App

	while(Serial.available() > 0){
		val = Serial.read();
		Serial.println(val);
     }

	//turn a relay on
	if(val == '1'){
		digitalWrite(relay1,HIGH);			
	}else if(val == '2'){
		digitalWrite(relay2,HIGH);
	}else if(val == '3'){
		digitalWrite(relay3,HIGH);
	}else if(val == '4'){
		digitalWrite(relay4,HIGH);
	}

	//turn all relays on
	if(val == 9){
		digitalWrite(relay1,HIGH);
     	digitalWrite(relay2,HIGH);
     	digitalWrite(relay3,HIGH);
     	digitalWrite(relay4,HIGH);
	}

//turn relay off
	if(val == 'A'){
		digitalWrite(relay1,LOW);			
	}else if(val == '2'){
		digitalWrite(relay2,LOW);
	}else if(val == '3'){
		digitalWrite(relay3,LOW);
	}else if(val == '4'){
		digitalWrite(relay4,LOW);
	}

	//Turn all relays down
	if(val == 9){
		digitalWrite(relay1,LOW);
     	digitalWrite(relay2,LOW);
     	digitalWrite(relay3,LOW);
     	digitalWrite(relay4,LOW);
	}

