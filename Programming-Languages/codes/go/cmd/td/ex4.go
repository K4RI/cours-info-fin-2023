package main

import (
	"fmt"
	"math/rand"
	"sync"
	"time"
)

/*
On considère 3 processus :
● un producer qui envoie aux deux autres (au hasard) des signe ‘+’ ou des signes ‘-’
(1000 par exemple)
● un consumer compte les ‘+’ et renvoie les ‘-’ à l’autre consumer
● un consumer compte les ‘-’ et renvoie les ‘+’ à l’autre consumer
L’ensemble doit s'arrêter et lorsque tous les ‘+’ et les ‘-’ ont été comptés
*/

var signs = [2]rune{'+', '-'}
var wg sync.WaitGroup

// Producer envoyant des signes + ou - au hasard.
func producer() <-chan rune {
	c := make(chan rune)
	rng := rand.New(rand.NewSource(time.Now().UnixNano()))
	go func() {
		for i := 0; i < 100; i += 1 {
			c <- signs[rng.Intn(2)]
		}
	}()
	return c
}

func main() {
	stream := producer()
	wg.Add(100)

	var cpt1, cpt2 int // compteurs
	var mu1, mu2 sync.Mutex
	var x1, x2 rune
	var c1 = make(chan rune)
	var c2 = make(chan rune)

	go func() { // c1 : le compteur de '+'
		for {
			mu1.Lock()
			time.Sleep(5 * time.Millisecond)
			select {
			case ch, _ := <-c1: // le message reçu de c2 :)
				x1 = ch
			default:
				x1 = <-stream
			}
			if x1 == '+' {
				cpt1++
				fmt.Println("FI1", cpt1, cpt2)
				wg.Done()
			} else {
				go func() { c2 <- x1 }() // ?
			}
			mu1.Unlock()
		}
	}()

	go func() { // c2 : le compteur de '-'
		for {
			mu2.Lock()
			time.Sleep(5 * time.Millisecond)
			select {
			case ch, _ := <-c2: // le message reçu de c1 :)
				x2 = ch
			default:
				x2 = <-stream
			}
			if x2 == '-' {
				cpt2++
				fmt.Println("FI2", cpt1, cpt2)
				wg.Done()
			} else {
				go func() { c1 <- x2 }()
			}
			mu2.Unlock()
		}
	}()
	wg.Wait()
	fmt.Println(cpt1, cpt2)
}
