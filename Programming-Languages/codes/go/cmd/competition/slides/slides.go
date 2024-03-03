package main

import (
	"fmt"
	"math/rand"
	"strconv"
	"time"
)

// https://go.dev/talks/2012/concurrency.slide

func boring(msg string) chan string { // Returns receive-only channel of strings.
	c := make(chan string)
	go func() {
		for i := 0; ; i++ {
			c <- msg + " " + strconv.Itoa(i) // Expression to be sent can be any suitable value.
			time.Sleep(time.Duration(rand.Intn(1e3)) * time.Millisecond)
		}
	}()
	return c // Return the channel to the caller.
}

func fanIn(input1, input2 <-chan string) <-chan string {
	c := make(chan string)
	go func() {
		for {
			c <- <-input1
		}
	}()
	go func() {
		for {
			c <- <-input2
		}
	}()
	return c
}

func main() {
	joe := boring("Joe")
	ann := boring("Ann")
	for i := 0; i < 5; i++ {
		select {
		case v1 := <-joe:
			fmt.Printf("received %v from Joe\n", v1)
		case v2 := <-ann:
			fmt.Printf("received %v from Ann\n", v2)
		}
	}
	fmt.Println("You're both boring; I'm leaving.")

	// multiplexing : les deux channels parlent dans un channel
	c := fanIn(boring("Joe"), boring("Ann"))
	for i := 0; i < 10; i++ {
		fmt.Println(<-c)
	}
	fmt.Println("You're both boring; I'm leaving.")

	// daisy-chain = téléphone arabe
	f := func(left, right chan int) {
		left <- 1 + <-right
	}
	const n = 10000
	leftmost := make(chan int)
	right := leftmost
	left := leftmost
	for i := 0; i < n; i++ {
		right = make(chan int)
		go f(left, right)
		left = right
	}
	go func(c chan int) { c <- 1 }(right)
	fmt.Println(<-leftmost)

}
