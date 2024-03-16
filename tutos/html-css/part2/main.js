let baliseZoneProposition = document.getElementById("zoneProposition");
console.log(baliseZoneProposition);

let baliseZonePropositionSpan = document.querySelector("#zoneProposition span");
console.log(baliseZonePropositionSpan);

let listeInputRadio = document.querySelectorAll(".zoneChoix input");
for (let i = 0; i < listeInputRadio.length; i++) {
    console.log(i);
    console.log(listeInputRadio[i]);
}

console.log(document.querySelector("#valider"))

lancerJeu();