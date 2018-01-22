package main

import "fmt"

func one(xPtr *int) {
	*xPtr = 1
}

func main() {
	xPtr := new(int)
	one(xPtr)
	fmt.Println(*xPtr)

	two := 2
	one(&two)
	fmt.Println(two)
}
