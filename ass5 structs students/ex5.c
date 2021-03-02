//
// Created by ori on 13/12/2020.
//
/***********
* Ori Angel
* 314617739
* 01
* ass05
***********/
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "ex5.h"

void mainDataCourses();

void endProgram();

void buildSystem(char option);

typedef struct Student {
    char *nameOfStudent;
    int grade;
} Student;

typedef struct StudentItem {
    Student *data;
    struct StudentItem *next;
} StudentItem;

typedef struct {
    StudentItem *head, *last;
} StudentList;

typedef struct Course {
    char *numCourse;
    char *nameOfCourse;
    StudentList *list;
} Course;

enum Bool {
    FALSE = 0,
    TRUE = 1
};

Course courses[MAX_COURSES + 1];

/******************
* Function Name: options
* Input: -
* Output: print Select the next operation (insert 6 for the entire menu):
* Function Operation: manage the options menu (scan char 0 to 6) and call to the correct functions
******************/
void options() {
    char option;
    scanf(" %c", &option);
    switch (option) {
        case '0':
            endProgram();
            break;
        case '1':
        case '2':
        case '3':
        case '4':
            buildSystem(option);
            break;
        case '5':
            mainDataCourses();
            break;
        case '6':
            printTheMenu();
            break;
        default: {
            printf("Error: unrecognized operation.\n");
        }
    }
    printf("Select the next operation (insert 6 for the entire menu):\n");
    options();
}

/******************
* Function Name: printTheMenu
* Input: -
* Output: print the menu
* Function Operation: print the menu of options
******************/
void printTheMenu() {
    printf("Please select an operation:\n"
           "\t0. Exit.\n"
           "\t1. Insert or update a class.\n"
           "\t2. Insert or update a student.\n"
           "\t3. Remove a student from classes.\n"
           "\t4. Print a class.\n"
           "\t5. Print all classes with their computed scores.\n"
           "\t6. Print the menu.\n");
    options();
}

/******************
* Function Name: setStudentNumCourse
* Input: str student Num Course input , index of the the start scan , str that copy the values
* Output: -
* Function Operation: set the StudentNumCourse
******************/
void setStudentNumCourse(char *str, int *iStart, char *nameStr) {
    for (int i = 0; i < 5; ++i) {
        nameStr[i] = str[*iStart];
        (*iStart)++;
    }
    (*iStart)++;
}

/******************
* Function Name: setStudentNameCourse
* Input: str student Name Course input , index of the the start scan , str that copy the values
* Output: -
* Function Operation: set the StudentNameCourse
******************/
void setStudentNameCourse(char *str, int *iStart, char *nameStr) {
    int i = 0;
    if (*iStart < 0) {
        return;
    }
    while (str[*iStart] != 0) {
        nameStr[i] = str[*iStart];
        (*iStart)++;
        i++;
    }
    (*iStart)++;
}

/******************
* Function Name: setStudentName
* Input: str student name , index of the the start scan , str that copy the values
* Output: -
* Function Operation: set the StudentName
******************/
void setStudentName(char *str, int *iStart, char *nameStr) {
    int i = 0;
    while (str[*iStart] != ':') {
        nameStr[i] = str[*iStart];
        i++;
        (*iStart)++;
    }
    (*iStart)++;
}

/******************
* Function Name: setStudentGrade
* Input: str student grade , index of the the start scan , str that copy the values
* Output: -
* Function Operation: set the StudentGrade
******************/
void setStudentGrade(char *str, int *iStart, char *nameStr) {
    int j = 0;
    while (str[*iStart] != ';') {
        nameStr[j] = str[*iStart];
        (*iStart)++;
        j++;
    }
    (*iStart)++;
}

/******************
* Function Name: newStudent
* Input: char *nameOfStudent, int grade
* Output: Student
* Function Operation: create new student with string and grade
******************/
Student *newStudent(char *nameOfStudent, int grade) {
    Student *std = (Student *) calloc(1, sizeof(Student));
    if (std == NULL) {
        endProgram();
    }
    std->nameOfStudent = nameOfStudent;
    if (std->nameOfStudent == NULL) {
        free(std->nameOfStudent);
        free(std);
        endProgram();
    }
    int i = 0;
    setStudentNameCourse(nameOfStudent, &i, std->nameOfStudent);
    std->grade = grade;
    return std;

}

