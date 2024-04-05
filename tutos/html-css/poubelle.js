let ticket = {
    nomFilm: "Anatomie d'une chute",
    prix: 5.30,
    numeroSalle: 1
}
let nom = "Zac"
console.log("Bonjour " + nom + ", votre film " + ticket.nomFilm + " est en salle " + ticket.numeroSalle)

let playlist = ["On Sight", "Strawberry Fields Forever", "Week-end a Rome"]
playlist.push("El Dorado", "Promiscuous")
playlist.pop()
console.log(playlist)
let playlistMalCopiee = playlist; // garde le même pointeur :/
let playlistCopiee = [...playlist];

