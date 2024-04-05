const express = require('express')
const cors = require('cors')

const app = express()

app.use(cors())

app.get('/', (req, res) => { // https://expressjs.com/en/4x/api.html#res
    res.send("HEIN ?") // renvoie un texte dans le body
    // res.json([ { "id":"1",   "title":"Book Review: The Bear & The Nightingale" } ]) // renvoie un json mdr
    // res.status(404).send('Sorry, we cannot find that!') // renvoie une erreur et écrit dans le body
    // res.redirect("https://jej888.fr/") // redirige vers une URL
    // res.download("package.json")
})

app.listen(2368, () => {
  console.log('listening for requests on port 2368')
})