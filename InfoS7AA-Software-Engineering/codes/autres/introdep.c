// les pointeurs https://stackoverflow.com/a/5484723
// les structures de données https://pbil.univ-lyon1.fr/members/veber/ens/cours-C-L2/index.html
// les listes https://fr.wikibooks.org/wiki/Structures_de_donn%C3%A9es_en_C/Les_listes_simples


#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_Date Date;
struct s_Date { int day ;
                int month ;
                int year ;};

Date *create_date(int day, int month, int year)
{
    Date *date = malloc(sizeof(Date)); // IMPORTANT
    date->day = day;
    date->month = month;
    date->year = year;
    return date;
}

void print_date(Date *date)
{
    Date s_date = *date;
    printf("%i/%i/%i\n", s_date.day, s_date.month, s_date.year);
}

typedef struct s_Person Person;
struct s_Person { char *name ;
                  char *surname;
                  Date *birthdate;};

Person create_person(char *name, char *surname, int day, int month, int year)
{
    Person person = {.name = name, .surname = surname, .birthdate = create_date(day, month, year)};
    return person;
}

void print_person(Person person)
{
    printf("Name : %s\nSurname : %s\nDate of birth : ", person.name, person.surname);
    print_date(person.birthdate);
}


bool dates_equal (Date *date1, Date *date2)
{
    Date s_date1 = *date1;
    Date s_date2 = *date2;
    return (s_date1.day == s_date2.day) && (s_date1.month == s_date2.month) && (s_date1.year == s_date2.year);
}

Date *duplicate_date (Date *date)
{
    Date s_date = *date;
    return create_date(s_date.day, s_date.month, s_date.year);
}

Person duplicate_person (Person person)
{
    Date *newdate = duplicate_date(person.birthdate);
    Person newperson = {.name = person.name, .surname = person.surname, .birthdate = newdate};
    return newperson;
}

typedef struct s_List List;
struct s_List { List *next;
                void *date ;
};

List *insert(Date *date, List *list){
    List *newlist = malloc(0); // ok pk pas mdrr ?? pas malloc(sizeof(list)) ??
    newlist->date = date;
    newlist->next = list;
    return newlist;
}

void print_list(List *list){
    if (list){
        print_date(list->date);
        print_list(list->next);
    }
}

int main() {
   Date *date1 = create_date(1, 12, 2023);
   print_date(date1);
   Date *date2 = create_date(11, 11, 2000);
   print_date(date2);

   Person person = create_person("zac", "jej", 11, 11, 2000);
   print_person(person);

   Date *date3 = duplicate_date(date1);
   printf("%s\n", dates_equal(date1, date3) ? "true" : "false"); // true
   printf("%s\n", dates_equal(date2, date3) ? "true" : "false"); // false

   List *list = NULL; // liste vide
   list = insert(date1, list);
   list = insert(date2, list);
   list = insert(date3, list);
   print_list(list);

   return 0;
}