/******************
* Function Name: freeStudent
* Input: Student *ps
* Output: -
* Function Operation: free student memory
******************/
void freeStudent(Student *ps) {
    if (ps != NULL) {
        free(ps->nameOfStudent);
        free(ps);
    }
}

/******************
* Function Name: freeStudentItem
* Input:StudentItem *item
* Output: -
* Function Operation: free StudentItem memory
******************/
void freeStudentItem(StudentItem *item) {
    if (item != NULL) {
        if (item->data != NULL)
            freeStudent(item->data);
        freeStudentItem(item->next);
        free(item);
    }
}

/******************
* Function Name: freeStudentList
* Input:StudentList *list
* Output: -
* Function Operation: freeStudentList memory
******************/
void freeStudentList(StudentList *list) {
    freeStudentItem(list->head);
    free(list);
}

/******************
* Function Name: freeCourse
* Input: StudentList int currentAmount
* Output: -
* Function Operation: freeCourse memory
******************/
void freeCourse(int currentAmount) {
    freeStudentList(courses[currentAmount].list);
    free(courses[currentAmount].numCourse);
    free(courses[currentAmount].nameOfCourse);
}

/******************
* Function Name: freeArrCourses
* Input:StudentList -
* Output: -
* Function Operation: freeArrCourses memory
******************/
void freeArrCourses() {
    for (int i = 0; i < MAX_COURSES; i++) {
        if (courses[i].nameOfCourse != NULL) {
            freeCourse(i);
        }
    }
}

/******************
* Function Name: endProgram
* Input:StudentList -
* Output: -
* Function Operation: free All and exit the program
******************/
void endProgram() {
    freeArrCourses();
    exit(1);
}

/******************
* Function Name: cleanEmptySpace
* Input:StudentList char *str, int iStar
* Output: return index after spaces
* Function Operation: clean spaces in str
******************/
int cleanEmptySpace(char *str, int iStar) {
    while (str[iStar] == ' ') {
        if (strlen(str) > iStar)
            iStar++;
        else {
            return -1;
        }
    }
    if (strlen(str) <= iStar)
        return -1;
    return iStar;
}

/******************
* Function Name: getCourseIndex
* Input:char *check
* Output: return course index in arr
* Function Operation: get course index in arr
******************/
int getCourseIndex(char *check) {
    int i = 0;
    if (check == NULL) {
        return -1;
    }
    if (strlen(check) != 5) {
        return -1;
    }
    while (courses[i].numCourse != NULL) {
        if (!strcmp(courses[i].numCourse, check)) {
            return i;
        }
        i++;
    }
    return -1;
}

/******************
* Function Name: newStudentList
* Input: -
* Output: return StudentList
* Function Operation: create new StudentList
******************/
StudentList *newStudentList() {
    StudentList *sl = (StudentList *) malloc(sizeof(StudentList));
    if (sl == NULL) {
        endProgram();
    }
    sl->head = NULL;
    sl->last = sl->head;
    return sl;
}

/******************
* Function Name: newIterator
* Input: StudentList *list
* Output: return newIterator
* Function Operation: return the head of list
******************/
StudentItem *newIterator(StudentList *list) {
    return list->head;
}

/******************
* Function Name: correctInsertOrUpdateCourseInput
* Input: char *str
* Output: return if Input correct or incorrect
* Function Operation: check if input correct
******************/
int correctInsertOrUpdateCourseInput(char *str) {
    int i = 0;
    int nameLength = 0;
    if (strlen(str) >= NUM_COURSE_LENGTH + 2) {
        while (str[i] != ' ') {
            //check if num course include just digits
            if (isdigit(str[i]) == 0 || i > 4) {
                return FALSE;
            }
            i++;
        }
        if (i != 5) {
            return FALSE;
        }
        i = cleanEmptySpace(str, i);
        if (i == -1) {
            return FALSE;
        }
        while (str[i] != 0) {
            //check if name course valid
            if ((isdigit(str[i]) == 0 && isalpha(str[i]) == 0 && str[i] != ' ') || nameLength > 30) {
                return FALSE;
            }
            i++;
            nameLength++;
        }
    } else {
        return FALSE;
    }
    return TRUE;
}

