01. ADC


1) ADC란?

- Analog-to-Digital Converter

- 연속적인 아날로그 신호를 0과 1로 구성된 디지털 신호로 변환하는 칩

![image](https://user-images.githubusercontent.com/87634136/173390934-d8ea262d-1a16-4e31-b898-c022c8ee38d3.png)


- 10비트 ADC라면 아날로그 전압을 10비트의 디지털 수로 표시함을 의미함

- 즉, 2의 10승으로 1024개 디지털 값으로 분해할 수 있게 됨 (0~1023)

- 1024 분해능 또는 10비트 분해능이라 부름


2) A/D 변환 해야하는 이유

![image](https://user-images.githubusercontent.com/87634136/173390969-48b33e56-e5c6-4ff7-b54e-4f38f1fe8f54.png)


- 컴퓨터는 아날로그를 알아들을 수 없고, 디지털 언어만 알아들을 수 있음

- 컴퓨터에게 입력값을 이해시키기 위해 필요

​

3-1) ADC 과정 (1)

![image](https://user-images.githubusercontent.com/87634136/173391037-ffc5e3ff-1561-4c7d-8da0-b33a7537bd05.png)

- 표본화를 많이 하게 된다면?

: 아날로그 신호와의 일치성은 커지나, 그만큼 샘플링을 많이 했으니 디지털 데이터의 양도 N배로 늘어남

: 샘플링을 N배 늘리면, 데이터의 양도 N배로 늘어남


- 표본화 (Sampling) 

: 일정한 간격으로 아날로그 신호의 값을 추출하는 과정

: 표본화를 함으로써 연속적인 아날로그 시간이 이산시간 신호로 나타내게 됨

* 이산신호 : 별개의 시간 신호


3-2) ADC 과정 (2)

![image](https://user-images.githubusercontent.com/87634136/173391156-c0d1f6f9-09fa-4e92-add9-7a70315797ad.png)

- 양자화 (Quantization)

: 추출한 샘플링 신호의 레벨을 몇 단계로 나타내는 과정

: 표본화 된 값을 구간별 (y축)로 구분하고, 각 구간의 대폿값으로 치환함



- 부호화 (Coding)

: 양자화로 나눈 레벨에 속한 값을 이진수로 변환하는 과정

: 각 구간 별로 이진 부호를 할당하고, 각 샘플을 이진 부호로 변환하면 됨



4) 싱글 엔드 입력과 차동 입력

- 싱글 엔드 입력 

: 신호 접지에 대하여 측정하며, 하나의 입력 신호를 위해 하나의 선이 필요함

