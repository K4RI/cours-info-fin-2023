// https://www.jetbrains.com/help/idea/2022.2/debugging-your-first-java-application.html#examining-code

public class AverageFinder {
    public static void main(String[] args) {
        System.out.println("Average finder v0.1");
        double avg = findAverage(args);
        System.out.println("The average is " + avg);
    }
    // arrivé au breakpoint dans le debug :
    // step into findAverage(), puis steps over
    // affiche dans un onglet annexe l'état des variables
    // on peut même les modifier avec Set Value

    private static double findAverage(String[] input) {
        double result = 0;
        for (String s : input) {
            result += Integer.parseInt(s);
        }
        return result / input.length;
    }
}