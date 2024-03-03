{
// Création d’un tableau
[];
[1, 2, 3];
console.log(Array.from({ length: 5 }, (v, i) => i));

// Création d’un objet
const empty = {};
const o = {
    name: "hello",
    array: [1, 2, 3],
};

const x = 5;
const y = 12;
const point1 = {
    x: x,
    y: y,
};
// spread operator
const point2 = { ...point1, x: 10 };
}

{
// Nested destructuring
const p = {
    name: "Bob",
    pos: { x: 5, y: 12 },
};
const {
    pos: { x }, // ???
    } = p;
const abs = x;
}

{
// Function destructuring
const p = {
    x: 5,
    y: 12,
};

const move1 = (p) => {
    return { x: p.x + 1, y: p.y };
};

const move2 = (p) => {
    const { x, y } = p;
    return { x: x + 1, y };
};

const move3 = ({ x, y }) => {
    return { x: x + 1, y };
};

const move4 = ({ x, y }) => ({ x: x + 1, y });

// map/reduce - object values
const a = [1, 2, 3, 4];
const sum = a.reduce((acc, cur) => acc + cur, 0);
console.log("somme =", sum)

const o = { a: 1, b: 2, c: 3, d: 4 };
const sum2 = Object.values(o).reduce((acc, cur) => acc + cur, 0);
console.log("autre somme =", sum2)

const new_o = Object.entries(o).reduce((acc, [key, value]) => {
    return { ...acc, [key]: value * 2 };
}, {});
console.log("objet doublé =", new_o)

const langages = [
    {
        id: 1,
        nom: "Python",
    },
    {
        id: 2,
        nom: "JavaScript",
    },
    {
        id: 3,
        nom: "Rust",
    }
]
const langagesObject = langages.reduce((accumulateur, ObjetCourant) => {
    return Object.assign(accumulateur, {[ObjetCourant.id]: ObjetCourant.nom})
}, {})
console.log(langagesObject)


// boucles
const N = 4;
console.log("Boucle for :");
for (let i = 0; i < N; i++) {
    console.log(i);
}

console.log("Boucle sur l'array :");
Array.from({ length: N }, (v, i) => {
    console.log(i);
});


// JSONobject
const jsonobject = {
    menu: {
    id: "file",
    value: "File",
    popup: {
    menuitem: [
    { value: "New", onclick: "CreateNewDoc()" },
    { value: "Open", onclick: "OpenDoc()" },
    { value: "Close", onclick: "CloseDoc()" },
    ],
    },
    },
};
console.log(JSON.stringify(jsonobject)); // objet vers texte...
}

{
const jsonstring =
'{"menu":{"id":"file","value":"File","popup":{"menuitem":[{"value":"New","onclick":"CreateNewDoc()"}, {"value":"Open","onclick":"OpenDoc()"},{"value":"Close","onclick":"CloseDoc()"}]}}}';
const jsonobject = JSON.parse(jsonstring); // ...texte vers objet
const {
    menu: {
        id,
        value,
    popup: { menuitem },
    },
} = jsonobject;
}