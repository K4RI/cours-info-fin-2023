package main

import (
	"fmt"
	"strings"
)

type Vertex struct {
	X int
	Y int
}

// Renvoie un tableau 2D de dimensions (dx, dy).
// https://go.dev/tour/moretypes/18
func Pic(dx, dy int, f func(int, int) uint8) [][]uint8 {
	tabb := make([][]uint8, dy)
	for y := 0; y < dy; y++ {
		tabb[y] = make([]uint8, dx)
		for x := 0; x < dx; x++ {
			tabb[y][x] = f(x, y)
		}
	}
	return tabb
}

// Compte le nombre d'occurrences des mots dans
// une chaîne de caractères. https://go.dev/tour/moretypes/23
func WordCount(s string) map[string]int {
	liste := strings.Fields(s)
	counts := make(map[string]int)
	for _, v := range liste {
		counts[v] += 1
	}
	return counts
}

// fibonacci is a function that returns
// a function that returns an int.
// https://go.dev/tour/moretypes/26
func fibonacci() func() int {
	fib0 := 0
	fib1 := 1
	return func() int {
		fib0, fib1 = fib1, fib0+fib1
		return fib0
	}
}

func main() {
	// utilisation de struct et des pointeurs
	vert := Vertex{1, 2}
	p := &vert
	p.X = 17
	vert.Y = 18
	fmt.Println(vert)
	fmt.Printf("type de ma structure : %T, et du pointeur : %T\n", vert, p)

	// un exemple de morpion avec des arrays de arrays
	board := [][]string{
		{"_", "_", "_"}, // []string
		{"_", "_", "_"}, // []string
		{"_", "_", "_"}, // []string
	}
	board[0][0] = "X"
	board[2][2] = "O"
	board[1][2] = "X"
	board[1][0] = "O"
	board[0][2] = "X"
	for i := 0; i < len(board); i++ {
		fmt.Printf("%s\n", strings.Join(board[i], " "))
	}

	tabb := []struct {
		i int
		b bool
	}{
		{2, true},
		{3, false},
		{5, true},
		{7, true},
		{11, false},
		{13, true},
	}
	fmt.Printf("%T\n", tabb[0])

	fun1 := func(x, y int) uint8 {
		return uint8((x + y) / 2)
	}
	fun2 := func(x, y int) uint8 {
		return uint8(x * y)
	}
	fun3 := func(x, y int) uint8 {
		return uint8(x ^ y)
	}
	picc1 := Pic(5, 4, fun1)
	picc2 := Pic(5, 4, fun2)
	picc3 := Pic(5, 4, fun3)
	fmt.Println(picc1)
	fmt.Println(picc2)
	fmt.Println(picc3)
	// pic.Show(Pic) // bon du coup marche pas avec ces arguments lol

	str := "coucou lala"
	for i := 0; i < len(str); i++ {
		fmt.Println(str[i])
	}

	fib := fibonacci()
	for i := 1; i < 15; i++ {
		fmt.Println(i, fib())
	}
}
