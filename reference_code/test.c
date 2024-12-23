#include <stdio.h>
#include <unistd.h> // sleep()과 usleep() 사용을 위한 헤더 파일
#include <time.h>   // 시간 측정을 위한 헤더 파일

int main() {
    printf("Blinking starts...\n");

    // 시작 시간 기록
    time_t start_time = time(NULL);
    time_t current_time;

    // 5초 동안 깜박임 지속
    do {
        printf("\033[5mThis text is blinking.\033[0m\r"); // 깜박임 출력
        fflush(stdout); // 즉시 출력 -> 터미널에 데이터를 전송하는 명령어
        usleep(500000); // 0.5초 대기

        printf("                        \r"); // 깜박임 지우기
        fflush(stdout); // 즉시 출력
        usleep(500000); // 0.5초 대기

        current_time = time(NULL); // 현재 시간 업데이트
    } while (current_time - start_time < 5); // 5초가 지나면 종료

    // 깜박임 멈추고 일반 텍스트 출력
    printf("Blinking stopped. This is normal text.\n");

    return 0;
}
