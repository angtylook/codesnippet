package main

import "fmt"

func main() {
	var x string = "Hello World"
	sameX := "Hello Again!"
	const constX string = "Const String"
	fmt.Println(x, sameX, constX)

	n := uint64(0x2)
	fmt.Printf("n=%x\n", n)
	fmt.Printf("nn=%x\n", ^n)

	fmt.Printf("u2=%b\n", uint64(2))
	fmt.Printf("u^2=%b\n", uint64(-3))
	fmt.Printf("2=%b\n", int64(2))
	fmt.Printf("^2=%b\n", ^int64(2))
}
