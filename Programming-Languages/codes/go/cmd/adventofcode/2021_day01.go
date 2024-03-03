package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	f, _ := os.Open("./cmd/adventofcode/files/1.txt")
	defer f.Close()
	sc := bufio.NewScanner(f)

	var cpta, cptb int
	var val int
	vals := make([]int, 3)

	for i := 0; i < 3; i++ {
		sc.Scan()
		val, _ = strconv.Atoi(sc.Text())
		vals[i] = val
		if i > 0 && vals[i] > vals[i-1] {
			cpta++
		}
	}

	for sc.Scan() {
		val, _ = strconv.Atoi(sc.Text())
		if val > vals[2] {
			cpta++
		}
		if val > vals[0] {
			cptb++
		}
		vals[0], vals[1], vals[2] = vals[1], vals[2], val
	}
	fmt.Println(cpta, cptb)
}
