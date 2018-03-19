package main

import "fmt"

func main() {
	// loop and condition
	i := 1
	for i <= 3 {
		if i%2 == 0 {
			fmt.Println("even ", i)
		} else if i%2 == 1 {
			fmt.Println("odd ", i)
		} else {
			fmt.Println("unreachable")
		}
		i = i + 1
	}
	for i := 4; i <= 10; i++ {
		switch i {
		case 3:
			fmt.Println("Three")
		case 4:
			fmt.Println("Four")
		case 5:
			fmt.Println("Five")
		case 6:
			fmt.Println("Six")
		default:
			fmt.Println("Unknown Number")
		}
	}

}
