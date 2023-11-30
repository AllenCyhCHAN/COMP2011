#include <iostream>
#include "lab7.h"
using namespace std;

void swap_students(Student*& student1, Student*& student2) {
    Student* temp = student1;
    student1 = student2;
    student2 = temp;
}

void reorder_student(Student* queue[], int num_students) {
    for (int i = 0; i < num_students - 1; i++) {
        for (int j = 0; j < num_students - i - 1; j++) {
            Student& currentStudentRef = *queue[j];
            Student& nextStudentRef = *queue[j + 1];

            int currentStudentYOS = currentStudentRef.yearOfStudy;
            int nextStudentYOS = nextStudentRef.yearOfStudy;

            if (currentStudentYOS < nextStudentYOS) {
                swap_students(queue[j], queue[j + 1]);
            }
        }
    }

}