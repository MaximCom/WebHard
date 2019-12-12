#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

void move_cur(int x, int y);
int getch(void);
void maximcom();
void smainPage();
void sPage1();
void sPage2();
void sPage3();
void filecontrol();
void joincontrol();
void logcontrol();
void fileimage();
void joinimage();
void logimage();
int choice();

void move_cur(int x, int y) { // 커서이동 함수
	printf("\033[%dd\033[%dG", y, x);
}
int getch(void) { // 입력함수
	int ch;
	struct termios buf, save;
	tcgetattr(0, &save);
	buf=save;
	buf.c_lflag &= ~(ICANON|ECHO);
	buf.c_cc[VMIN] = 1;
	buf.c_cc[VTIME] = 0;
	tcsetattr(0, TCSAFLUSH, &buf);
	ch = getchar();
	tcsetattr(0, TCSAFLUSH, &save);
	return ch;
}
void maximcom() { // maximcom 글씨 함수
	move_cur(24, 14);
	printf("●");
	move_cur(25, 13);
	printf("●");
	move_cur(26, 12);
	printf("●");
	move_cur(27, 11);
	printf("●");
	move_cur(28, 10);
	printf("●");
	move_cur(29, 11);
	printf("●");
	move_cur(30, 12);
	printf("●");
	move_cur(30, 13);
	printf("●");
	move_cur(31, 11);
	printf("●");
	move_cur(32, 10);
	printf("●");
	move_cur(33, 11);
	printf("●");
	move_cur(34, 12);
	printf("●");
	move_cur(35, 13);
	printf("●");
	move_cur(36, 14);
	printf("●");
	// A
	move_cur(38, 14);
	printf("●");
	move_cur(39, 13);
	printf("●");
	move_cur(40, 12);
	printf("●");
	move_cur(41, 11);
	printf("●");
	move_cur(42, 10);
	printf("●");
	move_cur(43, 11);
	printf("●");
	move_cur(44, 12);
	printf("●");
	move_cur(45, 13);
	printf("●");
	move_cur(46, 14);
	printf("●");
	move_cur(41, 13);
	printf("●");
	move_cur(43, 13);
	printf("●");
	// X
	move_cur(48, 14);
	printf("●");
	move_cur(50, 13);
	printf("●");
	move_cur(52, 12);
	printf("●");
	move_cur(54, 11);
	printf("●");
	move_cur(56, 10);
	printf("●");
	move_cur(48, 10);
	printf("●");
	move_cur(50, 11);
	printf("●");
	move_cur(52, 12);
	printf("●");
	move_cur(54, 13);
	printf("●");
	move_cur(56, 14);
	printf("●");
	// I
	move_cur(59, 10);
	printf("●");
	move_cur(61, 10);
	printf("●");
	move_cur(63, 10);
	printf("●");
	move_cur(61, 11);
	printf("●");
	move_cur(61, 12);
	printf("●");
	move_cur(61, 13);
	printf("●");
	move_cur(59, 14);
	printf("●");
	move_cur(61, 14);
	printf("●");
	move_cur(63, 14);
	printf("●");
	// M
	move_cur(66, 14);
	printf("●");
	move_cur(67, 13);
	printf("●");
	move_cur(68, 12);
	printf("●");
	move_cur(69, 11);
	printf("●");
	move_cur(70, 10);
	printf("●");
	move_cur(71, 11);
	printf("●");
	move_cur(72, 12);
	printf("●");
	move_cur(73, 11);
	printf("●");
	move_cur(74, 10);
	printf("●");
	move_cur(75, 11);
	printf("●");
	move_cur(76, 12);
	printf("●");
	move_cur(77, 13);
	printf("●");
	move_cur(78, 14);
	printf("●");
	move_cur(72, 13);
	printf("●");
	// C
	move_cur(80, 12);
	printf("●");
	move_cur(81, 11);
	printf("●");
	move_cur(81, 13);
	printf("●");
	move_cur(81, 11);
	printf("●");
	move_cur(83, 10);
	printf("●");
	move_cur(85, 10);
	printf("●");
	move_cur(87, 10);
	printf("●");
	move_cur(83, 14);
	printf("●");
	move_cur(85, 14);
	printf("●");
	move_cur(87, 14);
	printf("●");
	// O
	move_cur(91, 11);
	printf("●");
	move_cur(91, 12);
	printf("●");
	move_cur(91, 13);
	printf("●");
	move_cur(99, 11);
	printf("●");
	move_cur(99, 12);
	printf("●");
	move_cur(99, 13);
	printf("●");
	move_cur(93, 10);
	printf("●");
	move_cur(95, 10);
	printf("●");
	move_cur(97, 10);
	printf("●");
	move_cur(93, 14);
	printf("●");
	move_cur(95, 14);
	printf("●");
	move_cur(97, 14);
	printf("●");
	// M
	move_cur(101, 14);
	printf("●");
	move_cur(102, 13);
	printf("●");
	move_cur(103, 12);
	printf("●");
	move_cur(104, 11);
	printf("●");
	move_cur(105, 10);
	printf("●");
	move_cur(106, 11);
	printf("●");
	move_cur(107, 12);
	printf("●");
	move_cur(108, 11);
	printf("●");
	move_cur(109, 10);
	printf("●");
	move_cur(110, 11);
	printf("●");
	move_cur(111, 12);
	printf("●");
	move_cur(112, 13);
	printf("●");
	move_cur(113, 14);
	printf("●");
	move_cur(107, 13);
	printf("●");
}

