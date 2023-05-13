#include "functions.h"
#include <stdio.h>
#include <conio.h>

void getPassword()
{
  printf("getPassword function");
}

void menu()
{
  int optionId;

  printf("Options:\n");
  printf("1. Generate password\n");
  printf("0. exit\n");

  scanf("%d", &optionId);

  printf("Option choose: %d", optionId);

  getch();
}