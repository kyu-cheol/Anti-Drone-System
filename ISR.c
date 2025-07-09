// 젯슨나노로부터 드론의 정보를 받아서 parsing
// 좌표, 격추가능 구역 여부
SPI_recevie_ISR
{
	Drone 정보 parsing();
	drone_info_parsing_cplt = 1;
}

// 무선통신 모듈로부터 피아식별 ACK 데이터를 uart통신으로 수신받는다
UART_receive_ISR 
{
	Iff = friend;
	피아식별 타임아웃 타이머 종료();
}

// 피아식별 타임아웃
Timer_expire_ISR 
{
	Iff = foe;
	피아식별 타임아웃 타이머 종료();
}
