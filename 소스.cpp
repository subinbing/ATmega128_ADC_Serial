#define F_CPU 7372800UL

​

#include <avr/io.h>

#include <stdio.h>

#include <util/delay.h>

​

char mess[100] = { 0 };

​

void serial_init(unsigned long baud) {

	unsigned short ubrr;

	//보레이트 설정

	ubrr = (unsigned short)(F_CPU / (16 * baud) - 1);

	UBRR0H = (unsigned char)(ubrr >> 8); //상위 비트

	UBRR0L = (unsigned char)(ubrr & 0xff); //하위 비트

	UCSR0B = 0b00011000; //인터럽트 불가능하게 함,수신부 가능, 송신부 가능

	UCSR0C = 0b00000110; //비동기모드, 패리티비트 사용안함, 정지비트 1비트, 문자크기 8비트

}

​

void ADC_init(void) {

	ADCSRA = 0b11100111; //ADC가능, ADC변환시작, ADC프리러닝모드, ADC인터럽트플래그사용안함, 프리스케일러128

	ADMUX = 0b11000000; //내부기준전압, 오른쪽 정렬, 싱글엔드 입력

}

​

void tx_data(unsigned char data) { //데이터 송신함수

	while ((UCSR0A & 0x20) == 0x00); //data가 비었는지 확인(UDR0에 데이터가 있으면 while문에 멈춰있음)

	UDR0 = data; //tx와 rx 값을 저장하는 레지스터 UDR

}

​

void tx_string(char* str) //UART 문자열 전달 함수 

{ // *string 포인터가 문자열 첫 글자 주소를 가리킴

	while (*str != '\0') // 문자열 끝(null)이 올때까지 이하 내용 수행

	{

		tx_data(*str++); // *str 배열에 저장된 문자 송신하여 값 1증가시켜 다음 문자열 가리킴

	}

}

int main(void) {

	DDRF = 0x00; //포트F 입력 설정

	unsigned char data = 0;

	unsigned int temp = 0, temp_value = 0, light = 0, light_value = 0;

	serial_init(115200);

	ADC_init();

	​

		while (1) {

			if ((UCSR0A & 0x80) == 0x80) //수신이 완료됐을때 UDR0의 데이터를

				data = UDR0; //data에 복사

			if (data == '1') {

				ADMUX = 0b11000000; //내부전압사용, 싱글엔드 입력(ADC0)

				sprintf(mess, "%c:%d\r", data, temp);

				tx_string(mess);

				temp_value = ADC;

				temp = temp_value;

				_delay_ms(30);

			}

			else if (data == '2') {

				ADMUX = 0b11000001; //내부전압사용, 싱글엔드 입력(ADC1)

				sprintf(mess, "%c:%d\r", data, light);

				tx_string(mess);

				light_value = 1023 - ADC;

				light = light_value;

				​

					_delay_ms(30);

			}

		}

	​

}