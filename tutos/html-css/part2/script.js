if (typeof document == 'undefined') {
    throw new Error("Lancer dans index.html !!!");
}

/*
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
*/


function afficherMot(liste, i, motOuPhrase){
    let zoneMotEcrit = document.querySelector("#zoneProposition span");    
    switch (motOuPhrase) {
        case 0:
            zoneMotEcrit.innerText = "Entrez le mot : " + liste[i];
            break;
        case 1:
            zoneMotEcrit.innerText = "Entrez la phrase : " + liste[i];
            break;
    };
}

function afficherResultat(score, i){
    let zoneScore = document.querySelector("#zoneScore");
    zoneScore.innerText = "Votre score est de " + score + "/" + i + ".";
}

function validerNom(nom){
    if (nom.length < 2){
        throw new Error("Nom trop court !");
    }
}

function validerEmail(email){
    let regex = new RegExp("^[a-z0-9._-]+@[a-z0-9._-]+\.[a-z0-9._-]+$")
    if (!regex.test(email)){
        throw new Error("Mail non valide !");
    }
}

function lancerJeu(){
    let listeChoisie = listeMots;
    let motOuPhrase = 0;
    let i = 0;
    let score = 0;

    let btnsRadio = document.querySelectorAll(".zoneChoix input"); // les boutons radio
    let btnValider = document.getElementById("valider"); // le bouton "Valider"
    let inputEntree = document.getElementById("entree"); // la zone input    
    let btnPartager = document.querySelector("#partager"); // le bouton partager (pas encore affiché !)
    let formulaire = document.querySelector("#partagerForm"); // le formulaire de partage (pas encore affiché !)
    let inputNom = document.getElementById("nom");
    let inputEmail = document.getElementById("email");

    afficherMot(listeChoisie, i, motOuPhrase);
    btnsRadio[0].checked = true;
    inputEntree.value = "";
    inputNom.value = "";
    inputEmail.value = "";

    // Gestion du changement des phrases : boutons radio
    for (let ind = 0; ind < btnsRadio.length; ind++){
        btnsRadio[ind].addEventListener("change", (event) => {
            switch (ind) {
                case 0:
                    listeChoisie = listeMots;
                    motOuPhrase = 0;
                    break;
                case 1:
                    listeChoisie = listePhrases;
                    motOuPhrase = 1;
                    break;
            };
            afficherMot(listeChoisie, i, motOuPhrase);
        });
    };

    // Gestion de la validation d'un mot : bouton "Valider"
    btnValider.addEventListener("click", (event) => {
        for (let jnd = 0; jnd < btnsRadio.length; jnd++){
            btnsRadio[jnd].disabled = true;
        };
        if (inputEntree.value === listeChoisie[i]) {
            score++;
        };
        i++;
        inputEntree.value = "";
        afficherResultat(score, i);

        if (listeChoisie[i] == undefined){
            // fin du jeu, on désactive tout
            btnValider.disabled = true;
            inputEntree.disabled = true;
            document.querySelector("#zoneProposition span").innerText = "Fin du jeu.";
            btnPartager.style.display = "inline-block";
        } else {            
            afficherMot(listeChoisie, i, motOuPhrase);
        }
    });
    // Si l'on tape Entrée dans la zone d'écriture, cela compte aussi comme un clic de bouton
    inputEntree.addEventListener("keypress", function(event) {
        if (event.key === "Enter") {
            btnValider.click();
        }
    });

    // Gestion du choix de partager : bouton "Partager"
    btnPartager.addEventListener("click", (event) => {
        formulaire.style.display = "inline-block";
        nom.focus();
    });

    // Gestion de l'envoi du mail de partage : bouton "Envoyer"
    formulaire.addEventListener("submit", (event) => {
        event.preventDefault(); // On empêche le comportement par défaut (le rechargement de la page)
        try { // on vérifie que les entrées sont bien valides
            let nom = inputNom.value;
            validerNom(nom); // avec ça
            let email = inputEmail.value;
            validerEmail(email); // et ça
            
            document.querySelector("#messageErreur").innerText = "";
            let mailto = `mailto:${email}?subject=Partage du score&body=Salut c'est ${nom}, je viens de réaliser le score ${score}/${i} :)`
            console.log(mailto);
            //location.href = mailto
        } catch (error) { // si validerNom() ou validerEmail() renvoient une erreur
            document.querySelector("#messageErreur").innerText = error;
        }
    });
};