/******************
* Function Name: lastCourseIndex
* Input: -
* Output: return last course in arr index
* Function Operation: return last course in arr index
******************/
int lastCourseIndex() {
    if (courses[0].numCourse == NULL) {
        return 0;
    }
    for (int i = 0; i < MAX_COURSES; i++) {
        if (courses[i].numCourse == NULL) {
            return i;
        }
    }
    //no place in courses
    return -1;
}

/******************
* Function Name: insertCourse
* Input: char *numCourse, char *nameCourse
* Output: return if the function work
* Function Operation: insert course to arr
******************/
int insertCourse(char *numCourse, char *nameCourse) {
    int insertingIndex = lastCourseIndex();
    if (insertingIndex == -1) {
        printf("Unfortunately, there is no room for more classes.\n");
        return FALSE;
    }
    courses[insertingIndex].list = newStudentList();
    courses[insertingIndex].numCourse = numCourse;
    courses[insertingIndex].nameOfCourse = nameCourse;
    printf("Class \"%s %s\" added.\n", numCourse, nameCourse);
    return TRUE;

}

/******************
* Function Name: mainInsertOrUpdateCourse
* Input: char *str
* Output: message about add or update course
* Function Operation: manage insert or update functions
******************/
void mainInsertOrUpdateCourse(char *str) {
    if (correctInsertOrUpdateCourseInput(str)) {
        int i = 0;
        char *numCourse = (char *) calloc((NUM_COURSE_LENGTH + 1), sizeof(char));
        if (numCourse == NULL) {
            endProgram();
        }
        char *nameCourse = (char *) calloc((NAME_COURSE_LENGTH + 1), sizeof(char));
        if (nameCourse == NULL) {
            free(numCourse);
            endProgram();
        }
        setStudentNumCourse(str, &i, numCourse);
        i = cleanEmptySpace(str, i);
        setStudentNameCourse(str, &i, nameCourse);
        int courseIndex = getCourseIndex(numCourse);
        //insert course
        if (courseIndex == -1) {
            if (!insertCourse(numCourse, nameCourse)) {
                free(numCourse);
                free(nameCourse);
            }
        } else {
            //update course
            free(courses[courseIndex].numCourse);
            free(courses[courseIndex].nameOfCourse);
            courses[courseIndex].numCourse = numCourse;
            courses[courseIndex].nameOfCourse = nameCourse;
            printf("Class \"%s %s\" updated.\n", numCourse, nameCourse);
        }
    } else {
        printf("Error: invalid class number or name.\n");
    }
}

/******************
* Function Name: correctGrade
* Input: char *str
* Output: return if the grade correct (between 0 to 100)
* Function Operation: check if grade correct
******************/
int correctGrade(char *str) {
    int grade = atoi(str);
    if (grade >= 0 && grade <= 100) {
        return TRUE;
    }
    return FALSE;
}

/******************
* Function Name: checkNumCourse
* Input: char *str, int *iStart
* Output: return if num course correct
* Function Operation: check num course correct
******************/
int checkNumCourse(char *str, int *iStart) {
    char *checkNumCourse = (char *) calloc((NUM_COURSE_LENGTH + 1), sizeof(char));
    if (checkNumCourse == NULL) {
        endProgram();
    }
    int jCheck = 0;
    if ((strlen(str) - *iStart) >= 5) {
        while ((str[*iStart] != ',') && (strlen(str) - 1 != *iStart)) {
            if (strlen(str) > *iStart && jCheck <= 4 && isalnum(str[*iStart]) != 0) {
                checkNumCourse[jCheck] = str[*iStart];
                jCheck++;
                (*iStart)++;
            } else {
                free(checkNumCourse);
                return FALSE;
            }
        }
        //check if course is in arr courses
        if (getCourseIndex(checkNumCourse) == -1 || checkNumCourse == NULL) {
            free(checkNumCourse);
            return FALSE;
        }
    } else {
        free(checkNumCourse);
        return FALSE;
    }
    (*iStart)++;
    free(checkNumCourse);
    return TRUE;
}

