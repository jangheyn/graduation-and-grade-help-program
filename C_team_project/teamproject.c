#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define REQUIRED 1
#define OPTIONAL 0
#define DESIGN 1
#define NON_DESIGN 0
#define TOTAL_SUBJECTS (sizeof(subjects) / sizeof(subjects[0]))


typedef enum {
    FRESHMAN = 1, // 1학년
    SOPHOMORE,    // 2학년
    JUNIOR,       // 3학년
    SENIOR        // 4학년
} Year;

typedef enum {
    SEMESTER_1 = 1, // 1학기
    SEMESTER_2      // 2학기
} Semester;

typedef struct {
    int number;
    int year;           // 학년
    int semester;       // 학기
    char name[50];      // 과목명
    int isRequired;     // 전공필수 여부
    int isDesign;       // 설계과목 여부
    int score;          // 학점
} Subject;

Subject subjects[] = {
    {1,FRESHMAN, SEMESTER_1, "컴퓨터공학입문", OPTIONAL, NON_DESIGN, 3},
    {2,FRESHMAN, SEMESTER_1, "C프로그래밍", OPTIONAL, NON_DESIGN, 3},

    {3,FRESHMAN, SEMESTER_2, "C프로그래밍응용", OPTIONAL, DESIGN, 3},
    {4,FRESHMAN, SEMESTER_2, "창의적공학설계", OPTIONAL, DESIGN, 3},
    {5,FRESHMAN, SEMESTER_2, "파이썬프로그래밍", OPTIONAL, NON_DESIGN, 3},
    {6,FRESHMAN, SEMESTER_2, "전산수학", OPTIONAL, NON_DESIGN, 3},

    {7,SOPHOMORE, SEMESTER_1, "데이터구조", REQUIRED, NON_DESIGN, 3},
    {8,SOPHOMORE, SEMESTER_1, "자바프로그래밍", REQUIRED, NON_DESIGN, 3},
    {9,SOPHOMORE, SEMESTER_1, "유닉스와리눅스", OPTIONAL, DESIGN, 3},
    {10,SOPHOMORE, SEMESTER_1, "윈도우프로그래밍", OPTIONAL, NON_DESIGN, 3},
    {11,SOPHOMORE, SEMESTER_1, "진로탐색(1)", OPTIONAL, NON_DESIGN, 3},
    {12,SOPHOMORE, SEMESTER_1, "선형대수", OPTIONAL, NON_DESIGN, 3},

    {13,SOPHOMORE, SEMESTER_2, "데이터베이스", REQUIRED, NON_DESIGN, 3},
    {14,SOPHOMORE, SEMESTER_2, "자바프로그래밍응용", OPTIONAL, DESIGN, 3},
    {15,SOPHOMORE, SEMESTER_2, "논리회로", OPTIONAL, NON_DESIGN, 3},
    {16,SOPHOMORE, SEMESTER_2, "웹표준기술", OPTIONAL, NON_DESIGN, 3},
    {17,SOPHOMORE, SEMESTER_2, "진로탐색(2)", OPTIONAL, NON_DESIGN, 3},
    {18,SOPHOMORE, SEMESTER_2, "확률통계", OPTIONAL, NON_DESIGN, 3},
    {19,SOPHOMORE, SEMESTER_2, "컴퓨터네트워크", OPTIONAL, NON_DESIGN, 3},

    {20,JUNIOR, SEMESTER_1, "컴퓨터알고리즘", REQUIRED, DESIGN, 3},
    {21,JUNIOR, SEMESTER_1, "소프트웨어공학", REQUIRED, NON_DESIGN, 3},
    {22,JUNIOR, SEMESTER_1, "모바일프로그래밍", OPTIONAL, DESIGN, 3},
    {23,JUNIOR, SEMESTER_1, "웹응용기술", OPTIONAL, DESIGN, 3},
    {24,JUNIOR, SEMESTER_1, "인공지능", OPTIONAL, NON_DESIGN, 3},

    {25,JUNIOR, SEMESTER_2, "전공종합설계(1)", REQUIRED, DESIGN, 3},
    {26,JUNIOR, SEMESTER_2, "운영체제", REQUIRED, NON_DESIGN, 3},
    {27,JUNIOR, SEMESTER_2, "임베디드시스템", OPTIONAL, DESIGN, 3},
    {28,JUNIOR, SEMESTER_2, "머신러닝", OPTIONAL, DESIGN, 3},
    {29,JUNIOR, SEMESTER_2, "컴퓨터구조", OPTIONAL, NON_DESIGN, 3},

    {30,SENIOR, SEMESTER_1, "전공종합설계(2)", REQUIRED, DESIGN, 3},
    {31,SENIOR, SEMESTER_1, "고급네트워킹", OPTIONAL, NON_DESIGN, 3},
    {32,SENIOR, SEMESTER_1, "텍스트마이닝", OPTIONAL, NON_DESIGN, 3},
    {33,SENIOR, SEMESTER_1, "비즈니스컴퓨팅기술", OPTIONAL, NON_DESIGN, 3},

    {34,SENIOR, SEMESTER_2, "졸업작품", REQUIRED, NON_DESIGN, 0},
    {35,SENIOR, SEMESTER_2, "엔터프라이즈애플리케이션", OPTIONAL, NON_DESIGN, 3},
    {36,SENIOR, SEMESTER_2, "정보보안", OPTIONAL, NON_DESIGN, 3},
    {37,SENIOR, SEMESTER_2, "진로와취창업", OPTIONAL, NON_DESIGN, 2},
};

