package main

import (
	"fmt"
	"math/rand"
	"time"
)

var messages = [18]string{"The world itself's",
	"just one big hoax.",
	"Spamming each other with our",
	"running commentary of bullshit,",
	"masquerading as insight, our social media",
	"faking as intimacy.",
	"Or is it that we voted for this?",
	"Not with our rigged elections,",
	"but with our things, our property, our money.",
	"I'm not saying anything new.",
	"We all know why we do this,",
	"not because Hunger Games",
	"books make us happy,",
	"but because we wanna be sedated.",
	"Because it's painful not to pretend,",
	"because we're cowards.",
	"- Elliot Alderson",
	"Mr. Robot"}

func producer() <-chan string {
	c := make(chan string)
	go func() {
		for i := 0; i < 17; i++ {
			c <- messages[i]
			time.Sleep(time.Duration(rand.Intn(1e3)) * time.Millisecond)
		}
	}()
	return c
}

func main() {
	stream := producer()
	for i := 0; i < 17; i++ {
		fmt.Printf("Message reçu : %v\n", <-stream)
	}

}
