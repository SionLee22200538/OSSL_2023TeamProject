# OSSL_2023TeamProject

## Table of Contents

- [Introduction](#introduction)
- [mini project 주제](#mini-project-주제)
  - [mini project에 대한 소개](#mini-project에-대한-소개)

- [project에 포함시킬 기능 설명](#project에-포함시킬-기능-설명)
- [개발환경 및 언어](#개발환경-및-언어)
- [팀소개 및 팀원이 맡은 역할](#팀소개-및-팀원이-맡은-역할)

## Introduction
2023년 1학기 OSS 2분반 이시온, 이윤석님의 팀 프로젝트 입니다!
![pc방](https://github.com/SionLee22200538/OSSL_2023TeamProject/blob/main/image/PCRoom.jpeg)


## mini project 주제
PC방 관리 프로그램

### mini project에 대한 소개
PC방 관리자의 고객 관리 프로그램
![dataType](https://github.com/SionLee22200538/OSSL_2023TeamProject/blob/main/image/dataType.png)

Customer 구조체 구성요소

''' JAVA

public class Customer {
    
    String name;
    
    String id;
    
    char gender;
    
    int age;
    
    String startTime;
    
    int num;
    
    
    String phoneNumber;
   }

'''


## project에 포함시킬 기능 설명
- CRUD 기능활용
  CRUD 기능을 활용하여 PC 방 이용자를 등록, 조회, 수정, 삭제 기능을 포함시킬 것입니다.
  
- 좌석 상태 출력
  좌석 상태 출력을 실행했을 때 현재 사용가능한 좌석, 이용중인 좌석을 알려주는 줍니다.
  ex) 1. o  2. x  3. o  4. o  5. x  6. o  
  
- 좌석 표 출력
  좌석 표 출력을 실행하면 좌석 상태를 표(그림) 형태로 출력해줍니다.
  
  
'''java

  *************************************************************************************
  *             *             *              *               *            *           *
  *     O       *      X      *      O       *       O       *      X     *     O     *
  *             *             *              *               *            *           *
  *************************************************************************************
'''

  
  

- 미성년자 자동 로그아웃 시스템
  오후 10시 이후 미성년자들이 pc방 이용이 제한된다는 점을 가지고
  고객 정보를 받을 때 나이를 받아 20세 미만의 사용자는 모두 사용을 종료시키고 
  종료된 사용자의 리스트를 출력합니다.
  또한 종료와 동시에 정산을 진행합니다.
  
- 결제 정산 시스템
후불 결제 시스템을 활용하여 이용자가 이용을 중단했을 때 이용한 시간을 계산해서 이용한 시간만큼 일정 가격을 책정한다.

  - 이용 시간은 시스템 시간을 이용하여 사용자의 사용 시작시간을 기록하고, 사용의 사용 종료 시간을 기록하여 이 둘의 차로 계산합니다 .
  




## 개발환경 및 언어
게발 언어: JAVA


## 팀소개 및 팀원이 맡은 역할




