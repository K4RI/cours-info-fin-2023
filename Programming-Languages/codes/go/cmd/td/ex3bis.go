package main

// https://github.com/pemoreau/advent-of-code/blob/aca55ddb577bf2c757830519635611b09bb486d8/go/24/day24.go
// remplacé les champs "min" -> "mini" et "max" -> "maxi"
// pour substituer à "utils.min()" le générique "min()"

import (
	_ "embed"
	"fmt"
	"math"
	"strconv"
	"strings"
	"sync"
	"time"
)

//go:embed input.txt
var input_day string

type Instr interface {
	isInstr()
}

type Assign struct {
	reg Reg
	rhs Expr
}

type Input struct {
	reg Reg
}

func (a Assign) isInstr() {}
func (i Input) isInstr()  {}

func (i Input) String() string {
	return fmt.Sprintf("Input %s\n", i.reg)
}

func (a Assign) String() string {
	return fmt.Sprintf("%s = %v\n", a.reg, a.rhs)
}

type Expr interface {
	isExpr()
}
type Value int
type Reg string

type Add struct {
	reg Reg
	arg Expr
}

type Mul struct {
	reg Reg
	arg Expr
}

type Div struct {
	reg Reg
	arg Expr
}

type Mod struct {
	reg Reg
	arg Expr
}

type Eql struct {
	reg Reg
	arg Expr
}

func (v Value) isExpr() {}
func (r Reg) isExpr()   {}

func (a Add) isExpr() {}
func (m Mul) isExpr() {}
func (d Div) isExpr() {}
func (m Mod) isExpr() {}
func (e Eql) isExpr() {}

func (v Value) String() string {
	return fmt.Sprintf("%d", v)
}
func (r Reg) String() string {
	return string(r)
}

func (a Add) String() string {
	return fmt.Sprintf("(%s + %s)", a.reg, a.arg)
}
func (m Mul) String() string {
	return fmt.Sprintf("(%s * %s)", m.reg, m.arg)
}
func (m Mod) String() string {
	return fmt.Sprintf("(%s %% %s)", m.reg, m.arg)
}
func (d Div) String() string {
	return fmt.Sprintf("(%s / %s)", d.reg, d.arg)
}
func (e Eql) String() string {
	return fmt.Sprintf("(%s == %s)", e.reg, e.arg)
}

func parse(input string, index *int) (r Instr) {
	cmd := strings.Split(input, " ")

	reg := Reg(cmd[1][0])
	if cmd[0] == "inp" {
		var inputName = Reg(fmt.Sprintf("w%d", *index))
		*index += 1
		//return Assign{reg: reg, rhs: inputName}
		return Input{inputName}
	}

	var arg Expr
	if cmd[2] == "w" || cmd[2] == "x" || cmd[2] == "y" || cmd[2] == "z" {
		arg = Reg(cmd[2])
	} else {
		num, _ := strconv.Atoi(cmd[2])
		arg = Value(num)
	}
	var rhs Expr
	switch cmd[0] {
	case "add":
		rhs = Add{reg, arg}
	case "mul":
		rhs = Mul{reg, arg}
	case "div":
		rhs = Div{reg, arg}
	case "mod":
		rhs = Mod{reg, arg}
	case "eql":
		rhs = Eql{reg, arg}
	}
	return Assign{reg: reg, rhs: rhs}
}

func value(e Expr, env *Env) int {
	switch exp := e.(type) {
	case Value:
		return int(exp)
	case Reg:
		return env[regIndex(exp)]
	}
	return 0
}

func regIndex(reg Reg) int {
	return int(reg[0] - 'w')
}

type Env [4]int
type State struct {
	env        Env
	mini, maxi int
}
type World []*State

var wg sync.WaitGroup
var mu sync.Mutex

