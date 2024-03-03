package main

import (
	"fmt"
	"time"
)

func main() {
	start := time.Now()

	// select
	var c1, c2 <-chan int
	select {
	case <-c1:
	case <-c2:
	default:
		fmt.Printf("In default after %v\n", time.Since(start)) // jcrois il détecte que au-dessus de 250µs
	}
	fmt.Println("")

	// select exemple
	fibonaccii := func(c, quit chan int) {
		x, y := 0, 1
		for {
			select {
			case c <- x:
				x, y = y, x+y
			case <-quit:
				fmt.Println("quit")
				return
			}
		}
	}
	cc := make(chan int)
	quit := make(chan int)
	go func() {
		for i := 0; i < 10; i++ {
			fmt.Println(<-cc)
		}
		quit <- 0
	}()
	fibonaccii(cc, quit)
	time.Sleep(1000 * time.Millisecond)

	// select exemple 2 : minuteurs
	func() {
		tick := time.Tick(500 * time.Millisecond)   // attend 1000ms, puis renvoie, puis re-attend, etc...
		boom := time.After(3000 * time.Millisecond) // attend 5000ms, puis renvoie. c'est tout.
		for {
			select {
			case <-tick:
				fmt.Println("tick.")
			case <-boom:
				fmt.Println("BOOM!")
				return
			default:
				fmt.Println("    .")
				time.Sleep(200 * time.Millisecond)
			}
		}
	}()
}
