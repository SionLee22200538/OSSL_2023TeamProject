typedef struct {  //고객 데이터 구조체
    char name[30];
    char id[30];
    unsigned char gender;
    char phoneNumber[30];
    int age;
    char startTime[30];
    int seat_num;
} customer_t;


int add_customer(customer_t *s, int total); //고객 데이터를 구조체 배열에 저장하고 덮어쓰기로 변경도 하는 함수
int read_file(customer_t *s[]); //프로그램을 실행할때 파일을 통하여 데이터를 읽어오는 함수
void read_customer(customer_t *s[], int count); //구조체 배열의 데이터들을 출력
void saveFile(customer_t *s[], int count); //현재까지 구조체 배열에 저장된 데이터들을 텍스트 파일에 저장
int delete_customer(customer_t *s[], int index, int count); //구조체 배열에서 데이터를 삭제하는 함수


void current(customer_t *s[], int count); //PC방 전체의 현재 상황을 표시
int pay(customer_t *s[], int index, int count); //구조체 배열에서 데이터를 삭제하는 함수
void auto_Off(customer_t *s[], int count); //19세 미만 고객의 컴퓨터를 종료시키고 정산시키는 함수
int selectMenu(); //메뉴창을 출력하고 사용자가 어떤 동작을 선택했는지 return하는 함수
void nameSearch(customer_t *s[], int count, char *name); //이름을 검색하여 해당 고객의 데이터를 출력
void draw(customer_t *s[], int row, int column); //PC방 전체의 현재 상황을 표시