![image](https://user-images.githubusercontent.com/87634136/173391213-916f4530-194d-4aeb-a474-ed47f56b7166.png)

- 차동 입력 

: 두 개의 선이 들어가며, 입력 신호는 두 선의 전압 차로 주어짐

: 잡음에 강함 

: 입력 신호 = (signal+) - (signal-)

![image](https://user-images.githubusercontent.com/87634136/173391271-ed527774-c2df-44bc-9c85-bfd1fe6a8fc9.png)

5) ADC 싱글 엔드 입력과 차동 입력 변환

- 싱글 엔드 입력

![image](https://user-images.githubusercontent.com/87634136/173391303-4315d263-5f34-42d2-8b2f-8b761dda298b.png)

V in : 입력 전압

V ref : 기준 전압

ADC : 변환된 디지털 값

- 차동 입력 

![image](https://user-images.githubusercontent.com/87634136/173391339-3801350b-9d01-468f-a2ac-c9ce95f6e999.png)

V pos : "signal+" 단의 입력 전압

V neg : "signal-" 단의 입력 전압

GAIN : 증폭 이득


6) ADC 관련 레지스터

![image](https://user-images.githubusercontent.com/87634136/173391408-4e810db9-8aff-42b7-b020-5460e472e180.png)

![image](https://user-images.githubusercontent.com/87634136/173391465-f1296829-92a0-4ae5-85a9-0a52d65e4ede.png)


7) ADC 클럭 설정

- 10비트 분해능으로 정상적인 동작을 위해서는 50kHz ~ 200kHz 범위의 클럭 사용

- ADCSRA 레지스터의 ADPS2~0 비트에 의하여 2, 4, 8, 16, 32, 64, 128 중의 1가지로 선택

- 프리스케일러는 ADCSRA 레지스터에서 ADEN=1로 설정한 경우에만 동작


02. Serial

1) 직렬 통신

- 직렬 통신 : 하나의 신호선을 통하여 데이터를 전달하는 통신 방법

![image](https://user-images.githubusercontent.com/87634136/173391600-f92b8431-e218-46cb-a490-e1e2bb1cb9da.png)

- 전송 방식에 따라 구분

   * 동기식 통신 방식 : 기준 클럭에 동기를 맞추어 데이터를 순차적으로 전송하는 방식

   * 비동기식 통신 방식 : 동기 클럭 없이 데이터의 전송 속도를 서로 정하여 데이터를 순차적으로 전송하는 방식 

- 모뎀 : 정보 전달을 위해 신호를 변조하여 송신하고 수신측에서 원래의 신호로 복구하기 위해 복조하는 장치

- USART : 직렬 통신 방법으로 데이터를 전달하는 장치로 송신부와 수신부가 각각의 하나의 신호선을 사용함

![image](https://user-images.githubusercontent.com/87634136/173391646-9359ca0e-7ff3-4c82-be8b-9a791b951036.png)


2) 동기 통신과 비동기 통신

- 동기 통신 

: 통신 두 당사자의 시계를 동기시켜 서로 같은 시간을 사용하도록 함

: 같은 시간을 사용하므로 송신부와 수신부 각각에서 프레임 내의 데이터를 구분하는데 오차가 없음

: 신호선이 추가적으로 필요

​

- 비동기 통신 

: 송신부와 수신부가 각각의 시계를 사용하므로 두 시계는 동기되어 있지 않음

: 두 시계가 정확히 서로 일치하지 않아서 프레임 내의 비트를 구분하는 시간 간격이 서로 다름

: 두 시계 간의 오차 무시할 수 있는 경우에 사용

: 신호선 필요 없음

​

3) RS232C

: 현재 모뎀, 컴퓨터 주변 장치와의 입출력 인터페이스로서 널리 사용됨

![image](https://user-images.githubusercontent.com/87634136/173391700-2388e734-7476-4580-9c2d-ad42055df6e7.png)


4) USART의 동작

![image](https://user-images.githubusercontent.com/87634136/173391741-9cd2114d-42fd-44bf-9ceb-57be2afc601d.png)


5) 통신 방식

- 전이중 방식 : 데이터의 송신과 수신을 동시에 할 수 있는 방식

![image](https://user-images.githubusercontent.com/87634136/173391793-38fdc8aa-9ce4-4446-940a-7e6ad79c92eb.png)

- 반이중 방식 : 데이터의 송신과 수신을 동시에 할 수 없는 방식

![image](https://user-images.githubusercontent.com/87634136/173391829-cd0b9f20-a015-4b7f-b166-986cca32d48b.png)


6) 전송 데이터 형식

- 프로토콜

![image](https://user-images.githubusercontent.com/87634136/173391877-f156ddad-952b-4c47-a189-0b62327539f5.png)


7) 패리티 비트(1)

- 정보의 전달 과정에서 오류가 생겼는지를 검사하기 위해 추가된 비트

- 전송하고자 하는 데이터의 끝에 1비트를 더하여 전송하는 방법으로 2가지 종류의 패리티가 (짝수, 홀수)가 있음

- 오류 검출 부호에서 가장 간단한 형태로 쓰임

![image](https://user-images.githubusercontent.com/87634136/173392173-c5714f48-4089-4843-93ce-102f34f6713e.png)

- 실제 전송하고자 하는 8비트의 데이터 외에 추가적으로 패리티 비트 하나를 추가하여 송수신함


8) 패리티 비트(2)

![image](https://user-images.githubusercontent.com/87634136/173392241-c0dd089d-92a2-430d-b866-83b5229907e5.png)


9) Serial 관련 레지스터

![image](https://user-images.githubusercontent.com/87634136/173392042-82480836-f71c-490f-b762-6eadae41f9a8.png)

![image](https://user-images.githubusercontent.com/87634136/173392301-a94293c4-f27f-4eea-b2f1-c6a775997964.png)





