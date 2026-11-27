# Windows 콘솔 CLI 실습

Windows 콘솔에서 문자 한 개가 입력 버퍼와 화면까지 어떻게 전달되는지 C로 살펴본 실습입니다. `uart_win`은 키보드와 콘솔을 UART 형태의 읽기·쓰기 함수로 감쌉니다.

| 경로 | 살펴볼 내용 |
|---|---|
| [src/main.c](src/main.c) · [src/app](src/app) | 프로그램 진입, CLI 초기화, 반복 입력 처리 |
| [src/cli](src/cli) | 한 줄 버퍼, 문자 삽입, Backspace, 콘솔 출력 |
| [src/hw/driver](src/hw/driver) | `_getch()` 입력과 Win32 콘솔 출력, 확장 키용 링 버퍼 |
| [backup](backup) | 비트 연산, 엔디언, 소수 판별 등 독립 C 연습 |

## 빌드

MSVC C 빌드 도구와 CMake 3.16 이상이 있는 Windows 개발자 명령 프롬프트에서 실행합니다.

```powershell
cmake -S . -B build -G "Visual Studio 17 2022"
cmake --build build --config Debug
.\build\Debug\msvc_cli.exe
```

## 현재 구현 범위

문자 삽입과 삭제 로직을 따라가려면 `cliMain()` → `handleCharacterInsert()` 또는 `handleBackspace()` 순서로 읽으면 됩니다. 별도 보완에서 `rx_pop()`이 빈 버퍼에서는 즉시 반환하고 데이터가 있으면 먼저 들어온 바이트를 꺼내도록 수정했습니다. 시작 시 콘솔 핸들을 초기화하고, 방향키 시퀀스가 입력 문자열에 문자로 남지 않게 했습니다. 방향키로 커서를 옮기는 동작은 구현 범위에 포함되지 않습니다. 명령 등록용 `cliAdd()`와 Ctrl 핸들러 설정 함수는 빈 구현입니다. 이 저장소에는 Windows C 실습이 담겨 있습니다.
