#include <stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
    char  name[100];
    char type;
    int price;

} MENU;
int addScore(MENU *m);
void readScore(MENU m);
int updateScore(MENU *m);
void listScore(MENU *m[], int count);
int selectDataNo(MENU *m[], int count);

void saveData(MENU **s, int count);
int loadData(MENU **s);
void searchName(MENU **s, int count);


int selectMenu(){
int menu;
printf("\n*** PizzaYaho ***\n");
printf("1. 조회 \n");
printf("2. 추가 \n");
printf("3. 수정 \n");
printf("4. 삭제 \n");
printf("5. 파일저장 \n");
printf("6. 이름검색 \n");
printf("0. 종료\n\n");
printf("=> 원하는 메뉴는?");
scanf("%d", &menu);
return menu;
}

int main(void){ 
MENU*sp[100];
int index = 0;
int count = 0, menu;

count = loadData(sp);
index = count;

    while (1){
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1){
            if(count > 0)
                listScore(sp,index);
            else
                printf("데이터가 없습니다. \n");
        }
        else if (menu == 2){
            sp[index] = (MENU*)malloc(sizeof(MENU));
            count += addScore(sp[index++]);
        }
        else if (menu == 3){
            int no = selectDataNo(sp,index);
            if(no == 0){
                printf("=> 취소됨!\n");
                continue;
            }
            updateScore(sp[no-1]);
        }
        else if (menu == 4){
            int no = selectDataNo(sp, index);
            if(no == 0){
                printf("=> 취소됨!\n");
                continue;
            }
            int deleteok;
            printf("정말로 삭제하시겠습니까?(삭제 :1)");
            scanf("%d", &deleteok);
            if(deleteok ==1){
                if(sp[no -1]) free(sp[no-1]);
                sp[no-1] = NULL;
                 count --;
                 printf("\n=> 삭제됨!\n");
            } else printf("취소됨!\n");
        }

         else if (menu == 5){
            saveData(sp, index);
        }

        else if (menu == 6){
            searchName(sp, index);
        }

    }
printf("\n종료됨!\n");
return 0;
}



void readScore(MENU m){


     printf("     %d %c %s\n", m.price, m.type, m.name);
    
    

    return;
}

int addScore(MENU *m){
   printf("\n 메뉴명은?");
     scanf(" %[^\n]s", m->name);
    printf(" 메뉴종류(P/S/R)?");
    scanf(" %c", &m->type);
    printf(" 가격은?");
    scanf("%d", &m->price);
    
    printf("=>추가됨!\n");

    return 1;

}

int updateScore(MENU *m){
    printf("\n 메뉴명은?");
    scanf(" %[^\n]s", m->name);
    printf(" 메뉴종류(P/S/R)?");
    scanf(" %c", &m->type);
    printf(" 가격은?");
    scanf("%d", &m->price);

    printf("=> 수정성공!\n");

    return 1;
}


void listScore(MENU *m[], int count){
    printf("================================\n");
    for(int i=0; i<count ; i++){
        if(m[i] == NULL) continue;
        printf("%2d", i+1);
        readScore(*m[i]);
    }
    printf("\n");
}

int selectDataNo(MENU *m[], int count){
    int no;
    listScore(m, count);
    printf("번호는 (취소 :0)?");
    scanf("%d",&no);
    return no;
}

void saveData(MENU **m, int count){
    FILE *fp;
    fp = fopen("menu.txt","wt");

    for(int i=0; i<count ; i++){
        if(m[i] == NULL)continue;
        fprintf(fp,"     %d %c %s\n", m[i]->price, m[i]->type, m[i]->name);

    }
    fclose(fp);
    printf("==> 저장됨! ");
}


int loadData(MENU **m){
    int count =0, i = 0;
    FILE *fp;
    fp = fopen("menu.txt","rt");

    if(fp == NULL)
    {
        printf("\n=> 파일 없음\n");
        return 0;
    }

    for(; i<100 ; i++){
        m[i] = (MENU*)malloc(sizeof(MENU));
        fscanf(fp,"%s",m[i]->name);
        if(feof(fp)) break;
        fscanf(fp, "%d", &m[i]->price);
        fscanf(fp, "%c", &m[i]->type);

    }
    fclose(fp);
    printf("=> 로딩 성공!\n");
    return i;
}

void searchName(MENU **m, int count){
    int scnt = 0;
    char search [20];

    printf("\n검색할 이름? ");
    scanf("%s", search);

   printf("================================\n");
   for(int i =0; i <count ; i++){
    if(m[i]->price == -1) continue;
    if (strstr(m[i]->name, search)){
        printf("%2d", i+1);
        readScore(*m[i]);
        scnt++;
    }
   }
   if(scnt == 0) printf("=> 검색된 데이터 없음!");
   printf("\n");
}
