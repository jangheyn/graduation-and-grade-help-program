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
    char name[50];      // 교과목명
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

void choice_menu(int inputYear, int inputSemester);
void modifyTakenSubjects(int inputYear, int inputSemester);
void graduation_check();
void remove_subjects();
void showTakenSubjects();
void add_subject(int inputYear, int inputSemester);

int main() {
    int inputYear, inputSemester;
    void (*pf)(int, int); // 함수 포인터 선언

    printf("학년을 입력해주세요(ex: 1): ");
    scanf("%d", &inputYear);

    printf("학기를 입력해주세요(ex: 2): ");
    scanf("%d", &inputSemester);

    pf = add_subject;
    pf(inputYear, inputSemester);

    pf = choice_menu;
    pf(inputYear, inputSemester);

    return 0;
}

void showTakenSubjects() {
    printf("\n선택된 교과목 목록:\n");
    for (int i = 0; i < taken_count; i++) {
        printf("%d. %s\n", taken_subjects[i].number, taken_subjects[i].name);
    }
}

void choice_menu(inputYear, inputSemester) {
    int choice;
    int* pi;

    pi = &choice;

    while (1) {
        printf("\n========메뉴========\n");
        printf("1. 졸업 요건 확인\n");
        printf("2. 이수한 교과목 목록 보기\n");
        printf("3. 이수한 교과목 목록 수정\n");
        printf("4. 프로그램 종료\n");
        printf("메뉴를 선택하세요: ");
        scanf("%d", pi);

        switch (choice) {
        case 1:
            graduation_check();
            break;
        case 2:
            showTakenSubjects();
            break;
        case 3:
            modifyTakenSubjects(inputYear, inputSemester);
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

void graduation_check() {
    int required_major_credits = 24; // 전공필수 최소 학점
    int elective_major_credits = 39; // 전공선택 최소 학점
    int total_required_credits = 0; // 전공필수 이수 학점
    int total_elective_credits = 0; // 전공선택 이수 학점
    int design_course1_taken = 0; // 전공종합설계(1) 이수 여부
    int design_course2_taken = 0; // 전공종합설계(2) 이수 여부
    int graduation_project_passed = 0; // 졸업작품 심사 통과 여부

    FILE* file = fopen("graduation_requirements.txt", "w");
    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return;
    }

    // 이수한 과목 목록을 기준으로 학점 계산
    for (int i = 0; i < taken_count; i++) {
        if (taken_subjects[i].isRequired == REQUIRED) {
            total_required_credits += taken_subjects[i].score;
        }
        else {
            total_elective_credits += taken_subjects[i].score;
        }

        if (strcmp(taken_subjects[i].name, "전공종합설계(1)") == 0) {
            design_course1_taken = 1;
        }
        if (strcmp(taken_subjects[i].name, "전공종합설계(2)") == 0) {
            design_course2_taken = 1;
        }
        if (strcmp(taken_subjects[i].name, "졸업작품") == 0) {
            graduation_project_passed = 1;
        }
    }

    // 졸업 요건 충족 여부 확인
    if (total_required_credits >= required_major_credits &&
        total_elective_credits >= elective_major_credits &&
        design_course1_taken &&
        design_course2_taken &&
        graduation_project_passed) {
        printf("\n축하합니다 졸업 요건을 모두 충족하셨습니다!\n");
        fprintf(file, "축하합니다 졸업 요건을 모두 충족하셨습니다!\n");
    }
    else {
        printf("\n==== 졸업 요건 확인 ====\n");
        fprintf(file, "==== 졸업 요건 확인 ====\n");

        if (total_required_credits < required_major_credits) {
            printf("- 전공필수가 %d학점 부족합니다.\n", required_major_credits - total_required_credits);
            fprintf(file, "- 전공필수가 %d학점 부족합니다.\n", required_major_credits - total_required_credits);
        }
        if (total_elective_credits < elective_major_credits) {
            printf("- 전공선택이 %d학점 부족합니다.\n", elective_major_credits - total_elective_credits);
            fprintf(file, "- 전공선택이 %d학점 부족합니다.\n", elective_major_credits - total_elective_credits);
        }
        if (!design_course1_taken) {
            printf("- 전공종합설계(1)을 이수해야합니다.\n");
            fprintf(file, "- 전공종합설계(1)을 이수해야합니다.\n");
        }
        if (!design_course2_taken) {
            printf("- 전공종합설계(2)을 이수해야합니다.\n");
            fprintf(file, "- 전공종합설계(2)을 이수해야합니다.\n");
        }
        if (!graduation_project_passed) {
            printf("- 졸업작품 심사를 통과하셔야합니다.\n");
            fprintf(file, "- 졸업작품 심사를 통과하셔야합니다.\n");
        }

        printf("=========================\n");
        fprintf(file, "=========================\n");
    }
    printf("(graduation_requirements.txt에 현재 졸업요건이 저장 됐습니다.)\n");

    fclose(file);
}




void modifyTakenSubjects(int inputYear, int inputSemester) {
    int choice;

    // 함수 포인터 타입 정의
    typedef void (*SubjectFunction)(int, int);

    // 함수 포인터 배열
    SubjectFunction functions[] = { add_subject, remove_subjects };

    while (1) {
        printf("\n1. 교과목 추가\n");
        printf("2. 교과목 제거\n");
        printf("3. 메뉴로 돌아가기\n");
        printf("선택하세요: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 2) {
            // 함수 포인터를 사용하여 함수 호출
            functions[choice - 1](inputYear, inputSemester);
        }
        else if (choice == 3) {
            return;
        }
        else
            printf("잘못된 숫자입니다.\n");
    }
}

void remove_subjects() {
    if (taken_count == 0) {
        printf("이수한 과목이 없습니다.\n");
        return;
    }

    showTakenSubjects();

    char input[256];
    char seps[] = " ,\n\t"; // 분리자
    getchar(); // 입력 버퍼 비우기

    printf("\n제거할 과목의 번호를 공백으로 구분하여 입력하세요: ");
    fgets(input, sizeof(input), stdin);

    char* token = strtok(input, seps);
    while (token != NULL) {
        int number = atoi(token);

        // 과목 번호 검증
        if (number >= 1 && number <= TOTAL_SUBJECTS) {
            // 과목이 선택된 과목 목록에 있는지 확인
            int index = -1;
            for (int i = 0; i < taken_count; i++) {
                if (taken_subjects[i].number == number) {
                    index = i;
                    break;
                }
            }
            if (index != -1) {
                // 과목 제거
                for (int i = index; i < taken_count - 1; i++) {
                    taken_subjects[i] = taken_subjects[i + 1];
                }
                taken_count--;
                printf("과목 번호 %d (%s)가 제거되었습니다.\n", number, subjects[number - 1].name);
            }
            else {
                printf("과목 번호 %d는 선택된 과목 목록에 없습니다.\n", number);
            }
        }
        else {
            printf("유효하지 않은 과목 번호입니다: %d\n", number);
        }

        token = strtok(NULL, seps);
    }

    // 수정된 과목 목록 출력
    showTakenSubjects();

}

void add_subject(int inputYear, int inputSemester) {
    printf("\n추가 가능한 과목 목록:\n");
    int currentYear = 0;
    int currentSemester = 0;

    for (int i = 0; i < TOTAL_SUBJECTS; i++) {
        // 현재 과목의 학년과 학기가 사용자 입력 범위를 초과하면 종료
        if (subjects[i].year > inputYear || (subjects[i].year == inputYear && subjects[i].semester > inputSemester)) {
            break;
        }

        // 이미 선택된 과목인지 확인
        int already_taken = 0;
        for (int j = 0; j < taken_count; j++) {
            if (taken_subjects[j].number == subjects[i].number) {
                already_taken = 1;
                break;
            }
        }

        if (!already_taken) {
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

    // 추가할 과목 번호 입력 받기
    char input[256];
    char seps[] = " ,\n\t"; // 분리자

    printf("\n추가할 과목의 번호를 공백으로 구분하여 입력하세요: ");
    getchar(); // 입력 버퍼에 남아있는 개행 문자 제거
    fgets(input, sizeof(input), stdin);

    char* token = strtok(input, seps);
    while (token != NULL) {
        int number = atoi(token);

        // 과목 번호 검증
        if (number >= 1 && number <= TOTAL_SUBJECTS) {
            // 해당 과목이 입력한 학년과 학기 범위 내에 있는지 확인
            if (subjects[number - 1].year > inputYear || (subjects[number - 1].year == inputYear && subjects[number - 1].semester > inputSemester)) {
                printf("과목 번호 %d는 입력한 학년과 학기 범위를 벗어납니다.\n", number);
            }
            else {
                // 이미 선택된 과목인지 확인
                int already_taken = 0;
                for (int i = 0; i < taken_count; i++) {
                    if (taken_subjects[i].number == number) {
                        already_taken = 1;
                        break;
                    }
                }
                if (!already_taken) {
                    // 과목 추가
                    taken_subjects[taken_count++] = subjects[number - 1];
                    printf("과목 번호 %d (%s)가 추가되었습니다.\n", number, subjects[number - 1].name);
                }
                else {
                    printf("과목 번호 %d는 이미 선택되었습니다.\n", number);
                }
            }
        }
        else {
            printf("유효하지 않은 과목 번호입니다: %d\n", number);
        }

        token = strtok(NULL, seps);
    }

    // 추가된 과목 목록 출력
    showTakenSubjects();
}
