#ifndef TYPES_H_INCLUDED
#define TYPES_H_INCLUDED

typedef struct Books {
  char title  [50];
  char author [50];
  int  id;
} Books;

// custom types
typedef int *pt_int;

// Create a type wich is implicit week
typedef enum WeekType{Mon, Tue, Wed, Thur, Fri, Sat, Sun} WeekType;

#endif

// aliases types
#define TRUE 0;
#define FALSE 1;
