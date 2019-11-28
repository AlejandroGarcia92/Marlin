#include "chamberFanPWM.h"
#include "Marlin.h"

#define PWM_MAX_PERIOD 5

//Counters
uint8_t dutycycle = 0; //value range 0% to 100;
uint8_t counter_timer = 0; //value range 0% to 100;

//Class call
ChamberFanPWM chamberFanPWM;

//Timer
uint32_t timeelapsed_fan = 0;

void ChamberFanPWM::setup(){

	// Set led pins as output and low
	pinMode(CHAMBER_AUTO_FAN_PIN,OUTPUT);
	
	digitalWrite(CHAMBER_AUTO_FAN_PIN,LOW);
	
	//Setup Timer4 to fire every 1ms
	TCCR4A = 0;// set entire TCCR1A register to 0
	TCCR4B = 0;// same for TCCR1B
	TCNT4  = 0;//initialize counter value to 0
	// set compare match register for 1hz increments
	OCR4A = 500;// = (16*10^6) / (1*1024) - 1 (must be <65536)
	// turn on CTC mode
	TCCR4B |= (1 << WGM12);
	// Set CS12 and CS10 bits for 64 prescaler
	TCCR4B |= (1 << CS11) | (1 << CS10);
	// enable timer compare interrupt
	TIMSK4 |= (1 << OCIE4A);
	
	dutycycle = DEFAULT_DUTYCYCLE_CHAMBER; // 20 %
	timeelapsed_fan = millis();
}

void ChamberFanPWM::setup(uint16_t timer_period){

	// Set led pins as output and low
	pinMode(CHAMBER_AUTO_FAN_PIN,OUTPUT);
	
	digitalWrite(CHAMBER_AUTO_FAN_PIN,LOW);
	
	//Setup Timer4 to fire every 1ms
	TCCR4A = 0;// set entire TCCR1A register to 0
	TCCR4B = 0;// same for TCCR1B
	TCNT4  = 0;//initialize counter value to 0
	// set compare match register for 1hz increments
	OCR4A = timer_period;// = (16*10^6) / (1*1024) - 1 (must be <65536)
	// turn on CTC mode
	TCCR4B |= (1 << WGM12);
	// Set CS12 and CS10 bits for 8 prescaler
	TCCR4B |= (1 << CS11) | (1 << CS10);
	// enable timer compare interrupt
	TIMSK4 |= (1 << OCIE4A);
	
	dutycycle = DEFAULT_DUTYCYCLE_CHAMBER; // 20 %
	timeelapsed_fan = millis();
}


ISR(TIMER4_COMPA_vect) {
	
	if(millis() > timeelapsed_fan + 500)
	{
		if(counter_timer < dutycycle){
			digitalWrite(CHAMBER_AUTO_FAN_PIN,HIGH);
			}else{
			digitalWrite(CHAMBER_AUTO_FAN_PIN,LOW);
		}
		counter_timer++;
		if(counter_timer > PWM_MAX_PERIOD - 1) counter_timer = 0;
	}else{
		digitalWrite(CHAMBER_AUTO_FAN_PIN,HIGH);
	}
	
	
}
void ChamberFanPWM::setDuty(uint8_t duty) {
	
	if(dutycycle != duty){
		//SERIAL_PROTOCOLLNPAIR("New dutycycle: ", duty); //Debug
		timeelapsed_fan = millis();
	}
	dutycycle = duty;
}

