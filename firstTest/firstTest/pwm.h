/*
 * pwm.h
 *
 * Created: 12/29/2015 10:36:07 AM
 *  Author: Sili
 */ 


#ifndef PWM_H_
#define PWM_H_

void servo_init(unsigned int f_pwm);
void servo_position1(unsigned char dutyCycle);
void servo_position2(unsigned char dutyCycle);



#endif /* PWM_H_ */