/******************
* Function Name: checkName
* Input: char *str, int *iStart
* Output: return if name student correct
* Function Operation: check if name student correct
******************/
int checkName(char *str, int *iStart) {
    if (strlen(str) >= 2) {
        int countName = 0;
        int i = *iStart;
        if (str[i] == ':') {
            return FALSE;
        }
        while (str[i] != ':') {
            if (strlen(str) > i) {
                char c = str[i];
                if (isalpha(c) == 0 && (c != ' ') || countName > NAME_STUDENT_LENGTH) {
                    return FALSE;
                }
                i++;
                countName++;
            } else {
                return FALSE;
            }
        }
        i++;
        *iStart = i;
    } else {
        return FALSE;
    }
    return TRUE;
}

/******************
* Function Name: checkGrade
* Input: char *str, int *iStart
* Output: return if grade correct
* Function Operation: check if grade correct
******************/
int checkGrade(char *str, int *iStart) {
    char *checkGrade = (char *) calloc((4), sizeof(char));
    if (checkGrade == NULL) {
        endProgram();
    }
    int jCheck = 0;
    int i = *iStart;
    if (str[strlen(str) - 1] == ';') {
        while (str[i] != ';') {
            if (isdigit(str[i]) != 0) {
                checkGrade[jCheck] = str[i];
                jCheck++;
                i++;
            } else {
                free(checkGrade);
                return FALSE;
            }
        }
        if (!correctGrade(checkGrade)) {
            free(checkGrade);
            return FALSE;
        }
    } else {
        free(checkGrade);
        return FALSE;
    }
    i++;
    *iStart = i;
    free(checkGrade);
    return TRUE;
}

/******************
* Function Name: correctAddStudentInput
* Input: char *str
* Output: return if student input correct
* Function Operation: check if student input correct
******************/
int correctAddStudentInput(char *str) {
    int i = 0;
    int firstGrade = 1;
    //check name
    if (!checkName(str, &i)) {
        return FALSE;
    }
    while ((str[i] != ';' || firstGrade) && (str[i] != 0)) {
        //empty space
        i = cleanEmptySpace(str, i);
        if (i == -1) {
            return FALSE;
        }
        //numOfCourse
        if (!checkNumCourse(str, &i)) {
            return FALSE;
        }
        i = cleanEmptySpace(str, i);
        if (i == -1) {
            return FALSE;
        }
        //check valid grade
        if (!checkGrade(str, &i)) {
            return FALSE;
        }
        firstGrade = 0;
    }
    return TRUE;
}

/******************
* Function Name: isStudentInCourse
* Input: StudentList *list, char *nameStudent
* Output: return if student input correct
* Function Operation: check if student input correct
******************/
int isStudentInCourse(StudentList *list, char *nameStudent) {
    if (list != NULL) {
        StudentItem *iterator = newIterator(list);
        while (iterator != NULL) {
            if (!strcmp(iterator->data->nameOfStudent, nameStudent)) {
                return TRUE;
            }
            iterator = iterator->next;
        }
        return FALSE;
    }
    return FALSE;
}

/******************
* Function Name: countStudentInCourses
* Input: char *nameStr
* Output: return how many time student in courses
* Function Operation: return how many time student in courses
******************/
int countStudentInCourses(char *nameStr) {
    int count = 0;
    for (int i = 0; i < MAX_COURSES; i++) {
        if (isStudentInCourse(courses[i].list, nameStr)) {
            count++;
        }
    }
    return count;
}

