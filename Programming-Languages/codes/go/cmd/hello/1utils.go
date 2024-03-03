package main

import (
	"fmt"
	"math"
	"time"
)

func add(x int, y int) int {
	return x + y
}
func swap(x, y string) (string, string) {
	return y, x
}

func pow(x, n, lim float64) float64 {
	if v := math.Pow(x, n); v < lim {
		return v
	}
	return lim
}

// Fonction calculant une racine carrée
// à l'aide de l'algorithme de Newton.
// https://go.dev/tour/flowcontrol/8
func Sqrt(x float64) float64 {
	z := float64(30)
	for z*z-x > 1e-15 || z*z-x < -1e-15 {
		z -= (z*z - x) / (2 * z)
		fmt.Println(z)
	}
	return z
}

const Pi = 3.14

func main() {
	fmt.Printf("Now you have %f problems.\n", math.Sqrt(7))
	fmt.Println(math.Pi)
	fmt.Println(add(42, 13))
	u, v := swap("hello", "world")
	fmt.Println(u, v)

	var a int
	var b bool
	var c = 3
	var d int = 3
	e := 3
	fmt.Println(a, b, c, d, e)

	var x, y int = 3, 4
	var f float64 = math.Sqrt(float64(x*x + y*y))
	var z uint = uint(f)
	fmt.Println(x, y, z)

	var tab [2]string
	tab[0] = "Hello"
	tab[1] = "World"
	fmt.Println(tab[0], tab[1])
	fmt.Println(tab)
	primes := [6]int{2, 3, 5, 7, 11, 13}
	fmt.Println(primes)
	fmt.Println(primes[0])
	fmt.Println(len(primes))

	var s []int = primes[1:4]
	s[1] = 12
	fmt.Println(s)
	fmt.Println(primes)
	// Slice the slice to give it zero length.
	s = s[:0]
	printSlice(s)
	// Extend its length.
	s = s[:4]
	printSlice(s)
	// Drop its first two values.
	s = s[2:]
	printSlice(s)

	fmt.Println(s, len(s), cap(s))
	if s == nil {
		fmt.Println("nil!")
	}
	s = append(s, 3)
	printSlice(s)
	s2 := append(s, 3)
	printSlice(s2)

	var pow2 = []int{1, 2, 4, 8, 16, 32, 64, 128}
	for i, v := range pow2 {
		fmt.Printf("2**%d = %d\n", i, v)
	}

	sum := 0
	for i := 0; i < 10; i++ {
		sum += i
	}
	fmt.Println(sum)

	sum = 1
	for sum < 1000 {
		sum += sum
	}
	fmt.Println(sum)

	fmt.Println(
		pow(3, 2, 10),
		pow(3, 3, 20),
	)

	w := 42 // afficher le type
	fmt.Printf("w is of type %T\n", w)

	// package "time"
	t := time.Now()
	fmt.Println(t.String())
	fmt.Println(t.Format("2006-01-02 15:04:05")) // attention le format est précis
	fmt.Println(t.Weekday().String())
	fmt.Println(t.Hour())

}

func printSlice(s []int) {
	fmt.Printf("len=%d cap=%d %v\n", len(s), cap(s), s)
}