func eval(e Instr, world World) World {
	switch instr := e.(type) {
	case Input:
		fmt.Printf("BEFORE MERGE = %v\n", len(world))
		world = merge(world, instr.reg)
		fmt.Printf("AFTER MERGE  = %v\n", len(world))
		newWorld := make(World, 0, len(world))

		index := regIndex(instr.reg)
		//////////////////////////////////
		for _, state := range world {
			wg.Add(1)
			go func(state *State) {
				defer wg.Done()
				for i := 1; i <= 9; i++ {
					state.env[index] = i
					newState := State{env: state.env, mini: 10*state.mini + i, maxi: 10*state.maxi + i}
					mu.Lock()
					newWorld = append(newWorld, &newState)
					mu.Unlock()
				}
			}(state)
		}
		wg.Wait()
		//////////////////////////////////
		world = newWorld
		//fmt.Printf("AFTER INPUT  = %v\n", len(world))
	case Assign:
		switch exp := instr.rhs.(type) {
		case Add:
			index := regIndex(exp.reg)
			for _, state := range world {
				state.env[index] += value(exp.arg, &state.env)
			}
		case Mul:
			index := regIndex(exp.reg)
			for _, state := range world {
				state.env[index] *= value(exp.arg, &state.env)
			}
		case Div:
			index := regIndex(exp.reg)
			for _, state := range world {
				if value(exp.arg, &state.env) == 0 {
					panic("divide by zero")
				}
				state.env[index] /= value(exp.arg, &state.env)
			}
		case Mod:
			index := regIndex(exp.reg)
			for _, state := range world {
				if state.env[regIndex(exp.reg)] < 0 {
					panic("negative modulo")
				} else if value(exp.arg, &state.env) <= 0 {
					panic("modulo by zero or negative")
				}
				state.env[index] %= value(exp.arg, &state.env)
			}
		case Eql:
			index := regIndex(exp.reg)
			for _, state := range world {
				if value(exp.arg, &state.env) == state.env[index] {
					state.env[index] = 1
				} else {
					state.env[index] = 0
				}
			}
		}
	}
	return world
}

func merge(w World, reg Reg) World {
	m := map[Env]*struct{ mini, maxi int }{}
	//fmt.Printf("MERGE %v\n", w)
	for _, state := range w {
		//state.env[regIndex(reg)] = 0
		if entry, ok := m[state.env]; ok {
			entry.mini = min(entry.mini, state.mini)
			entry.maxi = max(entry.maxi, state.maxi)
			//fmt.Printf("UPDATE %v -> %v\n", state, entry)
		} else {
			m[state.env] = &struct{ mini, maxi int }{mini: state.mini, maxi: state.maxi}
			//fmt.Printf("ADD %v -> %v\n", state, m[state.env])
		}
	}
	res := make(World, 0, len(m))
	for env, minmax := range m {
		res = append(res, &State{env, minmax.mini, minmax.maxi})
	}
	return res
}

var mini = math.MaxInt
var maxi = 0

func Solve(input string) {
	if mini < maxi {
		return
	}
	input = strings.TrimSuffix(input, "\n")
	lines := strings.Split(input, "\n")
	instructions := make([]Instr, 0, len(lines))
	index := 1
	for _, line := range lines {
		instructions = append(instructions, parse(line, &index))
	}

	world := World{&State{env: Env{0, 0, 0, 0}, mini: 0, maxi: 0}}
	for i, instr := range instructions {
		fmt.Printf("#%d: %v\n", i, instr)
		world = eval(instr, world)
	}
	for _, state := range world {
		if state.env[regIndex("z")] == 0 {
			mini = min(mini, state.mini)
			maxi = max(maxi, state.maxi)
			//fmt.Printf("mini=%d maxi=%d\n", mini, maxi)
		}
	}

}
func Part1(input string) int {
	Solve(input)
	return maxi

}

func Part2(input string) int {
	Solve(input)
	return mini
}

func main() {
	fmt.Println("--2021 day 24 solution--")
	start := time.Now()
	fmt.Println("part1: ", Part1(string(input_day)))
	fmt.Println(time.Since(start))

	start = time.Now()
	fmt.Println("part2: ", Part2(string(input_day)))
	fmt.Println(time.Since(start))
}