/******************
* Function Name: isRemoveFromAllClass
* Input: char *str, int countCourses
* Output: return if student remove from all courses
* Function Operation: return if student remove from all courses
******************/
int isRemoveFromAllClass(char *str, int countCourses) {
    char *nameStr = (char *) calloc((NAME_STUDENT_LENGTH + 1), sizeof(char));
    if (nameStr == NULL) {
        endProgram();
    }
    int i = 0;
    setStudentName(str, &i, nameStr);
    if (countCourses == countStudentInCourses(nameStr)) {
        free(nameStr);
        printf("Error: student cannot be removed from all classes.\n");
        return FALSE;
    }
    free(nameStr);
    return TRUE;
}

/******************
* Function Name: correctRemoveStudentInput
* Input: char *str
* Output: return if remove student input correct
* Function Operation: check if remove student input correct
******************/
int correctRemoveStudentInput(char *str) {
    int i = 0;
    int firstGrade = 1;
    int countCourses = 0;
    if (!checkName(str, &i)) {
        printf("Error: invalid name or class number.\n");
        return FALSE;
    }
    while ((str[i] != ',' || firstGrade) && (str[i] != 0)) {
        //empty space
        firstGrade = 0;
        i = cleanEmptySpace(str, i);
        //numOfCourse
        if (!checkNumCourse(str, &i)) {
            printf("Error: invalid name or class number.\n");
            return FALSE;
        }
        countCourses++;
        firstGrade = 0;
    }
    if (firstGrade) {
        printf("Error: invalid name or class number.\n");
        return FALSE;
    }
    if (!isRemoveFromAllClass(str, countCourses)) {
        return FALSE;
    }
    return TRUE;
}

/******************
* Function Name: addStudentToCourse
* Input: StudentList *list, Student *str
* Output: -
* Function Operation: add student to course
******************/
void addStudentToCourse(StudentList *list, Student *str) {
    StudentItem *item = (StudentItem *) malloc(sizeof(StudentItem));
    item->data = str;
    item->next = NULL;
    if (list->head == NULL) {
        list->head = item;
        list->last = item;
    } else {
        list->last->next = item;
        list->last = item;
    }
}

/******************
* Function Name: printStudent
* Input: Student *ps
* Output: print student info
* Function Operation: print student info
******************/
void printStudent(Student *ps) {
    printf("%s, %d\n", ps->nameOfStudent, ps->grade);
}

/******************
* Function Name: printStudentList
* Input: StudentList *list
* Output: print StudentList
* Function Operation: print StudentList
******************/
void printStudentList(StudentList *list) {
    StudentItem *iterator = newIterator(list);
    while (iterator != NULL) {
        printStudent(iterator->data);
        iterator = iterator->next;
    }
}

/******************
* Function Name: updateStudentToCourse
* Input: StudentList *list, char *nameStudent, int grade
* Output: -
* Function Operation: update student data
******************/
void updateStudentToCourse(StudentList *list, char *nameStudent, int grade) {
    StudentItem *iterator = newIterator(list);
    while (iterator != NULL) {
        if (!strcmp(iterator->data->nameOfStudent, nameStudent)) {
            free(iterator->data->nameOfStudent);
            iterator->data->nameOfStudent = nameStudent;
            iterator->data->grade = grade;
        }
        iterator = iterator->next;
    }
}

/******************
* Function Name: divideAddOrUpdateStudent
* Input: char *numCourse, char *nameStr, int grade
* Output: send message update ot add the student to the system
* Function Operation: add or update student
******************/
void divideAddOrUpdateStudent(char *numCourse, char *nameStr, int grade) {
    int indexCourse = getCourseIndex(numCourse);
    int k = 0;
    char *nameStudent = (char *) calloc((NAME_STUDENT_LENGTH + 1), sizeof(char));
    if (nameStudent == NULL) {
        endProgram();
    }
    setStudentNameCourse(nameStr, &k, nameStudent);
    if (isStudentInCourse(courses[indexCourse].list, nameStudent)) {
        //update
        updateStudentToCourse(courses[indexCourse].list, nameStudent, grade);
        printf("Student \"%s\" updated to class \"%s %s\" with grade %d.\n",
               nameStudent, numCourse, courses[indexCourse].nameOfCourse, grade);

    } else {
        //add
        Student *str = newStudent(nameStudent, grade);
        addStudentToCourse(courses[indexCourse].list, str);
        printf("Student \"%s\" added to class \"%s %s\" with grade %d.\n",
               nameStudent, numCourse, courses[indexCourse].nameOfCourse, grade);
    }
}

