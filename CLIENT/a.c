/*정재훈 Client code UI*/
﻿#include "a.h"
#include "file.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
void loginmainPage();
void loginPage1();
void loginPage2();
void loginPage3();
void loginPage();
void joinMemberPage();
void maximcom();
void mainPage();
void mainPage1();
void mainPage2();
int getch(void);
void mypicture1();
void delete ();
void mypicture2();
void loginpicture();
void joinpicture();
void mypagepicture();
void mymainPage();
void myPage1();
void myPage2();
void mypagepicture1();
void mypagepicture2();
int mainchoice();
int mypagechoice();
int mypagemenuchoicce();
void draw(int n);
void draw(int n) {

    printf(
        "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
        "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
        "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    move_cur(51, 8);
    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
    move_cur(51, 9);
    printf("┃                                ┃");
    move_cur(51, 10);
    printf("┃                                ┃");
    move_cur(51, 11);
    printf("┃                                ┃");
    move_cur(51, 12);
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
    move_cur(62, 9);
    printf("★File List\n");
    move_cur(63, 10);
    printf("%d개 파일", n);
}
void move_cur(int x, int y) { // 커서이동 함수
    printf("\033[%dd\033[%dG", y, x);
}

int getch(void) { // 입력함수
    int ch;
    struct termios buf, save;
    tcgetattr(0, &save);
    buf = save;
    buf.c_lflag &= ~(ICANON | ECHO);
    buf.c_cc[VMIN] = 1;
    buf.c_cc[VTIME] = 0;
    tcsetattr(0, TCSAFLUSH, &buf);
    ch = getchar();
    tcsetattr(0, TCSAFLUSH, &save);
    return ch;
}
/*int get_pw(char *buf, int size) {
        int cnt = 0, key;

        while (1) {
                key = getch();
                if (key == ENTER_KEY || key == TAB_KEY)
                        break;
                if (key == BACKSPACE_KEY) {
                        if (cnt == 0)
                                continue;
                        if (cnt > 0) {
                                move_cur(30,8);
                                cnt = cnt-1;
                                buf[cnt] = '\0';
                                for (int j = 0; j<cnt; j++)
                                        printf("*");
                                printf("\b");
                                continue;
                        }
                }
                buf[cnt++] = (char)key;
                printf("*");
        }
}*/

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
void loginpicture() {
    move_cur(25, 27);
    printf("■");
    move_cur(25, 28);
    printf("■");
    move_cur(25, 29);
    printf("■");
    move_cur(27, 27);
    printf("■");
    move_cur(27, 28);
    printf("■");
    move_cur(27, 29);
    printf("■");
    move_cur(29, 27);
    printf("■");
    move_cur(29, 28);
    printf("■");
    move_cur(29, 29);
    printf("■");
    move_cur(31, 27);
    printf("■");
    move_cur(31, 28);
    printf("■");
    move_cur(31, 29);
    printf("■");
    move_cur(33, 27);
    printf("■");
    move_cur(33, 28);
    printf("■");
    move_cur(33, 29);
    printf("■");
    move_cur(35, 26);
    printf("■");
    move_cur(35, 27);
    printf("■");
    move_cur(35, 28);
    printf("■");
    move_cur(35, 29);
    printf("■");
    move_cur(35, 30);
    printf("■");
    move_cur(37, 27);
    printf("■");
    move_cur(37, 28);
    printf("■");
    move_cur(37, 29);
    printf("■");
    move_cur(39, 28);
    printf("■");
    move_cur(35, 33);
    printf("■");
    move_cur(35, 34);
    printf("■");
    move_cur(37, 33);
    printf("■");
    move_cur(37, 34);
    printf("■");
    move_cur(39, 33);
    printf("■");
    move_cur(39, 34);
    printf("■");
    move_cur(41, 33);
    printf("■");
    move_cur(41, 34);
    printf("■");
    move_cur(43, 33);
    printf("■");
    move_cur(43, 34);
    printf("■");
    move_cur(45, 33);
    printf("■");
    move_cur(45, 34);
    printf("■");
    move_cur(47, 33);
    printf("■");
    move_cur(47, 34);
    printf("■");
    move_cur(45, 32);
    printf("■");
    move_cur(47, 32);
    printf("■");
    move_cur(45, 31);
    printf("■");
    move_cur(47, 31);
    printf("■");
    move_cur(45, 30);
    printf("■");
    move_cur(47, 30);
    printf("■");
    move_cur(45, 29);
    printf("■");
    move_cur(47, 29);
    printf("■");
    move_cur(45, 28);
    printf("■");
    move_cur(47, 28);
    printf("■");
    move_cur(45, 27);
    printf("■");
    move_cur(47, 27);
    printf("■");
    move_cur(45, 27);
    printf("■");
    move_cur(47, 27);
    printf("■");
    move_cur(45, 26);
    printf("■");
    move_cur(47, 26);
    printf("■");
    move_cur(45, 25);
    printf("■");
    move_cur(47, 25);
    printf("■");
    move_cur(45, 24);
    printf("■");
    move_cur(47, 24);
    printf("■");
    move_cur(45, 23);
    printf("■");
    move_cur(47, 23);
    printf("■");
    move_cur(45, 22);
    printf("■");
    move_cur(47, 22);
    printf("■");
    move_cur(43, 22);
    printf("■");
    move_cur(43, 23);
    printf("■");
    move_cur(41, 22);
    printf("■");
    move_cur(41, 23);
    printf("■");
    move_cur(39, 22);
    printf("■");
    move_cur(39, 23);
    printf("■");
    move_cur(37, 22);
    printf("■");
    move_cur(37, 23);
    printf("■");
    move_cur(35, 22);
    printf("■");
    move_cur(35, 23);
    printf("■");
    move_cur(33, 22);
    printf("■");
    move_cur(33, 23);
    printf("■");
    move_cur(31, 22);
    printf("■");
    move_cur(31, 23);
    printf("■");
    move_cur(29, 22);
    printf("■");
    move_cur(29, 23);
    printf("■");
    move_cur(29, 24);
    printf("■");
    move_cur(31, 24);
    printf("■");
    move_cur(29, 25);
    printf("■");
    move_cur(31, 25);
    printf("■");
    move_cur(29, 33);
    printf("■");
    move_cur(29, 34);
    printf("■");
    move_cur(31, 33);
    printf("■");
    move_cur(31, 34);
    printf("■");
    move_cur(33, 33);
    printf("■");
    move_cur(33, 34);
    printf("■");
    move_cur(29, 32);
    printf("■");
    move_cur(31, 32);
    printf("■");
    move_cur(29, 31);
    printf("■");
    move_cur(31, 31);
    printf("■");
}
void joinpicture() {
    move_cur(91, 21);
    printf("■");
    move_cur(93, 21);
    printf("■");
    move_cur(95, 21);
    printf("■");
    move_cur(97, 21);
    printf("■");
    move_cur(99, 21);
    printf("■");
    move_cur(91, 23);
    printf("■");
    move_cur(93, 23);
    printf("■");
    move_cur(95, 23);
    printf("■");
    move_cur(97, 23);
    printf("■");
    move_cur(99, 23);
    printf("■");
    move_cur(85, 22);
    printf("■");
    move_cur(87, 22);
    printf("■");
    move_cur(89, 22);
    printf("■");
    move_cur(91, 22);
    printf("■");
    move_cur(99, 22);
    printf("■");
    move_cur(101, 22);
    printf("■");
    move_cur(103, 22);
    printf("■");
    move_cur(105, 22);
    printf("■");
    move_cur(85, 23);
    printf("■");
    move_cur(85, 24);
    printf("■");
    move_cur(85, 25);
    printf("■");
    move_cur(85, 26);
    printf("■");
    move_cur(85, 27);
    printf("■");
    move_cur(85, 28);
    printf("■");
    move_cur(85, 29);
    printf("■");
    move_cur(85, 30);
    printf("■");
    move_cur(85, 31);
    printf("■");
    move_cur(85, 32);
    printf("■");
    move_cur(85, 33);
    printf("■");
    move_cur(85, 34);
    printf("■");
    move_cur(105, 23);
    printf("■");
    move_cur(105, 25);
    printf("■");
    move_cur(105, 26);
    printf("■");
    move_cur(105, 27);
    printf("■");
    move_cur(105, 28);
    printf("■");
    move_cur(105, 29);
    printf("■");
    move_cur(105, 30);
    printf("■");
    move_cur(105, 31);
    printf("■");
    move_cur(105, 32);
    printf("■");
    move_cur(105, 33);
    printf("■");
    move_cur(105, 34);
    printf("■");
    move_cur(87, 34);
    printf("■");
    move_cur(89, 34);
    printf("■");
    move_cur(91, 34);
    printf("■");
    move_cur(93, 34);
    printf("■");
    move_cur(95, 34);
    printf("■");
    move_cur(97, 34);
    printf("■");
    move_cur(99, 34);
    printf("■");
    move_cur(101, 34);
    printf("■");
    move_cur(103, 34);
    printf("■");
    move_cur(89, 26);
    printf("■");
    move_cur(91, 26);
    printf("■");
    move_cur(93, 26);
    printf("■");
    move_cur(95, 26);
    printf("■");
    move_cur(97, 26);
    printf("■");
    move_cur(89, 28);
    printf("■");
    move_cur(91, 28);
    printf("■");
    move_cur(93, 28);
    printf("■");
    move_cur(95, 28);
    printf("■");
    move_cur(97, 28);
    printf("■");
    move_cur(89, 30);
    printf("■");
    move_cur(91, 30);
    printf("■");
    move_cur(93, 30);
    printf("■");
    move_cur(95, 30);
    printf("■");
    move_cur(97, 30);
    printf("■");
    move_cur(99, 25);
    printf("\x1b[34m■");
    move_cur(105, 24);
    printf("■");
    move_cur(101, 26);
    printf("■");
    move_cur(103, 25);
    printf("■");
    move_cur(107, 23);
    printf("■\x1b[0m");
}
void mypagepicture() {
    move_cur(106, 23);
    printf("■");
    move_cur(108, 23);
    printf("■");
    move_cur(110, 23);
    printf("■");
    move_cur(105, 24);
    printf("■");
    move_cur(107, 24);
    printf("■");
    move_cur(109, 24);
    printf("■");
    move_cur(111, 24);
    printf("■");
    move_cur(104, 25);
    printf("■");
    move_cur(106, 25);
    printf("■");
    move_cur(108, 25);
    printf("■");
    move_cur(110, 25);
    printf("■");
    move_cur(112, 25);
    printf("■");
    move_cur(105, 26);
    printf("■");
    move_cur(107, 26);
    printf("■");
    move_cur(109, 26);
    printf("■");
    move_cur(111, 26);
    printf("■");
    move_cur(106, 27);
    printf("■");
    move_cur(108, 27);
    printf("■");
    move_cur(110, 27);
    printf("■");
    move_cur(107, 29);
    printf("■");
    move_cur(109, 29);
    printf("■");
    move_cur(105, 29);
    printf("■");
    move_cur(111, 29);
    printf("■");
    move_cur(103, 30);
    printf("■");
    move_cur(113, 30);
    printf("■");
    move_cur(101, 30);
    printf("■");
    move_cur(115, 30);
    printf("■");
    move_cur(99, 31);
    printf("■");
    move_cur(117, 31);
    printf("■");
    move_cur(97, 31);
    printf("■");
    move_cur(119, 31);
    printf("■");
    move_cur(95, 32);
    printf("■");
    move_cur(121, 32);
    printf("■");
    move_cur(95, 33);
    printf("■");
    move_cur(121, 33);
    printf("■");
    move_cur(95, 34);
    printf("■");
    move_cur(121, 34);
    printf("■");
    move_cur(97, 34);
    printf("■");
    move_cur(99, 34);
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
    move_cur(117, 34);
    printf("■");
    move_cur(119, 34);
    printf("■");
}
void mypicture1() {
    move_cur(24, 22);
    printf("■");
    move_cur(26, 22);
    printf("■");
    move_cur(28, 22);
    printf("■");
    move_cur(24, 23);
    printf("■");
    move_cur(26, 23);
    printf("■");
    move_cur(28, 23);
    printf("■");
    move_cur(24, 24);
    printf("■");
    move_cur(26, 24);
    printf("■");
    move_cur(28, 24);
    printf("■");
    move_cur(24, 25);
    printf("■");
    move_cur(26, 25);
    printf("■");
    move_cur(28, 25);
    printf("■");
    move_cur(24, 26);
    printf("■");
    move_cur(26, 26);
    printf("■");
    move_cur(28, 26);
    printf("■");
    move_cur(24, 27);
    printf("■");
    move_cur(26, 27);
    printf("■");
    move_cur(28, 27);
    printf("■");
    move_cur(20, 28);
    printf("■");
    move_cur(22, 28);
    printf("■");
    move_cur(24, 28);
    printf("■");
    move_cur(26, 28);
    printf("■");
    move_cur(28, 28);
    printf("■");
    move_cur(30, 28);
    printf("■");
    move_cur(32, 28);
    printf("■");
    move_cur(22, 29);
    printf("■");
    move_cur(24, 29);
    printf("■");
    move_cur(26, 29);
    printf("■");
    move_cur(28, 29);
    printf("■");
    move_cur(30, 29);
    printf("■");
    move_cur(24, 30);
    printf("■");
    move_cur(26, 30);
    printf("■");
    move_cur(28, 30);
    printf("■");
    move_cur(26, 31);
    printf("■");
    move_cur(12, 29);
    printf("■");
    move_cur(14, 29);
    printf("■");
    move_cur(12, 30);
    printf("■");
    move_cur(14, 30);
    printf("■");
    move_cur(12, 31);
    printf("■");
    move_cur(14, 31);
    printf("■");
    move_cur(12, 32);
    printf("■");
    move_cur(14, 32);
    printf("■");
    move_cur(12, 33);
    printf("■");
    move_cur(14, 33);
    printf("■");
    move_cur(12, 34);
    printf("■");
    move_cur(14, 34);
    printf("■");
    move_cur(16, 33);
    printf("■");
    move_cur(16, 34);
    printf("■");
    move_cur(18, 33);
    printf("■");
    move_cur(18, 34);
    printf("■");
    move_cur(20, 33);
    printf("■");
    move_cur(20, 34);
    printf("■");
    move_cur(22, 33);
    printf("■");
    move_cur(22, 34);
    printf("■");
    move_cur(24, 33);
    printf("■");
    move_cur(24, 34);
    printf("■");
    move_cur(26, 33);
    printf("■");
    move_cur(26, 34);
    printf("■");
    move_cur(28, 33);
    printf("■");
    move_cur(28, 34);
    printf("■");
    move_cur(30, 33);
    printf("■");
    move_cur(30, 34);
    printf("■");
    move_cur(32, 33);
    printf("■");
    move_cur(32, 34);
    printf("■");
    move_cur(34, 33);
    printf("■");
    move_cur(34, 34);
    printf("■");
    move_cur(36, 33);
    printf("■");
    move_cur(36, 34);
    printf("■");
    move_cur(38, 33);
    printf("■");
    move_cur(38, 34);
    printf("■");
    move_cur(40, 33);
    printf("■");
    move_cur(40, 34);
    printf("■");
    move_cur(38, 32);
    printf("■");
    move_cur(40, 32);
    printf("■");
    move_cur(38, 31);
    printf("■");
    move_cur(40, 31);
    printf("■");
    move_cur(38, 30);
    printf("■");
    move_cur(40, 30);
    printf("■");
    move_cur(38, 29);
    printf("■");
    move_cur(40, 29);
    printf("■");
}
void mypicture2() {
    move_cur(67, 22);
    printf("■");
    move_cur(65, 23);
    printf("■");
    move_cur(67, 23);
    printf("■");
    move_cur(69, 23);
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
    move_cur(61, 25);
    printf("■");
    move_cur(63, 25);
    printf("■");
    move_cur(65, 25);
    printf("■");
    move_cur(67, 25);
    printf("■");
    move_cur(69, 25);
    printf("■");
    move_cur(71, 25);
    printf("■");
    move_cur(73, 25);
    printf("■");
    move_cur(67, 26);
    printf("■");
    move_cur(67, 27);
    printf("■");
    move_cur(67, 28);
    printf("■");
    move_cur(67, 29);
    printf("■");
    move_cur(67, 30);
    printf("■");
    move_cur(67, 31);
    printf("■");
    move_cur(65, 26);
    printf("■");
    move_cur(65, 27);
    printf("■");
    move_cur(65, 28);
    printf("■");
    move_cur(65, 29);
    printf("■");
    move_cur(65, 30);
    printf("■");
    move_cur(65, 31);
    printf("■");
    move_cur(69, 26);
    printf("■");
    move_cur(69, 27);
    printf("■");
    move_cur(69, 28);
    printf("■");
    move_cur(69, 29);
    printf("■");
    move_cur(69, 30);
    printf("■");
    move_cur(69, 31);
    printf("■");
    move_cur(53, 29);
    printf("■");
    move_cur(55, 29);
    printf("■");
    move_cur(53, 30);
    printf("■");
    move_cur(55, 30);
    printf("■");
    move_cur(53, 31);
    printf("■");
    move_cur(55, 31);
    printf("■");
    move_cur(53, 32);
    printf("■");
    move_cur(55, 32);
    printf("■");
    move_cur(53, 33);
    printf("■");
    move_cur(55, 33);
    printf("■");
    move_cur(53, 34);
    printf("■");
    move_cur(55, 34);
    printf("■");
    move_cur(57, 33);
    printf("■");
    move_cur(57, 34);
    printf("■");
    move_cur(59, 33);
    printf("■");
    move_cur(59, 34);
    printf("■");
    move_cur(61, 33);
    printf("■");
    move_cur(61, 34);
    printf("■");
    move_cur(63, 33);
    printf("■");
    move_cur(63, 34);
    printf("■");
    move_cur(65, 33);
    printf("■");
    move_cur(65, 34);
    printf("■");
    move_cur(67, 33);
    printf("■");
    move_cur(67, 34);
    printf("■");
    move_cur(69, 33);
    printf("■");
    move_cur(69, 34);
    printf("■");
    move_cur(71, 33);
    printf("■");
    move_cur(71, 34);
    printf("■");
    move_cur(73, 33);
    printf("■");
    move_cur(73, 34);
    printf("■");
    move_cur(75, 33);
    printf("■");
    move_cur(75, 34);
    printf("■");
    move_cur(77, 33);
    printf("■");
    move_cur(77, 34);
    printf("■");
    move_cur(79, 33);
    printf("■");
    move_cur(79, 34);
    printf("■");
    move_cur(81, 33);
    printf("■");
    move_cur(81, 34);
    printf("■");
    move_cur(79, 32);
    printf("■");
    move_cur(81, 32);
    printf("■");
    move_cur(79, 31);
    printf("■");
    move_cur(81, 31);
    printf("■");
    move_cur(79, 30);
    printf("■");
    move_cur(81, 30);
    printf("■");
    move_cur(79, 29);
    printf("■");
    move_cur(81, 29);
    printf("■");
}
void mypagepicture1() {
    move_cur(35, 22);
    printf("■");
    move_cur(37, 22);
    printf("■");
    move_cur(39, 22);
    printf("■");
    move_cur(35, 23);
    printf("■");
    move_cur(37, 23);
    printf("■");
    move_cur(39, 23);
    printf("■");
    move_cur(35, 24);
    printf("■");
    move_cur(37, 24);
    printf("■");
    move_cur(39, 24);
    printf("■");
    move_cur(35, 25);
    printf("■");
    move_cur(37, 25);
    printf("■");
    move_cur(39, 25);
    printf("■");
    move_cur(35, 26);
    printf("■");
    move_cur(37, 26);
    printf("■");
    move_cur(39, 26);
    printf("■");
    move_cur(35, 27);
    printf("■");
    move_cur(37, 27);
    printf("■");
    move_cur(39, 27);
    printf("■");
    move_cur(31, 28);
    printf("■");
    move_cur(33, 28);
    printf("■");
    move_cur(35, 28);
    printf("■");
    move_cur(37, 28);
    printf("■");
    move_cur(39, 28);
    printf("■");
    move_cur(41, 28);
    printf("■");
    move_cur(43, 28);
    printf("■");
    move_cur(33, 29);
    printf("■");
    move_cur(35, 29);
    printf("■");
    move_cur(37, 29);
    printf("■");
    move_cur(39, 29);
    printf("■");
    move_cur(41, 29);
    printf("■");
    move_cur(35, 30);
    printf("■");
    move_cur(37, 30);
    printf("■");
    move_cur(39, 30);
    printf("■");
    move_cur(37, 31);
    printf("■");
    move_cur(21, 29);
    printf("■");
    move_cur(23, 29);
    printf("■");
    move_cur(21, 30);
    printf("■");
    move_cur(23, 30);
    printf("■");
    move_cur(21, 31);
    printf("■");
    move_cur(23, 31);
    printf("■");
    move_cur(21, 32);
    printf("■");
    move_cur(23, 32);
    printf("■");
    move_cur(21, 33);
    printf("■");
    move_cur(23, 33);
    printf("■");
    move_cur(21, 34);
    printf("■");
    move_cur(23, 34);
    printf("■");
    move_cur(25, 33);
    printf("■");
    move_cur(25, 34);
    printf("■");
    move_cur(27, 33);
    printf("■");
    move_cur(27, 34);
    printf("■");
    move_cur(29, 33);
    printf("■");
    move_cur(29, 34);
    printf("■");
    move_cur(31, 33);
    printf("■");
    move_cur(31, 34);
    printf("■");
    move_cur(33, 33);
    printf("■");
    move_cur(33, 34);
    printf("■");
    move_cur(35, 33);
    printf("■");
    move_cur(35, 34);
    printf("■");
    move_cur(37, 33);
    printf("■");
    move_cur(37, 34);
    printf("■");
    move_cur(39, 33);
    printf("■");
    move_cur(39, 34);
    printf("■");
    move_cur(41, 33);
    printf("■");
    move_cur(41, 34);
    printf("■");
    move_cur(43, 33);
    printf("■");
    move_cur(43, 34);
    printf("■");
    move_cur(45, 33);
    printf("■");
    move_cur(45, 34);
    printf("■");
    move_cur(47, 33);
    printf("■");
    move_cur(47, 34);
    printf("■");
    move_cur(49, 33);
    printf("■");
    move_cur(49, 34);
    printf("■");
    move_cur(51, 33);
    printf("■");
    move_cur(51, 34);
    printf("■");
    move_cur(53, 33);
    printf("■");
    move_cur(53, 34);
    printf("■");
    move_cur(51, 32);
    printf("■");
    move_cur(53, 32);
    printf("■");
    move_cur(51, 31);
    printf("■");
    move_cur(53, 31);
    printf("■");
    move_cur(51, 30);
    printf("■");
    move_cur(53, 30);
    printf("■");
    move_cur(51, 29);
    printf("■");
    move_cur(53, 29);
    printf("■");
}

void mypagepicture2() {
    move_cur(95, 22);
    printf("■");
    move_cur(93, 23);
    printf("■");
    move_cur(95, 23);
    printf("■");
    move_cur(97, 23);
    printf("■");
    move_cur(91, 24);
    printf("■");
    move_cur(93, 24);
    printf("■");
    move_cur(95, 24);
    printf("■");
    move_cur(97, 24);
    printf("■");
    move_cur(99, 24);
    printf("■");
    move_cur(89, 25);
    printf("■");
    move_cur(91, 25);
    printf("■");
    move_cur(93, 25);
    printf("■");
    move_cur(95, 25);
    printf("■");
    move_cur(97, 25);
    printf("■");
    move_cur(99, 25);
    printf("■");
    move_cur(101, 25);
    printf("■");
    move_cur(95, 26);
    printf("■");
    move_cur(95, 27);
    printf("■");
    move_cur(95, 28);
    printf("■");
    move_cur(95, 29);
    printf("■");
    move_cur(95, 30);
    printf("■");
    move_cur(95, 31);
    printf("■");
    move_cur(93, 26);
    printf("■");
    move_cur(93, 27);
    printf("■");
    move_cur(93, 28);
    printf("■");
    move_cur(93, 29);
    printf("■");
    move_cur(93, 30);
    printf("■");
    move_cur(93, 31);
    printf("■");
    move_cur(97, 26);
    printf("■");
    move_cur(97, 27);
    printf("■");
    move_cur(97, 28);
    printf("■");
    move_cur(97, 29);
    printf("■");
    move_cur(97, 30);
    printf("■");
    move_cur(97, 31);
    printf("■");

    move_cur(79, 29);
    printf("■");
    move_cur(81, 29);
    printf("■");
    move_cur(79, 30);
    printf("■");
    move_cur(81, 30);
    printf("■");
    move_cur(79, 31);
    printf("■");
    move_cur(81, 31);
    printf("■");
    move_cur(79, 32);
    printf("■");
    move_cur(81, 32);
    printf("■");
    move_cur(79, 33);
    printf("■");
    move_cur(81, 33);
    printf("■");
    move_cur(79, 34);
    printf("■");
    move_cur(81, 34);
    printf("■");
    move_cur(83, 33);
    printf("■");
    move_cur(83, 34);
    printf("■");
    move_cur(85, 33);
    printf("■");
    move_cur(85, 34);
    printf("■");
    move_cur(87, 33);
    printf("■");
    move_cur(87, 34);
    printf("■");
    move_cur(89, 33);
    printf("■");
    move_cur(89, 34);
    printf("■");
    move_cur(91, 33);
    printf("■");
    move_cur(91, 34);
    printf("■");
    move_cur(93, 33);
    printf("■");
    move_cur(93, 34);
    printf("■");
    move_cur(95, 33);
    printf("■");
    move_cur(95, 34);
    printf("■");
    move_cur(97, 33);
    printf("■");
    move_cur(97, 34);
    printf("■");
    move_cur(99, 33);
    printf("■");
    move_cur(99, 34);
    printf("■");
    move_cur(101, 33);
    printf("■");
    move_cur(101, 34);
    printf("■");
    move_cur(103, 33);
    printf("■");
    move_cur(103, 34);
    printf("■");
    move_cur(105, 33);
    printf("■");
    move_cur(105, 34);
    printf("■");
    move_cur(107, 33);
    printf("■");
    move_cur(107, 34);
    printf("■");
    move_cur(109, 33);
    printf("■");
    move_cur(109, 34);
    printf("■");
    move_cur(111, 33);
    printf("■");
    move_cur(111, 34);
    printf("■");
    move_cur(109, 32);
    printf("■");
    move_cur(111, 32);
    printf("■");
    move_cur(109, 31);
    printf("■");
    move_cur(111, 31);
    printf("■");
    move_cur(109, 30);
    printf("■");
    move_cur(111, 30);
    printf("■");
    move_cur(109, 29);
    printf("■");
    move_cur(111, 29);
    printf("■");
}

void loginmainPage() {
    printf(
        "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
        "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf("┃        ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓       "
           "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓       "
           "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓      ┃\n");
    printf(
        "┃        ┃                                ┃       ┃                   "
        "             ┃       ┃                                ┃      ┃\n");
    printf(
        "┃        ┃                                ┃       ┃                   "
        "             ┃       ┃                                ┃      ┃\n");
    printf(
        "┃        ┃                                ┃       ┃                   "
        "             ┃       ┃                                ┃      ┃\n");
    printf(
        "┃        ┃                                ┃       ┃                   "
        "             ┃       ┃                                ┃      ┃\n");
    printf(
        "┃        ┃                                ┃       ┃                   "
        "             ┃       ┃                                ┃      ┃\n");
    printf(
        "┃        ┃                                ┃       ┃                   "
        "             ┃       ┃                                ┃      ┃\n");
    printf(
        "┃        ┃                                ┃       ┃                   "
        "             ┃       ┃                                ┃      ┃\n");
    printf(
        "┃        ┃                                ┃       ┃                   "
        "             ┃       ┃                                ┃      ┃\n");
    printf(
        "┃        ┃                                ┃       ┃                   "
        "             ┃       ┃                                ┃      ┃\n");
    printf(
        "┃        ┃                                ┃       ┃                   "
        "             ┃       ┃                                ┃      ┃\n");
    printf(
        "┃        ┃                                ┃       ┃                   "
        "             ┃       ┃                                ┃      ┃\n");
    printf(
        "┃        ┃                                ┃       ┃                   "
        "             ┃       ┃                                ┃      ┃\n");
    printf(
        "┃        ┃                                ┃       ┃                   "
        "             ┃       ┃                                ┃      ┃\n");
    printf(
        "┃        ┃                                ┃       ┃                   "
        "             ┃       ┃                                ┃      ┃\n");
    printf(
        "┃        ┃                                ┃       ┃                   "
        "             ┃       ┃                                ┃      ┃\n");
    printf(
        "┃        ┃                                ┃       ┃                   "
        "             ┃       ┃                                ┃      ┃\n");
    printf("┃        ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛       "
           "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛       "
           "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛      ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
        "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    maximcom();
    move_cur(15, 39);
    printf("<< 파 일 다 운 로 드 >>");
    move_cur(58, 39);
    printf("<< 파 일 업 로 드 >>");
    move_cur(103, 39);
    printf("<< 삭  제 >>");
    mypicture1();
    mypicture2();
    printf("\x1b[0m");
    delete ();
}

void loginPage1() {
    printf(
        "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
        "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf("┃        ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓       "
           "\x1b[2;37m┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓       "
           "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓   \x1b[0m   ┃\n");
    printf("┃        ┃                                ┃       \x1b[2;37m┃      "
           "                          ┃       ┃                                "
           "┃\x1b[0m      ┃\n");
    printf("┃        ┃                                ┃       \x1b[2;37m┃      "
           "                          ┃       ┃                                "
           "┃\x1b[0m      ┃\n");
    printf("┃        ┃                                ┃       \x1b[2;37m┃      "
           "                          ┃       ┃                                "
           "┃\x1b[0m      ┃\n");
    printf("┃        ┃                                ┃       \x1b[2;37m┃      "
           "                          ┃       ┃                                "
           "┃\x1b[0m      ┃\n");
    printf("┃        ┃                                ┃       \x1b[2;37m┃      "
           "                          ┃       ┃                                "
           "┃\x1b[0m      ┃\n");
    printf("┃        ┃                                ┃       \x1b[2;37m┃      "
           "                          ┃       ┃                                "
           "┃\x1b[0m      ┃\n");
    printf("┃        ┃                                ┃       \x1b[2;37m┃      "
           "                          ┃       ┃                                "
           "┃\x1b[0m      ┃\n");
    printf("┃        ┃                                ┃       \x1b[2;37m┃      "
           "                          ┃       ┃                                "
           "┃\x1b[0m      ┃\n");
    printf("┃        ┃                                ┃       \x1b[2;37m┃      "
           "                          ┃       ┃                                "
           "┃\x1b[0m      ┃\n");
    printf("┃        ┃                                ┃       \x1b[2;37m┃      "
           "                          ┃       ┃                                "
           "┃\x1b[0m      ┃\n");
    printf("┃        ┃                                ┃       \x1b[2;37m┃      "
           "                          ┃       ┃                                "
           "┃\x1b[0m      ┃\n");
    printf("┃        ┃                                ┃       \x1b[2;37m┃      "
           "                          ┃       ┃                                "
           "┃\x1b[0m      ┃\n");
    printf("┃        ┃                                ┃       \x1b[2;37m┃      "
           "                          ┃       ┃                                "
           "┃\x1b[0m      ┃\n");
    printf("┃        ┃                                ┃       \x1b[2;37m┃      "
           "                          ┃       ┃                                "
           "┃\x1b[0m      ┃\n");
    printf("┃        ┃                                ┃       \x1b[2;37m┃      "
           "                          ┃       ┃                                "
           "┃\x1b[0m      ┃\n");
    printf("┃        ┃                                ┃       \x1b[2;37m┃      "
           "                          ┃       ┃                                "
           "┃\x1b[0m      ┃\n");
    printf("┃        ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛       "
           "\x1b[2;37m┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛       "
           "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\x1b[0m      ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
        "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    move_cur(15, 39);
    printf("<< 파 일 다 운 로 드 >>");
    move_cur(58, 39);
    printf("<< 파 일 업 로 드 >>");
    move_cur(103, 39);
    printf("<< 삭  제 >>");
    maximcom();
    printf("\x1b[2;37m");
    mypicture2();
    delete ();
    printf("\x1b[0m");
    printf("\x1b[5m");
    mypicture1();
    printf("\x1b[0m");
}

void loginPage2() {
    printf(
        "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
        "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf("┃        \x1b[2;37m┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\x1b[0m       "
           "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓       "
           "\x1b[2;37m┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\x1b[0m      ┃\n");
    printf("┃        \x1b[2;37m┃                                ┃\x1b[0m       "
           "┃                                ┃       \x1b[2;37m┃               "
           "                 ┃\x1b[0m      ┃\n");
    printf("┃        \x1b[2;37m┃                                ┃\x1b[0m       "
           "┃                                ┃       \x1b[2;37m┃               "
           "                 ┃\x1b[0m      ┃\n");
    printf("┃        \x1b[2;37m┃                                ┃\x1b[0m       "
           "┃                                ┃       \x1b[2;37m┃               "
           "                 ┃\x1b[0m      ┃\n");
    printf("┃        \x1b[2;37m┃                                ┃\x1b[0m       "
           "┃                                ┃       \x1b[2;37m┃               "
           "                 ┃\x1b[0m      ┃\n");
    printf("┃        \x1b[2;37m┃                                ┃\x1b[0m       "
           "┃                                ┃       \x1b[2;37m┃               "
           "                 ┃\x1b[0m      ┃\n");
    printf("┃        \x1b[2;37m┃                                ┃\x1b[0m       "
           "┃                                ┃       \x1b[2;37m┃               "
           "                 ┃\x1b[0m      ┃\n");
    printf("┃        \x1b[2;37m┃                                ┃\x1b[0m       "
           "┃                                ┃       \x1b[2;37m┃               "
           "                 ┃\x1b[0m      ┃\n");
    printf("┃        \x1b[2;37m┃                                ┃\x1b[0m       "
           "┃                                ┃       \x1b[2;37m┃               "
           "                 ┃\x1b[0m      ┃\n");
    printf("┃        \x1b[2;37m┃                                ┃\x1b[0m       "
           "┃                                ┃       \x1b[2;37m┃               "
           "                 ┃\x1b[0m      ┃\n");
    printf("┃        \x1b[2;37m┃                                ┃\x1b[0m       "
           "┃                                ┃       \x1b[2;37m┃               "
           "                 ┃\x1b[0m      ┃\n");
    printf("┃        \x1b[2;37m┃                                ┃\x1b[0m       "
           "┃                                ┃       \x1b[2;37m┃               "
           "                 ┃\x1b[0m      ┃\n");
    printf("┃        \x1b[2;37m┃                                ┃\x1b[0m       "
           "┃                                ┃       \x1b[2;37m┃               "
           "                 ┃\x1b[0m      ┃\n");
    printf("┃        \x1b[2;37m┃                                ┃\x1b[0m       "
           "┃                                ┃       \x1b[2;37m┃               "
           "                 ┃\x1b[0m      ┃\n");
    printf("┃        \x1b[2;37m┃                                ┃\x1b[0m       "
           "┃                                ┃       \x1b[2;37m┃               "
           "                 ┃\x1b[0m      ┃\n");
    printf("┃        \x1b[2;37m┃                                ┃\x1b[0m       "
           "┃                                ┃       \x1b[2;37m┃               "
           "                 ┃\x1b[0m      ┃\n");
    printf("┃        \x1b[2;37m┃                                ┃\x1b[0m       "
           "┃                                ┃       \x1b[2;37m┃               "
           "                 ┃\x1b[0m      ┃\n");
    printf("┃        \x1b[2;37m┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\x1b[0m       "
           "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛       "
           "\x1b[2;37m┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\x1b[0m      ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
        "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    move_cur(15, 39);
    printf("<< 파 일 다 운 로 드 >>");
    move_cur(58, 39);
    printf("<< 파 일 업 로 드 >>");
    move_cur(103, 39);
    printf("<< 삭  제 >>");
    maximcom();
    printf("\x1b[2;37m");
    mypicture1();
    delete ();
    printf("\x1b[0m");
    printf("\x1b[5m");
    mypicture2();
    printf("\x1b[0m");
}

void loginPage3() {
    printf(
        "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
        "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf("┃        \x1b[2;37m┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓       "
           "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\x1b[0m       "
           "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓      ┃\n");
    printf("┃        \x1b[2;37m┃                                ┃       ┃      "
           "                          ┃\x1b[0m       ┃                         "
           "       ┃      ┃\n");
    printf("┃        \x1b[2;37m┃                                ┃       ┃      "
           "                          ┃\x1b[0m       ┃                         "
           "       ┃      ┃\n");
    printf("┃        \x1b[2;37m┃                                ┃       ┃      "
           "                          ┃\x1b[0m       ┃                         "
           "       ┃      ┃\n");
    printf("┃        \x1b[2;37m┃                                ┃       ┃      "
           "                          ┃\x1b[0m       ┃                         "
           "       ┃      ┃\n");
    printf("┃        \x1b[2;37m┃                                ┃       ┃      "
           "                          ┃\x1b[0m       ┃                         "
           "       ┃      ┃\n");
    printf("┃        \x1b[2;37m┃                                ┃       ┃      "
           "                          ┃\x1b[0m       ┃                         "
           "       ┃      ┃\n");
    printf("┃        \x1b[2;37m┃                                ┃       ┃      "
           "                          ┃\x1b[0m       ┃                         "
           "       ┃      ┃\n");
    printf("┃        \x1b[2;37m┃                                ┃       ┃      "
           "                          ┃\x1b[0m       ┃                         "
           "       ┃      ┃\n");
    printf("┃        \x1b[2;37m┃                                ┃       ┃      "
           "                          ┃\x1b[0m       ┃                         "
           "       ┃      ┃\n");
    printf("┃        \x1b[2;37m┃                                ┃       ┃      "
           "                          ┃\x1b[0m       ┃                         "
           "       ┃      ┃\n");
    printf("┃        \x1b[2;37m┃                                ┃       ┃      "
           "                          ┃\x1b[0m       ┃                         "
           "       ┃      ┃\n");
    printf("┃        \x1b[2;37m┃                                ┃       ┃      "
           "                          ┃\x1b[0m       ┃                         "
           "       ┃      ┃\n");
    printf("┃        \x1b[2;37m┃                                ┃       ┃      "
           "                          ┃\x1b[0m       ┃                         "
           "       ┃      ┃\n");
    printf("┃        \x1b[2;37m┃                                ┃       ┃      "
           "                          ┃\x1b[0m       ┃                         "
           "       ┃      ┃\n");
    printf("┃        \x1b[2;37m┃                                ┃       ┃      "
           "                          ┃\x1b[0m       ┃                         "
           "       ┃      ┃\n");
    printf("┃        \x1b[2;37m┃                                ┃       ┃      "
           "                          ┃\x1b[0m       ┃                         "
           "       ┃      ┃\n");
    printf("┃        \x1b[2;37m┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛       "
           "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\x1b[0m       "
           "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛      ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
        "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    move_cur(15, 39);
    printf("<< 파 일 다 운 로 드 >>");
    move_cur(58, 39);
    printf("<< 파 일 업 로 드 >>");
    move_cur(103, 39);
    printf("<< 삭  제 >>");
    maximcom();
    printf("\x1b[2;37m");
    mypicture1();
    mypicture2();
    printf("\x1b[0m");
    printf("\x1b[5m");
    delete ();
    printf("\x1b[0m");
}

void loginPage() {
    printf(
        "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
        "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
        "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    int j = 21;
    move_cur(42, 20);
    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
    for (int i = 0; i < 3; i++) {
        move_cur(42, j);
        printf("┃");
        move_cur(88, j);
        printf("┃");
        j++;
    }
    move_cur(42, 24);
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
    move_cur(42, 26);
    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
    j = 27;
    for (int i = 0; i < 3; i++) {
        move_cur(42, j);
        printf("┃");
        move_cur(88, j);
        printf("┃");
        j++;
    }
    move_cur(42, 30);
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
    maximcom();
}

void joinMemberPage() {
    printf(
        "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
        "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
        "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    int j = 21;
    move_cur(42, 19);
    printf("ID");
    move_cur(42, 20);
    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
    for (int i = 0; i < 3; i++) {
        move_cur(42, j);
        printf("┃");
        move_cur(88, j);
        printf("┃");
        j++;
    }
    move_cur(42, 24);
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
    move_cur(44, 22);
    printf("ID 입력");
    move_cur(42, 26);
    printf("PASSWORD");
    move_cur(42, 27);
    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
    j = 28;
    for (int i = 0; i < 3; i++) {
        move_cur(42, j);
        printf("┃");
        move_cur(88, j);
        printf("┃");
        j++;
    }
    move_cur(42, 31);
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
    move_cur(44, 29);
    printf("PASSWORD 입력");
    move_cur(42, 33);
    printf("PASSWORD CHEAK");
    move_cur(42, 34);
    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
    j = 35;
    for (int i = 0; i < 3; i++) {
        move_cur(42, j);
        printf("┃");
        move_cur(88, j);
        printf("┃");
        j++;
    }
    move_cur(42, 38);
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
    move_cur(44, 36);
    printf("PASSWORD 재입력");
    maximcom();
}

void mainPage() {

    printf(
        "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
        "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
        "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    maximcom();
    move_cur(10, 20);
    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
    int j = 21;
    for (int i = 0; i < 15; i++) {
        move_cur(10, j);
        printf("┃");
        move_cur(64, j);
        printf("┃");
        j++;
    }
    move_cur(10, 36);
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
    move_cur(68, 20);
    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
    j = 21;
    for (int i = 0; i < 15; i++) {
        move_cur(68, j);
        printf("┃");
        move_cur(122, j);
        printf("┃");
        j++;
    }
    move_cur(68, 36);
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
    move_cur(29, 38);
    printf("<< 로 그 인 >>");
    move_cur(88, 38);
    printf("<< 회 원 가 입 >>");
    loginpicture();
    joinpicture();
}

void mainPage1() {
    printf(
        "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
        "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
        "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    maximcom();
    move_cur(10, 20);
    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
    int j = 21;
    for (int i = 0; i < 15; i++) {
        move_cur(10, j);
        printf("┃");
        move_cur(64, j);
        printf("┃");
        j++;
    }
    move_cur(10, 36);
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
    printf("\x1b[2;37m");
    move_cur(68, 20);
    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
    j = 21;
    for (int i = 0; i < 15; i++) {
        move_cur(68, j);
        printf("┃");
        move_cur(122, j);
        printf("┃");
        j++;
    }
    move_cur(68, 36);
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
    printf("\x1b[0m");
    move_cur(29, 38);
    printf("<< 로 그 인 >>");
    move_cur(88, 38);
    printf("<< 회 원 가 입 >>");
    printf("\x1b[2;37m");
    joinpicture();
    printf("\x1b[0m");
    printf("\x1b[5m");
    loginpicture();
    printf("\x1b[0m");
}

void mainPage2() {
    printf(
        "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
        "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
        "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    maximcom();
    printf("%c[2;37m", 27);
    move_cur(10, 20);
    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
    int j = 21;
    for (int i = 0; i < 15; i++) {
        move_cur(10, j);
        printf("┃");
        move_cur(64, j);
        printf("┃");
        j++;
    }
    move_cur(10, 36);
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\x1b[0m");
    move_cur(68, 20);
    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
    j = 21;
    for (int i = 0; i < 15; i++) {
        move_cur(68, j);
        printf("┃");
        move_cur(122, j);
        printf("┃");
        j++;
    }
    move_cur(68, 36);
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
    move_cur(29, 38);
    printf("<< 로 그 인 >>");
    move_cur(88, 38);
    printf("<< 회 원 가 입 >>");
    printf("\x1b[2;37m");
    loginpicture();
    printf("\x1b[0m");
    printf("\x1b[5m");
    joinpicture();
    printf("\x1b[0m");
}
void mymainPage() {
    printf(
        "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
        "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
        "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    maximcom();
    move_cur(10, 20);
    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
    int j = 21;
    for (int i = 0; i < 15; i++) {
        move_cur(10, j);
        printf("┃");
        move_cur(64, j);
        printf("┃");
        j++;
    }
    move_cur(10, 36);
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
    move_cur(68, 20);
    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
    j = 21;
    for (int i = 0; i < 15; i++) {
        move_cur(68, j);
        printf("┃");
        move_cur(122, j);
        printf("┃");
        j++;
    }
    move_cur(68, 36);
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
    move_cur(23, 38);
    printf("<< 파 일 다 운 로 드 목 록 >>");
    move_cur(82, 38);
    printf("<< 파 일 업 로 드 목 록 >>");
    mypagepicture1();
    mypagepicture2();
}

void myPage1() {
    printf(
        "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
        "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
        "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    maximcom();
    move_cur(10, 20);
    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
    int j = 21;
    for (int i = 0; i < 15; i++) {
        move_cur(10, j);
        printf("┃");
        move_cur(64, j);
        printf("┃");
        j++;
    }
    move_cur(10, 36);
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
    printf("\x1b[2;37m");
    move_cur(68, 20);
    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
    j = 21;
    for (int i = 0; i < 15; i++) {
        move_cur(68, j);
        printf("┃");
        move_cur(122, j);
        printf("┃");
        j++;
    }
    move_cur(68, 36);
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
    printf("\x1b[0m");
    move_cur(23, 38);
    printf("<< 파 일 다 운 로 드 목 록 >>");
    move_cur(82, 38);
    printf("<< 파 일 업 로 드 목 록 >>");
    printf("\x1b[2;37m");
    mypagepicture2();
    printf("\x1b[0m");
    printf("\x1b[5m");
    mypagepicture1();
    printf("\x1b[0m");
}

void myPage2() {
    printf(
        "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
        "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┃                                                                     "
        "                                                             ┃\n");
    printf(
        "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
        "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    maximcom();
    printf("\x1b[2;37m");
    move_cur(10, 20);
    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
    int j = 21;
    for (int i = 0; i < 15; i++) {
        move_cur(10, j);
        printf("┃");
        move_cur(64, j);
        printf("┃");
        j++;
    }
    move_cur(10, 36);
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
    printf("\x1b[0m");
    move_cur(68, 20);
    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
    j = 21;
    for (int i = 0; i < 15; i++) {
        move_cur(68, j);
        printf("┃");
        move_cur(122, j);
        printf("┃");
        j++;
    }
    move_cur(68, 36);
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
    move_cur(23, 38);
    printf("<< 파 일 다 운 로 드 목 록 >>");
    move_cur(82, 38);
    printf("<< 파 일 업 로 드 목 록 >>");
    printf("\x1b[2;37m");
    mypagepicture1();
    printf("\x1b[0m");
    printf("\x1b[5m");
    mypagepicture2();
    printf("\x1b[0m");
}

int mainchoice() {

    int nSelect = 0;
    int count = 0;
    int result = 0;
    system("clear");
    mainPage();
    nSelect = getch();
    while (1) {
        nSelect = getch();

        if (nSelect == 10) {
            break;
        } else if (nSelect == 67) {
            count += 1;
            if (count % 2 == 1) {
                system("clear");
                mainPage1();
            } else if (count % 2 == 0) {
                system("clear");
                mainPage2();
            }
        } else if (nSelect == 68) {
            if (count == 0) {
                count += 21;
            }
            count -= 1;
            if (count % 2 == 1) {
                system("clear");
                mainPage1();
            } else if (count % 2 == 0) {
                system("clear");
                mainPage2();
            }
        }
    }
    return count % 2;
}
void delete () {
    move_cur(98, 23);
    printf("■");
    move_cur(100, 24);
    printf("■");
    move_cur(102, 25);
    printf("■");
    move_cur(104, 26);
    printf("■");
    move_cur(106, 27);
    printf("■");
    move_cur(108, 28);
    printf("■");
    move_cur(110, 29);
    printf("■");
    move_cur(112, 30);
    printf("■");
    move_cur(114, 31);
    printf("■");
    move_cur(116, 32);
    printf("■");
    move_cur(118, 33);
    printf("■");
    move_cur(118, 23);
    printf("■");
    move_cur(116, 24);
    printf("■");
    move_cur(114, 25);
    printf("■");
    move_cur(112, 26);
    printf("■");
    move_cur(110, 27);
    printf("■");
    move_cur(108, 28);
    printf("■");
    move_cur(106, 29);
    printf("■");
    move_cur(104, 30);
    printf("■");
    move_cur(102, 31);
    printf("■");
    move_cur(100, 32);
    printf("■");
    move_cur(98, 33);
    printf("■");
    move_cur(98, 24);
    printf("■");
    move_cur(100, 25);
    printf("■");
    move_cur(102, 26);
    printf("■");
    move_cur(104, 27);
    printf("■");
    move_cur(106, 28);
    printf("■");
    move_cur(108, 29);
    printf("■");
    move_cur(110, 30);
    printf("■");
    move_cur(112, 31);
    printf("■");
    move_cur(114, 32);
    printf("■");
    move_cur(116, 33);
    printf("■");
    move_cur(100, 23);
    printf("■");
    move_cur(102, 24);
    printf("■");
    move_cur(104, 25);
    printf("■");
    move_cur(106, 26);
    printf("■");
    move_cur(108, 27);
    printf("■");
    move_cur(110, 28);
    printf("■");
    move_cur(112, 29);
    printf("■");
    move_cur(114, 30);
    printf("■");
    move_cur(116, 31);
    printf("■");
    move_cur(118, 32);
    printf("■");
    move_cur(98, 32);
    printf("■");
    move_cur(100, 31);
    printf("■");
    move_cur(102, 30);
    printf("■");
    move_cur(104, 29);
    printf("■");
    move_cur(106, 28);
    printf("■");
    move_cur(108, 27);
    printf("■");
    move_cur(110, 26);
    printf("■");
    move_cur(112, 25);
    printf("■");
    move_cur(114, 24);
    printf("■");
    move_cur(116, 23);
    printf("■");
    move_cur(100, 33);
    printf("■");
    move_cur(102, 32);
    printf("■");
    move_cur(104, 31);
    printf("■");
    move_cur(106, 30);
    printf("■");
    move_cur(108, 29);
    printf("■");
    move_cur(110, 28);
    printf("■");
    move_cur(112, 27);
    printf("■");
    move_cur(114, 26);
    printf("■");
    move_cur(116, 25);
    printf("■");
    move_cur(118, 24);
    printf("■");
}

int mypagechoice() {

    int mySelect = 0;
    int mycount = 0;
    int result = 0;

    mySelect = getch();
    while (1) {
        mySelect = getch();
        if (mySelect == 10) {
            result = mycount % 3;
            return result;
        } else if (mySelect == 27) {
            mySelect = getch();
            if (mySelect == 91) {
                mySelect = getch();
                switch (mySelect) {
                case 67:
                    mycount += 1;
                    if (mycount % 3 == 1) {
                        system("clear");
                        loginPage1();
                    } else if (mycount % 3 == 2) {
                        system("clear");
                        loginPage2();
                    } else if (mycount % 3 == 0) {
                        system("clear");
                        loginPage3();
                    }
                    break;
                case 68:
                    if (mycount == 0) {
                        mycount = 34;
                    }
                    mycount -= 1;
                    if (mycount % 3 == 1) {
                        system("clear");
                        loginPage1();
                    } else if (mycount % 3 == 2) {
                        system("clear");
                        loginPage2();
                    } else if (mycount % 3 == 0) {
                        system("clear");
                        loginPage3();
                    }
                    break;
                default:
                    break;
                }
            }
        }
    }
    return 0;
}

int mypagemenuchoice() {

    int mySelect1 = 0;
    int mycount1 = 0;
    int result = 0;

    while (1) {
        mySelect1 = getch();
        if (mySelect1 == 10) {
            result = mycount1 % 2;
            return result;
        } else if (mySelect1 == 27) {
            mySelect1 = getch();
            if (mySelect1 == 91) {
                mySelect1 = getch();
                switch (mySelect1) {
                case 67:
                    mycount1 += 1;
                    if (mycount1 % 2 == 1) {
                        system("clear");
                        myPage1();
                    } else {
                        system("clear");
                        myPage2();
                    }
                    break;
                case 68:
                    if (mycount1 == 0) {
                        mycount1 = 21;
                    }
                    mycount1 -= 1;
                    if (mycount1 % 2 == 1) {
                        system("clear");
                        myPage1();
                    } else {
                        system("clear");
                        myPage2();
                    }
                    break;
                default:
                    break;
                }
            }
        }
    }
    return 0;
}
