package main

import (
	"fmt"
	"sync"
	"time"
)

func main() {
	say := func(s string) {
		for i := 0; i < 5; i++ {
			time.Sleep(200 * time.Millisecond)
			fmt.Println(s)
		}
	}
	go say("world")
	say("hello")

	// on a le go func qui marche en parallèle
	// finira-t-il avant le if ? avant l'affichage ?
	var data int
	go func() { data++ }()
	time.Sleep(0 * time.Millisecond)
	if data == 0 {
		time.Sleep(1 * time.Millisecond)
		fmt.Printf("the value is %v.\n", data)
	}

	// exemple de mutual exclusion :
	var memoryAccess sync.Mutex
	var value int
	go func() {
		memoryAccess.Lock() // -------
		value++
		memoryAccess.Unlock() // -------
	}()
	// ... mais si on avait pausé avant le Lock,
	// l'incrémentation passe devant
	memoryAccess.Lock() // -------
	// même en attendant longtemps, on a locké
	// donc la goroutine n'incrémentera pas avant l'affichage ...
	if value == 0 {
		fmt.Printf("the value is %v.\n", value)
	} else {
		fmt.Printf("the value is %v.\n", value)
	}
	memoryAccess.Unlock() // -------

	// deadlock
	/*
		type val struct {
			mu    sync.Mutex
			value int
		}
		var wg sync.WaitGroup
		printSum := func(v1, v2 *val) {
			defer wg.Done()
			v1.mu.Lock()
			defer v1.mu.Unlock()
			time.Sleep(2 * time.Second)
			v2.mu.Lock()
			defer v2.mu.Unlock()
			fmt.Printf("sum=%v\n", v1.value+v2.value)
		}
		var a, b val
		wg.Add(2)
		go printSum(&a, &b)
		go printSum(&b, &a)
		wg.Wait()
	*/

	// goroutine exemple 1
	var wg sync.WaitGroup
	salutation := "hello"
	wg.Add(1)
	go func() {
		defer wg.Done()
		salutation = "welcome"
	}()
	wg.Wait()
	fmt.Println(salutation) // hello or welcome?

	// goroutine exemple 2
	var wgg sync.WaitGroup
	for _, salutation := range []string{"hello", "greetings", "good day"} {
		wgg.Add(1)
		go func(salutation string) {
			defer wgg.Done()
			fmt.Println(salutation) // closure
		}(salutation)
	}
	wgg.Wait()

	// goroutine exemple 3
	var wggg sync.WaitGroup
	for _, salutation := range []string{"hello", "greetings", "good day"} {
		wggg.Add(1)
		go func(salutation string) {
			defer wggg.Done()
			fmt.Println(salutation)
		}(salutation)
	}
	wggg.Wait()

}