/******************
* Function Name: mainInsertOrUpdateStudent
* Input: char *str
* Output: message if there is an error with the input
* Function Operation: manage insert or update student divide the input to student info
******************/
void mainInsertOrUpdateStudent(char *str) {
    int i = 0;
    if (correctAddStudentInput(str)) {
        char *nameStr = (char *) calloc((NAME_STUDENT_LENGTH + 1), sizeof(char));
        if (nameStr == NULL) {
            endProgram();
        }
        char *numCourse = (char *) calloc((NUM_COURSE_LENGTH + 1), sizeof(char));
        if (numCourse == NULL) {
            free(nameStr);
            endProgram();
        }
        setStudentName(str, &i, nameStr);
        while (str[i] != 0) {
            char *gradeStr = (char *) calloc((4), sizeof(char));
            if (gradeStr == NULL) {
                free(nameStr);
                free(numCourse);
                endProgram();
            }
            i = cleanEmptySpace(str, i);
            setStudentNumCourse(str, &i, numCourse);
            i = cleanEmptySpace(str, i);
            setStudentGrade(str, &i, gradeStr);
            divideAddOrUpdateStudent(numCourse, nameStr, atoi(gradeStr));
            free(gradeStr);
        }
        free(numCourse);
        free(nameStr);
    } else {
        printf("Error: invalid name, class number or grade.\n");
    }
}

/******************
* Function Name: removeStudent
* Input: StudentList *list, char *nameStr
* Output: -
* Function Operation: remove student from course divide the input to student info
******************/
void removeStudent(StudentList *list, char *nameStr) {
    StudentItem *iterator = newIterator(list);
    StudentItem *previous;
    // if this is the first item
    if (list->head && strcmp(list->head->data->nameOfStudent, nameStr) == 0) {
        list->head = iterator->next;
        if (list->head == NULL) {
            list->last = list->head;
        }
        iterator->next = NULL;
        freeStudentItem(iterator);
        return;
    }
    while (iterator != NULL && strcmp(iterator->data->nameOfStudent, nameStr) != 0) {
        previous = iterator;
        iterator = iterator->next;
    }
    if (iterator == NULL) return;
    else if (strcmp(iterator->data->nameOfStudent, nameStr) == 0) {
        previous->next = iterator->next;
        iterator->next = NULL;
        if (iterator == list->last)
            list->last = previous;
        freeStudentItem(iterator);
    }
}

/******************
* Function Name: mainRemoveStudent
* Input: char *str
* Output: -
* Function Operation: manage remove student from course
******************/
void mainRemoveStudent(char *str) {
    int i = 0;
    if (correctRemoveStudentInput(str)) {
        char *nameStr = (char *) calloc((NAME_STUDENT_LENGTH + 1), sizeof(char));
        if (nameStr == NULL) {
            endProgram();
        }
        char *numCourse = (char *) calloc((NUM_COURSE_LENGTH + 1), sizeof(char));
        if (numCourse == NULL) {
            free(nameStr);
            endProgram();
        }
        setStudentName(str, &i, nameStr);
        while (str[i] != 0) {
            i = cleanEmptySpace(str, i);
            setStudentNumCourse(str, &i, numCourse);
            int indC = getCourseIndex(numCourse);
            //is student in course
            if (!isStudentInCourse(courses[indC].list, nameStr)) {
                printf("Error: student is not a member of class \"%s %s\".\n",
                       numCourse, courses[indC].nameOfCourse);
                break;
            }
            removeStudent(courses[indC].list, nameStr);
            printf("Student \"%s\" removed from class \"%s %s\".\n",
                   nameStr, numCourse, courses[indC].nameOfCourse);
        }
        free(nameStr);
        free(numCourse);
    }
}

/******************
* Function Name: switchStudentItems
* Input: StudentItem *a, StudentItem *b
* Output: -
* Function Operation: switchStudentItems
******************/
void switchStudentItems(StudentItem *a, StudentItem *b) {
    Student *temp = a->data;
    a->data = b->data;
    b->data = temp;
}

