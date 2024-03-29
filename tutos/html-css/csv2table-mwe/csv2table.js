import 'https://cdn.jsdelivr.net/npm/jquery-csv@1.0.21/src/jquery.csv.min.js'

// on récupère l'en-tête et le corps du tableau dans la page HTML
const tableauHead = document.getElementById("tableau-head");
const tableauBody = document.getElementById("tableau-body");

///////// C'EST CA À MODIFIER /////////
const filePath = "table.csv";

$.get(filePath, function( data ) { // on lit le texte du csv

    // on parse ce texte en un objet
    const records = $.csv.toObjects(data);

    // les noms des colonnes
    const keys = Object.keys(records[0]);

    // création de l'en-tête
    let headrow = document.createElement("tr");
    keys.forEach(key => {
        let headcell = document.createElement("th");
        headcell.innerHTML = key;
        headrow.appendChild(headcell);
    })
    tableauHead.appendChild(headrow);

    // création du corps du tableau
    for (let i = 0; i < records.length; i++) {
        // on crée un HTMLElement de type ligne
        let row = document.createElement("tr");
        keys.forEach(key => {
            // on crée un HTMLElement de type case
            var cell = document.createElement("td")
            cell.innerHTML = records[i][key];
            row.appendChild(cell); // qu'on ajoute à la ligne
        })
        // et la ligne est ajoutée au tableau
        tableauBody.appendChild(row);
    }
})


