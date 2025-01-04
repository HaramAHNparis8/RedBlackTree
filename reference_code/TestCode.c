#include <stdio.h>
#include <unistd.h> // usleep() 사용을 위한 헤더 파일
#include <string.h> // 문자열 길이를 계산하기 위한 헤더 파일

void typeEffect(const char *text, useconds_t delay) {
    for (size_t i = 0; i < strlen(text); i++) {
        printf("%c", text[i]); // 한 글자씩 출력
        fflush(stdout);        // 즉시 출력
        usleep(delay);         // 지연 시간
    }
    printf("\n"); // 줄바꿈
}

int main() {
    printf("Typing effect starts...\n");

    // 타이핑 효과 적용
    const char *message = "This text appears with a typing effect.";
    typeEffect(message, 100000); // 0.1초(100,000 마이크로초) 딜레이

    printf("Typing effect finished.\n");

    return 0;
}
