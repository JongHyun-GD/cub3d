# PARSING 체크 리스트

### 매개변수
- [x] 매개변수의 개수가 1개인가?

- [x] 매개변수인 map의 경로가 올바른가?

- [x] 파일 확장자가 .cub인가?

### 유형 식별자

- [x] 유형 식별자가 올바른가? (R, NO, SO, ..., S, F, C)

- [x] 유형 식별자 데이터 개수가 올바른가?
>
> - [x] R의 데이터 2개
>	
> - [x] NO, SO, WE, EA, S의 데이터 1개
>	
> - [x] F, C의 데이터 2개~3개

- [x] 유형 식별자의 데이터가 올바른가?
>	
> - [x] width와 height의 값이 너무 크거나 작지 않은가?
>	width 320미만 4096 초과
>	height 200 미만 2160 초과
>
> - [x] texture_path가 올바른가?
>
> - [x] F와 C의 구분자(,) 외에 숫자가 아닌 값이 들어왔는가?
>
> - [x] F와 C의 값이 (0 ~ 255)를 벗어났는가?
>
> - [x] type data 사이에 탭으로 구분 되어 있는가?

### Map

- [x] map이 닫혀있는가?

- [x] 플레이어가 한 명인가?

- [x] check_closed_map에서 위 아래 범위 넘어가면 에러 출력하기
---
# PARSING TODO

- [x] RGB값은 int형 변수에 bit연산해서 넣기

- [x] map_info 구조체에 있는 texture는 path->image로 변환해서 넣기

- [x] char **map에 player는 N, S, W, E가 아닌 숫자로 넣기. ex) 3

- [x] info.p_pos에 플레이어의 현재 위치 받기

- [ ] type_data 추가로 체크 할 케이스가 있는지 생각해보기