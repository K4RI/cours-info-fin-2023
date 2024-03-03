package main

import (
	"fmt"
)

func main() {

	// les channels
	stringStream := make(chan string)
	go func() {
		stringStream <- "Hello channels!"
		stringStream <- "yoyoyo!"
	}()
	str, ok := <-stringStream
	fmt.Printf("(%v): %s\n", ok, str)
	fmt.Println(<-stringStream)

	// on fait print un channel vide : deadlock
	/*
		stringStreamm := make(chan string)
		go func() {
			if true {
				return
			}
			stringStreamm <- "Hello channels!"
		}()
		fmt.Println(<-stringStreamm)
	*/

	// on peut close le stream pour lire en évitant le deadlock
	intStream := make(chan int)
	close(intStream)
	integer, ok := <-intStream
	fmt.Printf("(%v): %v\n", ok, integer)

	// exemple ici :
	intStreamm := make(chan int)
	go func() {
		defer close(intStreamm)
		for i := 1; i <= 5; i++ {
			intStreamm <- i
		}
	}()
	for integer := range intStreamm {
		fmt.Printf("%v ", integer) // sans le close, le dernier lirait dans un stream vide
	}

	// encapsulage...
	chanOwner := func() <-chan int {
		resultStream := make(chan int, 5)
		go func() {
			defer close(resultStream)
			for i := 0; i <= 5; i++ {
				resultStream <- i
			}
		}()
		return resultStream
	}
	// ... et lecture
	resultStream := chanOwner()
	for result := range resultStream {
		fmt.Printf("Received: %d\n", result)
	}
	fmt.Println("Done receiving!")

	// autre exemple
	fibonacci := func(n int, c chan int) {
		x, y := 0, 1
		for i := 0; i < n; i++ {
			c <- x
			x, y = y, x+y
		}
		close(c)
	}
	c := make(chan int, 10)
	go fibonacci(cap(c), c)
	for i := range c {
		fmt.Println(i)
	}
}
