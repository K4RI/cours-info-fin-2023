package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	f, _ := os.Open("./cmd/adventofcode/files/2.txt")
	defer f.Close()
	sc := bufio.NewScanner(f)

	var horiz, depth int
	var horiz2, depth2 int
	for sc.Scan() {
		line := strings.Split(sc.Text(), " ")
		n, _ := strconv.Atoi(line[1])
		switch line[0] {
		case "forward":
			horiz += n
			horiz2 += n         //
			depth2 += depth * n //
		case "down":
			depth += n
		case "up":
			depth -= n
		}
	}
	fmt.Println(horiz, depth, horiz*depth)
	fmt.Println(horiz2, depth2, horiz2*depth2)
}
