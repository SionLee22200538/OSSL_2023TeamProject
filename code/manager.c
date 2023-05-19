#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "manager.h"

int selectMenu() {
  int menu;
  printf("\n*** PC방 관리 프로그램 ***\n");
  printf("1. 조회\n");
  printf("2. 추가\n");
  printf("3. 수정\n");
  printf("4. 삭제\n");
  printf("5. 파일저장\n");
  printf("6. 이름검색\n");
  printf("7. 미성년자 강제 종료\n");
  printf("8. 정산하기\n");
  printf("9. PC방 전체 조회\n");
  printf("10. 좌석 확인\n");
  printf("0. 종료\n\n");
  printf("=> 원하는 메뉴 입력: ");
  scanf("%d", &menu);
  return menu;
}

int add_customer(customer_t *s) {
  printf("\n[고객 추가]\n");
  printf("이름: ");
  scanf("%s", s->name);
  printf("ID: ");
  scanf("%s", s->id);
  printf("성별(M/F): ");
  getchar(); 
  scanf("%c", &(s->gender));
  printf("전화번호: ");
  scanf("%s", s->phoneNumber);
  getchar();
  printf("나이: ");
  scanf("%d", &(s->age));
  printf("입장 시간: ");
  scanf("%s", s->startTime);
  printf("좌석 번호: ");
  scanf("%d", &(s->seat_num));
  return 1;
}

int read_file(customer_t *s[]) {
  FILE *fp;
  int count = 0;
  fp = fopen("customer.txt", "r");
  if (fp == NULL) {
    printf("파일 열기 실패!\n");
    return 0;
  }
  while (1) {
    s[count] = (customer_t*)malloc(sizeof(customer_t));
    int data = fscanf(fp, "%[^,],%[^,],%c %[^,],%d %c %f %c\n", s[count]->st_name, s[count]->st_id, &s[count]->fm, s[count]->st_major, &s[count]->abs_num, &s[count]->pf, &s[count]->grade, &s[count]->assignment);
    if (data != 8) {
      free(s[count]);
      break;
    }
    count++;
  }
  if (count == 0) printf("불러올 데이터가 없습니다.\n");
  else printf("%d명의 데이터 불러오기 성공!\n",count);
  fclose(fp);
  return count;
}
int read_file(customer_t *s[]) {
  FILE *fp = fopen("customer.txt", "rt");
  int count = 0;
  if (fp == NULL) {
    printf("파일 열기 실패!\n");
    return 0;
  }
  while (!feof(fp)) {
    s[count] = (customer_t *)malloc(sizeof(customer_t));
    int data = fscanf(fp, "%s %s %c %s %d %s %d", s[count]->name, s[count]->id,
           &(s[count]->gender), s[count]->phoneNumber, &(s[count]->age),
           s[count]->startTime, &(s[count]->seat_num));
    if (data != 8) {
      free(s[count]);
      break;
    }
    count++;
  }
  if (count == 0) printf("불러올 데이터가 없습니다.\n");
  else printf("%d명의 데이터 불러오기 성공!\n",count);
  fclose(fp);
  return count;
}