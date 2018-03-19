package main

import "fmt"

func main() {
	var x string = "Hello World"
	sameX := "Hello Again!"
	const constX string = "Const String"
	fmt.Println(x, sameX, constX)
}
