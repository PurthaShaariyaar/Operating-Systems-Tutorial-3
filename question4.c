// Import all necessary header files

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief Main driver function initiates professor and number of students and their grades
 * 
 * @return int 
 */

int main () {

  // Assign number of characters to hold for professor name
  int nameSize = 256; 

  // Initialize number of students 
  int numStudents; 

  // Initialize Professor pointer and use calloc to allocate space  
  char *prof = (char *) calloc(nameSize, sizeof(char)); 

  printf("Enter your full name: "); 
  scanf("%s", prof);

  printf("Please enter your class size: "); 
  scanf("%d", &numStudents); 
 
  // Allocate memory for Student ID's and Grades
  int *studentID = (int *) malloc(numStudents * sizeof(int)); 
  int *studentGrades = (int *) malloc(numStudents * sizeof(int)); 

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

  // Test check to see if this worked
  printf("You entered\n: %s\n%d\n", prof, numStudents);
  
  // Free all allocated memory to reduce wasted storage space 
  free(prof); 
  free(studentID);
  free(studentGrades);

  return 0; 
}