// 이수한 과목 정보를 저장할 배열
Subject taken_subjects[TOTAL_SUBJECTS];
int taken_count = 0;

void choice_menu();

void showTakenSubjects();

void printSubjectsGrid(int targetYear, int targetSemester);

void choice_Subjects();


int main() {
    int inputYear, inputSemester;
    void (*pf)(int, int); // 함수 포인터 선언

    printf("학년을 입력해주세요(ex: 1): ");
    scanf("%d", &inputYear);

    printf("학기를 입력해주세요(ex: 2): ");
    scanf("%d", &inputSemester);

    pf = printSubjectsGrid;
    pf(inputYear, inputSemester);

    pf = choice_Subjects;
    pf(inputYear, inputSemester);

    choice_menu();

    return 0;
}

void choice_menu() {
    int choice;
    int* pi;

    pi = &choice;

    while (1) {
        printf("\n======메뉴======\n");
        printf("1. 졸업 요건 확인\n");
        printf("2. 이수한 과목 목록 보기\n");
        printf("3. 이수한 과목 목록 수정\n");
        printf("4. 프로그램 종료\n");
        printf("메뉴를 선택하세요: ");
        scanf("%d", pi);

        switch (choice) {
        case 1:
            choice_Subjects();
            break;
        case 2:
            break;
        case 3:

            break;
        case 4:
            printf("프로그램을 종료합니다.\n");
            return;
        default:
            printf("잘못된 선택입니다. 다시 입력해주세요.\n");
            break;
        }
    }
}

void printSubjectsGrid(int inputYear, int inputSemester) {
    int currentYear = 0;
    int currentSemester = 0;

    for (int i = 0; i < TOTAL_SUBJECTS; i++) { //데이터의 순서가 정렬되어 있기 때문에 첫 과목부터 사용자가 입력한 학년과 학기까지 쭉 출력한다.

        // 현재 과목의 학년과 학기가 사용자 입력 범위를 초과하면 종료
        if (subjects[i].year > inputYear || (subjects[i].year == inputYear && subjects[i].semester > inputSemester)) { // 학년이 초과하거나 학년은 같은데 학기가 초과하는 경우
            break;
        }

        // 학년 또는 학기가 변경되면 헤더 출력
        if (subjects[i].year != currentYear || subjects[i].semester != currentSemester) {
            currentYear = subjects[i].year;
            currentSemester = subjects[i].semester;

            printf("\n%d학년 %d학기\n", currentYear, currentSemester);
            printf("-------------------------------------------------------------------------------------------------------------------\n");
        }

        // 과목 정보 출력 (과목 번호 포함)
        printf("%d. %s\n", subjects[i].number, subjects[i].name);
    }
}

void choice_Subjects() {
    int subject_number = 0;
    int inrequired_sum = 0;
    int noinrequired_sum = 0;

    printf("\n과목의 번호를 입력하시오 (종료하려면 100 입력):\n");
    while (1) {
        printf("과목 번호: ");
        scanf("%d", &subject_number);

        // 종료 조건
        if (subject_number == 100) {
            printf("입력이 종료되었습니다.\n");
            break;
        }

        // 입력한 과목 번호를 찾는 루프
        int found = 0; // 과목을 찾았는지 확인
        for (int i = 0; i < TOTAL_SUBJECTS; i++) {
            if (subject_number == subjects[i].number) { // 과목 번호가 일치하면 처리
                found = 1;

                if (subjects[i].isRequired == REQUIRED) { // 전공 필수 과목일 경우
                    inrequired_sum += subjects[i].score;
                }
                else { // 전공 선택 과목일 경우
                    if (subject_number == 34) { // 졸업작품의 학점은 0
                        noinrequired_sum += 0;
                    }
                    else if (subject_number == 37) { // 진로와취창업의 학점은 2
                        noinrequired_sum += 2;
                    }
                    else {
                        noinrequired_sum += subjects[i].score;
                    }
                }
                printf("%s 과목이 추가되었습니다.\n", subjects[i].name);
                break;
            }
        }

        // 디버깅 출력
        if (!found) {
            printf("잘못된 과목 번호입니다. 다시 입력하세요.\n");
        }
        else {
            printf("현재 전공 필수 학점: %d, 전공 선택 학점: %d\n", inrequired_sum, noinrequired_sum);
        }
    }

    // 졸업 요건 계산
    int required_credits = 24;    // 전공 필수 요건
    int elective_credits = 39;   // 전공 선택 요건

    required_credits -= inrequired_sum;
    elective_credits -= noinrequired_sum;

    // 초과 학점 처리
    if (required_credits < 0) required_credits = 0;
    if (elective_credits < 0) elective_credits = 0;

    // 최종 출력
    if (required_credits <= 0 && elective_credits <= 0) {
        printf("\n전공 종합설계와 졸업작품을 하셨을 경우 모든 요건을 채웠습니다.\n");
    }
    else {
        if (required_credits > 0) {
            printf("\n전공 필수가 %d 학점만큼 부족합니다.\n", required_credits);
        }
        if (elective_credits > 0) {
            printf("\n전공 선택이 %d 학점만큼 부족합니다.\n", elective_credits);
        }
    }
}

}
