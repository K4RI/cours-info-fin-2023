if (typeof document == 'undefined') {
    throw new Error("Lancer dans index.html !!!")
}


function choisirPhrasesOuMots(){
    let choix = "";
    while (choix != "mots" && choix != "phrases") {
        choix = prompt("Choisissez 'mots' ou 'phrases'")
    }
    return choix
}

function lancerBoucleDeJeu(liste){
    let score = 0;
    for (let i = 0; i < 3; i++) {
        let motUtilisateur = prompt("Entrez le mot : " + liste[i])
        if (motUtilisateur === liste[i]) {
            score++;
        }
    }
    return score
}

function afficherResultat(score, nombreQuestions) {
    console.log('Votre score est de ' + score + ' sur ' + nombreQuestions)
}

function lancerJeu(){
    choix = choisirPhrasesOuMots();
    if (choix == "mots"){
        score = lancerBoucleDeJeu(listeMots)
        afficherResultat(score, listeMots.length)
    } else if (choix == "phrases"){
        score = lancerBoucleDeJeu(listePhrases)
        afficherResultat(score, listePhrases.length)
    } else {
        throw new Error("Problème de liste !?")
    }
}
