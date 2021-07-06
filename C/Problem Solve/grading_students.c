/*
HackerLand University has the following grading policy:

   1. Every student receives a grade in the inclusive range from 1 to 100.
   2. Any grade less than 30 is a failing grade. 

     

Sam is a professor at the university and likes to round each student's grade according to these rules:

  1.If the difference between the grade and the next multiple of 5 is less than 3 , round up to the next multiple of 5.
  2.If the value of grade  is less than 38 , no rounding occurs as the result will still be a failing grade.

Examples

  1. grade = 84 round to85 (85 - 84 is less than 3)
  2. grade = 29 do not round (result is less than 40)
  3. grade = do not round (60 - 57 is 3 or higher)

Given the initial value of  grade for each of Sam's n students, write code to automate the rounding 
process. 

Function Description

Complete the function gradingStudents in the editor below.

gradingStudents has the following parameter(s):

    int grades[n]: the grades before rounding

Returns

    int[n]: the grades after rounding as appropriate

Input Format

The first line contains a single integer,n , the number of students.
Each line i of the n subsequent lines contains a single integer, grades[i].

Constraints
  
  1<= n < =60
  0 <= grades[i] <= 100
  
Sample Input 0

4
73
67
38
33

Sample Output 0

75
67
40
33

*/

#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);

int parse_int(char*);

/*
 * Complete the 'gradingStudents' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY grades as parameter.
 */

/*
 * To return the integer array from the function, you should:
 *     - Store the size of the array to be returned in the result_count variable
 *     - Allocate the array statically or dynamically
 *
 * For example,
 * int* return_integer_array_using_static_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     static int a[5] = {1, 2, 3, 4, 5};
 *
 *     return a;
 * }
 *
 * int* return_integer_array_using_dynamic_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     int *a = malloc(5 * sizeof(int));
 *
 *     for (int i = 0; i < 5; i++) {
 *         *(a + i) = i + 1;
 *     }
 *
 *     return a;
 * }
 *
 */
int* gradingStudents(int grades_count, int* grades, int* result_count) {
    int t;
    for(int i =0; i<grades_count; i++)
    {
        if( grades[i]<38)
        {
            
        }
        else
        {
            t= grades[i]%5;
            if(t>=3)
            {
                t=5-t;
                grades[i]= grades[i]+t;
            }
        }
    }
    *result_count = grades_count;
    return grades;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int grades_count = parse_int(ltrim(rtrim(readline())));

    int* grades = malloc(grades_count * sizeof(int));

    for (int i = 0; i < grades_count; i++) {
        int grades_item = parse_int(ltrim(rtrim(readline())));

        *(grades + i) = grades_item;
    }

    int result_count;
    int* result = gradingStudents(grades_count, grades, &result_count);

    for (int i = 0; i < result_count; i++) {
        fprintf(fptr, "%d", *(result + i));

        if (i != result_count - 1) {
            fprintf(fptr, "\n");
        }
    }

    fprintf(fptr, "\n");

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}