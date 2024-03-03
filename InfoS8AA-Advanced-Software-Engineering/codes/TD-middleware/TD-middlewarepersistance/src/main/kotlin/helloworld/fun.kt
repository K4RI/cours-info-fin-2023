package helloworld

fun main() {
    cases("Bonjour")
    cases(1)
    cases(3)
    cases(System.currentTimeMillis())
    cases(MaClasse())
    cases("bonjour")
}

fun cases(obj: Any) {
    when (obj) {
        1 -> println("Un")
        in 2..4 -> println("Entre deux et quatre")
        "Bonjour" -> println("Bienvenue")
        is Long -> println("Long")
        !is String -> println("Pas une chaîne de caractères")
        else -> println("Inconnu")
    }
}

class MaClasse() {
}