void fileimage() {
	move_cur(36, 34);
	printf("■");
	move_cur(34, 34);
	printf("■");
	move_cur(32, 34);
	printf("■");
	move_cur(30, 34);
	printf("■");
	move_cur(28, 34);
	printf("■");
	move_cur(28, 33);
	printf("■");
	move_cur(28, 32);
	printf("■");
	move_cur(28, 31);
	printf("■");
	move_cur(28, 30);
	printf("■");
	move_cur(28, 29);
	printf("■");
	move_cur(28, 28);
	printf("■");
	move_cur(36, 33);
	printf("■");
	move_cur(36, 32);
	printf("■");
	move_cur(36, 31);
	printf("■");
	move_cur(36, 30);
	printf("■");
	move_cur(34, 29);
	printf("■");
	move_cur(32, 28);
	printf("■");
	move_cur(30, 28);
	printf("■");
	move_cur(26, 32);
	printf("■");
	move_cur(24, 32);
	printf("■");
	move_cur(22, 32);
	printf("■");
	move_cur(22, 31);
	printf("■");
	move_cur(22, 30);
	printf("■");
	move_cur(22, 29);
	printf("■");
	move_cur(22, 28);
	printf("■");
	move_cur(22, 27);
	printf("■");
	move_cur(22, 26);
	printf("■");
	move_cur(24, 26);
	printf("■");
	move_cur(26, 26);
	printf("■");
	move_cur(28, 26);
	printf("■");
	move_cur(30, 26);
	printf("■");
	move_cur(30, 27);
	printf("■");
	move_cur(20, 30);
	printf("■");
	move_cur(18, 30);
	printf("■");
	move_cur(16, 30);
	printf("■");
	move_cur(16, 29);
	printf("■");
	move_cur(16, 28);
	printf("■");
	move_cur(16, 27);
	printf("■");
	move_cur(16, 26);
	printf("■");
	move_cur(16, 25);
	printf("■");
	move_cur(16, 24);
	printf("■");
	move_cur(18, 24);
	printf("■");
	move_cur(20, 24);
	printf("■");
	move_cur(22, 24);
	printf("■");
	move_cur(24, 24);
	printf("■");
	move_cur(24, 25);
	printf("■");
}
void joinimage() {
	move_cur(63, 22);
	printf("■");
	move_cur(65, 22);
	printf("■");
	move_cur(67, 22);
	printf("■");
	move_cur(69, 22);
	printf("■");
	move_cur(71, 22);
	printf("■");
	move_cur(63, 24);
	printf("■");
	move_cur(65, 24);
	printf("■");
	move_cur(67, 24);
	printf("■");
	move_cur(69, 24);
	printf("■");
	move_cur(71, 24);
	printf("■");
	move_cur(57, 23);
	printf("■");
	move_cur(59, 23);
	printf("■");
	move_cur(61, 23);
	printf("■");
	move_cur(63, 23);
	printf("■");
	move_cur(71, 23);
	printf("■");
	move_cur(73, 23);
	printf("■");
	move_cur(75, 23);
	printf("■");
	move_cur(77, 23);
	printf("■");
	move_cur(57, 24);
	printf("■");
	move_cur(57, 25);
	printf("■");
	move_cur(57, 26);
	printf("■");
	move_cur(57, 27);
	printf("■");
	move_cur(57, 28);
	printf("■");
	move_cur(57, 29);
	printf("■");
	move_cur(57, 30);
	printf("■");
	move_cur(57, 31);
	printf("■");
	move_cur(57, 32);
	printf("■");
	move_cur(57, 33);
	printf("■");
	move_cur(57, 34);
	printf("■");
	move_cur(57, 35);
	printf("■");
	move_cur(77, 24);
	printf("■");
	move_cur(77, 26);
	printf("■");
	move_cur(77, 27);
	printf("■");
	move_cur(77, 28);
	printf("■");
	move_cur(77, 29);
	printf("■");
	move_cur(77, 30);
	printf("■");
	move_cur(77, 31);
	printf("■");
	move_cur(77, 32);
	printf("■");
	move_cur(77, 33);
	printf("■");
	move_cur(77, 34);
	printf("■");
	move_cur(77, 35);
	printf("■");
	move_cur(59, 35);
	printf("■");
	move_cur(61, 35);
	printf("■");
	move_cur(63, 35);
	printf("■");
	move_cur(65, 35);
	printf("■");
	move_cur(67, 35);
	printf("■");
	move_cur(69, 35);
	printf("■");
	move_cur(71, 35);
	printf("■");
	move_cur(73, 35);
	printf("■");
	move_cur(75, 35);
	printf("■");
	move_cur(61, 27);
	printf("■");
	move_cur(63, 27);
	printf("■");
	move_cur(65, 27);
	printf("■");
	move_cur(67, 27);
	printf("■");
	move_cur(69, 27);
	printf("■");
	move_cur(61, 29);
	printf("■");
	move_cur(63, 29);
	printf("■");
	move_cur(65, 29);
	printf("■");
	move_cur(67, 29);
	printf("■");
	move_cur(69, 29);
	printf("■");
	move_cur(61, 31);
	printf("■");
	move_cur(63, 31);
	printf("■");
	move_cur(65, 31);
	printf("■");
	move_cur(67, 31);
	printf("■");
	move_cur(69, 31);
	printf("■");
	move_cur(71, 26);
	printf("\x1b[34m■");
	move_cur(77, 25);
	printf("■");
	move_cur(73, 27);
	printf("■");
	move_cur(75, 26);
	printf("■");
	move_cur(79, 24);
	printf("■\x1b[0m");
}
void logimage() {
	move_cur(101, 23);
	printf("■");
	move_cur(101, 24);
	printf("■");
	move_cur(101, 25);
	printf("■");
	move_cur(101, 26);
	printf("■");
	move_cur(101, 27);
	printf("■");
	move_cur(101, 33);
	printf("■");
	move_cur(101, 34);
	printf("■");
	move_cur(103, 34);
	printf("■");
	move_cur(105, 34);
	printf("■");
	move_cur(107, 34);
	printf("■");
	move_cur(109, 34);
	printf("■");
	move_cur(111, 34);
	printf("■");
	move_cur(113, 34);
	printf("■");
	move_cur(115, 34);
	printf("■");
	move_cur(115, 23);
	printf("■");
	move_cur(115, 24);
	printf("■");
	move_cur(115, 25);
	printf("■");
	move_cur(115, 26);
	printf("■");
	move_cur(115, 27);
	printf("■");
	move_cur(115, 33);
	printf("■");
	move_cur(103, 23);
	printf("■");
	move_cur(105, 23);
	printf("■");
	move_cur(107, 23);
	printf("■");
	move_cur(109, 23);
	printf("■");
	move_cur(111, 23);
	printf("■");
	move_cur(113, 23);
	printf("■");
	move_cur(97, 28);
	printf("■");
	move_cur(99, 28);
	printf("■");
	move_cur(101, 28);
	printf("■");
	move_cur(103, 28);
	printf("■");
	move_cur(105, 28);
	printf("■");
	move_cur(107, 28);
	printf("■");
	move_cur(109, 28);
	printf("■");
	move_cur(111, 28);
	printf("■");
	move_cur(113, 28);
	printf("■");
	move_cur(115, 28);
	printf("■");
	move_cur(117, 28);
	printf("■");
	move_cur(119, 28);
	printf("■");
	move_cur(97, 32);
	printf("■");
	move_cur(99, 32);
	printf("■");
	move_cur(101, 32);
	printf("■");
	move_cur(103, 32);
	printf("■");
	move_cur(105, 32);
	printf("■");
	move_cur(107, 32);
	printf("■");
	move_cur(109, 32);
	printf("■");
	move_cur(111, 32);
	printf("■");
	move_cur(113, 32);
	printf("■");
	move_cur(115, 32);
	printf("■");
	move_cur(117, 32);
	printf("■");
	move_cur(119, 32);
	printf("■");
	move_cur(97, 29);
	printf("■");
	move_cur(97, 30);
	printf("■");
	move_cur(97, 31);
	printf("■");
	move_cur(119, 29);
	printf("■");
	move_cur(119, 30);
	printf("■");
	move_cur(119, 31);
	printf("■");
	move_cur(106, 30);
	printf("L O G");
}

