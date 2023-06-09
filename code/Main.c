#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "manager.h" 

int main(void) {
  int row, column;
  printf("가로 줄의 컴퓨터 수? ");
  scanf("%d", &row);
  printf("세로 줄의 컴퓨터 수? ");
  scanf("%d", &column);
  int total=row*column;
  customer_t *s[total]; //최대 컴퓨터 수 만큼 빈 고객 배열 만들기
  
  int count = 0;
  count=read_file(s);  //현재 저장된 파일에서 사용중인 고객 수를 받아옴

  int menu;
  while (1) {
    menu = selectMenu();
    if (menu == 0)
      break;
    if (menu == 1) {
      if (count != 0)
        read_customer(s, count);
      else 
        printf("데이터가 없습니다.\n");
    } else if (menu == 2) {
      s[count] = (customer_t*)malloc(sizeof(customer_t)); //배열에 메모리 할당
      if (add_customer(s[count],total)){
        printf("=> 추가됨!\n");
        count++;
      }
      else free(s[count]);
    } else if (menu == 3) {
      read_customer(s, count);
      int num = 0;
      printf("변경하고자 하는 고객 번호는 (취소 :0)? ");
      scanf("%d", &num);
      if (num == 0)
        break;
      int isUpdate = add_customer(s[num - 1], total); // add_customer()함수에서 데이터가 변경되었는지 확인 
      if (isUpdate == 1)
        printf("=> 수정됨!\n");
    } else if (menu == 4) {
      int num;
      int yn;
      if (count != 0) {
        read_customer(s, count);
        printf("삭제하실 고객의 좌석 번호는 (취소 :0)? ");
        scanf("%d", &num);
        if (num != 0) {
          printf("정말로 삭제하시겠습니까?(삭제 :1)" );
          scanf("%d", &yn);
        }
        if (yn == 1) {
          int isDel = delete_customer(s, num-1, count);
          if (isDel == 1)
            printf("=> 삭제됨!\n");
          count--;
        }
      }
    }
    else if (menu == 5){
      saveFile(s, count);
      printf("저장됨!\n");
    }
    else if (menu == 6){
      char sName[20];
      printf("검색할 이름은? ");
      scanf("%s", sName);
      nameSearch(s, count, sName);
    }
    else if (menu == 7) {
      auto_Off(s, count);
    }

    else if (menu == 8) {
      read_customer(s, count);
      int num = 0;
      printf("고객의 번호는 (취소 :0)? ");
      scanf("%d", &num);
      if (num == 0)
        break;
      int isPay = pay(s, num-1, count); // add_customer()함수에서 데이터가 변경되었는지 확인 
    }
    else if (menu == 9) {
      current(s,count,total);
    }
    else if (menu == 10){
      write(s,count,total);
    }
    else if (menu == 11){
      draw(s,row,column,count);
    }
  }
  
    for (int i = 0; i < count; i++) { //프로그램 종료 후 메모리 free
      free(s[i]); 
    }
}
