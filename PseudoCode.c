while (1) {
        if (drone_info_parsing_cplt) {  		// 젯슨나노에서 드론을 인식하고 보내준 데이터가 파싱 완료되면 진입
		Drone_info_parsing_cplt = 0;

		if (처음 인식하는 드론인가?) {
			// 피아식별 변수로 iff의 상태는 unknown, friend, foe 중 하나이다. 각각 미확인, 아군, 적기
			iff = unknown;			   
			드론에게 피아식별 패킷 전송( );     // 일정 시간동안 드론에게서 ack 응답이 없을 시 적기로 간주
			Timeout timer set;
		}
		If (iff == friend) {
			Tracking_flag = 0;
		} else {
			Tracking_flag = 1;
		}
	}
	
        if (tracking_flag) {
		PID 제어 TIM on;
		if ((iff == foe) && (격추가능구역 flag)) {
			격추시도();
		} else {
			격추중지();
		}
	} else {				
                격추중지();
                PID 제어 TIM off;
                모터 원위치();
		Moter_Stop();
        }

        if (50ms_flag) {
		50ms_flag = 0;
		모터들의 PID제어;
	}
        
	if (miss_drone) {		// missing drone or destroy drone
		Tracking_flag = 0;
	}
}