void smainPage() {	
printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");	
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃        ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓       ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓       ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓      ┃\n");
printf("┃        ┃                                ┃       ┃                                ┃       ┃                                ┃      ┃\n");
printf("┃        ┃                                ┃       ┃                                ┃       ┃                                ┃      ┃\n");
printf("┃        ┃                                ┃       ┃                                ┃       ┃                                ┃      ┃\n");
printf("┃        ┃                                ┃       ┃                                ┃       ┃                                ┃      ┃\n");
printf("┃        ┃                                ┃       ┃                                ┃       ┃                                ┃      ┃\n");
printf("┃        ┃                                ┃       ┃                                ┃       ┃                                ┃      ┃\n");
printf("┃        ┃                                ┃       ┃                                ┃       ┃                                ┃      ┃\n");
printf("┃        ┃                                ┃       ┃                                ┃       ┃                                ┃      ┃\n");
printf("┃        ┃                                ┃       ┃                                ┃       ┃                                ┃      ┃\n");
printf("┃        ┃                                ┃       ┃                                ┃       ┃                                ┃      ┃\n");
printf("┃        ┃                                ┃       ┃                                ┃       ┃                                ┃      ┃\n");
printf("┃        ┃                                ┃       ┃                                ┃       ┃                                ┃      ┃\n");
printf("┃        ┃                                ┃       ┃                                ┃       ┃                                ┃      ┃\n");
printf("┃        ┃                                ┃       ┃                                ┃       ┃                                ┃      ┃\n");
printf("┃        ┃                                ┃       ┃                                ┃       ┃                                ┃      ┃\n");
printf("┃        ┃                                ┃       ┃                                ┃       ┃                                ┃      ┃\n");
printf("┃        ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛       ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛       ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛      ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
maximcom();
fileimage();
joinimage();
logimage();
move_cur(18, 39);
printf("<< 파 일 관 리 >>");
move_cur(60, 39);
printf("<< 회 원 관 리 >>");
move_cur(100, 39);
printf("<< 로 그 관 리 >>");
}
void sPage1() {	
printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");	
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃        ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓       \x1b[2;37m┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓       ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓   \x1b[0m   ┃\n");
printf("┃        ┃                                ┃       \x1b[2;37m┃                                ┃       ┃                                ┃\x1b[0m      ┃\n");
printf("┃        ┃                                ┃       \x1b[2;37m┃                                ┃       ┃                                ┃\x1b[0m      ┃\n");
printf("┃        ┃                                ┃       \x1b[2;37m┃                                ┃       ┃                                ┃\x1b[0m      ┃\n");
printf("┃        ┃                                ┃       \x1b[2;37m┃                                ┃       ┃                                ┃\x1b[0m      ┃\n");
printf("┃        ┃                                ┃       \x1b[2;37m┃                                ┃       ┃                                ┃\x1b[0m      ┃\n");
printf("┃        ┃                                ┃       \x1b[2;37m┃                                ┃       ┃                                ┃\x1b[0m      ┃\n");
printf("┃        ┃                                ┃       \x1b[2;37m┃                                ┃       ┃                                ┃\x1b[0m      ┃\n");
printf("┃        ┃                                ┃       \x1b[2;37m┃                                ┃       ┃                                ┃\x1b[0m      ┃\n");
printf("┃        ┃                                ┃       \x1b[2;37m┃                                ┃       ┃                                ┃\x1b[0m      ┃\n");
printf("┃        ┃                                ┃       \x1b[2;37m┃                                ┃       ┃                                ┃\x1b[0m      ┃\n");
printf("┃        ┃                                ┃       \x1b[2;37m┃                                ┃       ┃                                ┃\x1b[0m      ┃\n");
printf("┃        ┃                                ┃       \x1b[2;37m┃                                ┃       ┃                                ┃\x1b[0m      ┃\n");
printf("┃        ┃                                ┃       \x1b[2;37m┃                                ┃       ┃                                ┃\x1b[0m      ┃\n");
printf("┃        ┃                                ┃       \x1b[2;37m┃                                ┃       ┃                                ┃\x1b[0m      ┃\n");
printf("┃        ┃                                ┃       \x1b[2;37m┃                                ┃       ┃                                ┃\x1b[0m      ┃\n");
printf("┃        ┃                                ┃       \x1b[2;37m┃                                ┃       ┃                                ┃\x1b[0m      ┃\n");
printf("┃        ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛       \x1b[2;37m┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛       ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\x1b[0m      ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
maximcom();
printf("\x1b[5m");
fileimage();
printf("\x1b[0m");
printf("\x1b[2;37m");
joinimage();
printf("\x1b[0m");
printf("\x1b[2;37m");
logimage();
printf("\x1b[0m");
move_cur(18, 39);
printf("<< 파 일 관 리 >>");
move_cur(60, 39);
printf("<< 회 원 관 리 >>");
move_cur(100, 39);
printf("<< 로 그 관 리 >>");
}
void sPage2() {	
printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");	
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃        \x1b[2;37m┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\x1b[0m       ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓       \x1b[2;37m┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\x1b[0m      ┃\n");
printf("┃        \x1b[2;37m┃                                ┃\x1b[0m       ┃                                ┃       \x1b[2;37m┃                                ┃\x1b[0m      ┃\n");
printf("┃        \x1b[2;37m┃                                ┃\x1b[0m       ┃                                ┃       \x1b[2;37m┃                                ┃\x1b[0m      ┃\n");
printf("┃        \x1b[2;37m┃                                ┃\x1b[0m       ┃                                ┃       \x1b[2;37m┃                                ┃\x1b[0m      ┃\n");
printf("┃        \x1b[2;37m┃                                ┃\x1b[0m       ┃                                ┃       \x1b[2;37m┃                                ┃\x1b[0m      ┃\n");
printf("┃        \x1b[2;37m┃                                ┃\x1b[0m       ┃                                ┃       \x1b[2;37m┃                                ┃\x1b[0m      ┃\n");
printf("┃        \x1b[2;37m┃                                ┃\x1b[0m       ┃                                ┃       \x1b[2;37m┃                                ┃\x1b[0m      ┃\n");
printf("┃        \x1b[2;37m┃                                ┃\x1b[0m       ┃                                ┃       \x1b[2;37m┃                                ┃\x1b[0m      ┃\n");
printf("┃        \x1b[2;37m┃                                ┃\x1b[0m       ┃                                ┃       \x1b[2;37m┃                                ┃\x1b[0m      ┃\n");
printf("┃        \x1b[2;37m┃                                ┃\x1b[0m       ┃                                ┃       \x1b[2;37m┃                                ┃\x1b[0m      ┃\n");
printf("┃        \x1b[2;37m┃                                ┃\x1b[0m       ┃                                ┃       \x1b[2;37m┃                                ┃\x1b[0m      ┃\n");
printf("┃        \x1b[2;37m┃                                ┃\x1b[0m       ┃                                ┃       \x1b[2;37m┃                                ┃\x1b[0m      ┃\n");
printf("┃        \x1b[2;37m┃                                ┃\x1b[0m       ┃                                ┃       \x1b[2;37m┃                                ┃\x1b[0m      ┃\n");
printf("┃        \x1b[2;37m┃                                ┃\x1b[0m       ┃                                ┃       \x1b[2;37m┃                                ┃\x1b[0m      ┃\n");
printf("┃        \x1b[2;37m┃                                ┃\x1b[0m       ┃                                ┃       \x1b[2;37m┃                                ┃\x1b[0m      ┃\n");
printf("┃        \x1b[2;37m┃                                ┃\x1b[0m       ┃                                ┃       \x1b[2;37m┃                                ┃\x1b[0m      ┃\n");
printf("┃        \x1b[2;37m┃                                ┃\x1b[0m       ┃                                ┃       \x1b[2;37m┃                                ┃\x1b[0m      ┃\n");
printf("┃        \x1b[2;37m┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\x1b[0m       ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛       \x1b[2;37m┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\x1b[0m      ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
maximcom();
printf("\x1b[2;37m");
fileimage();
printf("\x1b[0m");
printf("\x1b[5m");
joinimage();
printf("\x1b[0m");
printf("\x1b[2;37m");
logimage();
printf("\x1b[0m");
move_cur(18, 39);
printf("<< 파 일 관 리 >>");
move_cur(60, 39);
printf("<< 회 원 관 리 >>");
move_cur(100, 39);
printf("<< 로 그 관 리 >>");
}
void sPage3() {	
printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");	
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃        \x1b[2;37m┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓       ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\x1b[0m       ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓      ┃\n");
printf("┃        \x1b[2;37m┃                                ┃       ┃                                ┃\x1b[0m       ┃                                ┃      ┃\n");
printf("┃        \x1b[2;37m┃                                ┃       ┃                                ┃\x1b[0m       ┃                                ┃      ┃\n");
printf("┃        \x1b[2;37m┃                                ┃       ┃                                ┃\x1b[0m       ┃                                ┃      ┃\n");
printf("┃        \x1b[2;37m┃                                ┃       ┃                                ┃\x1b[0m       ┃                                ┃      ┃\n");
printf("┃        \x1b[2;37m┃                                ┃       ┃                                ┃\x1b[0m       ┃                                ┃      ┃\n");
printf("┃        \x1b[2;37m┃                                ┃       ┃                                ┃\x1b[0m       ┃                                ┃      ┃\n");
printf("┃        \x1b[2;37m┃                                ┃       ┃                                ┃\x1b[0m       ┃                                ┃      ┃\n");
printf("┃        \x1b[2;37m┃                                ┃       ┃                                ┃\x1b[0m       ┃                                ┃      ┃\n");
printf("┃        \x1b[2;37m┃                                ┃       ┃                                ┃\x1b[0m       ┃                                ┃      ┃\n");
printf("┃        \x1b[2;37m┃                                ┃       ┃                                ┃\x1b[0m       ┃                                ┃      ┃\n");
printf("┃        \x1b[2;37m┃                                ┃       ┃                                ┃\x1b[0m       ┃                                ┃      ┃\n");
printf("┃        \x1b[2;37m┃                                ┃       ┃                                ┃\x1b[0m       ┃                                ┃      ┃\n");
printf("┃        \x1b[2;37m┃                                ┃       ┃                                ┃\x1b[0m       ┃                                ┃      ┃\n");
printf("┃        \x1b[2;37m┃                                ┃       ┃                                ┃\x1b[0m       ┃                                ┃      ┃\n");
printf("┃        \x1b[2;37m┃                                ┃       ┃                                ┃\x1b[0m       ┃                                ┃      ┃\n");
printf("┃        \x1b[2;37m┃                                ┃       ┃                                ┃\x1b[0m       ┃                                ┃      ┃\n");
printf("┃        \x1b[2;37m┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛       ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\x1b[0m       ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛      ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
maximcom();
printf("\x1b[2;37m");
fileimage();
joinimage();
printf("\x1b[0m");
printf("\x1b[5m");
logimage();
printf("\x1b[0m");
move_cur(18, 39);
printf("<< 파 일 관 리 >>");
move_cur(60, 39);
printf("<< 회 원 관 리 >>");
move_cur(100, 39);
printf("<< 로 그 관 리 >>");
}

void filecontrol() {
printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");	
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
move_cur(51, 8);
printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
move_cur(51,9);
printf("┃                                ┃");
move_cur(51,10);
printf("┃                                ┃");
move_cur(51,11);
printf("┃                                ┃");
move_cur(51,12);
printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
move_cur(59,10);
printf("★  File Control ★\n");
move_cur(33,15);
printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
for (int i=16; i<38; i++) {
	move_cur(33, i);
	printf("┃                                                                  ┃");
}
move_cur(33,38);
printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");

printf("\n");
}
void joincontrol() {
printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");	
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
move_cur(51, 8);
printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
move_cur(51,9);
printf("┃                                ┃");
move_cur(51,10);
printf("┃                                ┃");
move_cur(51,11);
printf("┃                                ┃");
move_cur(51,12);
printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
move_cur(54,10);
printf("★  Joinmembership Control  ★\n");
move_cur(33,15);
printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
for (int i=16; i<38; i++) {
	move_cur(33, i);
	printf("┃                                                                  ┃");
}
move_cur(33,38);
printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");

printf("\n");
}

void logcontrol() {
printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");	
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┃                                                                                                                                  ┃\n");
printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
move_cur(51, 8);
printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
move_cur(51,9);
printf("┃                                ┃");
move_cur(51,10);
printf("┃                                ┃");
move_cur(51,11);
printf("┃                                ┃");
move_cur(51,12);
printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
move_cur(59,10);
printf("★  Log Control  ★\n");
move_cur(33,15);
printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
for (int i=16; i<38; i++) {
	move_cur(33, i);
	printf("┃                                                                  ┃");
}
move_cur(33,38);
printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");

printf("\n");
}

int choice() {

	int mySelect = 0;
	int mycount = 0;

	while(1) {
		mySelect = getch();
		if (mySelect == 10) {
			return mycount;
		}
		else if (mySelect == 27) {
			mySelect = getch();
			if (mySelect == 91) {
				mySelect = getch();
				switch (mySelect)
				{
					case 67:
						mycount += 1;
						if (mycount % 3 == 1) {		
							system("clear");
							sPage1();
						}
						else if (mycount % 3 == 2) {
							system("clear");
							sPage2();
						}
						else if (mycount % 3 == 0) {
							system("clear");
							sPage3();
						}
						break;
					case 68:
						if (mycount == 0) {
							mycount = 34;
						}
						mycount -= 1;
						if (mycount % 3 == 1) {
							system("clear");
							sPage1();
						}
						else if (mycount % 3 == 2) {
							system("clear");
							sPage2();
						}
						else if (mycount % 3 == 0) {
							system("clear");
							sPage3();
						}
						break;
					default:
						break;
					
				}
			}
		}
	}

}

int main() {

	int mycount = 0;

	system("clear");
	smainPage();

	mycount = choice();

	if (mycount % 3 == 1) {		// 여기가 파일 관리
		system("clear");
		filecontrol();
	}
	else if (mycount % 3 == 2) {	// 여기가 회원 관리
		system("clear");
		joincontrol();
	}
	else if (mycount % 3 == 0) {	// 여기가 로그 관리
		system("clear");
		logcontrol();
	}
}



