/******************
* Function Name: bubbleSort
* Input: StudentList *list
* Output: -
* Function Operation: bubbleSort
 * function from lecture 9
******************/
void bubbleSort(StudentList *list) {
    StudentItem *i;
    int aBool = TRUE;
    while (aBool) {
        aBool = FALSE;
        i = newIterator(list);
        while (i->next != NULL) {
            if (strcmp(i->data->nameOfStudent, i->next->data->nameOfStudent) > 0) {
                aBool = TRUE;
                switchStudentItems(i, i->next);
            }
            i = i->next;
        }
    }
}

/******************
* Function Name: mainPrintParticipant
* Input: char *str
* Output: print participant info
* Function Operation: print participant info
******************/
void mainPrintParticipant(char *str) {
    int cInd = getCourseIndex(str);

    if (cInd != -1) {
        if (courses[cInd].list->head == NULL) {
            printf("Class \"%s %s\" has no students.\n", courses[cInd].numCourse, courses[cInd].nameOfCourse);
            return;
        } else {

            bubbleSort(courses[cInd].list);
            printf("Class \"%s %s\" students:\n", courses[cInd].numCourse, courses[cInd].nameOfCourse);
            printStudentList(courses[cInd].list);
        }

    } else {
        printf("Error: invalid class number.\n");
    }
}

/******************
* Function Name: countSpecificCourse
* Input: Course course
* Output: return how many student in course
* Function Operation: return how many student in course
******************/
int countSpecificCourse(Course course) {
    int countStudents = 0;
    StudentItem *iterator = newIterator(course.list);
    while (iterator != NULL) {
        countStudents++;
        iterator = iterator->next;
    }
    return countStudents;
}

/******************
* Function Name: countStudents
* Input: -
* Output: print how many student in course
* Function Operation: print how many student in course
******************/
void countStudents() {
    int i = 0;
    while (courses[i].numCourse != NULL) {
        int s = countSpecificCourse(courses[i]);
        if (s == 0) {
            printf("Class \"%s %s\" has no students.\n", courses[i].numCourse, courses[i].nameOfCourse);
        } else {
            printf("%s %s, %d\n", courses[i].numCourse, courses[i].nameOfCourse, s);
        }
        i++;
    }
}

/******************
* Function Name: sumSpecificCourse
* Input: Course course
* Output: return sum
* Function Operation: return sum of student in course
******************/
int sumSpecificCourse(Course course) {
    int sumStudents = 0;
    StudentItem *iterator = newIterator(course.list);
    if (iterator == NULL) {
        return -1;
    }
    while (iterator != NULL) {
        sumStudents = sumStudents + iterator->data->grade;
        iterator = iterator->next;
    }
    return sumStudents;
}

/******************
* Function Name: sumGrades
* Input: -
* Output: print sum of student in course
* Function Operation: print sum of student in course
******************/
void sumGrades() {
    int i = 0;
    while (courses[i].numCourse != NULL) {
        int s = sumSpecificCourse(courses[i]);
        if (s == -1) {
            printf("Class \"%s %s\" has no students.\n", courses[i].numCourse, courses[i].nameOfCourse);
        } else {
            printf("%s %s, %d\n", courses[i].numCourse, courses[i].nameOfCourse, s);
        }
        i++;
    }
}

/******************
* Function Name: averageGrade
* Input: -
* Output: print avg of student in course
* Function Operation: print avg of student in course
******************/
void averageGrade() {
    int i = 0;
    while (courses[i].numCourse != NULL) {
        //how many times the student in course
        int cSudents = countSpecificCourse(courses[i]);
        if (cSudents == 0) {
            printf("Class \"%s %s\" has no students.\n", courses[i].numCourse, courses[i].nameOfCourse);
        } else {
            int sum = sumSpecificCourse(courses[i]);
            int avg = sum / cSudents;
            printf("%s %s, %d\n", courses[i].numCourse, courses[i].nameOfCourse, avg);
        }
        i++;
    }
}

