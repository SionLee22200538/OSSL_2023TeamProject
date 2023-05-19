#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "manager.h"
#include "customer.h"

    
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
  printf("0. 종료\n\n");
  printf("=> 원하는 메뉴 입력: ");
  scanf("%d", &menu);
  return menu;
}