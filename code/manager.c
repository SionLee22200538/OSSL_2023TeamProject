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
  printf("10. 좌석 이용 현황\n");
  printf("11. 좌석표\n");
  printf("0. 종료\n\n");
  printf("=> 원하는 메뉴 입력: ");
  scanf("%d", &menu);
  return menu;
}

int add_customer(customer_t *s, int total) {
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
  printf("좌석 번호 (1~%d): ", total);
  scanf("%d", &(s->seat_num));
  return 1;
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

void read_customer(customer_t *s[], int count) {
  printf("\n[고객 정보 조회]\n");
  for (int i = 0; i < count; i++) {
    printf("========== 고객 정보 %d ==========\n", i + 1);
    printf("이름: %s\n", s[i]->name);
    printf("ID: %s\n", s[i]->id);
    printf("성별: %c\n", s[i]->gender);
    printf("전화번호: %s\n", s[i]->phoneNumber);
    printf("나이: %d\n", s[i]->age);
    printf("입장 시간: %s\n", s[i]->startTime);
    printf("좌석 번호: %d\n", s[i]->seat_num);
    printf("==============================\n");
  }
}

void saveFile(customer_t *s[], int count) {
  FILE *fp = fopen("customer.txt", "wt");
  if (fp == NULL) {
    printf("파일 열기 실패!\n");
    return;
  }

  for (int i = 0; i < count; i++) {
    fprintf(fp, "%s %s %c %s %d %s %d\n", s[i]->name, s[i]->id, s[i]->gender,
            s[i]->phoneNumber, s[i]->age, s[i]->startTime, s[i]->seat_num);
  }
  fclose(fp);
  printf("=> 저장 성공!\n");
}

int delete_customer(customer_t *s[], int index, int count) {
  if (index < 0 || index >= count) {
    printf("삭제할 데이터가 없습니다.\n");
    return 0;
  }
  free(s[index]);
  for (int i = index; i < count - 1; i++) {
    s[i] = s[i + 1];
  }
  printf("=> 삭제되었습니다!\n");
  return 1;
}

void current(customer_t *s[], int count, int total) {
  printf("\n[PC방 전체 확인]\n");
  printf("------------------------------------\n");
  for (int i = 0; i < count; i++) {
    printf("좌석 번호: %d\t", s[i]->seat_num);
    printf("이름: %s\t", s[i]->name);
    printf("입장 시간: %s\n", s[i]->startTime);
  }
  printf("------------------------------------\n");
}

int pay(customer_t *s[], int index, int count) {
  if (index < 0 || index >= count) {
    printf("범위 초과!\n");
    return 0;
  }
  else if (s[index] == NULL)
    printf("결제할 데이터가 없습니다.\n");
  else{
    printf("\n[정산하기]\n");
    printf("이름: %s\n", s[index]->name);
    printf("좌석 번호: %d\n", s[index]->seat_num);
    printf("입장 시간: %s\n", s[index]->startTime);
    free(s[index]);
    for (int i = index; i < count - 1; i++) {
      s[i] = s[i + 1];
    }
    printf("결제가 완료되었습니다!\n");
  }
  return 1;
}

void auto_Off(customer_t *s[], int count) {
  printf("\n[미성년자 강제 종료]\n");
  int underageCount = 0;
  for (int i = 0; i < count; i++) {
    if (s[i]->age < 19) {
      printf("미성년자 %s의 컴퓨터를 종료합니다.\n", s[i]->name);
      free(s[i]);
      underageCount++;
    }
  }
  printf("총 %d개의 미성년자 컴퓨터가 종료되었습니다.\n", underageCount);
}

void nameSearch(customer_t *s[], int count, char *name) {
  printf("\n[이름 검색]\n");
  int searchCount = 0;
  for (int i = 0; i < count; i++) {
    if (strcmp(s[i]->name, name) == 0) {
      printf("========== 고객 정보 %d ==========\n", i + 1);
      printf("이름: %s\n", s[i]->name);
      printf("ID: %s\n", s[i]->id);
      printf("성별: %c\n", s[i]->gender);
      printf("전화번호: %s\n", s[i]->phoneNumber);
      printf("나이: %d\n", s[i]->age);
      printf("입장 시간: %s\n", s[i]->startTime);
      printf("좌석 번호: %d\n", s[i]->seat_num);
    }
  }
}
void write(customer_t *s[], int count, int total){
    char seat[total];
    for(int i=0; i < total; i++){
        seat[i] = 'x';
        for(int j=0; j< count; j++) {
            if( i == (s[j]->seat_num)-1)
                seat[i] = 'o';
        }

        printf(" %d. %c ", i+1, seat[i]);

    }

}

void draw(customer_t *s[], int row, int column, int count){
    int total=row*column;

    char seat[total];
    for(int i=0; i < total; i++){
        seat[i] = 'x';
        for(int j=0; j< count; j++) {
            if( i == (s[j]->seat_num)-1)
                seat[i] = 'o';
        }
    }

    for(int i=0; i<row; i++) {
      for(int j=0; j<column; j++){
        printf("*********");
      }printf("\n");
      for(int j=0; j<column; j++){
        printf("*  %2d   *",(j+1)+column*(i));
      }printf("\n");
      for(int j=0; j<column; j++){
          printf("*   %c   *",seat[((j+1)+column*(i))-1]);
      }printf("\n");
      for(int j=0; j<column; j++){
          printf("*       *");
      }printf("\n");
      for(int j=0; j<column; j++){
          printf("*********");
      }
      printf("\n");
    
    }
    
}
