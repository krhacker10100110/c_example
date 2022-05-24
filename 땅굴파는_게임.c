#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#define ESC 27
#define LEFT 75
#define RIGHT 77
#define DOWN 80
#define ENTER 13
int current_score = 0;//현재 점수
int best_score = 0;//최고 점수
int coin = 0;//동전 갯수
void gotoxy(int x, int y)
{
	COORD pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}//입력한 좌표로 커서를 이동시켜 주는 함수
void SetColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
enum
{
	BLACK,
	DARK_BLUE,
	DARK_GREEN,
	DARK_SKYBLUE,
	DARK_RED,
	DARK_VIOLET,
	DARK_YELLOW,
	GRAY,
	DARK_GRAY,
	BLUE,
	GREEN,
	SKYBLUE,
	RED,
	VIOLET,
	YELLOW,
	WHITE,
};//색깔 설정 함수 정의
typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;
void setcursortype(CURSOR_TYPE c)
{
	CONSOLE_CURSOR_INFO CurInfo;
	switch (c) {
	case NOCURSOR:
		CurInfo.dwSize = 1;
		CurInfo.bVisible = FALSE;
		break;
	case SOLIDCURSOR:
		CurInfo.dwSize = 100;
		CurInfo.bVisible = TRUE;
		break;
	case NORMALCURSOR:
		CurInfo.dwSize = 20;
		CurInfo.bVisible = TRUE;
		break;
	}
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}//커서 숨기는 함수 정의
void main_screen() {
	system("mode con cols=80 lines=25");
	int x = 23, y = 17;
	gotoxy(x, y);     printf("+--------------------------------+");
	gotoxy(x, y + 1); printf("|           무한의 땅굴          |");
	gotoxy(x, y + 2); printf("+--------------------------------+");//게임 제목
	for (int i = 1; i <= 25; ++i) {
		SetColor(GRAY);
		gotoxy(1, i);
		printf("▼");
		Sleep(20);
	}//왼쪽 화살표 내려옴
	for (int i = 25; i >= 1; --i) {
		SetColor(GRAY);
		gotoxy(78, i);
		printf("▲");
		Sleep(20);
	}//오른쪽 화살표 올라옴
	SetColor(DARK_YELLOW);
	int a = 30, b = 7;
	gotoxy(a, b + 9); printf("        ■■"); Sleep(50);
	gotoxy(a, b + 8); printf("        ■■"); Sleep(50);
	gotoxy(a, b + 7); printf("        ■■"); Sleep(50);
	gotoxy(a, b + 6); printf("        ■■"); Sleep(50);
	gotoxy(a, b + 5); printf("        ■■"); Sleep(50);
	gotoxy(a, b + 4); printf("■      ■■      ■"); Sleep(50);
	gotoxy(a, b + 3); printf(" ■■   ■■   ■■"); Sleep(50);
	gotoxy(a, b + 2); printf("   ■■■■■■■"); Sleep(50);
	gotoxy(a, b + 1); printf("     ■■■■■"); Sleep(50);
	gotoxy(a, b); printf("       ■■■"); Sleep(50); //도끼 그리기
	for (int i = 25; i >= 1; --i) {
		SetColor(BLACK);
		gotoxy(78, i);
		printf("▲");
		Sleep(10);
	}//오른쪽 화살표 지움
	for (int i = 1; i <= 25; ++i) {
		SetColor(BLACK);
		gotoxy(1, i);
		printf("▼");
		Sleep(10);
	}//왼쪽 화살표 지움
	for (int i = 1; i <= 8; ++i) {
		if (i == i) {
			SetColor(BLACK);
			gotoxy(x, y + 3);
			printf("■■■■■■■■■■■■■■■■■■■■■");
		}
		Sleep(60);
		SetColor(RED);
		gotoxy(x, y + 3);
		printf("     <PRESS ANY KEY TO START>");
		Sleep(60);
	}//게임시작법 안내
	getch();
}
int tutorial() {
	system("cls");//화면 초기화 해줌
	system("mode con cols=94 lines=23");//콘솔창 크기 조절
	int x = 4, y = 3;
	gotoxy(x, y); printf("■■■■■ ■      ■ ■■■■■ ■■■■■ ■■■■   ■■■■■     ■     ■");
	gotoxy(x, y + 1); printf("    ■     ■      ■     ■     ■      ■ ■     ■      ■        ■■    ■ ");
	gotoxy(x, y + 2); printf("    ■     ■      ■     ■     ■      ■ ■■■■       ■       ■  ■   ■");
	gotoxy(x, y + 3); printf("    ■     ■      ■     ■     ■      ■ ■  ■         ■      ■■■■  ■");
	gotoxy(x, y + 4); printf("    ■     ■■■■■     ■     ■■■■■ ■   ■■      ■     ■      ■ ■■■■■");
	y = 5;
	SetColor(VIOLET);
	gotoxy(x, y + 7); printf("How to play?");
	SetColor(WHITE);
	gotoxy(x + 20, y + 7); printf("Follow the stairs!!");
	gotoxy(x + 20, y + 9); printf("Press '→' key to move right");
	gotoxy(x + 20, y + 11); printf("Press '←' key to move left");
	gotoxy(x + 20, y + 13); printf("Press '↓' key to move down"); Sleep(700);
	gotoxy(x + 70, y + 7); printf("옷");
	gotoxy(x + 70, y + 8); printf("〓"); Sleep(300);
	gotoxy(x + 72, y + 9); printf("〓");
	gotoxy(x + 70, y + 7); printf(" ");
	gotoxy(x + 72, y + 8); printf("옷"); Sleep(300);
	gotoxy(x + 70, y + 10); printf("〓");
	gotoxy(x + 72, y + 8); printf(" ");
	gotoxy(x + 70, y + 9); printf("옷"); Sleep(300);
	gotoxy(x + 68, y + 11); printf("〓");
	gotoxy(x + 70, y + 9); printf(" ");
	gotoxy(x + 68, y + 10); printf("옷"); Sleep(300);
	gotoxy(x + 68, y + 13); printf("〓");
	gotoxy(x + 68, y + 10); printf(" ");
	gotoxy(x + 68, y + 12); printf("옷"); Sleep(300);
	gotoxy(x + 66, y + 14); printf("〓");
	gotoxy(x + 68, y + 12); printf(" ");
	gotoxy(x + 66, y + 13); printf("옷"); Sleep(300);//게임 플레이 장면 예시 보여주기
	getch();
	return 0;
}
int px = 18, py = 1;//플레이어의 좌표
void player() {
	SetColor(GRAY);
	gotoxy(px, py);
	printf("옷");
}//플레이어 찍어주는 함수
void erase_player() {
	SetColor(BLACK);
	gotoxy(px, py);
	printf("■");
}//이동한 플레이어 지워주는 함수
void player_move() {
	int ch = getch();
	if (0 == ch || 224 == ch)//방향키를 누르면 한번에 두개의 값이 들어오기 때문에 이 조건을 걸어주지 않으면 루프가 두번 돌게된다
		ch = getch();//방향키를 받는다
	switch (ch)
	{
	case LEFT:
		if (px >= 3 && px <= 37 && py >= 1 && py <= 34) {
			erase_player();
			px -= 2;
			py++;
		}
		break;//플레이어 왼쪽으로 이동
	case RIGHT:
		if (px >= 1 && px <= 35 && py >= 1 && py <= 34) {
			erase_player();
			px += 2;
			py++;
		}
		break;//플레이어 오른쪽으로 이동
	case DOWN:
		if (px >= 1 && px <= 37 && py >= 1 && py <= 33) {
			erase_player();
			py += 2;
		}
		break;//플레이어 아래로 이동
	default:
		player();
		break;//아무키도 입력되지 않았을 때
	}
	player();
}//결과적으로 플레이어를 움직이는 함수
void line() {
	for (int i = 1; i <= 35; ++i) {
		SetColor(WHITE);
		gotoxy(38, i); printf("│");
		Sleep(10);
	}
}//화면 칸 나누기
int score() {
	SetColor(WHITE);
	gotoxy(42, 5);
	printf("MY SCORE : %d", current_score);
	gotoxy(42, 10);
	printf("BEST SCORE : %d", best_score);
	gotoxy(42, 15);
	printf("COIN : %d", coin);
	return 0;
}//현재점수와 최고기록 표시
int end_screen() {
	system("cls");
	SetColor(WHITE);
	for (int i = 6; i <= 53; i += 2) {
		gotoxy(i, 6);
		printf("─");
		gotoxy(i, 29);
		printf("─");
	}
	gotoxy(6, 6);
	printf("┌");
	gotoxy(54, 6);
	printf("┐");
	for (int i = 7; i <= 28; ++i) {
		gotoxy(6, i);
		printf("│");
		gotoxy(54, i);
		printf("│");
	}
	gotoxy(6, 29);
	printf("└");
	gotoxy(54, 29);
	printf("┘");
	gotoxy(10, 10); printf("■■■■■ ■      ■ ■■■■■ ■■■■");
	gotoxy(10, 11); printf("■      ■  ■    ■  ■         ■     ■");
	gotoxy(10, 12); printf("■      ■   ■  ■   ■■■■■ ■■■■");
	gotoxy(10, 13); printf("■      ■    ■■    ■         ■ ■");
	gotoxy(10, 14); printf("■■■■■     ■     ■■■■■ ■  ■■");
	if (current_score > best_score) {
		best_score = current_score;
	}
	gotoxy(34, 18);
	printf("SCORE : %d", current_score);//현재점수 출력
	gotoxy(34, 21);
	printf("BEST SCORE : %d", best_score);//최고 점수 출력
	if (current_score >= best_score) {
		SetColor(RED);
		gotoxy(36, 19);
		printf("RECORD BREAKING!!!");
	}//점수 갱신되었을때 출력하는 안내 메세지
	if (0 == 0) {
		SetColor(RED);
		gotoxy(9, 27);
		printf("<PRESS 'ENTER' TO REPLAY>");
	}
	return 0;
}
int sx = 18, sy = 4;
int check_x, check_y;
int stair() {
	int i, num;
	SetColor(WHITE);
	check_x = sx;
	check_y = sy;
	gotoxy(sx, sy);
	printf("〓");//계단 출력
	num = rand() % 3;//0,1,2중 한개의 변수 받기
	if (num == 0 && sx >= 3) {
		sx -= 2;
		sy++;
	}//왼쪽으로 계단 이동
	else if (num == 1 && sx <= 35) {
		sx += 2;
		sy++;
	}//오른쪽으로 계단 이동
	else {
		sy += 2;
	}
	return 0;
}//땅굴 생성하는 함수
int cx, cy, check_c1 = 0, check_c2 = 0;
int coin_score() {
	SetColor(YELLOW);
	int num;
	cx = check_x;
	cy = check_y - 1;//동전 갯수를 세기 위해서 계속 변하는 값인 cx와 cy의 값 대신 조건을 비교 할 변수를 선언함
	num = rand() % 1000;
	if (num % 3 == 0) {
		gotoxy(cx, cy);
		printf("○");
		check_c2 = check_c1;
		check_c1++;//만약 동전이 출력되면 동전갯수도 올려주어야함
	}
	else {
		check_c2 = check_c1;
		check_c1--;//이 값을 줄여주지 않으면 계속 동전 점수가 늘어나기 때문에 줄여줌
	}
	return 0;
}//동전 출력하는 함수
int screen_reset() {
	if (sy == 35 || sy == 34) {
		for (int i = 1; i <= 35; ++i) {
			for (int j = 1; j <= 37; ++j) {
				gotoxy(j, i);
				printf(" ");
			}
		}
		gotoxy(18, 1);
		printf("옷");
		px = 18; py = 1;
		sx = 18; sy = 4;
	}
	return 0;
}//화면 넘어갔을 때 초기화 시키는 함수
int store() {
	system("mode con cols=80 lines=17");//콘솔창 초기화 시키기
	int i, x = 1, y = 4;
	SetColor(RED);
	gotoxy(x + 1, y - 2); printf("Store");
	SetColor(DARK_GRAY);
	gotoxy(x + 65, y - 2); printf("Your Coin : %d", coin);
	SetColor(WHITE);
	for (i = 1; i <= 80; i += 2) {
		gotoxy(x + i - 1, y); printf("─"); Sleep(10);
	}//현재 보유 코인과 store표시 하기
	gotoxy(x + 5, y + 2); printf("You need ");
	SetColor(RED); printf("30"); SetColor(WHITE); printf("coins");
	gotoxy(x + 7, y + 3); printf("to buy this!!");
	gotoxy(x + 11, y + 6); printf("못");
	gotoxy(x + 6, y + 9); printf("If you want to");
	gotoxy(x + 8, y + 10); printf("buy this,");
	gotoxy(x + 3, y + 11); printf("Please Press ");
	SetColor(RED); printf("'→' "); SetColor(WHITE); printf("key");
	gotoxy(x + 31, y + 2); printf("You need ");
	SetColor(RED); printf("35"); SetColor(WHITE); printf("coins");
	gotoxy(x + 33, y + 3); printf("to buy this!!");
	gotoxy(x + 37, y + 6); printf("촛");
	gotoxy(x + 31, y + 9); printf("If you want to");
	gotoxy(x + 33, y + 10); printf("buy this,");
	gotoxy(x + 28, y + 11); printf("Please Press ");
	SetColor(RED); printf("'←' "); SetColor(WHITE); printf("key");
	gotoxy(x + 57, y + 2); printf("You need ");
	SetColor(RED); printf("50"); SetColor(WHITE); printf("coins");
	gotoxy(x + 59, y + 3); printf("to buy this!!");
	gotoxy(x + 63, y + 6); printf("홋");
	gotoxy(x + 57, y + 9); printf("If you want to");
	gotoxy(x + 59, y + 10); printf("buy this,");
	gotoxy(x + 54, y + 11); printf("Please Press ");
	SetColor(RED); printf("'↓' "); SetColor(WHITE); printf("key");
	//////////////////////////////////////캐릭터 바꿔주는 것은 아직 구현하지 못함
	/*int get = getch();
	if (0 == get || 224 == get)//방향키를 누르면 한번에 두개의 값이 들어오기 때문에 이 조건을 걸어주지 않으면 루프가 두번 돌게된다
		get = getch();//방향키를 받는다
	switch (get)
	{
	case RIGHT:
		skin = 1; break;
	case LEFT:
		skin = 2; break;
	case DOWN:
		skin = 3; break;
	}
	*/
	getch();
	return 0;
}
int start_time = 0, end_time, gap = 0;//타이머 기능을 쓰기위해 필요한 변수
int main() {
	//랜덤함수 값이 다양한 값이 나오도록 함
	srand(time(NULL));
	setcursortype(NOCURSOR);
	//게임 첫 화면
	main_screen();
	//게임 설명
	tutorial();
	//게임 다시 시작하기
replay:
	//시스템 화면 초기화
	system("cls");
	//게임 화면 크기 조정
	system("mode con cols=60 lines=35");
	//게임 화면 만들기
	line();
	//점수 화면 찍기
	score();
	//시작 플레이어 찍기
	player();
	SetColor(WHITE);
	//시작 계단
	gotoxy(18, 2);
	printf("〓");
	//게임 플레이 화면
	for (;;) {
		int temp = py;
		stair();//계단 먼저 찍기
		start_time = clock();
		coin_score();//동전 출력하기
		player_move();//플레이어 움직이기
		end_time = clock();
		gap = (int)(end_time - start_time);
		if (gap >= 700) {
			goto game_over;
		}//일정 시간동안 키 입력하지 않으면 게임종료
		if (py>temp) {
			current_score++;
		}//현재 점수 올려주기
		if (px != check_x) {
			goto game_over;
		}//게임 종료하는 조건
		screen_reset();//화면 초기화
		if (check_c1 > check_c2) {
			coin++;
		}//동전 갯수 올리기
		score();
	}
	//게임 종료 됐을때
game_over:
	store();
	system("mode con cols=60 lines=35");//콘솔창 크기 초기화
										//게임 종료
	end_screen();
	//게임종료시 enter키로 게임을 다시 시작함
	if (getch() == ENTER) {
		px = 18, py = 1;
		sx = 18, sy = 4;
		current_score = 0;//게임이 종료 됬으므로 전 게임의 정보를 초기화 해준다
		goto replay;
	}
	//커서 숨기는 것
	getch();
	return 0;
}