/******************
* Function Name: maxSpecificCourse
* Input: Course course
* Output: return max grade of student in course
* Function Operation: return max grade of student in course
******************/
int maxSpecificCourse(Course course) {
    int max = -1;
    StudentItem *iterator = newIterator(course.list);
    while (iterator != NULL) {
        if (max < iterator->data->grade) {
            max = iterator->data->grade;
        }
        iterator = iterator->next;
    }
    return max;
}

/******************
* Function Name: maxGrade
* Input: -
* Output: print max grade of student in course
* Function Operation: print max grade of student in course
******************/
void maxGrade() {
    int i = 0;
    while (courses[i].numCourse != NULL) {
        int max = maxSpecificCourse(courses[i]);
        if (max == -1) {
            printf("Class \"%s %s\" has no students.\n", courses[i].numCourse, courses[i].nameOfCourse);
        } else {
            printf("%s %s, %d\n", courses[i].numCourse, courses[i].nameOfCourse, max);
        }
        i++;
    }
}

/******************
* Function Name: minimalSpecificCourse
* Input: Course course
* Output: return min grade of student in course
* Function Operation: return min grade of student in course
******************/
int minimalSpecificCourse(Course course) {
    int minimal = 101;
    StudentItem *iterator = newIterator(course.list);
    while (iterator != NULL) {
        if (minimal > iterator->data->grade) {
            minimal = iterator->data->grade;
        }
        iterator = iterator->next;
    }
    return minimal;
}

/******************
* Function Name: minimalGrade
* Input: -
* Output: print min grade of student in course
* Function Operation: print min grade of student in course
******************/
void minimalGrade() {
    int i = 0;
    while (courses[i].numCourse != NULL) {
        int minimal = minimalSpecificCourse(courses[i]);
        if (minimal == 101) {
            printf("Class \"%s\" has no students.\n", courses[i].nameOfCourse);
        } else {
            printf("%s %s, %d\n", courses[i].numCourse, courses[i].nameOfCourse, minimal);
        }
        i++;
    }
}

/******************
* Function Name: dataOptions
* Input: -
* Output: print info course options
* Function Operation: print info course options call to the correct function
******************/
void dataOptions() {
    char dataOption;
    scanf(" %c", &dataOption);
    switch (dataOption) {
        case '0':
            printf("Select the next operation (insert 6 for the entire menu):\n");
            options();
            break;
        case 'a':
            averageGrade();
            break;
        case 'b':
            maxGrade();
            break;
        case 'c':
            minimalGrade();
            break;
        case 'd':
            sumGrades();
            break;
        case 'e':
            countStudents();
            break;
        default: {
            printf("Error.\n");
        }
    }
}

/******************
* Function Name: dataCoursesMenu
* Input: -
* Output: print info course options
* Function Operation: print info course options
******************/
void dataCoursesMenu() {
    printf("Please select the aggregation method:\n"
           "\ta. Average Grade.\n"
           "\tb. Maximal Grade.\n"
           "\tc. Minimal Grade.\n"
           "\td. Sum.\n"
           "\te. Count.\n"
           "\t0. Return to the main menu.\n");
    dataOptions();
}

/******************
* Function Name: mainDataCourses
* Input: -
* Output: print error if there is no classes
* Function Operation: manage data courses check if there is classes in the system
******************/
void mainDataCourses() {
    if (courses[0].numCourse == NULL) {
        printf("Error: there are no classes.\n");
        return;
    }
    dataCoursesMenu();
}

/******************
* Function Name: buildSystem
* Input: char option (1 to 4)
* Output: -
* Function Operation: manage system functions call to correct function
******************/
void buildSystem(char option) {
    char str[200];
    scanf(" %[^\n]", str);
    switch (option) {
        case '1':
            mainInsertOrUpdateCourse(str);
            break;
        case '2':
            mainInsertOrUpdateStudent(str);
            break;
        case '3':
            mainRemoveStudent(str);
            break;
        case '4':
            mainPrintParticipant(str);
            break;
        default: {
            printf("Error.\n");
        }
    }
}
