// les linked list https://www.geeksforgeeks.org/implementing-a-linked-list-in-java-using-class/

public class Introdep {
    public static class Date {
        private int day;
        private int month;
        private int year;

        public Date(int day, int month, int year) {
            this.day = day;
            this.month = month;
            this.year = year;
        }
        public String toString(){
            return String.valueOf(day) + "/" + String.valueOf(month) + "/" + String.valueOf(year);
        }

        public int getDay(){return day;}
        public int getMonth(){return month;}
        public int getYear(){return year;}
    }

    public static class Person {
        private String name;
        private String surname;
        private Date birthdate;

        public Person(String name, String surname, Date birthdate) {
            this.name = name;
            this.surname = surname;
            this.birthdate = birthdate;
        }
        public String toString(){
            return "Name : " + name + "\nSurname : " + surname + "\nDate of birth : " + birthdate;
        }

        public String getName(){return name;}
        public String getSurname(){return surname;}
        public Date getBirthdate(){return birthdate;}
    }

    public static boolean datesEqual(Date date1, Date date2){
        return (date1.getDay() == date2.getDay()) && (date1.getMonth() == date2.getMonth()) && (date1.getYear() == date2.getYear());
    }

    public static Date duplicateDate(Date date){
        return new Date(date.getDay(), date.getMonth(), date.getYear());
    }

    public static Person duplicatePerson(Person person){
        return new Person(person.getName(), person.getSurname(), duplicateDate(person.getBirthdate()));
    }
    

    public static class DateList {
        Date head;
        DateList next;

        public DateList() {
            this.head = null;
            this.next = null;
        }
        public String toString(){
            if (head == null){
                return "";
            } else if (next == null){
                return head.toString();
            } else {
                return head.toString() + "\n" + next.toString();
            }                
        }
    }
        
    public static DateList insert(DateList list, Date date){
        DateList newlist = new DateList();
        if (list.head == null){
            newlist.head = date;
        } else {
            newlist.next = list;
            newlist.head = date;
        }
        return newlist;
    }
    
    public static void main(String[] args) {
        Date date1 = new Date(1, 12, 2023);
        System.out.println(date1);
        Date date2 = new Date(11, 11, 2000);
        System.out.println(date2);
     
        Person person = new Person("zac", "jej", date2);
        System.out.println(person);
     
        Date date3 = duplicateDate(date1);
        System.out.println(datesEqual(date2, date3) ? "true" : "false"); // false
        System.out.println(datesEqual(date1, date3) ? "true" : "false"); // true

        DateList datelist = new DateList();
        datelist = insert(datelist, date1);
        datelist = insert(datelist, date2);
        System.out.println(datelist);

    }
}