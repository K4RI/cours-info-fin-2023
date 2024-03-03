package main

import (
	"fmt"
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

// Producer envoyant des nombres aux workers.
func producer() <-chan int {
	c := make(chan int)
	go func() {
		for i := 1000000000000000001; i > 0; i -= 2 {
			c <- i
			// time.Sleep(time.Duration(200) * time.Millisecond)
		}
	}()
	return c
}

const N = 4 // nombre de workers

func main() {
	fin := make(chan bool)
	stream := producer()

	var nombres [N]int
	var mu [N]sync.Mutex
	for i := 0; i < N; i++ {
		go func(i int) {
			for {
				mu[i].Lock()
				// chaque worker reçoit un nombre dès qu'il le peut
				nombres[i] = <-stream
				// fmt.Printf("%d : %d\n", i, n[i])
				if primarysearch(nombres[i]) {
					// s'il est premier, il l'affiche...
					fmt.Println(nombres[i])
					// ...et met fin au programme.
					fin <- true
					mu[i].Unlock()
					return
				}
				// fmt.Printf("FINI %d : %d\n", i, n[i])
				mu[i].Unlock()
			}
		}(i)
	}
	<-fin
}
