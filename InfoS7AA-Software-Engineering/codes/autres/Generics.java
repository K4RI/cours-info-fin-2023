import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;
/* https://stackoverflow.com/questions/897935/when-do-java-generics-require-extends-t-instead-of-t-and-is-there-any-down/904118#904118 */


class Generics {

    private static <T> void addGeneric(T element, List<T> list) {
        list.add(element);
        System.out.println(list);
    }

    public static void main(String[] args) {
        List<Serializable> dateList = new ArrayList<Serializable>();
        // List<java.util.Date> dateList = new ArrayList<java.util.Date>();
        Serializable s = new String();
        addGeneric(s, dateList);
    }
}