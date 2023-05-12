#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
  char name[30];

  printf("Welcome!\n");

  printf("Type your name:");
  gets(name);

  printf("\nThis program is in production yet.\nThanks for comming, %s", name);

  return 0;
}