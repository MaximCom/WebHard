#include "file.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
void move_cur(int x, int y);
void maximcom();
void fileupload();
void filedown();

// void move_cur(int x, int y) { // 커서이동 함수
//	printf("\033[%dd\033[%dG", y, x);
//}
/*
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
*/
void fileupload() {
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
    move_cur(56, 9);
    printf("★  My File Upload List\n");
    move_cur(57, 11);
    printf("n개 파일");
    move_cur(33, 15);
    printf(
        "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
    for (int i = 16; i < 38; i++) {
        move_cur(33, i);
        printf("┃                                                              "
               "    ┃");
    }
    move_cur(33, 38);
    printf(
        "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");

    printf("\n");
}

void filedowm() {
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
    move_cur(56, 9);
    printf("★  My File Dowmload List\n");
    move_cur(57, 11);
    printf("n개 파일");
    move_cur(33, 15);
    printf(
        "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
    for (int i = 16; i < 38; i++) {
        move_cur(33, i);
        printf("┃                                                              "
               "    ┃");
    }
    move_cur(33, 38);
    printf(
        "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");

    printf("\n");
}

/*
int main() {
system("clear");
fileupload();

return 0;
}*/
