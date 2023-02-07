// Import all necessary header files

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief Create a new type name as a struct with two integers for student id and grades
 * 
 */

typedef struct grade {
  int student_id; 
  int mark; 
} grade; 

/**
 * @brief Opens a grades file and sums up all grades while also 
 *        saving each grade to corresponding studet
 * 
 * @param grades Struct type pointing to grade struct
 * @param num_students Corrosponds to number of students to be input in grades
 */

void grade_students(struct grade *grades, int num_students) {

  // Create a pointer of type file for communication between file and program
  FILE *fp; 

  // Open the grades.txt file in write mode 
  fp = fopen("grades.txt", "w"); 

  // Initialize sum of all grades to be zero 
  int sum = 0; 

  // Iterate through all grades and adding up the sum
  for (int i = 0; i < num_students; i++) {
    sum+=grades[i].mark; 

    // Write each Grade to corresponding Student ID in grades.txt in a single line
    fprintf(fp, "%d\t%d\n", grades[i].student_id, grades[i].mark);
  }

  // Close the file --> no longer needed
  fclose(fp);
}

int main() {
  
  // Assign number of characters to hold for professors name
  int nameSize = 256; 

  // Initialize all pointers and variables required 
  int num_students; 
  struct grade *g; 

  // Initialize Professor pointer and use calloc to allocate space  
  char *prof = (char *) calloc(nameSize, sizeof(char)); 

  // Professor user input of name
  printf("Enter your full name: "); 
  scanf("%s", prof); 

  // Professor user input of class size
  printf("Please enter number of students to mark: ");
  scanf("%d", &num_students); 

  // Allocate memory for Student ID's and Grades
  int *studentID = (int *) malloc(num_students * sizeof(int)); 
  int *studentGrades = (int *) malloc(num_students * sizeof(int)); 

  // Check if memory has been allocated by calloc and malloc 
  if (prof == NULL && studentID == NULL && studentGrades == NULL) {
    
    // Inform user allocation failed 
    printf("Memory allocation failed\n"); 

    // Return error 
    return 1; 
  } else {

    // Inform user allocation is a success
    printf("Memory allocation success\n"); 
  }

  // Allocate struct array for number of students 
  g = (grade*) malloc(sizeof(grade) * num_students);
  
  // Ask professor to input in Student IDs and grades;
  for (int i = 0; i < num_students; i++) {
    printf("Please enter the Student ID along with their grade: ");
    scanf("%d%d", &g[i].student_id, &g[i].mark); 
  }

  // Call grading system function to input in grades to grades.txt file 
  grade_students(g, num_students); 


  // Free all allocated memory to reduce wasted storage space 
  free(prof); 
  free(studentID);
  free(studentGrades);
  free(g); 


  return 0; 
} 