package main

import (
	"math"
	"sync"
)

// Fonction déterminant si un nombre
// entier impair est premier ou non.
func primarysearch(n int) bool {
	sqn := int(math.Sqrt(float64(n)))
	for i := 3; i <= sqn; i += 2 {
		if n%i == 0 {
			return false
		}
	}
	return true
}

// Pour le calcul des premiers jusqu'à 10 millions,
// l'usage de goroutines réduit le temps de
// calcul de 11-12 sec à 8-9 sec
func main() {
	// var compteur = make(map[int]int)
	var primes []int
	var wg sync.WaitGroup
	var mu sync.Mutex
	for i := 3; i < 1e7; i += 2 {
		wg.Add(1)
		go func(i int) {
			defer wg.Done()
			if primarysearch(i) {
				mu.Lock()
				defer mu.Unlock()
				primes = append(primes, i)
			}
		}(i)
	}
	wg.Wait()
	// fmt.Println(primes)
}
