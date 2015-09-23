#include <stdio.h>
#include <string.h>

int main() {
    char max_scholarship_student_name[1000] = "";
    int n,
        max_scholarship = 0, 
        total = 0;
    scanf("%d", &n);

    for (int i=0; i<n; ++i) {
        char name[1000] = "", is_leader, is_west_student;
        int final, review, paper;
        int scholarship = 0;

        scanf("%s %d %d %c %c %d\n", name, &final, &review, &is_leader, &is_west_student, &paper);
        scholarship += final > 80 && paper > 0                  ? 8000 : 0;
        scholarship += final > 85 && review > 80                ? 4000 : 0;
        scholarship += final > 90                               ? 2000 : 0;
        scholarship += is_west_student == 'Y' && final > 85     ? 1000 : 0;
        scholarship += is_leader == 'Y' && review > 80          ? 850  : 0;
        
        if (scholarship > max_scholarship) {
            max_scholarship = scholarship;
            strcpy(max_scholarship_student_name, name);
        }

        total += scholarship;
    }

    printf("%s\n%d\n%d\n", max_scholarship_student_name, max_scholarship, total);
    return 0;
}

