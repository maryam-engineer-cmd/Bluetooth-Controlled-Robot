/*
 * PIC Bluetooth Car Robot - Main Code
 * Microcontroller: PIC16F877A
 * Bluetooth Module: HC-05
 * Motor Driver: L298N (4 DC Motors)
 *
 * Commands received via UART from Android app over HC-05:
 *   F / f -> Forward
 *   B / b -> Backward
 *   L / l -> Left
 *   R / r -> Right
 *   S / s / 0 -> Stop
 *   1-9 -> Speed levels (Slow -> Max)
 */

char hc5;
unsigned short speed = 200;
unsigned int timeout_counter = 0;

void main() {
    UART1_Init(9600);
    Delay_ms(100);

    TRISB = 0b00000000;
    PORTB = 0b00000000;

    TRISD = 0b00000000;
    PORTD = 0b00000000;

    TRISC = 0b10000000;

    PWM1_Init(5000);
    PWM2_Init(5000);

    PWM1_Start();
    PWM2_Start();

    PWM1_Set_Duty(0);
    PWM2_Set_Duty(0);

    Delay_ms(20);

    while (1) {
        if (UART1_Data_Ready() == 1) {
            hc5 = UART1_Read();
            timeout_counter = 0;

            if (hc5 == 'F' || hc5 == 'f') {
                PORTD = 0b00000001; PORTB = 0b00000001;
                PWM1_Set_Duty(speed); PWM2_Set_Duty(speed);
            }
            else if (hc5 == 'B' || hc5 == 'b') {
                PORTD = 0b00000010; PORTB = 0b00000010;
                PWM1_Set_Duty(speed); PWM2_Set_Duty(speed);
            }
            else if (hc5 == 'L' || hc5 == 'l') {
                PORTD = 0b00000010; PORTB = 0b00000001;
                PWM1_Set_Duty(speed); PWM2_Set_Duty(speed);
            }
            else if (hc5 == 'R' || hc5 == 'r') {
                PORTD = 0b00000001; PORTB = 0b00000010;
                PWM1_Set_Duty(speed); PWM2_Set_Duty(speed);
            }
            else if (hc5 == 'S' || hc5 == 's' || hc5 == '0') {
                PORTD = 0b00000000; PORTB = 0b00000000;
                PWM1_Set_Duty(0); PWM2_Set_Duty(0);
            }
            else if (hc5 == '1') speed = 50;
            else if (hc5 == '2') speed = 75;
            else if (hc5 == '3') speed = 125;
            else if (hc5 == '5') speed = 150;
            else if (hc5 == '6') speed = 175;
            else if (hc5 == '7') speed = 200;
            else if (hc5 == '8') speed = 230;
            else if (hc5 == '9') speed = 255;
        }
        else {
            Delay_ms(1);
            timeout_counter++;
            if (timeout_counter > 450) {
                PORTD = 0b00000000;
                PORTB = 0b00000000;
                PWM2_Set_Duty(0);
                timeout_counter = 451;
            }
        }
    }
}
